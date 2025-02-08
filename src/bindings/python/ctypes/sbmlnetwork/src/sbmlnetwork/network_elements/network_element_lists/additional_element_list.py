from .network_element_base_list import NetworkElementBaseList

class NetworkElementList(NetworkElementBaseList):
    pass

    def __str__(self):
        result = []
        for element in self:
            result.append(str(element))
        return "\n".join(result)
