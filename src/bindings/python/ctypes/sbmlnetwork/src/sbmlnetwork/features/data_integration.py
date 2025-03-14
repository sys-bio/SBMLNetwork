from matplotlib.colors import LinearSegmentedColormap
import tellurium as te


class DataIntegrationBase:

    def __init__(self, network_obj):
        self.network_obj = network_obj
        self.data_type = None
        self._simulation_end_time = None
        self._simulation_start_time = None
        self._simulation_time_steps = None
        self._data = None
        self._element_features_original_values = {}
        self._color_bar = None

    def show(self, simulation_end_time, simulation_start_time, simulation_time_steps, data):
        self.hide()
        from .color_bar.color_bar_manager import ColorBarManager

        self._initialize_parameters(simulation_end_time, simulation_start_time, simulation_time_steps, data)
        if self._data is None:
            self._data = self._get_data(self._simulation_end_time, self._simulation_start_time, self._simulation_time_steps)
        self._color_bar = ColorBarManager().add_color_bar(self.network_obj, self.data_type)

        return self.update_styles()

    def hide(self):
        from .color_bar.color_bar_manager import ColorBarManager

        if self._color_bar is not None:
            ColorBarManager().remove_color_bar(self.network_obj, self.data_type)
        self._color_bar = None

    def update_styles(self):
        self._color_bar.set_max_value(max_value=max(self._data.values()))
        self._color_bar.set_min_value(min_value=min(self._data.values()))
        for element_id in self._data:
            color = self._get_color(self._color_bar, self._data[element_id])
            self._update_element_features(element_id, color)
        return True

    def set_colors(self, gradient_colors):
        self._color_bar.set_gradient_colors(gradient_colors)
        return self.update_styles()

    def get_colors(self):
        return self._color_bar.get_gradient_colors()

    def _get_data(self, simulation_end_time, simulation_start_time, simulation_time_steps):
        pass

    def _update_element_features(self, element_id, color):
        pass

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

    def _initialize_parameters(self, simulation_end_time, simulation_start_time, simulation_time_steps, data):
        if isinstance(simulation_end_time, dict):
            self.data = simulation_end_time
        if data is None:
            if simulation_end_time is None or simulation_start_time is None or simulation_time_steps is None:
                if self.data_type == "fluxes" and self.network_obj.concentrations is not None:
                    self._simulation_end_time = self.network_obj.concentrations.get_simulation_end_time()
                    self._simulation_start_time = self.network_obj.concentrations.get_simulation_start_time()
                    self._simulation_time_steps = self.network_obj.concentrations.get_simulation_time_steps()
                elif self.data_type == "concentrations" and self.network_obj.fluxes is not None:
                    self._simulation_end_time = self.network_obj.fluxes.get_simulation_end_time()
                    self._simulation_start_time = self.network_obj.fluxes.get_simulation_start_time()
                    self._simulation_time_steps = self.network_obj.fluxes.get_simulation_time_steps()
                else:
                    self._simulation_end_time = 10
                    self._simulation_start_time = 0
                    self._simulation_time_steps = 100
            else:
                if simulation_end_time <= simulation_start_time:
                    raise ValueError("Simulation end time must be greater than simulation start time")
                if simulation_time_steps <= 0:
                    raise ValueError("Simulation time steps must be greater than 0")
                if simulation_start_time < 0:
                    raise ValueError("Simulation start time cannot be negative")
                self._simulation_end_time = simulation_end_time
                self._simulation_start_time = simulation_start_time
                self._simulation_time_steps = simulation_time_steps

    def get_simulation_end_time(self):
        return self._simulation_end_time

    def get_simulation_start_time(self):
        return self._simulation_start_time

    def get_simulation_time_steps(self):
        return self._simulation_time_steps

    def has_color_bar(self):
        if self._color_bar is not None:
            return True

        return False

    def get_color_bar(self):
        return self._color_bar

    def remove_color_bar(self):
        from .color_bar.color_bar_manager import ColorBarManager

        return ColorBarManager().remove_color_bar(self, self.data_type)

    @property
    def color_bar(self):
        return self.get_color_bar()


class Fluxes(DataIntegrationBase):

    def __init__(self, network_obj):
        super().__init__(network_obj)
        self.data_type = "fluxes"

    def _get_data(self, simulation_end_time, simulation_start_time, simulation_time_steps):
        model = self.network_obj.save()
        r = te.loadSBMLModel(model)
        r.simulate(start=simulation_start_time, end=simulation_end_time, steps=simulation_time_steps)
        fluxes = {}
        for i, reaction in enumerate(r.getReactionIds()):
            fluxes[reaction] = float(r.getReactionRates()[i])

        return fluxes

    def _update_element_features(self, element_id, color):
        reactions_list = self.network_obj.get_reactions_list(element_id)
        for reaction in reactions_list:
            self._element_features_original_values[reaction.get_id()] = {'color': reaction.get_curves_list().get_colors()[0],
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
                reaction.set_arrow_head_relative_positions(self._element_features_original_values[reaction.get_id()]['arrow_head_relative_positions'])


class Concentrations(DataIntegrationBase):

    def __init__(self, network_obj):
        super().__init__(network_obj)
        self.data_type = "concentrations"

    def _get_data(self, simulation_end_time, simulation_start_time, simulation_time_steps):
        model = self.network_obj.save()
        r = te.loadSBMLModel(model)
        r.simulate(start=simulation_start_time, end=simulation_end_time, steps=simulation_time_steps)
        concentrations = {}
        for i, species in enumerate(r.getFloatingSpeciesIds()):
            concentrations[species] = float(r.getFloatingSpeciesConcentrations()[i])

        return concentrations

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
