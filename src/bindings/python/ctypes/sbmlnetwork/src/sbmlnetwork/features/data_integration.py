import tellurium as te
from typing import Union, Dict
import math


class DataIntegrationBase:

    def __init__(self, network_obj):
        self.network_obj = network_obj
        self._data_type = None
        self._data = None
        self._element_features_original_values = {}
        self._log_scale = False
        self._min_threshold = None

    def show(self, data: Union[float, Dict], log_scale: bool = False, min_threshold: float = None):
        self._log_scale = log_scale
        self._set_min_threshold(min_threshold)
        self.hide()
        self._set_data(data)

    def hide(self):
        pass

    def update_styles(self):
        pass

    def _get_data(self):
        pass

    def _set_min_threshold(self, min_threshold):
        if min_threshold is None:
            if self._log_scale:
                self._min_threshold = 1e-10
            else:
                self._min_threshold = -math.inf
        else:
            if self._log_scale and min_threshold < 0:
                raise ValueError("Minimum threshold must be a positive value for log scale")
            self._min_threshold = min_threshold

    def _set_data(self, data):
        if data is None:
            raise ValueError("Simulation data or time is not provided")
        else:
            if isinstance(data, dict):
                if not all(isinstance(value, (float, int)) for value in data.values()):
                    raise ValueError("Data values must be float or int")
                if not all(isinstance(key, str) for key in data.keys()):
                    raise ValueError("Data keys must be strings")
                if not self._log_scale:
                    self._data = {key: value for key, value in data.items() if value >= self._min_threshold}
                else:
                    self._data = {key: value for key, value in data.items() if abs(value) >= self._min_threshold}
            elif isinstance(data, float) or isinstance(data, int):
                self._data = self._simulate(data)

    def get_max_value(self):
        if self._data is None:
            raise ValueError("Data is not initialized")

        abs_values = [abs(value) for value in self._data.values()]
        max_value = max(abs_values)
        if self._log_scale:
            max_value = math.log(max_value, 10)

        return max_value

    def get_min_value(self):
        if self._data is None:
            raise ValueError("Data is not initialized")

        abs_values = [abs(value) for value in self._data.values()]
        min_value = min(abs_values)
        if self._log_scale:
            min_value = math.log(min_value, 10)

        return min_value

    def _simulate(self, simulation_time):
        pass


class ColorCodingDataIntegrationBase(DataIntegrationBase):

    def __init__(self, network_obj, skip_hidden_elements=True):
        super().__init__(network_obj)
        self._color_bar = None
        self._skip_hidden_elements = skip_hidden_elements

    def show(self, data: Union[float, Dict], log_scale: bool = False, min_threshold: float = None):
        super().show(data, log_scale, min_threshold)
        from .color_bar.color_bar_manager import ColorBarManager

        self._color_bar = ColorBarManager().add_color_bar(self.network_obj, self._data_type, self._log_scale)

        return self.update_styles()

    def hide(self):
        from .color_bar.color_bar_manager import ColorBarManager

        if self._color_bar is not None:
            ColorBarManager().remove_color_bar(self.network_obj, self._data_type)
        self._color_bar = None

    def update_styles(self):
        self._color_bar.set_min_value(min_value=self.get_min_value())
        self._color_bar.set_max_value(max_value=self.get_max_value())
        for element_id in self._data:
            color = self._color_bar.get_associated_color(self._data[element_id])
            self._update_element_features(element_id, color)

        return True

    def _update_element_features(self, element_id, color):
        pass

    def set_colors(self, gradient_colors):
        self._color_bar.set_gradient_colors(gradient_colors)
        return self.update_styles()

    def get_colors(self):
        return self._color_bar.get_gradient_colors()

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

    def __init__(self, network_obj, skip_hidden_elements=True):
        super().__init__(network_obj, skip_hidden_elements)
        self._data_type = "fluxes"

    def _simulate(self, simulation_time):
        model = self.network_obj.save()
        r = te.loadSBMLModel(model)
        r.simulate(start=0.0, end=simulation_time, steps=simulation_time * 100)
        fluxes = {}
        for i, reaction in enumerate(r.getReactionIds()):
            if not self._log_scale:
                if r.getReactionRates()[i] > self._min_threshold:
                    fluxes[reaction] = float(r.getReactionRates()[i])
            else:
                if abs(r.getReactionRates()[i]) > self._min_threshold:
                    fluxes[reaction] = float(r.getReactionRates()[i])

        return fluxes

    def _update_element_features(self, element_id, color):
        reactions_list = self.network_obj.get_reactions_list(element_id)
        for reaction in reactions_list:
            features = {'reaction_border_color': reaction.get_border_color()[0]}
            curve_features = []
            for curve in reaction.get_curves_list():
                curve_data = {
                    'color': curve.get_color(),
                    'thickness': curve.get_thickness()
                }

                arrow_head = curve.get_arrow_head()
                if arrow_head is not None:
                    curve_data['arrow_head_features'] = {
                        'fill_color': arrow_head.get_fill_color()[0],
                        'border_color': arrow_head.get_border_color()[0],
                        'thickness': arrow_head.get_border_thickness()[0],
                        'relative_position': arrow_head.get_relative_position()
                    }

                curve_features.append(curve_data)

            features['curves'] = curve_features
            self._element_features_original_values[reaction.get_id()] = features
            if not reaction.is_hidden() or not self._skip_hidden_elements:
                reaction.get_shapes_list().set_border_colors(color)
            for curve in reaction.get_curves_list():
                if not curve.is_hidden() or not self._skip_hidden_elements:
                    curve.set_color(color)
                    curve.set_thickness(8)
                    arrow_head = curve.get_arrow_head()
                    if arrow_head is not None:
                        arrow_head.move_relative_position_by((-2, 0))
                        arrow_head.set_border_color(color)
                        arrow_head.set_fill_color(color)
                        arrow_head.set_border_thickness(8)

    def hide(self):
        super().hide()
        reactions_list = self.network_obj.get_reactions_list()
        for reaction in reactions_list:
            if reaction.get_id() in self._element_features_original_values:
                if not reaction.is_hidden() or not self._skip_hidden_elements:
                    reaction.get_shapes_list().set_border_colors(self._element_features_original_values[reaction.get_id()]['reaction_border_color'])
                for index, curve in enumerate(reaction.get_curves_list()):
                    if not curve.is_hidden() or not self._skip_hidden_elements:
                        curve.set_color(self._element_features_original_values[reaction.get_id()]['curves'][index]['color'])
                        curve.set_thickness(self._element_features_original_values[reaction.get_id()]['curves'][index]['thickness'])
                        arrow_head = curve.get_arrow_head()
                        if arrow_head is not None:
                            arrow_head.set_border_color(self._element_features_original_values[reaction.get_id()]['curves'][index]['arrow_head_features']['border_color'])
                            arrow_head.set_fill_color(self._element_features_original_values[reaction.get_id()]['curves'][index]['arrow_head_features']['fill_color'])
                            arrow_head.set_border_thickness(self._element_features_original_values[reaction.get_id()]['curves'][index]['arrow_head_features']['thickness'])
                            arrow_head.set_relative_position(self._element_features_original_values[reaction.get_id()]['curves'][index]['arrow_head_features']['relative_position'])

