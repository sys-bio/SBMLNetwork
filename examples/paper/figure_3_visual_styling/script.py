import sbmlnetwork


net = sbmlnetwork.load("./ecoli.xml")
net.set_style("escher")
net.draw("./figure_3_visual_styling.pdf", update_network_extents=True)
net.save("./figure_3_visual_styling.xml", update_network_extents=True)
