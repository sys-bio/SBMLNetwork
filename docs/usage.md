# Getting started

To get started with SBMLNetwork, follow the installation instructions provided in the [Installation](installation.md) section.

## Load an SBML model with graphical representation data

After loading the SBML model, SBMLNetwork first checks for Layout data. If missing, default Layout Data is added for all elements, followed by applying an autolayout algorithm to determine positions and dimensions for each graphical object. Once Layout data is ensured, SBMLNetwork then verifies Render data. If absent, default rendering styles are generated for each graphical object based on the Layout data. Here's an example of how SBMLNetwork can be used to load an SBML model and add missing Layout and Render data:

```python
import sbmlnetwork

# Load an SBML model with graphical representation data
network = sbmlnetwork.laod('path/to/model.xml')
``` 

## Apply the autolayout algorithm

Given the non-deterministic nature of the autolayout algorithm, users can apply it multiple times, thereby obtaining different arrangements of the layout elements. Additionally, while doing so, users have the flexibility to adjust various parameters related to the autolayout algorithm features. Here is an example of how to apply the autolayout algorithm multiple times for different arrangements.

```python
import sbmlnetwork

# Load an SBML model with graphical representation data
network = sbmlnetwork.laod('path/to/model.xml')

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

## Get/Set Layout and Render data attributes

Another feature of SBMLNetwork is its provision of high-level API functions that allow users to retrieve and modify attributes of Layout and Render data without requiring familiarity with the underlying SBML data structure. Users can gain access to and manipulate every individual attribute of the Layout and Render data simply by calling a single API function. Here is an example demonstrating its functionality:

```python
import sbmlnetwork

# Load an SBML model with graphical representation data
network = sbmlnetwork.lod('path/to/model.xml')

# update a Species position
network.setPpsition("S1", 245, 675)

# get the X position of a node
x = network.getX("S1")

# update a Species fill color
network.setFillColor("S1", "blue")

# get a Species boundary color
color = network.getBoundaryColor("S1")

# Set the species geometric shape
network.setSpeciesGeometricShape ("S1", "triangle")
```

## Align species

SBMLNetwork also offers a feature enabling users to align Species in various directions. Users can specify alignment options to position a set of species within the model layout. This feature enhances the visualization of SBML models, which provides greater control over layout arrangement and enables customization tailored to specific preferences or requirements. Here is an example an how to align a set of Species:

```python
import sbmlnetwork

# Load an SBML model with graphical representation data
network = sbmlnetwork.laod('path/to/model.xml')

# Align Species S1, S2, and S3 on a circle
network.align(["S1", "S2", "S3"], "circular")
```

Other alignment options include top, bottom, left, right, distributeV, distributeH, and center.

## Set style

SBMLNetwork has an extra feature allowing users to set a predefined style for the graphical representation of SBML models. This feature enables users to apply a predefined set of Render attributes to the model, which allows the quick change of the visual styles of the graphical representation elements. By setting a style, users can efficiently obtain diverse representations of the model, enhancing the flexibility and usability of SBMLNetwork. Here is an example demonstrating how to set a new style for the graphical representation of an SBML model:

```python
import sbmlnetwork

# Load an SBML model with graphical representation data
network = sbmlnetwork.laod('path/to/model.xml')

## Set Escher style
network.setStyle("escher")
```

## Save the model

After modifying the Layout and Render data, users can save the model with the updated graphical representation data. SBMLNetwork provides a function to save the model with the updated Layout and Render data. Here is an example of how to save the model with the updated graphical representation data:

```python
import sbmlnetwork

# Load an SBML model with graphical representation data
network = sbmlnetwork.laod('path/to/model.xml')

# retrieve an SBML string
print(network.save())

# export the SBML model as an XML file
xml_output_file_path = "path/to/output_example.xml"
network.save(xml_output_file_path)
```

## Draw
Another feature of SBMLNetwork is its capability to render an image of the graphical representation of the SBML model by making use of its Layout and Render data and leveraging Skia, a powerful graphics library developed by Google. Users can call the `draw` function to display the image on the console or export the image by passing the `file_name` argument, which contains the directory, name, and format of the image to be exported, to the draw function. Exporting to PDF, JPG, and PNG formats is currently supported. Export tp PDF is a vector format enabling resolution-independent rendering. Below is a demonstration of utilizing the `draw` function.

```python
import sbmlnetwork

# Load an SBML model with graphical representation data
network = sbmlnetwork.laod('path/to/model.xml')

# draw on the console
network.draw()

# export the image in PDF format
file_name = "path/to/output.pdf"
network.draw(file_name)
```
