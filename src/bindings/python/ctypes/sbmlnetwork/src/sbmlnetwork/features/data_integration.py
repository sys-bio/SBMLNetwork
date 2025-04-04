from matplotlib.colors import LinearSegmentedColormap
import tellurium as te
from typing import Union, Dict
import math


class DataIntegrationBase:

    def __init__(self, network_obj):
        self.network_obj = network_obj
        self._data_type = None
        self._simulation_time = None
        self._data = None
        self._element_features_original_values = {}
        self._log_scale = False

    def show(self, data: Union[float, Dict], log_scale: bool = False):
        self._log_scale = log_scale
        self.hide()

        self._initialize_parameters(data)
        if self._data is None:
            self._data = self._get_data()

    def hide(self):
        pass

    def update_styles(self):
        pass

    def _get_data(self):
        pass

    def _initialize_parameters(self, data):
        if data is not None:
            if isinstance(data, dict):
                self._data = data
            elif isinstance(data, float) or isinstance(data, int):
                self._simulation_time = data
        else:
            raise ValueError("Simulation data or time is not provided")

    def get_simulation_time(self):
        return self._simulation_time

    def get_max_value(self):
        if self._data is None:
            raise ValueError("Data is not initialized")

        max_value = max(self._data.values())
        if self._log_scale:
            max_value = math.log(max_value, 10)

        return max_value

    def get_min_value(self):
        if self._data is None:
            raise ValueError("Data is not initialized")

        min_value = min(self._data.values())
        if self._log_scale:
            min_value = math.log(min_value, 10)

        return min_value


class ColorCodingDataIntegrationBase(DataIntegrationBase):

    def __init__(self, network_obj):
        super().__init__(network_obj)
        self._color_bar = None

    def show(self, data: Union[float, Dict], log_scale: bool = False):
        super().show(data, log_scale)
        from .color_bar.color_bar_manager import ColorBarManager

        self._color_bar = ColorBarManager().add_color_bar(self.network_obj, self._data_type)

        return self.update_styles()

    def hide(self):
        from .color_bar.color_bar_manager import ColorBarManager

        if self._color_bar is not None:
            ColorBarManager().remove_color_bar(self.network_obj, self._data_type)
        self._color_bar = None

    def update_styles(self):
        self._color_bar.set_max_value(max_value=self.get_max_value())
        self._color_bar.set_min_value(min_value=self.get_min_value())
        for element_id in self._data:
            if self._log_scale:
                color = self._get_color(self._color_bar, math.log(self._data[element_id], 10))
            else:
                color = self._get_color(self._color_bar, self._data[element_id])
            self._update_element_features(element_id, color)

        return True

    def _update_element_features(self, element_id, color):
        pass

    def set_colors(self, gradient_colors):
        self._color_bar.set_gradient_colors(gradient_colors)
        return self.update_styles()

    def get_colors(self):
        return self._color_bar.get_gradient_colors()

    @staticmethod
    def _get_color(color_bar, value):
        colors = color_bar.get_gradient_colors()[::-1]
        max_value = color_bar.get_max_value()
        min_value = color_bar.get_min_value()
        if max_value == min_value:
            normalized_value = 0
            color_bar.set_gradient_colors([colors[0], colors[0]])
            color_bar.set_number_of_tick_marks(2)
        else:
            normalized_value = (value - min_value) / (max_value - min_value)
        camp = LinearSegmentedColormap.from_list('my_cmap', colors)
        rgba = camp(normalized_value)
        r, g, b, a = rgba
        hex_color = '#{:02x}{:02x}{:02x}{:02x}'.format(int(r * 255), int(g * 255), int(b * 255), int(a * 255))

        return hex_color

    def has_color_bar(self):
        if self._color_bar is not None:
            return True

        return False

    def get_color_bar(self):
        return self._color_bar

    def remove_color_bar(self):
        from .color_bar.color_bar_manager import ColorBarManager

        return ColorBarManager().remove_color_bar(self, self._data_type)

    @property
    def color_bar(self):
        return self.get_color_bar()


