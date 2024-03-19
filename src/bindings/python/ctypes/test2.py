import libsbmlnetworkeditor

a = libsbmlnetworkeditor.LibSBMLNetworkEditor("example.xml")
a.autolayout()
print(a.getListOfCompartmentIds())
print(a.getListOfSpeciesIds())
print(a.getListOfReactionIds())
print(a.getFillColor("S1"))
print(a.setFillColor("S1", "black"))
print(a.getFillColor("S1"))
print(a.setFillColor("S1", "fsdjdf"))
print(a.getFillColor("S1"))
