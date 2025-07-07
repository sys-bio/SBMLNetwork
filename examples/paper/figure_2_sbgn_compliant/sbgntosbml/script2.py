import sbmlnetwork

import sys
import os


sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from sbgntosbml import *


model = '''

glyph4: -> glyph8;
glyph5: glyph8 ->;
glyph20 -( glyph4;
glyph6: glyph20 ->;
glyph7: -> glyph20;
glyph32: -> glyph1;
glyph8 -| glyph32;
glyph9: glyph1 ->;
glyph23: -> glyph24;
glyph1 -( glyph23;
glyph14: glyph24 ->;
glyph13: -> glyph21;
glyph24 -| glyph13;
glyph28: glyph21 ->;
glyph26: -> glyph27;
glyph27 -| glyph7;
glyph21 -( glyph26;
glyph16: glyph27 ->;

'''

net = sbmlnetwork.load(model)
net.get_reactions_list().get_labels().hide()
net.get_compartments_list().set_sizes((875, 675))
net.get_compartments_list().hide()

sbgn_elements = []

# empty species glyph2
element = SBGNEmptySet(node_id="glyph2", reaction_id="glyph5", x=180.0, y=25.0, width=36.0, height=36.0, border_color="#bc0000")
sbgn_elements.append(element)

# empty species glyph3
element = SBGNEmptySet(node_id="glyph3", reaction_id="glyph4", x=530.0, y=25.0, width=36.0, height=36.0, border_color="#bc0000")
sbgn_elements.append(element)

# empty species glyph11
element = SBGNEmptySet(node_id="glyph11", reaction_id="glyph7", x=455.0, y=265.0, width=36.0, height=36.0, border_color="#bc0000")
sbgn_elements.append(element)

# empty species glyph12
element = SBGNEmptySet(node_id="glyph12", reaction_id="glyph6", x=625.0, y=125.0, width=36.0, height=36.0, border_color="#bc0000")
sbgn_elements.append(element)

# empty species glyph19
element = SBGNEmptySet(node_id="glyph19", reaction_id="glyph32", x=350.0, y=378.61728, width=36.0, height=36.0, border_color="#ff9900")
sbgn_elements.append(element)

# empty species glyph18
element = SBGNEmptySet(node_id="glyph18", reaction_id="glyph9", x=20.0, y=378.617, width=36.0, height=36.0, border_color="#ff9900")
sbgn_elements.append(element)

# empty species glyph17
element = SBGNEmptySet(node_id="glyph17", reaction_id="glyph23", x=115.0, y=480.0, width=36.0, height=36.0, border_color="#ff9900")
sbgn_elements.append(element)

# empty species glyph30
element = SBGNEmptySet(node_id="glyph30", reaction_id="glyph14", x=275.0, y=625.0, width=36.0, height=36.0, border_color="#ff9900")
sbgn_elements.append(element)

# empty species glyph10
element = SBGNEmptySet(node_id="glyph10", reaction_id="glyph13", x=545.0, y=378.61728, width=36.0, height=36.0, border_color="#335aec")
sbgn_elements.append(element)

# empty species glyph22
element = SBGNEmptySet(node_id="glyph22", reaction_id="glyph28", x=700.0, y=528.6667, width=36.0, height=36.0, border_color="#335aec")
sbgn_elements.append(element)

# empty species glyph25
element = SBGNEmptySet(node_id="glyph25", reaction_id="glyph26", x=800.0, y=450.0, width=36.0, height=36.0, border_color="#335aec")
sbgn_elements.append(element)

# empty species glyph15
element = SBGNEmptySet(node_id="glyph15", reaction_id="glyph16", x=800.0, y=125.0, width=36.0, height=36.0, border_color="#335aec")
sbgn_elements.append(element)