class ColorCodingFluxes(ColorCodingDataIntegrationBase):

    def __init__(self, network_obj):
        super().__init__(network_obj)
        self._data_type = "fluxes"

    def _get_data(self):
        model = self.network_obj.save()
        r = te.loadSBMLModel(model)
        r.simulate(start=0.0, end=self._simulation_time, steps=self._simulation_time * 100)
        fluxes = {}
        for i, reaction in enumerate(r.getReactionIds()):
            fluxes[reaction] = float(r.getReactionRates()[i])

        return fluxes

    def _update_element_features(self, element_id, color):
        reactions_list = self.network_obj.get_reactions_list(element_id)
        for reaction in reactions_list:
            self._element_features_original_values[reaction.get_id()] = {
                'color': reaction.get_curves_list().get_colors()[0],
                'thickness': reaction.get_curves_list().get_thicknesses()[0],
                'arrow_head_relative_positions': reaction.get_arrow_head_relative_positions()[0]}
            reaction.set_colors(color)
            reaction.set_thicknesses(8)
            reaction.move_arrow_head_relative_positions_by((-2, 0))

    def hide(self):
        super().hide()
        reactions_list = self.network_obj.get_reactions_list()
        for reaction in reactions_list:
            if reaction.get_id() in self._element_features_original_values:
                reaction.set_colors(self._element_features_original_values[reaction.get_id()]['color'])
                reaction.set_thicknesses(self._element_features_original_values[reaction.get_id()]['thickness'])
                reaction.set_arrow_head_relative_positions(
                    self._element_features_original_values[reaction.get_id()]['arrow_head_relative_positions'])


class ConcentrationDataIntegrationBase(DataIntegrationBase):

    def __init__(self, network_obj):
        super().__init__(network_obj)
        self._data_type = "concentrations"

    def _get_data(self):
        model = self.network_obj.save()
        r = te.loadSBMLModel(model)
        r.simulate(start=0.0, end=self._simulation_time, steps=self._simulation_time * 10)
        concentrations = {}
        for i, species in enumerate(r.getFloatingSpeciesIds()):
            concentrations[species] = float(r.getFloatingSpeciesConcentrations()[i])

        return concentrations


class ColorCodingConcentrations(ColorCodingDataIntegrationBase, ConcentrationDataIntegrationBase):

    def _update_element_features(self, element_id, color):
        species_list = self.network_obj.get_species_list(element_id)
        for species in species_list:
            self._element_features_original_values[species.get_id()] = species.get_fill_color()[0]
            species.set_fill_color(color)

    def hide(self):
        super().hide()
        species_list = self.network_obj.get_species_list()
        for species in species_list:
            if species.get_id() in self._element_features_original_values:
                species.set_fill_color(self._element_features_original_values[species.get_id()])


class SizeCodingConcentrations(DataIntegrationBase):

    def show(self, data: Union[float, Dict], log_scale: bool = False):
        super().show(data, log_scale)
        return self.update_styles()

    def hide(self):
        species_list = self.network_obj.get_species_list()
        for species in species_list:
            if species.get_id() in self._element_features_original_values:
                species.set_size(self._element_features_original_values[species.get_id()])

    def update_styles(self):
        for element_id in self._data:
            if self._log_scale:
                size = self._get_size(math.log(self._data[element_id], 10))
            else:
                size = self._get_size(self._data[element_id])

            self._update_element_features(element_id, size)

        return True

    def _update_element_features(self, element_id, dimension):
        species_list = self.network_obj.get_species_list(element_id)
        for species in species_list:
            self._element_features_original_values[species.get_id()] = species.get_size()
            species.set_size((dimension, dimension))

    def _get_size(self, value):
        sizes = self.network_obj.get_species_list().get_sizes()
        max_dimension = max(math.sqrt(size[0] ** 2 + size[1] ** 2) for size in sizes)
        min_dimension = min(math.sqrt(size[0] ** 2 + size[1] ** 2) for size in sizes)
        mean_dimension = 0.5 * (max_dimension + min_dimension)
        max_value = self.get_max_value()
        min_value = self.get_min_value()
        if max_value == min_value:
            normalized_value = 0.5
        else:
            normalized_value = (value - min_value) / (max_value - min_value)

        return mean_dimension * (0.75 + normalized_value * 0.5)
