def load_sbml_info(sbmlnetwork_object, sbgn_elements: list):
    if sbmlnetwork_object is not None and sbgn_elements is not None:
        for sbgn_element in sbgn_elements:
            sbgn_element.load_sbml_info(sbmlnetwork_object, sbgn_elements=sbgn_elements)