class ConcentrationDataIntegrationBase(DataIntegrationBase):

    def __init__(self, network_obj):
        super().__init__(network_obj)
        self._data_type = "concentrations"

    def _simulate(self, simulation_time):
        model = self.network_obj.save()
        r = te.loadSBMLModel(model)
        r.simulate(start=0.0, end=simulation_time, steps=simulation_time * 100)
        concentrations = {}
        for i, species in enumerate(r.getFloatingSpeciesIds()):
            if not self._log_scale:
                if r.getFloatingSpeciesConcentrations()[i] > self._min_threshold:
                    concentrations[species] = float(r.getFloatingSpeciesConcentrations()[i])
            else:
                if abs(r.getFloatingSpeciesConcentrations()[i]) > self._min_threshold:
                    concentrations[species] = float(r.getFloatingSpeciesConcentrations()[i])

        return concentrations


class ColorCodingConcentrations(ColorCodingDataIntegrationBase, ConcentrationDataIntegrationBase):

    def __init__(self, network_obj, skip_hidden_elements=True):
        ColorCodingDataIntegrationBase.__init__(self, network_obj, skip_hidden_elements)
        ConcentrationDataIntegrationBase.__init__(self, network_obj)

    def _update_element_features(self, element_id, color):
        species_list = self.network_obj.get_species_list(element_id)
        for species in species_list:
            if not species.is_hidden() or not self._skip_hidden_elements:
                self._element_features_original_values[species.get_id()] = species.get_fill_color()[0]
                species.set_fill_color(color)

    def hide(self):
        super().hide()
        species_list = self.network_obj.get_species_list()
        for species in species_list:
            if species.get_id() in self._element_features_original_values:
                species.set_fill_color(self._element_features_original_values[species.get_id()])


class SizeCodingConcentrations(ConcentrationDataIntegrationBase):

    def __init__(self, network_obj, min_size: float = 10, max_size: float = 100):
        super().__init__(network_obj)
        self._min_size = min_size
        self._max_size = max_size

    def show(self, data: Union[float, Dict], log_scale: bool = False, min_threshold: float = None):
        super().show(data, log_scale, min_threshold)
        return self.update_styles()

    def hide(self):
        species_list = self.network_obj.get_species_list()
        for species in species_list:
            if species.get_id() in self._element_features_original_values:
                species.set_size(self._element_features_original_values[species.get_id()], adjust_font_size=False)

    def update_styles(self):
        for element_id in self._data:
            if self._data[element_id] < 0:
                raise ValueError("Negative concentrations are not allowed for size coding")
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
            species.set_size((dimension, dimension), adjust_font_size=False)

    def _get_size(self, value):
        max_value = self.get_max_value()
        min_value = self.get_min_value()
        if max_value == min_value:
            return 0.5 * (self._max_size + self._min_size)
        else:
            return ((value - min_value) / (max_value - min_value)) * (self._max_size - self._min_size) + self._min_size
