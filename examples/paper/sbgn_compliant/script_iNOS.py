import sbmlnetwork

import sys
import os


sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from sbgntosbml import *


model = '''
compartment glyph2, glyph58, glyph0, glyph1;

species glyph16 in glyph2;
species glyph33 in glyph2;
species glyph37 in glyph2;
species glyph5 in glyph58;
species glyph6 in glyph58;
species glyph7 in glyph58;
species glyph11 in glyph0;
species glyph13 in glyph0;
species glyph10 in glyph0;
species glyph29 in glyph0;
species glyph48 in glyph0;
species glyph27 in glyph0;
species glyph3 in glyph0;
species glyph4 in glyph0;
species glyph8 in glyph0;
species glyph36 in glyph0;
species glyph35 in glyph0;
species glyph31 in glyph0;
species glyph34 in glyph0;
species glyph32 in glyph0;
species glyph44 in glyph0;
species glyph38 in glyph0;
species glyph45 in glyph0;
species glyph30 in glyph0;
species glyph9 in glyph1;
species glyph25 in glyph1;
species glyph26 in glyph1;
species glyph39 in glyph1;
species glyph28 in glyph1;
species glyph24 in glyph1;

glyph59: glyph16 + glyph7 -> glyph5;
glyph72: glyph5 -> glyph6;
glyph74: glyph13 -> glyph11;
glyph6 -( glyph74;
glyph77: glyph11 -> glyph10;
glyph73: glyph10 -> glyph9;
// glyph49: glyph9 + glyph25 -> glyph26;
glyph64: -> glyph26;
glyph9 -( glyph64;
glyph25 -( glyph64;
glyph71: glyph26 -> glyph29;
glyph68: -> glyph48;
glyph76: glyph48 -> glyph39;
glyph66: -> glyph24;
glyph28 -( glyph66;
glyph39 -( glyph66;
glyph63: glyph24 -> glyph27;
glyph61: glyph27 -> ;
glyph65: glyph3 + glyph4 -> glyph8;
glyph57: glyph29 -> ;
glyph29 -( glyph68;
glyph75: -> glyph3;
glyph27 -( glyph75;

glyph69: glyph33 -> glyph36;
glyph70: glyph36 + glyph35 -> glyph31 + glyph34;
glyph8 -( glyph70;
glyph67: glyph31 -> glyph37;
glyph62: glyph34 + glyph32 -> glyph38;
glyph44 -( glyph62;
glyph60: glyph38 -> glyph36 + glyph30;
glyph45 -( glyph60;
'''

net = sbmlnetwork.load(model)
net.get_reactions_list().get_labels().hide()

sbgn_elements = []

# compartment glyph2
element = SBGNCompartment(node_id="glyph2", x=10, y=10, width=1760, height=150, fill_color="#EEEAE4", text="EXTRACELLULAR SPACE", text_x=801.5, text_y=18, text_width=177, text_height=18, font_size=12, text_vertical_alignment="top")
sbgn_elements.append(element)

# compartment glyph58
element = SBGNCompartment(node_id="glyph58", x=10, y=160, width=1760, height=260, fill_color="#EEEAE4", text="PLASMA MEMBRANE", text_x=815.5, text_y=168, text_width=149, text_height=18, font_size=12, text_vertical_alignment="top")
sbgn_elements.append(element)

# compartment glyph0
element = SBGNCompartment(node_id="glyph0", x=10, y=420, width=1760, height=500, fill_color="#EEEAE4", text="CYTOSOL", text_x=852.5, text_y=428, text_width=76, text_height=18, font_size=12, text_vertical_alignment="top")
sbgn_elements.append(element)

# compartment glyph1;
element = SBGNCompartment(node_id="glyph1", x=10, y=920, width=1760, height=270, fill_color="#EEEAE4", text="NUCLEUS", text_x=852.5, text_y=1164, text_width=75, text_height=18, font_size=12, text_vertical_alignment="bottom")
sbgn_elements.append(element)

