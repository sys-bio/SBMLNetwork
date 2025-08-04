# ---------------------------------------------------------------------
# Benchmark parameters
# ---------------------------------------------------------------------
SIZES = [(20, 5),
         (40, 10),
         (60, 15),
         (80, 20),
         (120, 30),
         (160, 40),
         (240, 60),
         (320, 80),
         (480, 120),
         (640, 160),
         (800, 200),
         (1000, 250),
         (1200, 300),
         (1400, 350),
         (1600, 400),
         (1800, 450),
         (2000, 500)]

import math
import time
import random
import libsbml
import SBMLDiagrams
import sbmlnetwork
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import json
import glob
import os
from datetime import datetime
from matplotlib import rcParams

# Set style
rcParams.update({
    'font.size': 11,
    'font.family': 'serif',
    'axes.linewidth': 0.8,
    'axes.spines.left': True,
    'axes.spines.bottom': True,
    'axes.spines.top': False,
    'axes.spines.right': False,
    'xtick.major.size': 4,
    'xtick.minor.size': 2,
    'ytick.major.size': 4,
    'ytick.minor.size': 2,
    'legend.frameon': True,
    'legend.fancybox': False,
    'legend.shadow': False,
    'grid.alpha': 0.3,
    'grid.linewidth': 0.5
})


# ---------------------------------------------------------------------
# SBML model generator
# ---------------------------------------------------------------------
def create_model(
        num_species: int,
        num_reactions: int,
) -> str:
    model_id = "model"
    compartment_id = "compartment"
    rate_value = 1.0

    # 1.  Document + model + compartment
    doc = libsbml.SBMLDocument(3, 1)
    model = doc.createModel()
    model.setId(model_id)

    comp = model.createCompartment()
    comp.setId(compartment_id)
    comp.setSize(1.0)
    comp.setConstant(True)

    # 2.  Create all species
    species_ids = [f"S{i + 1}" for i in range(num_species)]
    for sid in species_ids:
        sp = model.createSpecies()
        sp.setId(sid)
        sp.setCompartment(compartment_id)
        sp.setInitialAmount(0.0)
        sp.setBoundaryCondition(False)
        sp.setHasOnlySubstanceUnits(False)
        sp.setConstant(False)

    # 3.  Partition species into N chunks
    chunk_size = math.ceil(num_species / num_reactions)
    chunks = [
        species_ids[i * chunk_size: (i + 1) * chunk_size]
        for i in range(num_reactions)
    ]

    # 4.  Build reactions
    for idx, chunk in enumerate(chunks, start=1):
        rid = f"R{idx}"
        reaction = model.createReaction()
        reaction.setId(rid)
        reaction.setReversible(False)
        reaction.setFast(False)

        # split chunk into reactants/products
        half = len(chunk) // 2
        reactants = chunk[:half] or chunk
        products = chunk[half:] or chunk

        # add reactants
        for s in reactants:
            r = reaction.createReactant()
            r.setSpecies(s)
            r.setStoichiometry(1)
            r.setConstant(True)

        # add products
        for s in products:
            p = reaction.createProduct()
            p.setSpecies(s)
            p.setStoichiometry(1)
            p.setConstant(True)

        # simple mass‐action kinetics
        law = reaction.createKineticLaw()
        expr = " * ".join(reactants)
        law.setMath(libsbml.parseL3Formula(f"k_{rid} * {expr}"))
        param = law.createParameter()
        param.setId(f"k_{rid}")
        param.setValue(rate_value)
        param.setConstant(True)

    return libsbml.writeSBMLToString(doc)


# ---------------------------------------------------------------------
# Timing helpers
# ---------------------------------------------------------------------
def time_cpp_layout(sbml: str, iters: int = 50) -> float:
    net = sbmlnetwork.load(sbml)
    t0 = time.perf_counter()
    net.auto_layout(iterations=iters)
    return (time.perf_counter() - t0) * 1_000  # ms


def time_py_layout(sbml: str, iters: int = 50) -> float:
    dia = SBMLDiagrams.load(sbml)
    t0 = time.perf_counter()
    dia.autolayout(iterations=iters)
    return (time.perf_counter() - t0) * 1_000  # ms


