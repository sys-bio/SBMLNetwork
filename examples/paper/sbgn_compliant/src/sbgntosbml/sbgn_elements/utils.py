def find_element(element_id, sbgn_elements, visited=None):
    if sbgn_elements is None:
        return None

    if visited is None:
        visited = set()

    for sbgn_element in sbgn_elements:
        if sbgn_element.get_id() == element_id:
            return sbgn_element

        if sbgn_element in visited:
            continue

        visited.add(sbgn_element)

        found_element = find_element(element_id, sbgn_element.get_sub_elements(), visited)
        if found_element is not None:
            return found_element

    return None

def find_parent_element(element_id, sbgn_elements, visited=None):
    if sbgn_elements is None:
        return None

    if visited is None:
        visited = set()

    for sbgn_element in sbgn_elements:
        if sbgn_element.get_id() == element_id:
            return sbgn_element

        if sbgn_element in visited:
            continue

        visited.add(sbgn_element)

        found_element = find_parent_element(element_id, sbgn_element.get_sub_elements(), visited)
        if found_element is not None:
            return sbgn_element

    return None