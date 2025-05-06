class SBGNElementBase:

    def __init__(self, element_id, sub_elements=None):
        self.element_id = element_id
        if sub_elements is None:
            self.sub_elements = []
        else:
            self.sub_elements = sub_elements

    @staticmethod
    def get_super_type():
        return ""

    @staticmethod
    def get_type():
        return ""

    def get_id(self):
        return self.element_id

    def set_id(self, element_id):
        self.element_id = element_id

    def get_sub_elements(self):
        return self.sub_elements

    def set_sub_elements(self, sub_elements):
        self.sub_elements = sub_elements

    def load_sbml_info(self, sbmlnetwork_object, parent_element=None, sbgn_elements=None):
        pass

    def initialize_sbml_info(self, sbmlnetwork_object, parent_element):
        pass

    def add_geometric_shape(self, sbmlnetwork_object, parent_element):
        pass

    def load_sbml_info_with_sub_elements(self, sbmlnetwork_object, parent_element):
        for sub_element in self.get_sub_elements():
            sub_element.load_sbml_info(sbmlnetwork_object, parent_element)

    def __str__(self):
        element_type = ""
        if hasattr(self, "get_type"):
            element_type = self.get_type()
        return "type:" + element_type + ", id: " + self.element_id