# ---------------------------------------------------------------------
# Data Loading/Generation with Caching
# ---------------------------------------------------------------------
def load_existing_data():
    # Look for existing CSV files
    csv_files = glob.glob('layout_benchmark_data_*.csv')
    json_files = glob.glob('layout_benchmark_raw_*.json')

    if csv_files and json_files:
        # Get the most recent files
        latest_csv = max(csv_files, key=os.path.getctime)
        latest_json = max(json_files, key=os.path.getctime)

        print(f"Found existing data files:")
        print(f"  • {latest_csv}")
        print(f"  • {latest_json}")
        print("Loading existing data instead of running benchmark...\n")

        # Load CSV data
        df = pd.read_csv(latest_csv)

        # Load JSON data
        with open(latest_json, 'r') as f:
            json_data = json.load(f)

        # Extract data for plotting
        species_counts = df['species'].tolist()
        cpp_means = df['cpp_mean_ms'].tolist()
        py_means = df['python_mean_ms'].tolist()
        cpp_stds = df['cpp_std_ms'].tolist()
        py_stds = df['python_std_ms'].tolist()

        # Get fit parameters
        fit_cpp = [json_data['fit_parameters']['cpp_slope'],
                   json_data['fit_parameters']['cpp_intercept']]
        fit_py = [json_data['fit_parameters']['python_slope'],
                  json_data['fit_parameters']['python_intercept']]
        r2_cpp = json_data['fit_parameters']['cpp_r_squared']
        r2_py = json_data['fit_parameters']['python_r_squared']

        return {
            'species_counts': species_counts,
            'cpp_means': cpp_means,
            'py_means': py_means,
            'cpp_stds': cpp_stds,
            'py_stds': py_stds,
            'fit_cpp': fit_cpp,
            'fit_py': fit_py,
            'r2_cpp': r2_cpp,
            'r2_py': r2_py,
            'loaded_from_file': True,
            'csv_file': latest_csv,
            'json_file': latest_json
        }

    return None


def run_benchmark():
    print("No existing data found. Running benchmark...")

    cpp_means, py_means, species_counts = [], [], []
    cpp_stds, py_stds = [], []
    all_raw_data = []

    print("Starting benchmark...")
    print("Species | Reactions | C++ Time (ms) | Python Time (ms) | Progress")
    print("-" * 70)

    for i, (n_sp, n_rxn) in enumerate(SIZES):
        doc = create_model(n_sp, n_rxn)

        # Increased number of runs for better statistics
        cpp_runs = [time_cpp_layout(doc) for _ in range(10)]
        py_runs = [time_py_layout(doc) for _ in range(10)]

        cpp_mean = np.mean(cpp_runs)
        py_mean = np.mean(py_runs)
        cpp_std = np.std(cpp_runs)
        py_std = np.std(py_runs)

        species_counts.append(n_sp)
        cpp_means.append(cpp_mean)
        py_means.append(py_mean)
        cpp_stds.append(cpp_std)
        py_stds.append(py_std)

        # Store raw data
        run_data = {
            'species': n_sp,
            'reactions': n_rxn,
            'cpp_runs': cpp_runs,
            'py_runs': py_runs,
            'cpp_mean': cpp_mean,
            'cpp_std': cpp_std,
            'py_mean': py_mean,
            'py_std': py_std
        }
        all_raw_data.append(run_data)

        progress = f"({i + 1}/{len(SIZES)})"
        print(
            f"{n_sp:7d} | {n_rxn:9d} | {cpp_mean:8.1f} ± {cpp_std:5.1f} | {py_mean:10.1f} ± {py_std:6.1f} | {progress}")

    print("-" * 70)

    # Calculate fits
    logX = np.log10(species_counts)
    fit_cpp = np.polyfit(logX, np.log10(cpp_means), 1)
    fit_py = np.polyfit(logX, np.log10(py_means), 1)

    r2_cpp = calculate_r_squared(logX, np.log10(cpp_means), fit_cpp)
    r2_py = calculate_r_squared(logX, np.log10(py_means), fit_py)

    return {
        'species_counts': species_counts,
        'cpp_means': cpp_means,
        'py_means': py_means,
        'cpp_stds': cpp_stds,
        'py_stds': py_stds,
        'fit_cpp': fit_cpp,
        'fit_py': fit_py,
        'r2_cpp': r2_cpp,
        'r2_py': r2_py,
        'loaded_from_file': False,
        'all_raw_data': all_raw_data
    }