# species glyph20
sub_element_1 = SBGNUnitOfInformation(node_id="glyph20a", x=441.25, y=111.75, width=63.5, height=17.5, border_color="#bc0000", text="ct:mRNA", font_color="#bc0000")
element = SBGNNucleicAcidFeature(node_id="glyph20", x=437.0, y=120.5, width=72.0, height=45.0, border_color="#bc0000", fill_color="#e89a9a", text="Laclm", font_color="#bc0000", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph8
element = SBGNMacromolecule(node_id="glyph8", x=342.0, y=20.5, width=72.0, height=45.0, border_color="#bc0000", fill_color="#e89a9a", text="Laclp", font_color="#bc0000")
sbgn_elements.append(element)

# species glyph1
sub_element_1 = SBGNUnitOfInformation(node_id="glyph1a", x=171.25, y=365.367, width=63.5, height=17.5, border_color="#ff9900", text="ct:mRNA", font_color="#ff9900")
element = SBGNNucleicAcidFeature(node_id="glyph1", x=167.0, y=374.117, width=72.0, height=45.0, border_color="#ff9900", fill_color="#ffffc0", text="Tetm", font_color="#ff9900", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph24
element = SBGNMacromolecule(node_id="glyph24", x=257.0, y=475.5, width=72.0, height=45.0, border_color="#ff9900", fill_color="#ffffc0", text="Tetp", font_color="#ff9900")
sbgn_elements.append(element)

# species glyph21
sub_element_1 = SBGNUnitOfInformation(node_id="glyph21a", x=686.25, y=365.367, width=63.5, height=17.5, border_color="#335aec", text="ct:mRNA", font_color="#335aec")
element = SBGNNucleicAcidFeature(node_id="glyph21", x=682.0, y=374.117, width=72.0, height=45.0, border_color="#335aec", fill_color="#d2ffff", text="Clm", font_color="#335aec", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph27
element = SBGNMacromolecule(node_id="glyph27", x=782.0, y=280.5, width=72.0, height=45.0, border_color="#335aec", fill_color="#d2ffff", text="Clp", font_color="#335aec")
sbgn_elements.append(element)

# reaction glyph4
sub_element_1 = SBGNPort(port_id="glyph4_1", x=453.0, y=43.0, border_color="#bc0000")
sub_element_2 = SBGNPort(port_id="glyph4_2", x=493.0, y=43.0, border_color="#bc0000")
element = SBGNProcess(node_id="glyph4", x=463.0, y=33.0, width=20.0, height=20.0, sub_elements=[sub_element_1, sub_element_2], border_color="#bc0000")
sbgn_elements.append(element)

# reaction glyph5
sub_element_1 = SBGNPort(port_id="glyph5_1", x=263.0, y=43.0, border_color="#bc0000")
sub_element_2 = SBGNPort(port_id="glyph5_2", x=303.0, y=43.0, border_color="#bc0000")
element = SBGNProcess(node_id="glyph5", x=273.0, y=33.0, width=20.0, height=20.0, sub_elements=[sub_element_1, sub_element_2], border_color="#bc0000")
sbgn_elements.append(element)

# reaction glyph6
sub_element_1 = SBGNPort(port_id="glyph6_1", x=543.0, y=143.0, border_color="#bc0000")
sub_element_2 = SBGNPort(port_id="glyph6_2", x=583.0, y=143.0, border_color="#bc0000")
element = SBGNProcess(node_id="glyph6", x=553.0, y=133.0, width=20.0, height=20.0, sub_elements=[sub_element_1, sub_element_2], border_color="#bc0000")
sbgn_elements.append(element)

# reaction glyph7
sub_element_1 = SBGNPort(port_id="glyph7_1", x=473.0, y=198.0, border_color="#bc0000")
sub_element_2 = SBGNPort(port_id="glyph7_2", x=473.0, y=238.0, border_color="#bc0000")
element = SBGNProcess(node_id="glyph7", x=463.0, y=208.0, width=20.0, height=20.0, sub_elements=[sub_element_1, sub_element_2], border_color="#bc0000")
sbgn_elements.append(element)

# reaction glyph32
sub_element_1 = SBGNPort(port_id="glyph32_1", x=278.0, y=396.61728, border_color="#ff9900")
sub_element_2 = SBGNPort(port_id="glyph32_2", x=318.0, y=396.61728, border_color="#ff9900")
element = SBGNProcess(node_id="glyph32", x=288.0, y=386.61728, width=20.0, height=20.0, sub_elements=[sub_element_1, sub_element_2], border_color="#ff9900")
sbgn_elements.append(element)

# reaction glyph9
sub_element_1 = SBGNPort(port_id="glyph9_1", x=100.0, y=396.61728, border_color="#ff9900")
sub_element_2 = SBGNPort(port_id="glyph9_2", x=140.0, y=396.61728, border_color="#ff9900")
element = SBGNProcess(node_id="glyph9", x=110.0, y=386.61728, width=20.0, height=20.0, sub_elements=[sub_element_1, sub_element_2], border_color="#ff9900")
sbgn_elements.append(element)

# reaction glyph23
sub_element_1 = SBGNPort(port_id="glyph23_1", x=184.0, y=498.0, border_color="#ff9900")
sub_element_2 = SBGNPort(port_id="glyph23_2", x=224.0, y=498.0, border_color="#ff9900")
element = SBGNProcess(node_id="glyph23", x=194.0, y=488.0, width=20.0, height=20.0, sub_elements=[sub_element_1, sub_element_2], border_color="#ff9900")
sbgn_elements.append(element)

# reaction glyph14
sub_element_1 = SBGNPort(port_id="glyph14_1", x=293.0, y=548.0, border_color="#ff9900")
sub_element_2 = SBGNPort(port_id="glyph14_2", x=293.0, y=588.0, border_color="#ff9900")
element = SBGNProcess(node_id="glyph14", x=283.0, y=558.0, width=20.0, height=20.0, sub_elements=[sub_element_1, sub_element_2], border_color="#ff9900")
sbgn_elements.append(element)

# reaction glyph13
sub_element_1 = SBGNPort(port_id="glyph13_1", x=608.0, y=396.61728, border_color="#335aec")
sub_element_2 = SBGNPort(port_id="glyph13_2", x=648.0, y=396.61728, border_color="#335aec")
element = SBGNProcess(node_id="glyph13", x=618.0, y=386.61728, width=20.0, height=20.0, sub_elements=[sub_element_1, sub_element_2], border_color="#335aec")
sbgn_elements.append(element)

# reaction glyph28
sub_element_1 = SBGNPort(port_id="glyph28_1", x=718.0, y=446.6667, border_color="#335aec")
sub_element_2 = SBGNPort(port_id="glyph28_2", x=718.0, y=486.6667, border_color="#335aec")
element = SBGNProcess(node_id="glyph28", x=708.0, y=456.6667, width=20.0, height=20.0, sub_elements=[sub_element_1, sub_element_2], border_color="#335aec")
sbgn_elements.append(element)

# reaction glyph26
sub_element_1 = SBGNPort(port_id="glyph26_1", x=818.0, y=376.61728, border_color="#335aec")
sub_element_2 = SBGNPort(port_id="glyph26_2", x=818.0, y=416.61728, border_color="#335aec")
element = SBGNProcess(node_id="glyph26", x=808.0, y=386.61728, width=20.0, height=20.0, sub_elements=[sub_element_1, sub_element_2], border_color="#335aec")
sbgn_elements.append(element)

# reaction glyph16
sub_element_1 = SBGNPort("glyph16_1", x=818.0, y=218.0, border_color="#335aec")
sub_element_2 = SBGNPort("glyph16_2", x=818.0, y=258.0, border_color="#335aec")
element = SBGNProcess(node_id="glyph16", x=808.0, y=228.0, width=20.0, height=20.0, sub_elements=[sub_element_1, sub_element_2], border_color="#335aec")
sbgn_elements.append(element)

# species reference arc1
element = SBGNConsumption(element_id="arc1", source_id="glyph3", target_id="glyph4_2", start_x=530.0, start_y=43.0, end_x=493.0, end_y=43.0, border_color="#bc0000", fill_color="#bc0000")
sbgn_elements.append(element)

# species reference arc3
element = SBGNConsumption(element_id="arc3", source_id="glyph8", target_id="glyph5_2", start_x=342.0, start_y=43.0, end_x=303.0, end_y=43.0, border_color="#bc0000", fill_color="#bc0000")
sbgn_elements.append(element)

# species reference arc4
element = SBGNProduction(element_id="arc4", source_id="glyph5_1", target_id="glyph2", start_x=263.0, start_y=43.0, end_x=216.0, end_y=43.0, border_color="#bc0000", fill_color="#bc0000")
sbgn_elements.append(element)

# species reference arc22
element = SBGNProduction(element_id="arc22", source_id="glyph4_1", target_id="glyph8", start_x=453.0, start_y=43.0, end_x=414.0, end_y=43.0, border_color="#bc0000", fill_color="#bc0000")
sbgn_elements.append(element)

# species reference arc27
element = SBGNNecessaryStimulation(element_id="arc27", source_id="glyph20", target_id="glyph4", start_x=473.0, start_y=120.5, end_x=473.0, end_y=53.0, border_color="#bc0000")
sbgn_elements.append(element)

# species reference arc9
element = SBGNProduction(element_id="arc9", source_id="glyph6_2", target_id="glyph12", start_x=583.0, start_y=143.0, end_x=625.0, end_y=143.0, border_color="#bc0000", fill_color="#bc0000")
sbgn_elements.append(element)

# species reference arc30
element = SBGNConsumption(element_id="arc30", source_id="glyph20", target_id="glyph6_1", start_x=509.0, start_y=143.0, end_x=543.0, end_y=143.0, border_color="#bc0000", fill_color="#bc0000")
sbgn_elements.append(element)

# species reference arc6
element = SBGNConsumption(element_id="arc6", source_id="glyph11", target_id="glyph7_2", start_x=473.0, start_y=265.0, end_x=473.0, end_y=238.0, border_color="#bc0000", fill_color="#bc0000")
sbgn_elements.append(element)

# species reference arc29
element = SBGNProduction(element_id="arc29", source_id="glyph7_1", target_id="glyph20", start_x=473.0, start_y=198.0, end_x=473.0, end_y=165.5, border_color="#bc0000", fill_color="#bc0000")
sbgn_elements.append(element)

# species reference arc15
element = SBGNInhibition(element_id="arc15", source_id="glyph8", target_id="glyph32", start_x=353.74677, start_y=65.0, end_x=297.89154, end_y=380.61728,
                         control_point1_x= 295.0, control_point1_y=120.0,
                         border_color="#bc0000", fill_color="#bc0000")
sbgn_elements.append(element)

# species reference arc25
element = SBGNConsumption(element_id="arc25", source_id="glyph19", target_id="glyph32_2", start_x=350.0, start_y=396.61728, end_x=318.0, end_y=396.61728, border_color="#ff9900", fill_color="#ff9900")
sbgn_elements.append(element)

# species reference arc14
element = SBGNProduction(element_id="arc14", source_id="glyph32_1", target_id="glyph1", start_x=278.0, start_y=396.61728, end_x=239.0, end_y=396.617, border_color="#ff9900", fill_color="#ff9900")
sbgn_elements.append(element)

# species reference arc28
element = SBGNProduction(element_id="arc28", source_id="glyph9_1", target_id="glyph18", start_x=100.0, start_y=396.61728, end_x=56.0, end_y=396.617, border_color="#ff9900", fill_color="#ff9900")
sbgn_elements.append(element)

# species reference arc18
element = SBGNConsumption(element_id="arc18", source_id="glyph1", target_id="glyph9_2", start_x=167.0, start_y=396.617, end_x=140.0, end_y=396.61728, border_color="#ff9900", fill_color="#ff9900")
sbgn_elements.append(element)

# species reference arc21
element = SBGNProduction(element_id="arc21", source_id="glyph23_2", target_id="glyph24", start_x=224.0, start_y=498.0, end_x=257.0, end_y=498.0, border_color="#ff9900", fill_color="#ff9900")
sbgn_elements.append(element)

# species reference arc26
element = SBGNNecessaryStimulation(element_id="arc26", source_id="glyph1", target_id="glyph23", start_x=203.22192, start_y=419.117, end_x=203.90137, end_y=488.0, border_color="#ff9900")
sbgn_elements.append(element)

# species reference arc17
element = SBGNConsumption(element_id="arc17", source_id="glyph24", target_id="glyph14_1", start_x=293.0, start_y=520.5, end_x=293.0, end_y=548.0, border_color="#ff9900", fill_color="#ff9900")
sbgn_elements.append(element)

# species reference arc20
element = SBGNConsumption(element_id="arc20", source_id="glyph17", target_id="glyph23_1", start_x=151.0, start_y=498.0, end_x=184.0, end_y=498.0, border_color="#ff9900", fill_color="#ff9900")
sbgn_elements.append(element)

# species reference arc16
element = SBGNProduction(element_id="arc16", source_id="glyph14_2", target_id="glyph30", start_x=293.0, start_y=588.0, end_x=293.0, end_y=625.0, border_color="#ff9900", fill_color="#ff9900")
sbgn_elements.append(element)

# species reference arc2
element = SBGNInhibition(element_id="arc23", source_id="glyph24", target_id="glyph13", start_x=329.0, start_y=498.77063, end_x=627.2619, end_y=411.61728,
                         control_point1_x= 620.0, control_point1_y=505.0,
                         border_color="#ff9900", fill_color="#ff9900")
sbgn_elements.append(element)

# species reference arc19
element = SBGNConsumption(element_id="arc19", source_id="glyph10", target_id="glyph13_1", start_x=581.0, start_y=396.61728, end_x=608.0, end_y=396.61728, border_color="#335aec", fill_color="#335aec")
sbgn_elements.append(element)

# species reference arc5
element = SBGNProduction(element_id="arc5", source_id="glyph13_2", target_id="glyph21", start_x=648.0, start_y=396.61728, end_x=682.0, end_y=396.617, border_color="#335aec", fill_color="#335aec")
sbgn_elements.append(element)

# species reference arc12
element = SBGNConsumption(element_id="arc12", source_id="glyph21", target_id="glyph28_1", start_x=718.0, start_y=419.117, end_x=718.0, end_y=446.6667, border_color="#335aec", fill_color="#335aec")
sbgn_elements.append(element)

# species reference arc8
element = SBGNProduction(element_id="arc8", source_id="glyph28_2", target_id="glyph22", start_x=718.0, start_y=486.6667, end_x=718.0, end_y=528.6667, border_color="#335aec", fill_color="#335aec")
sbgn_elements.append(element)

# species reference arc11
element = SBGNConsumption(element_id="arc11", source_id="glyph25", target_id="glyph26_2", start_x=818.0, start_y=450.0, end_x=818.0, end_y=416.61728, border_color="#335aec", fill_color="#335aec")
sbgn_elements.append(element)

# species reference arc10
element = SBGNProduction(element_id="arc10", source_id="glyph26_1", target_id="glyph27", start_x=818.0, start_y=376.61728, end_x=818.0, end_y=325.5, fill_color="#335aec", border_color="#335aec")
sbgn_elements.append(element)

# species reference arc7
element = SBGNNecessaryStimulation(element_id="arc7", source_id="glyph21", target_id="glyph26", start_x=754.0, start_y=396.617, end_x=808.0, end_y=396.61728, border_color="#335aec")
sbgn_elements.append(element)

# species reference arc24
element = SBGNProduction(element_id="arc24", source_id="glyph16_1", target_id="glyph15", start_x=818.0, start_y=218.0, end_x=818.0, end_y=161.0, border_color="#335aec", fill_color="#335aec")
sbgn_elements.append(element)

# species reference arc13
element = SBGNConsumption(element_id="arc13", source_id="glyph27", target_id="glyph16_2", start_x=818.0, start_y=280.5, end_x=818.0, end_y=258.0, border_color="#335aec", fill_color="#335aec")
sbgn_elements.append(element)

# species reference arc2
element = SBGNInhibition(element_id="arc2", source_id="glyph27", target_id="glyph7", start_x=791.871, start_y=280.5, end_x=488.0, end_y=217.66245,
                         control_point1_x= 710.0, control_point1_y=210.0,
                         border_color="#335aec", fill_color="#335aec")
sbgn_elements.append(element)

load_sbml_info(net, sbgn_elements)

net.draw("./figure_2_sbgn_compliant_2.pdf", update_network_extents=True)
net.save("./figure_2_sbgn_compliant_2.xml", update_network_extents=True)