# species glyph16
sub_element_1 = SBGNUnitOfInformation(node_id="glyph16a", x=774.5, y=52, width=31, height=16, text="N:2")
element = SBGNMacromoleculeMultimer(node_id="glyph16", x=770, y=60, width=80, height=40, fill_color="#D9E5F2", text="IFNγ", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph7
sub_sub_element_1 = SBGNUnitOfInformation(node_id="glyph18a", x=1009.5, y=232, width=31, height=16, text="N:2")
sub_element_1 = SBGNMacromoleculeMultimer(node_id="glyph18", x=1005, y=240, width=80, height=40, fill_color="#D9E5F2", text="IFNγR2", sub_elements=[sub_sub_element_1])
sub_sub_element_1 = SBGNUnitOfInformation(node_id="glyph14a", x=899.5, y=232, width=31, height=16, text="N:2")
sub_sub_element_2 = SBGNStateVariable(node_id="glyph14b", x=925, y=270, width=20, height=20)
sub_element_2 = SBGNMacromoleculeMultimer(node_id="glyph14", x=895, y=240, width=80, height=40, fill_color="#D9E5F2", text="IFNγR1", sub_elements=[sub_sub_element_1, sub_sub_element_2])
sub_element_3 = SBGNMacromolecule(node_id="glyph47", x=995, y=300, width=80, height=40, fill_color="#D9E5F2", text="JAK2")
sub_element_4 = SBGNMacromolecule(node_id="glyph40", x=895, y=300, width=80, height=40, fill_color="#D9E5F2", text="JAK1")
element = SBGNComplex(node_id="glyph7", x=870, y=210, width=230, height=160, fill_color="#E7EDF3", sub_elements=[sub_element_1, sub_element_2, sub_element_3, sub_element_4])
sbgn_elements.append(element)

# species glyph5
sub_sub_element_1 = SBGNUnitOfInformation(node_id="glyph23a", x=554.5, y=192, width=31, height=16, text="N:2")
sub_element_1 = SBGNMacromoleculeMultimer(node_id="glyph23", x=550, y=200, width=80, height=40, fill_color="#D9E5F2", text="IFNγ", sub_elements=[sub_sub_element_1])
sub_sub_element_1 = SBGNUnitOfInformation(node_id="glyph17a", x=614.5, y=262, width=31, height=16, text="N:2")
sub_element_2 = SBGNMacromoleculeMultimer(node_id="glyph17", x=610, y=270, width=80, height=40, fill_color="#D9E5F2", text="IFNγR2", sub_elements=[sub_sub_element_1])
sub_element_3 = SBGNMacromolecule(node_id="glyph42", x=500, y=330, width=80, height=40, fill_color="#D9E5F2", text="JAK1")
sub_element_4 = SBGNMacromolecule(node_id="glyph46", x=600, y=330, width=80, height=40, fill_color="#D9E5F2", text="JAK2")
sub_sub_element_1 = SBGNUnitOfInformation(node_id="glyph12a", x=509.5, y=257, width=31, height=16, text="N:2")
sub_sub_element_2 = SBGNStateVariable(node_id="glyph12b", x=535.0, y=295, width=20, height=20)
sub_element_5 = SBGNMacromoleculeMultimer(node_id="glyph12", x=505, y=265, width=80, height=40, fill_color="#D9E5F2", text="IFNγR1", sub_elements=[sub_sub_element_1, sub_sub_element_2])
element = SBGNComplex(node_id="glyph5", x=480, y=180, width=230, height=220, fill_color="#E7EDF3", sub_elements=[sub_element_1, sub_element_2, sub_element_3, sub_element_4, sub_element_5])
sbgn_elements.append(element)

# species glyph6
sub_sub_element_1 = SBGNUnitOfInformation(node_id="glyph20a", x=199.5, y=192, width=31, height=16, text="N:2")
sub_element_1 = SBGNMacromoleculeMultimer(node_id="glyph20", x=195, y=200, width=80, height=40, fill_color="#D9E5F2", text="IFNγ", sub_elements=[sub_sub_element_1])
sub_sub_element_1 = SBGNUnitOfInformation(node_id="glyph15a", x=149.5, y=262, width=31, height=16, text="N:2")
sub_sub_element_2 = SBGNStateVariable(node_id="glyph15b", x=173.0, y=300, width=24, height=20, text="P")
sub_element_2 = SBGNMacromoleculeMultimer(node_id="glyph15", x=145, y=270, width=80, height=40, fill_color="#D9E5F2", text="IFNγR1", sub_elements=[sub_sub_element_1, sub_sub_element_2])
sub_sub_element_1 = SBGNUnitOfInformation(node_id="glyph19a", x=259.5, y=262, width=31, height=16, text="N:2")
sub_element_3 = SBGNMacromoleculeMultimer(node_id="glyph19", x=255, y=270, width=80, height=40, fill_color="#D9E5F2", text="IFNγR2", sub_elements=[sub_sub_element_1])
sub_element_4 = SBGNMacromolecule(node_id="glyph43", x=145, y=330, width=80, height=40, fill_color="#D9E5F2", text="JAK1")
sub_element_5 = SBGNMacromolecule(node_id="glyph41", x=245, y=330, width=80, height=40, fill_color="#D9E5F2", text="JAK2")
element = SBGNComplex(node_id="glyph6", x=120, y=180, width=230, height=220, fill_color="#E7EDF3", sub_elements=[sub_element_1, sub_element_2, sub_element_3, sub_element_4, sub_element_5])
sbgn_elements.append(element)

# species glyph11
sub_element_1 = SBGNStateVariable(node_id="glyph11a", x=118, y=545, width=24, height=20, text="P")
element = SBGNMacromolecule(node_id="glyph11", x=55, y=515, width=100, height=40, fill_color="#D9E5F2", text="STAT1α", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph13
sub_element_1 = SBGNStateVariable(node_id="glyph13a", x=367.5, y=545, width=20, height=20)
element = SBGNMacromolecule(node_id="glyph13", x=310, y=515, width=90, height=40, fill_color="#D9E5F2", text="STAT1α", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph10
sub_element_1 = SBGNUnitOfInformation(node_id="glyph10a", x=64.5, y=687, width=31, height=16, text="N:2")
sub_element_2 = SBGNStateVariable(node_id="glyph10b", x=118, y=725, width=24, height=20, text="P")
element = SBGNMacromoleculeMultimer(node_id="glyph10", x=55, y=695, width=100, height=40, fill_color="#D9E5F2", text="STAT1α", sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# species glyph9
sub_element_1 = SBGNStateVariable(node_id="glyph9a", x=118, y=990, width=24, height=20, text="P")
element = SBGNMacromoleculeMultimer(node_id="glyph9", x=55, y=960, width=100, height=40, fill_color="#D9E5F2", text="STAT1α", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph25
sub_element_1 = SBGNUnitOfInformation(node_id="glyph25a", x=270, y=952, width=50, height=16, text="ct:gene")
element = SBGNNucleicAcidFeature(node_id="glyph25", x=250, y=960, width=90, height=40, text="IRF1", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph26
sub_element_1 = SBGNUnitOfInformation(node_id="glyph26a", x=367.5, y=1102, width=55, height=16, text="ct:mRNA")
element = SBGNNucleicAcidFeature(node_id="glyph26", x=350, y=1110, width=90, height=40, text="IRF1", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph29
sub_element_1 = SBGNUnitOfInformation(node_id="glyph29a", x=345, y=762, width=55, height=16, text="ct:mRNA")
element = SBGNNucleicAcidFeature(node_id="glyph29", x=350, y=770, width=90, height=40, text="IRF1", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph48
element = SBGNMacromolecule(node_id="glyph48", x=565, y=675, width=80, height=40, fill_color="#D9E5F2", text="IRF1")
sbgn_elements.append(element)

# species glyph39
element = SBGNMacromolecule(node_id="glyph39", x=565, y=960, width=80, height=40, fill_color="#D9E5F2", text="IRF1")
sbgn_elements.append(element)

# species glyph28
sub_element_1 = SBGNUnitOfInformation(node_id="glyph28a", x=760, y=952, width=50, height=16, text="ct:gene")
element = SBGNNucleicAcidFeature(node_id="glyph28", x=740, y=960, width=90, height=40, text="iNOS", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph24
sub_element_1 = SBGNUnitOfInformation(node_id="glyph24a", x=852.5, y=1102, width=55, height=16, text="ct:mRNA")
element = SBGNNucleicAcidFeature(node_id="glyph24", x=835, y=1110, width=90, height=40, text="iNOS", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph27
sub_element_1 = SBGNUnitOfInformation(node_id="glyph27a", x=852.5, y=767, width=55, height=16, text="ct:mRNA")
element = SBGNNucleicAcidFeature(node_id="glyph27", x=835, y=775, width=90, height=40, text="iNOS", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph3
element = SBGNMacromolecule("glyph3", x=950, y=680, width=80, height=40, fill_color="#D9E5F2", text="iNOS")
sbgn_elements.append(element)

# species glyph4
element = SBGNMacromolecule("glyph4", x=795, y=530, width=80, height=40, fill_color="#D9E5F2", text="CaM")
sbgn_elements.append(element)

# species glyph8
sub_sub_element_1 = SBGNUnitOfInformation("glyph21a", x=1119.5, y=502, width=31, height=16, text="N:2")
sub_element_1 = SBGNMacromoleculeMultimer("glyph21", x=1115, y=510, width=80, height=40, fill_color="#D9E5F2", text="CaM", sub_elements=[sub_sub_element_1])
sub_sub_element_1 = SBGNUnitOfInformation("glyph22a", x=1119.5, y=572, width=31, height=16, text="N:2")
sub_element_2 = SBGNMacromoleculeMultimer("glyph22", x=1115, y=580, width=80, height=40, fill_color="#D9E5F2", text="CaM", sub_elements=[sub_sub_element_1])
element = SBGNComplex(node_id="glyph8", x=1090, y=460, width=130, height=180, fill_color="#E7EDF3",  text="1.14.13.39", text_x=1116.5, text_y=462, text_width=77, text_height=18, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# species glyph33
element = SBGNSimpleChemical(node_id="glyph33", x=1235, y=55, width=60, height=60, fill_color="#E4F8E4", text="arginie")
sbgn_elements.append(element)

# species glyph37
element = SBGNSimpleChemical(node_id="glyph37", x=1465, y=55, width=60, height=60, fill_color="#E4F8E4", text="NO")
sbgn_elements.append(element)

# species glyph36
element = SBGNSimpleChemical(node_id="glyph36", x=1235, y=645, width=60, height=60, fill_color="#E4F8E4", text="arginie")
sbgn_elements.append(element)

# species glyph35
element = SBGNSimpleChemical(node_id="glyph35", x=1295, y=545, width=60, height=60, fill_color="#E4F8E4", text="O2")
sbgn_elements.append(element)

# species glyph34
element = SBGNSimpleChemical(node_id="glyph34", x=1525, y=645, width=60, height=60, fill_color="#E4F8E4", text="citrulline")
sbgn_elements.append(element)

# species glyph31
element = SBGNSimpleChemical(node_id="glyph31", x=1465, y=545, width=60, height=60, fill_color="#E4F8E4", text="NO")
sbgn_elements.append(element)

# species glyph32
element = SBGNSimpleChemical(node_id="glyph32", x=1620, y=680, width=60, height=60, fill_color="#E4F8E4", text="aspartate")
sbgn_elements.append(element)

# species glyph44
element = SBGNMacromolecule(node_id="glyph44", x=1615, y=765, width=80, height=40, fill_color="#D9E5F2", text="6.3.4.5")
sbgn_elements.append(element)

# species glyph38
element = SBGNSimpleChemical(node_id="glyph38", x=1385, y=835, width=60, height=60, fill_color="#E4F8E4", text="arginino-succcinate")
sbgn_elements.append(element)

# species glyph45
element = SBGNMacromolecule(node_id="glyph45", x=1125, y=765, width=80, height=40, fill_color="#D9E5F2", text="4.3.2.1")
sbgn_elements.append(element)

# species glyph30
element = SBGNSimpleChemical(node_id="glyph30", x=1135, y=685, width=60, height=60, fill_color="#E4F8E4", text="fumarate")
sbgn_elements.append(element)

# empty species glyph51
element = SBGNEmptySet(node_id="glyph51", reaction_id="glyph64", x=95, y=1110, width=40, height=40)
sbgn_elements.append(element)

# empty species glyph52
element = SBGNEmptySet(node_id="glyph52", reaction_id="glyph68", x=285, y=675, width=40, height=40)
sbgn_elements.append(element)

# empty species glyph53
element = SBGNEmptySet(node_id="glyph53", reaction_id="glyph66", x=605, y=1110, width=40, height=40)
sbgn_elements.append(element)

# empty species glyph55
element = SBGNEmptySet(node_id="glyph55", reaction_id="glyph61", x=1045, y=775, width=40, height=40)
sbgn_elements.append(element)

# empty species glyph54
element = SBGNEmptySet(node_id="glyph54", reaction_id="glyph75", x=780, y=680, width=40, height=40)
sbgn_elements.append(element)

# empty species glyph56
element = SBGNEmptySet(node_id="glyph56", reaction_id="glyph57", x=545, y=770, width=40, height=40)
sbgn_elements.append(element)

# reaction glyph59
sub_element_1 = SBGNPort(port_id="glyph59_1", x=761, y=290)
sub_element_2 = SBGNPort(port_id="glyph59_2", x=809, y=290)
element = SBGNProcess(node_id="glyph59", x=773, y=278, width=24, height=24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph72
sub_element_1 = SBGNPort(port_id="glyph72_1", x=401, y=290)
sub_element_2 = SBGNPort(port_id="glyph72_2", x=449, y=290)
element = SBGNProcess(node_id="glyph72", x=413, y=278, width=24, height=24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph73
sub_element_1 = SBGNPort(port_id="glyph73_1", x=105, y=861)
sub_element_2 = SBGNPort(port_id="glyph73_2", x=105, y=909)
element = SBGNProcess(node_id="glyph73", x=93, y=873, width=24, height=24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph64
sub_element_1 = SBGNPort(port_id="glyph64_1", x=181, y=1130)
sub_element_2 = SBGNPort(port_id="glyph64_2", x=229, y=1130)
element = SBGNProcess(node_id="glyph64", x=193, y=1118, width=24, height=24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph66
sub_element_1 = SBGNPort(port_id="glyph66_1", x=661, y=1130)
sub_element_2 = SBGNPort(port_id="glyph66_2", x=709, y=1130)
element = SBGNProcess(node_id="glyph66", x=673, y=1118, width=24, height=24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph68
sub_element_1 = SBGNPort(port_id="glyph68_1", x=371, y=695)
sub_element_2 = SBGNPort(port_id="glyph68_2", x=419, y=695)
element = SBGNProcess(node_id="glyph68", x=383, y=683, width=24, height=24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph71
sub_element_1 = SBGNPort(port_id="glyph71_1", x=395, y=861)
sub_element_2 = SBGNPort(port_id="glyph71_2", x=395, y=909)
element = SBGNProcess(node_id="glyph71", x=383, y=873, width=24, height=24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph76
sub_element_1 = SBGNPort(port_id="glyph76_1", x=605, y=861)
sub_element_2 = SBGNPort(port_id="glyph76_2", x=605, y=909)
element = SBGNProcess(node_id="glyph76", x=593, y=873, width=24, height=24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph75
sub_element_1 = SBGNPort(port_id="glyph75_1", x=856, y=700)
sub_element_2 = SBGNPort(port_id="glyph75_2", x=904, y=700)
element = SBGNProcess(node_id="glyph75", x=868, y=688, width=24, height=24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph63
sub_element_1 = SBGNPort(port_id="glyph63_1", x=880, y=861)
sub_element_2 = SBGNPort(port_id="glyph63_2", x=880, y=909)
element = SBGNProcess(node_id="glyph63", x=868, y=873, width=24, height=24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph70
sub_element_1 = SBGNPort(port_id="glyph70_1", x=1381, y=635)
sub_element_2 = SBGNPort(port_id="glyph70_2", x=1429, y=635)
element = SBGNProcess(node_id="glyph70", x=1393, y=623, width=24, height=24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph60
sub_element_1 = SBGNPort(port_id="glyph60_1", x=1265, y=761)
sub_element_2 = SBGNPort(port_id="glyph60_2", x=1265, y=809)
element = SBGNProcess(node_id="glyph60", x=1253, y=773, width=24, height=24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph69
sub_element_1 = SBGNPort(port_id="glyph69_1", x=1265, y=316)
sub_element_2 = SBGNPort(port_id="glyph69_2", x=1265, y=364)
element = SBGNProcess(node_id="glyph69", x=1253, y=328, width=24, height=24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph67
sub_element_1 = SBGNPort(port_id="glyph67_1", x=1495, y=316)
sub_element_2 = SBGNPort(port_id="glyph67_2", x=1495, y=364)
element = SBGNProcess(node_id="glyph67", x=1483, y=328, width=24, height=24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph77
sub_element_1 = SBGNPort(port_id="glyph77_1", x=105, y=601)
sub_element_2 = SBGNPort(port_id="glyph77_2", x=105, y=649)
element = SBGNProcess(node_id="glyph77", x=93, y=613, width=24, height=24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph57
sub_element_1 = SBGNPort(port_id="glyph57_1", x=461, y=790)
sub_element_2 = SBGNPort(port_id="glyph57_2", x=509, y=790)
element = SBGNProcess(node_id="glyph57", x=473, y=778, width=24, height=24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph61
sub_element_1 = SBGNPort(port_id="glyph61_1", x=946, y=795)
sub_element_2 = SBGNPort(port_id="glyph61_2", x=994, y=795)
element = SBGNProcess(node_id="glyph61", x=958, y=783, width=24, height=24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph74
sub_element_1 = SBGNPort(port_id="glyph74_1", x=211, y=535)
sub_element_2 = SBGNPort(port_id="glyph74_2", x=259, y=535)
element = SBGNProcess(node_id="glyph74", x=223, y=523, width=24, height=24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph62
sub_element_1 = SBGNPort(port_id="glyph62_1", x=1555, y=761)
sub_element_2 = SBGNPort(port_id="glyph62_2", x=1555, y=809)
element = SBGNProcess(node_id="glyph62", x=1543, y=773, width=24, height=24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph65
sub_element_1 = SBGNPort(port_id="glyph65_1", x=996, y=550)
sub_element_2 = SBGNPort(port_id="glyph65_2", x=1044, y=550)
element = SBGNProcess(node_id="glyph65", x=1008, y=538, width=24, height=24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# species reference arc0
element = SBGNProduction(element_id="arc0", source_id="glyph72_1", target_id="glyph6", start_x=401, start_y=290, end_x=350, end_y=290, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc1
element = SBGNConsumption(element_id="arc1", source_id="glyph5", target_id="glyph72_2", start_x=480, start_y=290, end_x=449, end_y=290)
sbgn_elements.append(element)

# species reference arc2
element = SBGNStimulation(element_id="arc2", source_id="glyph6", target_id="glyph74", start_x=235, start_y=400, end_x=235, end_y=523)
sbgn_elements.append(element)

# species reference arc3
element = SBGNProduction(element_id="arc3", source_id="glyph74_1", target_id="glyph11", start_x=211, start_y=535, end_x=155, end_y=535, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc9
element = SBGNProduction(element_id="arc9", source_id="glyph73_2", target_id="glyph9", start_x=105, start_y=909, end_x=105, end_y=960, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc10
element = SBGNConsumption(element_id="arc10", source_id="glyph10", target_id="glyph73_1", start_x=105, start_y=735, end_x=105, end_y=861)
sbgn_elements.append(element)

# species reference arc11
element = SBGNNecessaryStimulation(element_id="arc11", source_id="glyph49_2", target_id="glyph64", start_x=205, start_y=1092, end_x=205, end_y=1118)
sbgn_elements.append(element)

# species reference arc12
element = SBGNLogicArc(element_id="arc12", source_id="glyph9", target_id="glyph49_1", start_x=155, start_y=994, end_x=205, end_y=1008)
sbgn_elements.append(element)

# species reference arc13
element = SBGNLogicArc(element_id="arc13", source_id="glyph25", target_id="glyph49_1", start_x=250, start_y=994, end_x=205, end_y=1008)
sbgn_elements.append(element)

# species reference arc14
element = SBGNProduction(element_id="arc14", source_id="glyph64_2", target_id="glyph26", start_x=229, start_y=1130, end_x=350, end_y=1130, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc15
element = SBGNConsumption(element_id="arc15", source_id="glyph51", target_id="glyph64_1", start_x=135, start_y=1130, end_x=181, end_y=1130)
sbgn_elements.append(element)

# species reference arc16
element = SBGNProduction(element_id="arc16", source_id="glyph66_2", target_id="glyph24", start_x=709, start_y=1130, end_x=835, end_y=1130, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc17
element = SBGNConsumption(element_id="arc17", source_id="glyph53", target_id="glyph66_1", start_x=645, start_y=1130, end_x=661, end_y=1130)
sbgn_elements.append(element)

# species reference arc18
element = SBGNNecessaryStimulation(element_id="arc18", source_id="glyph50_2", target_id="glyph66", start_x=685, start_y=1092, end_x=685, end_y=1118)
sbgn_elements.append(element)

# species reference arc19
element = SBGNLogicArc(element_id="arc19", source_id="glyph28", target_id="glyph50_1", start_x=740, start_y=992.6, end_x=685, end_y=1008)
sbgn_elements.append(element)

# species reference arc20
element = SBGNLogicArc(element_id="arc20", source_id="glyph39", target_id="glyph50_1", start_x=645, start_y=994, end_x=685, end_y=1008)
sbgn_elements.append(element)

# species reference arc21
element = SBGNConsumption(element_id="arc21", source_id="glyph52", target_id="glyph68_1", start_x=325, start_y=695, end_x=371, end_y=695)
sbgn_elements.append(element)

# species reference arc22
element = SBGNNecessaryStimulation(element_id="arc22", source_id="glyph29", target_id="glyph68", start_x=395, start_y=770, end_x=395, end_y=707)
sbgn_elements.append(element)

# species reference arc23
element = SBGNProduction(element_id="arc23", source_id="glyph68_2", target_id="glyph48", start_x=419, start_y=695, end_x=565, end_y=695, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc24
element = SBGNConsumption(element_id="arc24", source_id="glyph48", target_id="glyph76_1", start_x=605, start_y=715, end_x=605, end_y=861)
sbgn_elements.append(element)

# species reference arc25
element = SBGNConsumption(element_id="arc25", source_id="glyph26", target_id="glyph71_2", start_x=395, start_y=1110, end_x=395, end_y=909)
sbgn_elements.append(element)

# species reference arc26
element = SBGNProduction(element_id="arc26", source_id="glyph71_1", target_id="glyph29", start_x=395, start_y=861, end_x=395, end_y=810, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc27
element = SBGNProduction(element_id="arc27", source_id="glyph76_2", target_id="glyph39", start_x=605, start_y=909, end_x=605, end_y=960, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc31
element = SBGNProduction(element_id="arc31", source_id="glyph75_2", target_id="glyph3", start_x=904, start_y=700, end_x=950, end_y=700, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc32
element = SBGNProduction(element_id="arc32", source_id="glyph63_1", target_id="glyph27", start_x=880, start_y=861, end_x=880, end_y=815, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc33
element = SBGNConsumption(element_id="arc33", source_id="glyph54", target_id="glyph75_1", start_x=820, start_y=700, end_x=856, end_y=700)
sbgn_elements.append(element)

# species reference arc34
element = SBGNNecessaryStimulation(element_id="arc34", source_id="glyph27", target_id="glyph75", start_x=880, start_y=775, end_x=880, end_y=712)
sbgn_elements.append(element)

# species reference arc36
element = SBGNConsumption(element_id="arc36", source_id="glyph24", target_id="glyph63_2", start_x=880, start_y=1110, end_x=880, end_y=909)
sbgn_elements.append(element)

# species reference arc41
element = SBGNProduction(element_id="arc41", source_id="glyph60_1", target_id="glyph36", start_x=1265, start_y=761, end_x=1265, end_y=705, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc42
element = SBGNProduction(element_id="arc42", source_id="glyph60_1", target_id="glyph30", start_x=1265, start_y=761, end_x=1189.5769, end_y=732.20386, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc43
element = SBGNProduction(element_id="arc43", source_id="glyph70_2", target_id="glyph34", start_x=1429, start_y=635, end_x=1526.013, end_y=667.27014, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc44
element = SBGNProduction(element_id="arc44", source_id="glyph70_2", target_id="glyph31", start_x=1429, start_y=635, end_x=1470.0385, end_y=591.641, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc45
element = SBGNConsumption(element_id="arc45", source_id="glyph32", target_id="glyph62_1", start_x=1623.568, start_y=724.1898, end_x=1555, end_y=761)
sbgn_elements.append(element)

# species reference arc46
element = SBGNConsumption(element_id="arc46", source_id="glyph34", target_id="glyph62_1", start_x=1555, start_y=705, end_x=1555, end_y=761)
sbgn_elements.append(element)

# species reference arc47
element = SBGNConsumption(element_id="arc47", source_id="glyph36", target_id="glyph70_1", start_x=1293.3612, start_y=665.2203, end_x=1381, end_y=635)
sbgn_elements.append(element)

# species reference arc48
element = SBGNConsumption(element_id="arc48", source_id="glyph35", target_id="glyph70_1", start_x=1345.4696, start_y=596.93164, end_x=1381, end_y=635)
sbgn_elements.append(element)

# species reference arc49
element = SBGNConsumption(element_id="arc49", source_id="glyph38", target_id="glyph60_2", start_x=1386.8948, start_y=854.5074, end_x=1265, end_y=809)
sbgn_elements.append(element)

# species reference arc50
element = SBGNCatalysis(element_id="arc50", source_id="glyph8", target_id="glyph70", start_x=1155, start_y=460, end_x=1405, end_y=623, intermediate_points=[(1155, 440), (1405, 440), (1405, 525)])
sbgn_elements.append(element)

# species reference arc51
element = SBGNCatalysis(element_id="arc51", source_id="glyph45", target_id="glyph60", start_x=1205, start_y=785, end_x=1253, end_y=785)
sbgn_elements.append(element)

# species reference arc52
element = SBGNCatalysis(element_id="arc52", source_id="glyph44", target_id="glyph62", start_x=1615, start_y=785, end_x=1567, end_y=785)
sbgn_elements.append(element)

# species reference arc53
element = SBGNProduction(element_id="arc53", source_id="glyph69_2", target_id="glyph36", start_x=1265, start_y=364, end_x=1265, end_y=645, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc54
element = SBGNConsumption(element_id="arc54", source_id="glyph33", target_id="glyph69_1", start_x=1265, start_y=115, end_x=1265, end_y=316)
sbgn_elements.append(element)

# species reference arc55
element = SBGNProduction(element_id="arc55", source_id="glyph67_1", target_id="glyph37", start_x=1495, start_y=316, end_x=1495, end_y=115, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc56
element = SBGNConsumption(element_id="arc56", source_id="glyph31", target_id="glyph67_2", start_x=1495, start_y=545, end_x=1495, end_y=364)
sbgn_elements.append(element)

# species reference arc5
element = SBGNProduction(element_id="arc5", source_id="glyph77_2", target_id="glyph10", start_x=105, start_y=649, end_x=105, end_y=695, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc29
element = SBGNConsumption(element_id="arc29", source_id="glyph11", target_id="glyph77_1", start_x=105, start_y=555, end_x=105, end_y=601)
sbgn_elements.append(element)

# species reference arc35
element = SBGNConsumption(element_id="arc35", source_id="glyph27", target_id="glyph61_1", start_x=925, start_y=795, end_x=946, end_y=795)
sbgn_elements.append(element)

# species reference arc57
element = SBGNConsumption(element_id="arc57", source_id="glyph29", target_id="glyph57_1", start_x=440, start_y=790, end_x=461, end_y=790)
sbgn_elements.append(element)

# species reference arc4
element = SBGNProduction(element_id="arc4", source_id="glyph57_2", target_id="glyph56", start_x=509, start_y=790, end_x=545, end_y=790, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc28
element = SBGNProduction(element_id="arc28", source_id="glyph61_2", target_id="glyph55", start_x=994, start_y=795, end_x=1045, end_y=795, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc30
element = SBGNConsumption(element_id="arc30", source_id="glyph13", target_id="glyph74_2", start_x=310, start_y=535, end_x=259, end_y=535)
sbgn_elements.append(element)

# species reference arc40
element = SBGNProduction(element_id="arc40", source_id="glyph62_2", target_id="glyph38", start_x=1555, start_y=809, end_x=1441.0472, end_y=850.11584, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc6
element = SBGNProduction(element_id="arc6", source_id="glyph65_2", target_id="glyph8", start_x=1044, start_y=550, end_x=1090, end_y=550, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc7
element = SBGNConsumption(element_id="arc7", source_id="glyph4", target_id="glyph65_1", start_x=875, start_y=550, end_x=996, end_y=550)
sbgn_elements.append(element)

# species reference arc8
element = SBGNConsumption(element_id="arc8", source_id="glyph3", target_id="glyph65_1", start_x=990.8, start_y=680, end_x=996, end_y=550)
sbgn_elements.append(element)

# species reference arc37
element = SBGNProduction(element_id="arc37", source_id="glyph59_1", target_id="glyph5", start_x=761, start_y=290, end_x=710, end_y=290, fill_color="#000000")
sbgn_elements.append(element)

# species reference arc38
element = SBGNConsumption(element_id="arc38", source_id="glyph7", target_id="glyph59_2", start_x=870, start_y=290, end_x=809, end_y=290)
sbgn_elements.append(element)

# species reference arc39
element = SBGNConsumption(element_id="arc39", source_id="glyph16", target_id="glyph59_2", start_x=809.9048, start_y=100, end_x=809, end_y=290)
sbgn_elements.append(element)

# reaction glyph49
sub_element_1 = SBGNLogicPort("glyph49_1", x=205, y=1008)
sub_element_2 = SBGNLogicPort("glyph49_2", x=205, y=1092)
element = SBGNAndOperator("glyph49", x=184, y=1029, width=42, height=42, sub_elements=[sub_element_1, sub_element_2], sbgn_elements=sbgn_elements)
sbgn_elements.append(element)

# reaction glyph50
sub_element_1 = SBGNLogicPort("glyph50_1", x=685, y=1008)
sub_element_2 = SBGNLogicPort("glyph50_2", x=685, y=1092)
element = SBGNAndOperator("glyph50", x=664, y=1029, width=42, height=42, sub_elements=[sub_element_1, sub_element_2], sbgn_elements=sbgn_elements)
sbgn_elements.append(element)

load_sbml_info(net, sbgn_elements)

net.draw("./sbgn_compliant_iNOS.pdf", update_network_extents=True)
net.save("./sbgn_compliant_iNOS.xml", update_network_extents=True)