# ---------------------------------------------------------------------
# Main execution: Load existing data or run benchmark
# ---------------------------------------------------------------------
random.seed(1)

# Try to load existing data first
data = load_existing_data()

if data is None:
    # No existing data found, run the benchmark
    data = run_benchmark()
else:
    # Data was loaded from file
    print("Data loaded successfully!")

# Extract variables for compatibility with rest of code
species_counts = data['species_counts']
cpp_means = data['cpp_means']
py_means = data['py_means']
cpp_stds = data['cpp_stds']
py_stds = data['py_stds']
fit_cpp = data['fit_cpp']
fit_py = data['fit_py']
r2_cpp = data['r2_cpp']
r2_py = data['r2_py']


# ---------------------------------------------------------------------
# Power-law (straight-line) fits in log–log space
# ---------------------------------------------------------------------
def calculate_r_squared(x, y, fit_params):
    y_pred = np.polyval(fit_params, x)
    ss_res = np.sum((y - y_pred) ** 2)
    ss_tot = np.sum((y - np.mean(y)) ** 2)
    return 1 - (ss_res / ss_tot)


def power_law(x, a, b):
    return 10 ** b * x ** a


x_dense = np.logspace(np.log10(min(species_counts)) * 0.8,
                      np.log10(max(species_counts)) * 1.2,
                      500)
fig, ax = plt.subplots(figsize=(8, 6), dpi=300)
colors = {
    'cpp': '#2E86AB',     # blue
    'python': '#F24236',  # red
}

# --- Plot data -------------------------------------------------------
ax.loglog(species_counts, cpp_means, 'o',  color=colors['cpp'],
          markersize=6, alpha=0.8, markeredgewidth=0.5,
          markeredgecolor='white')
ax.loglog(species_counts, py_means,  's',  color=colors['python'],
          markersize=6, alpha=0.8, markeredgewidth=0.5,
          markeredgecolor='white')

print(species_counts)
print(cpp_means)
print(py_means)
print([py / cpp for cpp, py in zip(cpp_means, py_means)])

# Fitted curves (same colour)
ax.loglog(x_dense, power_law(x_dense, *fit_cpp),
          color=colors['cpp'], linewidth=2, alpha=0.7)
ax.loglog(x_dense, power_law(x_dense, *fit_py),
          color=colors['python'], linewidth=2, linestyle='--', alpha=0.7)

# --- Legend ----------------------------------------------------------
from matplotlib.lines import Line2D

legend_handles = [
    Line2D([], [], marker='o', linestyle='-', linewidth=2,
           color=colors['cpp'], markerfacecolor=colors['cpp'],
           markeredgecolor='white', markersize=6,
           label=f'SBMLNetwork (C++)'),
    Line2D([], [], marker='s', linestyle='--', linewidth=2,
           color=colors['python'], markerfacecolor=colors['python'],
           markeredgecolor='white', markersize=6,
           label=f'SBMLDiagrams (pure-Python)'),
]

ax.legend(handles=legend_handles, loc='upper left', fontsize=10, bbox_to_anchor=(0.035, 0.99),
          framealpha=0.95)

# --- Axes, grid, etc. -----------------------------------
ax.set_xlabel('Number of species (fixed 4:1 species-to-reactions ratio)', fontsize=12)
ax.set_ylabel('Run-time (ms)', fontsize=12)
ax.set_title('Runtime Scaling of Auto-layout Algorithms',
             fontsize=13, fontweight='bold', pad=20)

ax.set_xlim(15, 2200)
ax.set_ylim(0.8, 100000)
ax.tick_params(which='minor', length=2, color='gray')
ax.tick_params(which='major', length=4, width=0.8)
plt.tight_layout(pad=1.5)
plt.savefig('myplot.pdf')
plt.show()


