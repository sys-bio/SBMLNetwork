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
net.settings.hide_reaction_labels()

sbgn_elements = []

# compartment glyph2;
element = SBGNCompartment("glyph2", 10, 10, 1760, 150, "EXTRACELLULAR SPACE", 801.5, 18, 177, 18, 12, "top")
sbgn_elements.append(element)

# compartment glyph58;
element = SBGNCompartment("glyph58", 10, 160, 1760, 260, "PLASMA MEMBRANE", 815.5, 168, 149, 18, 12, "top")
sbgn_elements.append(element)

# compartment glyph0;
element = SBGNCompartment("glyph0", 10, 420, 1760, 500, "CYTOSOL", 852.5, 428, 76, 18, 12, "top")
sbgn_elements.append(element)

# compartment glyph1;
element = SBGNCompartment("glyph1", 10, 920, 1760, 270, "NUCLEUS", 852.5, 1164, 75, 18, 12, "bottom")
sbgn_elements.append(element)

# species glyph16
sub_element_1 = SBGNUnitOfInformation("glyph16a", 774.5, 52, 31, 16, "N:2")
element = SBGNMacromoleculeMultimer("glyph16", 770, 60, 80, 40, "IFNγ", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph7
sub_sub_element_1 = SBGNUnitOfInformation("glyph18a", 1009.5, 232, 31, 16, "N:2")
sub_element_1 = SBGNMacromoleculeMultimer("glyph18", 1005, 240, 80, 40, "IFNγR2", sub_elements=[sub_sub_element_1])
sub_sub_element_1 = SBGNUnitOfInformation("glyph14a", 899.5, 232, 31, 16, "N:2")
sub_sub_element_2 = SBGNStateVariable("glyph14b", 925, 270, 20, 20)
sub_element_2 = SBGNMacromoleculeMultimer("glyph14", 895, 240, 80, 40, "IFNγR1", sub_elements=[sub_sub_element_1, sub_sub_element_2])
sub_element_3 = SBGNMacromolecule("glyph47", 995, 300, 80, 40, "JAK2")
sub_element_4 = SBGNMacromolecule("glyph40", 895, 300, 80, 40, "JAK1")
element = SBGNComplex("glyph7", 870, 210, 230, 160, sub_elements=[sub_element_1, sub_element_2, sub_element_3, sub_element_4])
sbgn_elements.append(element)

# species glyph5
sub_sub_element_1 = SBGNUnitOfInformation("glyph23a", 554.5, 192, 31, 16, "N:2")
sub_element_1 = SBGNMacromoleculeMultimer("glyph23", 550, 200, 80, 40, "IFNγ", sub_elements=[sub_sub_element_1])
sub_sub_element_1 = SBGNUnitOfInformation("glyph17a", 614.5, 262, 31, 16, "N:2")
sub_element_2 = SBGNMacromoleculeMultimer("glyph17", 610, 270, 80, 40, "IFNγR2", sub_elements=[sub_sub_element_1])
sub_element_3 = SBGNMacromolecule("glyph42", 500, 330, 80, 40, "JAK1")
sub_element_4 = SBGNMacromolecule("glyph46", 600, 330, 80, 40, "JAK2")
sub_sub_element_1 = SBGNUnitOfInformation("glyph12a", 509.5, 257, 31, 16, "N:2")
sub_sub_element_2 = SBGNStateVariable("glyph12b", 535.0, 295, 20, 20)
sub_element_5 = SBGNMacromoleculeMultimer("glyph12", 505, 265, 80, 40, "IFNγR1", sub_elements=[sub_sub_element_1, sub_sub_element_2])
element = SBGNComplex("glyph5", 480, 180, 230, 220, sub_elements=[sub_element_1, sub_element_2, sub_element_3, sub_element_4, sub_element_5])
sbgn_elements.append(element)

# species glyph6
sub_sub_element_1 = SBGNUnitOfInformation("glyph20a", 199.5, 192, 31, 16, "N:2")
sub_element_1 = SBGNMacromoleculeMultimer("glyph20", 195, 200, 80, 40, "IFNγ", sub_elements=[sub_sub_element_1])
sub_sub_element_1 = SBGNUnitOfInformation("glyph15a", 149.5, 262, 31, 16, "N:2")
sub_sub_element_2 = SBGNStateVariable("glyph15b", 173.0, 300, 24, 20, "P")
sub_element_2 = SBGNMacromoleculeMultimer("glyph15", 145, 270, 80, 40, "IFNγR1", sub_elements=[sub_sub_element_1, sub_sub_element_2])
sub_sub_element_1 = SBGNUnitOfInformation("glyph19a", 259.5, 262, 31, 16, "N:2")
sub_element_3 = SBGNMacromoleculeMultimer("glyph19", 255, 270, 80, 40, "IFNγR2", sub_elements=[sub_sub_element_1])
sub_element_4 = SBGNMacromolecule("glyph43", 145, 330, 80, 40, "JAK1")
sub_element_5 = SBGNMacromolecule("glyph41", 245, 330, 80, 40, "JAK2")
element = SBGNComplex("glyph6", 120, 180, 230, 220, sub_elements=[sub_element_1, sub_element_2, sub_element_3, sub_element_4, sub_element_5])
sbgn_elements.append(element)

# species glyph11
sub_element_1 = SBGNStateVariable("glyph11a", 118, 545, 24, 20, "P")
element = SBGNMacromolecule("glyph11", 55, 515, 100, 40, "STAT1α", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph13
sub_element_1 = SBGNStateVariable("glyph13a", 367.5, 545, 20, 20)
element = SBGNMacromolecule("glyph13", 310, 515, 90, 40, "STAT1α", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph10
sub_element_1 = SBGNUnitOfInformation("glyph10a", 64.5, 687, 31, 16, "N:2")
sub_element_2 = SBGNStateVariable("glyph10b", 118, 725, 24, 20, "P")
element = SBGNMacromoleculeMultimer("glyph10", 55, 695, 100, 40, "STAT1α", sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# species glyph9
sub_element_1 = SBGNStateVariable("glyph9a", 118, 990, 24, 20, "P")
element = SBGNMacromoleculeMultimer("glyph9", 55, 960, 100, 40, "STAT1α", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph25
sub_element_1 = SBGNUnitOfInformation("glyph25a", 270, 952, 50, 16, "ct:gene")
element = SBGNNucleicAcidFeature("glyph25", 250, 960, 90, 40, "IRF1", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph26
sub_element_1 = SBGNUnitOfInformation("glyph26a", 367.5, 1102, 55, 16, "ct:mRNA")
element = SBGNNucleicAcidFeature("glyph26", 350, 1110, 90, 40, "IRF1", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph29
sub_element_1 = SBGNUnitOfInformation("glyph29a", 345, 762, 55, 16, "ct:mRNA")
element = SBGNNucleicAcidFeature("glyph29", 350, 770, 90, 40, "IRF1", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph48
element = SBGNMacromolecule("glyph48", 565, 675, 80, 40, "IRF1")
sbgn_elements.append(element)

# species glyph39
element = SBGNMacromolecule("glyph39", 565, 960, 80, 40, "IRF1")
sbgn_elements.append(element)

# species glyph28
sub_element_1 = SBGNUnitOfInformation("glyph28a", 760, 952, 50, 16, "ct:gene")
element = SBGNNucleicAcidFeature("glyph28", 740, 960, 90, 40, "iNOS", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph24
sub_element_1 = SBGNUnitOfInformation("glyph24a", 852.5, 1102, 55, 16, "ct:mRNA")
element = SBGNNucleicAcidFeature("glyph24", 835, 1110, 90, 40, "iNOS", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph27
sub_element_1 = SBGNUnitOfInformation("glyph27a", 852.5, 767, 55, 16, "ct:mRNA")
element = SBGNNucleicAcidFeature("glyph27", 835, 775, 90, 40, "iNOS", sub_elements=[sub_element_1])
sbgn_elements.append(element)

# species glyph3
element = SBGNMacromolecule("glyph3", 950, 680, 80, 40, "iNOS")
sbgn_elements.append(element)

# species glyph4
element = SBGNMacromolecule("glyph4", 795, 530, 80, 40, "CaM")
sbgn_elements.append(element)

# species glyph8
sub_sub_element_1 = SBGNUnitOfInformation("glyph21a", 1119.5, 502, 31, 16, "N:2")
sub_element_1 = SBGNMacromoleculeMultimer("glyph21", 1115, 510, 80, 40, "CaM", sub_elements=[sub_sub_element_1])
sub_sub_element_1 = SBGNUnitOfInformation("glyph22a", 1119.5, 572, 31, 16, "N:2")
sub_element_2 = SBGNMacromoleculeMultimer("glyph22", 1115, 580, 80, 40, "CaM", sub_elements=[sub_sub_element_1])
element = SBGNComplex("glyph8", 1090, 460, 130, 180, "1.14.13.39", text_x=1116.5, text_y=462, text_width=77, text_height=18, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# species glyph33
element = SBGNSimpleChemical("glyph33", 1235, 55, 60, 60, "arginie")
sbgn_elements.append(element)

# species glyph37
element = SBGNSimpleChemical("glyph37", 1465, 55, 60, 60, "NO")
sbgn_elements.append(element)

# species glyph36
element = SBGNSimpleChemical("glyph36", 1235, 645, 60, 60, "arginie")
sbgn_elements.append(element)

# species glyph35
element = SBGNSimpleChemical("glyph35", 1295, 545, 60, 60, "O2")
sbgn_elements.append(element)

# species glyph34
element = SBGNSimpleChemical("glyph34", 1525, 645, 60, 60, "citrulline")
sbgn_elements.append(element)

# species glyph31
element = SBGNSimpleChemical("glyph31", 1465, 545, 60, 60, "NO")
sbgn_elements.append(element)

# species glyph32
element = SBGNSimpleChemical("glyph32", 1620, 680, 60, 60, "aspartate")
sbgn_elements.append(element)

# species glyph44
element = SBGNMacromolecule("glyph44", 1615, 765, 80, 40, "6.3.4.5")
sbgn_elements.append(element)

# species glyph38
element = SBGNSimpleChemical("glyph38", 1385, 835, 60, 60, "arginino-succcinate")
sbgn_elements.append(element)

# species glyph45
element = SBGNMacromolecule("glyph45", 1125, 765, 80, 40, "4.3.2.1")
sbgn_elements.append(element)

# species glyph30
element = SBGNSimpleChemical("glyph30", 1135, 685, 60, 60, "fumarate")
sbgn_elements.append(element)

# empty species glyph51
element = SBGNEmptySet("glyph51", "glyph64", 95, 1110, 40, 40)
sbgn_elements.append(element)

# empty species glyph52
element = SBGNEmptySet("glyph52", "glyph68", 285, 675, 40, 40)
sbgn_elements.append(element)

# empty species glyph53
element = SBGNEmptySet("glyph53", "glyph66", 605, 1110, 40, 40)
sbgn_elements.append(element)

# empty species glyph55
element = SBGNEmptySet("glyph55", "glyph61", 1045, 775, 40, 40)
sbgn_elements.append(element)

# empty species glyph54
element = SBGNEmptySet("glyph54", "glyph75", 780, 680, 40, 40)
sbgn_elements.append(element)

# empty species glyph56
element = SBGNEmptySet("glyph56", "glyph57", 545, 770, 40, 40)
sbgn_elements.append(element)

# reaction glyph59
sub_element_1 = SBGNPort("glyph59_1", 761, 290)
sub_element_2 = SBGNPort("glyph59_2", 809, 290)
element = SBGNProcess("glyph59", 773, 278, 24, 24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph72
sub_element_1 = SBGNPort("glyph72_1", 401, 290)
sub_element_2 = SBGNPort("glyph72_2", 449, 290)
element = SBGNProcess("glyph72", 413, 278, 24, 24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph73
sub_element_1 = SBGNPort("glyph73_1", 105, 861)
sub_element_2 = SBGNPort("glyph73_2", 105, 909)
element = SBGNProcess("glyph73", 93, 873, 24, 24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph64
sub_element_1 = SBGNPort("glyph64_1", 181, 1130)
sub_element_2 = SBGNPort("glyph64_2", 229, 1130)
element = SBGNProcess("glyph64", 193, 1118, 24, 24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# # reaction glyph66
sub_element_1 = SBGNPort("glyph66_1", 661, 1130)
sub_element_2 = SBGNPort("glyph66_2", 709, 1130)
element = SBGNProcess("glyph66", 673, 1118, 24, 24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph68
sub_element_1 = SBGNPort("glyph68_1", 371, 695)
sub_element_2 = SBGNPort("glyph68_2", 419, 695)
element = SBGNProcess("glyph68", 383, 683, 24, 24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph71
sub_element_1 = SBGNPort("glyph71_1", 395, 861)
sub_element_2 = SBGNPort("glyph71_2", 395, 909)
element = SBGNProcess("glyph71", 383, 873, 24, 24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph76
sub_element_1 = SBGNPort("glyph76_1", 605, 861)
sub_element_2 = SBGNPort("glyph76_2", 605, 909)
element = SBGNProcess("glyph76", 593, 873, 24, 24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph75
sub_element_1 = SBGNPort("glyph75_1", 856, 700)
sub_element_2 = SBGNPort("glyph75_2", 904, 700)
element = SBGNProcess("glyph75", 868, 688, 24, 24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph63
sub_element_1 = SBGNPort("glyph63_1", 880, 861)
sub_element_2 = SBGNPort("glyph63_2", 880, 909)
element = SBGNProcess("glyph63", 868, 873, 24, 24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph70
sub_element_1 = SBGNPort("glyph70_1", 1381, 635)
sub_element_2 = SBGNPort("glyph70_2", 1429, 635)
element = SBGNProcess("glyph70", 1393, 623, 24, 24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph60
sub_element_1 = SBGNPort("glyph60_1", 1265, 761)
sub_element_2 = SBGNPort("glyph60_2", 1265, 809)
element = SBGNProcess("glyph60", 1253, 773, 24, 24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph69
sub_element_1 = SBGNPort("glyph69_1", 1265, 316)
sub_element_2 = SBGNPort("glyph69_2", 1265, 364)
element = SBGNProcess("glyph69", 1253, 328, 24, 24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph67
sub_element_1 = SBGNPort("glyph67_1", 1495, 316)
sub_element_2 = SBGNPort("glyph67_2", 1495, 364)
element = SBGNProcess("glyph67", 1483, 328, 24, 24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph77
sub_element_1 = SBGNPort("glyph77_1", 105, 601)
sub_element_2 = SBGNPort("glyph77_2", 105, 649)
element = SBGNProcess("glyph77", 93, 613, 24, 24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph57
sub_element_1 = SBGNPort("glyph57_1", 461, 790)
sub_element_2 = SBGNPort("glyph57_2", 509, 790)
element = SBGNProcess("glyph57", 473, 778, 24, 24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph61
sub_element_1 = SBGNPort("glyph61_1", 946, 795)
sub_element_2 = SBGNPort("glyph61_2", 994, 795)
element = SBGNProcess("glyph61", 958, 783, 24, 24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph74
sub_element_1 = SBGNPort("glyph74_1", 211, 535)
sub_element_2 = SBGNPort("glyph74_2", 259, 535)
element = SBGNProcess("glyph74", 223, 523, 24, 24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph62
sub_element_1 = SBGNPort("glyph62_1", 1555, 761)
sub_element_2 = SBGNPort("glyph62_2", 1555, 809)
element = SBGNProcess("glyph62", 1543, 773, 24, 24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# reaction glyph65
sub_element_1 = SBGNPort("glyph65_1", 996, 550)
sub_element_2 = SBGNPort("glyph65_2", 1044, 550)
element = SBGNProcess("glyph65", 1008, 538, 24, 24, sub_elements=[sub_element_1, sub_element_2])
sbgn_elements.append(element)

# species reference arc0
element = SBGNProduction("arc0", "glyph72_1", "glyph6", 401, 290, 350, 290, sbgn_elements)
sbgn_elements.append(element)

# species reference arc1
element = SBGNConsumption("arc1", "glyph5", "glyph72_2", 480, 290, 449, 290, sbgn_elements)
sbgn_elements.append(element)

# species reference arc2
element = SBGNStimulation("arc2", "glyph6", "glyph74", 235, 400, 235, 523, sbgn_elements)
sbgn_elements.append(element)

# species reference arc3
element = SBGNProduction("arc3", "glyph74_1", "glyph11", 211, 535, 155, 535, sbgn_elements)
sbgn_elements.append(element)

# species reference arc9
element = SBGNProduction("arc9", "glyph73_2", "glyph9", 105, 909, 105, 960, sbgn_elements)
sbgn_elements.append(element)

# species reference arc10
element = SBGNConsumption("arc10", "glyph10", "glyph73_1", 105, 735, 105, 861, sbgn_elements)
sbgn_elements.append(element)

# species reference arc11
element = SBGNNecessaryStimulation("arc11", "glyph49_2", "glyph64", 205, 1092, 205, 1118, sbgn_elements)
sbgn_elements.append(element)

# # species reference arc12
element = SBGNLogicArc("arc12", "glyph9", "glyph49_1", 155, 994, 205, 1008, sbgn_elements)
sbgn_elements.append(element)

# # species reference arc13
element = SBGNLogicArc("arc13", "glyph25", "glyph49_1", 250, 994, 205, 1008, sbgn_elements)
sbgn_elements.append(element)

# species reference arc14
element = SBGNProduction("arc14", "glyph64_2", "glyph26", 229, 1130, 350, 1130, sbgn_elements)
sbgn_elements.append(element)

# species reference arc15
element = SBGNConsumption("arc15", "glyph51", "glyph64_1", 135, 1130, 181, 1130, sbgn_elements)
sbgn_elements.append(element)

# species reference arc16
element = SBGNProduction("arc16", "glyph66_2", "glyph24", 709, 1130, 835, 1130, sbgn_elements)
sbgn_elements.append(element)

# species reference arc17
element = SBGNConsumption("arc17", "glyph53", "glyph66_1", 645, 1130, 661, 1130, sbgn_elements)
sbgn_elements.append(element)

# species reference arc18
element = SBGNNecessaryStimulation("arc18", "glyph50_2", "glyph66", 685, 1092, 685, 1118, sbgn_elements)
sbgn_elements.append(element)

# species reference arc19
element = SBGNLogicArc("arc19", "glyph28", "glyph50_1", 740, 992.6, 685, 1008, sbgn_elements)
sbgn_elements.append(element)

# species reference arc20
element = SBGNLogicArc("arc20", "glyph39", "glyph50_1", 645, 994, 685, 1008, sbgn_elements)
sbgn_elements.append(element)

# species reference arc21
element = SBGNConsumption("arc21", "glyph52", "glyph68_1", 325, 695, 371, 695, sbgn_elements)
sbgn_elements.append(element)

# species reference arc22
element = SBGNNecessaryStimulation("arc22", "glyph29", "glyph68", 395, 770, 395, 707, sbgn_elements)
sbgn_elements.append(element)

# species reference arc23
element = SBGNProduction("arc23", "glyph68_2", "glyph48", 419, 695, 565, 695, sbgn_elements)
sbgn_elements.append(element)

# species reference arc24
element = SBGNConsumption("arc24", "glyph48", "glyph76_1", 605, 715, 605, 861, sbgn_elements)
sbgn_elements.append(element)

# species reference arc25
element = SBGNConsumption("arc25", "glyph26", "glyph71_2", 395, 1110, 395, 909, sbgn_elements)
sbgn_elements.append(element)

# species reference arc26
element = SBGNProduction("arc26", "glyph71_1", "glyph29", 395, 861, 395, 810, sbgn_elements)
sbgn_elements.append(element)

# species reference arc27
element = SBGNProduction("arc27", "glyph76_2", "glyph39", 605, 909, 605, 960, sbgn_elements)
sbgn_elements.append(element)

# species reference arc31
element = SBGNProduction("arc31", "glyph75_2", "glyph3", 904, 700, 950, 700, sbgn_elements)
sbgn_elements.append(element)

# species reference arc32
element = SBGNProduction("arc32", "glyph63_1", "glyph27", 880, 861, 880, 815, sbgn_elements)
sbgn_elements.append(element)

# species reference arc33
element = SBGNConsumption("arc33", "glyph54", "glyph75_1", 820, 700, 856, 700, sbgn_elements)
sbgn_elements.append(element)

# species reference arc34
element = SBGNNecessaryStimulation("arc34", "glyph27", "glyph75", 880, 775, 880, 712, sbgn_elements)
sbgn_elements.append(element)

# species reference arc36
element = SBGNConsumption("arc36", "glyph24", "glyph63_2", 880, 1110, 880, 909, sbgn_elements)
sbgn_elements.append(element)

# species reference arc41
element = SBGNProduction("arc41", "glyph60_1", "glyph36", 1265, 761, 1265, 705, sbgn_elements)
sbgn_elements.append(element)

# species reference arc42
element = SBGNProduction("arc42", "glyph60_1", "glyph30", 1265, 761, 1189.5769, 732.20386, sbgn_elements)
sbgn_elements.append(element)

# species reference arc43
element = SBGNProduction("arc43", "glyph70_2", "glyph34", 1429, 635, 1526.013, 667.27014, sbgn_elements)
sbgn_elements.append(element)

# species reference arc44
element = SBGNProduction("arc44", "glyph70_2", "glyph31", 1429, 635, 1470.0385, 591.641, sbgn_elements)
sbgn_elements.append(element)

# species reference arc45
element = SBGNConsumption("arc45", "glyph32", "glyph62_1", 1623.568, 724.1898, 1555, 761, sbgn_elements)
sbgn_elements.append(element)

# species reference arc46
element = SBGNConsumption("arc46", "glyph34", "glyph62_1", 1555, 705, 1555, 761, sbgn_elements)
sbgn_elements.append(element)

# species reference arc47
element = SBGNConsumption("arc47", "glyph36", "glyph70_1", 1293.3612, 665.2203, 1381, 635, sbgn_elements)
sbgn_elements.append(element)

# species reference arc48
element = SBGNConsumption("arc48", "glyph35", "glyph70_1", 1345.4696, 596.93164, 1381, 635, sbgn_elements)
sbgn_elements.append(element)

# species reference arc49
element = SBGNConsumption("arc49", "glyph38", "glyph60_2", 1386.8948, 854.5074, 1265, 809, sbgn_elements)
sbgn_elements.append(element)

# species reference arc50
element = SBGNCatalysis("arc50", "glyph8", "glyph70", 1155, 460, 1405, 623, [(1155, 440), (1405, 440), (1405, 525)],  sbgn_elements)
sbgn_elements.append(element)

# species reference arc51
element = SBGNCatalysis("arc51", "glyph45", "glyph60", 1205, 785, 1253, 785, sbgn_elements)
sbgn_elements.append(element)

# species reference arc52
element = SBGNCatalysis("arc52", "glyph44", "glyph62", 1615, 785, 1567, 785, sbgn_elements)
sbgn_elements.append(element)

# species reference arc53
element = SBGNProduction("arc53", "glyph69_2", "glyph36", 1265, 364, 1265, 645, sbgn_elements)
sbgn_elements.append(element)

# species reference arc54
element = SBGNConsumption("arc54", "glyph33", "glyph69_1", 1265, 115, 1265, 316, sbgn_elements)
sbgn_elements.append(element)

# species reference arc55
element = SBGNProduction("arc55", "glyph67_1", "glyph37", 1495, 316, 1495, 115, sbgn_elements)
sbgn_elements.append(element)

# species reference arc56
element = SBGNConsumption("arc56", "glyph31", "glyph67_2", 1495, 545, 1495, 364, sbgn_elements)
sbgn_elements.append(element)

# species reference arc5
element = SBGNProduction("arc5", "glyph77_2", "glyph10", 105, 649, 105, 695, sbgn_elements)
sbgn_elements.append(element)

# species reference arc29
element = SBGNConsumption("arc29", "glyph11", "glyph77_1", 105, 555, 105, 601, sbgn_elements)
sbgn_elements.append(element)

# species reference arc35
element = SBGNConsumption("arc35", "glyph27", "glyph61_1", 925, 795, 946, 795, sbgn_elements)
sbgn_elements.append(element)

# species reference arc57
element = SBGNConsumption("arc57", "glyph29", "glyph57_1", 440, 790, 461, 790, sbgn_elements)
sbgn_elements.append(element)

# species reference arc4
element = SBGNProduction("arc4", "glyph57_2", "glyph56", 509, 790, 545, 790, sbgn_elements)
sbgn_elements.append(element)

# species reference arc28
element = SBGNProduction("arc28", "glyph61_2", "glyph55", 994, 795, 1045, 795, sbgn_elements)
sbgn_elements.append(element)

# species reference arc30
element = SBGNConsumption("arc30", "glyph13", "glyph74_2", 310, 535, 259, 535, sbgn_elements)
sbgn_elements.append(element)

# species reference arc40
element = SBGNProduction("arc40", "glyph62_2", "glyph38", 1555, 809, 1441.0472, 850.11584, sbgn_elements)
sbgn_elements.append(element)

# species reference arc6
element = SBGNProduction("arc6", "glyph65_2", "glyph8", 1044, 550, 1090, 550, sbgn_elements)
sbgn_elements.append(element)

# species reference arc7
element = SBGNConsumption("arc7", "glyph4", "glyph65_1", 875, 550, 996, 550, sbgn_elements)
sbgn_elements.append(element)

# species reference arc8
element = SBGNConsumption("arc8", "glyph3", "glyph65_1", 990.8, 680, 996, 550, sbgn_elements)
sbgn_elements.append(element)

# species reference arc37
element = SBGNProduction("arc37", "glyph59_1", "glyph5", 761, 290, 710, 290, sbgn_elements)
sbgn_elements.append(element)

# species reference arc38
element = SBGNConsumption("arc38", "glyph7", "glyph59_2", 870, 290, 809, 290, sbgn_elements)
sbgn_elements.append(element)

# species reference arc39
element = SBGNConsumption("arc39", "glyph16", "glyph59_2", 809.9048, 100, 809, 290, sbgn_elements)
sbgn_elements.append(element)

# reaction glyph49
sub_element_1 = SBGNLogicPort("glyph49_1", 205, 1008)
sub_element_2 = SBGNLogicPort("glyph49_2", 205, 1092)
element = SBGNAndOperator("glyph49", 184, 1029, 42, 42, sub_elements=[sub_element_1, sub_element_2], sbgn_elements=sbgn_elements)
sbgn_elements.append(element)

# reaction glyph50
sub_element_1 = SBGNLogicPort("glyph50_1", 685, 1008)
sub_element_2 = SBGNLogicPort("glyph50_2", 685, 1092)
element = SBGNAndOperator("glyph50", 664, 1029, 42, 42, sub_elements=[sub_element_1, sub_element_2], sbgn_elements=sbgn_elements)
sbgn_elements.append(element)

load_sbml_info(net, sbgn_elements)

net.draw("./figure_2_sbgn_compliant.pdf", update_network_extents=True)
net.save("./figure_2_sbgn_compliant.xml", update_network_extents=True)