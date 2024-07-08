# Getting started

To get started with SBMLNetwork, follow the installation instructions provided in the [Installation](installation.md) section.

## Load an SBML model with graphical representation data

After loading the SBML model, SBMLNetwork first checks for Layout data. If missing, default Layout Data is added for all elements, followed by applying an autolayout algorithm to determine positions and dimensions for each graphical object. Once Layout data is ensured, SBMLNetwork then verifies Render data. If absent, default rendering styles are generated for each graphical object based on the Layout data. Here's an example of how SBMLNetwork can be used to load an SBML model and add missing Layout and Render data:

```python
import sbmlnetwork

# Load an SBML model with graphical representation data
model = sbmlnetwork.laod('path/to/model.xml')
``` 

## Apply the autolayout algorithm

Given the non-deterministic nature of the autolayout algorithm, users can apply it multiple times, thereby obtaining different arrangements of the layout elements. Additionally, while doing so, users have the flexibility to adjust various parameters related to the autolayout algorithm features. Here is an example of how to apply the autolayout algorithm multiple times for different arrangements.

```python
import sbmlnetwork

# Load an SBML model with graphical representation data
model = sbmlnetwork.laod('path/to/model.xml')

# run autolayout with default parameters
network.autolayout()

# autolayout parameters
    # stiffness: determines string constants that affect edge lenghts
    # gravity: determines the extents of the layout
    # use_magnetism: determines whether to use magnetism
    # use_boundary: determines whether to use boundary restriction
    # use_grid: determines whether to palce the nodes on grid lines
    # locked_nodes: a list of nodes to be locked during autolayout execution

# run autolayout with set parameters
network.autolayout(stiffness=10, gravity=15, use_magnetism=True, use_boundary=True, use_grid=True, locked_nodes=["S1", "S2"])
```