# ---------------------------------------------------------------------
# Data Storage (only if data was freshly calculated)
# ---------------------------------------------------------------------
if not data['loaded_from_file']:
    # Create timestamp for unique filenames
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")

    # 1. Save as CSV for easy analysis
    df = pd.DataFrame({
        'species': species_counts,
        'reactions': [s[1] for s in SIZES],
        'cpp_mean_ms': cpp_means,
        'cpp_std_ms': cpp_stds,
        'python_mean_ms': py_means,
        'python_std_ms': py_stds,
        'performance_ratio': np.array(py_means) / np.array(cpp_means)
    })

    csv_filename = f'layout_benchmark_data_{timestamp}.csv'
    df.to_csv(csv_filename, index=False)
    print(f"Summary data saved to: {csv_filename}")

    # 2. Save raw data as JSON for complete reproducibility
    raw_data_dict = {
        'metadata': {
            'timestamp': timestamp,
            'description': 'Layout algorithm benchmark - raw timing data',
            'iterations_per_test': 10,
            'species_reaction_ratio': '4:1',
            'random_seed': 1
        },
        'fit_parameters': {
            'cpp_slope': float(fit_cpp[0]),
            'cpp_intercept': float(fit_cpp[1]),
            'cpp_r_squared': float(r2_cpp),
            'python_slope': float(fit_py[0]),
            'python_intercept': float(fit_py[1]),
            'python_r_squared': float(r2_py)
        },
        'raw_data': data['all_raw_data']
    }

    json_filename = f'layout_benchmark_raw_{timestamp}.json'
    with open(json_filename, 'w') as f:
        json.dump(raw_data_dict, f, indent=2)
    print(f"Raw data saved to: {json_filename}")

    # 3. Save summary statistics
    summary_filename = f'layout_benchmark_summary_{timestamp}.txt'
    with open(summary_filename, 'w') as f:
        f.write("LAYOUT ALGORITHM BENCHMARK SUMMARY\n")
        f.write("=" * 50 + "\n\n")
        f.write(f"Generated on: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n")
        f.write(f"Species range: {min(species_counts)} - {max(species_counts)}\n")
        f.write(f"Total data points: {len(species_counts)}\n")
        f.write(f"Iterations per test: 10\n\n")

        f.write("POWER-LAW FITS (t = c * n^a):\n")
        f.write("-" * 30 + "\n")
        f.write(f"C++ backend:\n")
        f.write(f"  Scaling exponent (a): {fit_cpp[0]:.4f}\n")
        f.write(f"  R-squared: {r2_cpp:.4f}\n")
        f.write(f"  Equation: t = {10 ** fit_cpp[1]:.3e} * n^{fit_cpp[0]:.3f}\n\n")

        f.write(f"Python backend:\n")
        f.write(f"  Scaling exponent (a): {fit_py[0]:.4f}\n")
        f.write(f"  R-squared: {r2_py:.4f}\n")
        f.write(f"  Equation: t = {10 ** fit_py[1]:.3e} * n^{fit_py[0]:.3f}\n\n")

        f.write("PERFORMANCE COMPARISON:\n")
        f.write("-" * 25 + "\n")
        f.write(f"Performance ratio at {species_counts[0]} species: {py_means[0] / cpp_means[0]:.1f}x\n")
        f.write(f"Performance ratio at {species_counts[-1]} species: {py_means[-1] / cpp_means[-1]:.1f}x\n")
        f.write(f"Average performance ratio: {np.mean(np.array(py_means) / np.array(cpp_means)):.1f}x\n")

    print(f"Summary saved to: {summary_filename}")

    print(f"\nNew data files created:")
    print(f"  • {csv_filename} (tabular data for analysis)")
    print(f"  • {json_filename} (complete raw data)")
    print(f"  • {summary_filename} (human-readable summary)")
else:
    print(f"\nUsing existing data files:")
    print(f"  • {data['csv_file']}")
    print(f"  • {data['json_file']}")
    print("  (Error bars calculated but not shown on plot)")

# Print summary statistics
print("=" * 60)
print("SUMMARY STATISTICS")
print("=" * 60)
print(f"C++ backend scaling exponent:    {fit_cpp[0]:.3f} (R² = {r2_cpp:.3f})")
print(f"Python backend scaling exponent: {fit_py[0]:.3f} (R² = {r2_py:.3f})")
print(f"Performance ratio at {species_counts[0]} species: {py_means[0] / cpp_means[0]:.1f}×")
print(f"Performance ratio at {species_counts[-1]} species: {py_means[-1] / cpp_means[-1]:.1f}×")