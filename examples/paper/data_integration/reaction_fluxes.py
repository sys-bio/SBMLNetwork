import sbmlnetwork

net = sbmlnetwork.load("./test0.xml")

fluxes = {'J0': 5, 'J1': 5, 'J2': 4, 'J3': 4, 'J4': 3, 'J5': 3, 'J6': 2, 'J7': 2, 'J8': 1, 'J9': 1, 'J10': 0}
net.show_fluxes(1)
net.get_color_bar().set_left_margin(75)
net.get_reactions_list().set_thicknesses(5)
net.get_reactions_list().set_arrow_head_border_thicknesses(3)

net.draw("./test1.pdf")
net.save("./test1.xml")