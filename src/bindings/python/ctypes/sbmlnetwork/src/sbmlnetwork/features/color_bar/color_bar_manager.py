from .color_bar import ColorBar

class ColorBarManager:

    def add_color_bar(self, network_obj, color_bar_type: str = None):
        color_bar_id = self._get_color_bar_id(color_bar_type)
        network_obj.remove_additional_element(color_bar_id)
        current_color_bars = self.get_color_bars(network_obj)
        if network_obj.libsbmlnetwork.addAdditionalGraphicalObject(id=color_bar_id) == 0:
            color_bar = ColorBar(network_obj.libsbmlnetwork, color_bar_id)
            if len(current_color_bars) > 0:
                for current_color_bar in current_color_bars:
                    color_bar.move_by((current_color_bar.get_horizontal_extent(), 0))
            return color_bar

        return None

    def get_color_bar(self, network_obj, color_bar_type: str = None):
        if color_bar_type is None:
            if self.has_color_bar(network_obj, "fluxes") and not self.has_color_bar(network_obj, "concentrations"):
                color_bar_id = self._get_color_bar_id("fluxes")
            elif not self.has_color_bar(network_obj, "fluxes") and self.has_color_bar(network_obj, "concentrations"):
                color_bar_id = self._get_color_bar_id("concentrations")
        else:
            color_bar_id = self._get_color_bar_id(color_bar_type)
        for i in range(network_obj.libsbmlnetwork.getNumAllAdditionalGraphicalObjects()):
            if network_obj.libsbmlnetwork.getAdditionalGraphicalObjectId(i) == color_bar_id:
                return ColorBar(network_obj.libsbmlnetwork, color_bar_id)

        return None

    def get_color_bars(self, network_obj):
        color_bars = []
        if self.has_color_bar(network_obj, "fluxes"):
            color_bars.append(self.get_color_bar(network_obj, "fluxes"))
        if self.has_color_bar(network_obj, "concentrations"):
            color_bars.append(self.get_color_bar(network_obj, "concentrations"))

        return color_bars

    def remove_color_bar(self, network_obj, color_bar_type: str = None):
        color_bars = self.get_color_bars(network_obj)
        if len(color_bars) == 1:
            color_bar_id = color_bars[0].get_id()
        else:
            color_bar_id = self._get_color_bar_id(color_bar_type)
        color_bars.sort(key=lambda x: x.get_position()[0])
        color_bar_id = self._get_color_bar_id(color_bar_type)
        for color_bar in color_bars:
            if color_bar.get_id() == color_bar_id:
                for i in range(color_bars.index(color_bar) + 1, len(color_bars)):
                    color_bars[i].move_by((-color_bar.get_horizontal_extent(), 0))
                color_bar.remove_all_labels()
                color_bar.remove_all_shapes()
                return network_obj.remove_additional_element(color_bar_id)

        color_bar = self.get_color_bar(network_obj, color_bar_type)
        if color_bar:
            return network_obj.remove_additional_element(color_bar.get_id())

        return False

    def remove_color_bars(self, network_obj):
        cannot_remove = False
        if self.has_color_bar(network_obj, "fluxes"):
            if not self.remove_color_bar(network_obj, "fluxes"):
                cannot_remove = True

        if self.has_color_bar(network_obj, "concentrations"):
            if not self.remove_color_bar(network_obj, "concentrations"):
                cannot_remove = True

        if cannot_remove:
            return False

        return True

    def has_color_bar(self, network_obj, color_bar_type: str):
        color_bar_ids = []
        if color_bar_type is not None:
            color_bar_ids.append(self._get_color_bar_id(color_bar_type))
        else:
            color_bar_ids.append(self._get_color_bar_id("fluxes"))
            color_bar_ids.append(self._get_color_bar_id("concentrations"))
        for i in range(network_obj.libsbmlnetwork.getNumAllAdditionalGraphicalObjects()):
            if network_obj.libsbmlnetwork.getAdditionalGraphicalObjectId(i) in color_bar_ids:
                return True

        return False

    @staticmethod
    def _get_color_bar_id(color_bar_type: str = None):
        if color_bar_type is None or color_bar_type in ["fluxes", "Fluxes", "fluxes_color_bar", "Fluxes_Color_Bar"]:
            return "SBMLNetwork_Fluxes_ColorBar"
        elif color_bar_type in ["concentrations", "Concentrations", "concentrations_color_bar", "Concentrations_Color_Bar", "Conc.", "conc."]:
            return "SBMLNetwork_Concentrations_ColorBar"
        else:
            raise ValueError("Color bar type must be one of 'fluxes' or 'concentrations'")