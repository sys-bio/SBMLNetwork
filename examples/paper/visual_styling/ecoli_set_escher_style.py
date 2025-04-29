import sbmlnetwork
import tellurium as te

model = '''
J0: S1 -> S2;
'''

net = sbmlnetwork.load("./ecoli.xml")
net.set_style("escher")
net.draw("./ecoli_escher_style.pdf")
net.save("./ecoli_escher_style.xml")
