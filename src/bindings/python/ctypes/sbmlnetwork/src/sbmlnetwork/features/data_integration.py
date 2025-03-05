from matplotlib.colors import LinearSegmentedColormap
import tellurium as te


class Fluxes:

    def display(self, network_obj, simulation_end_time, simulation_start_time, simulation_time_steps, fluxes):
        if isinstance(simulation_end_time, dict):
            fluxes = simulation_end_time
        else:
            if simulation_end_time <= simulation_start_time:
                raise ValueError("Simulation end time must be greater than simulation start time")
            if simulation_time_steps <= 0:
                raise ValueError("Simulation time steps must be greater than 0")
            if simulation_start_time < 0:
                raise ValueError("Simulation start time cannot be negative")

        if fluxes is None:
            fluxes = self._get_fluxes(network_obj, simulation_end_time, simulation_start_time, simulation_time_steps)
        color_bar = network_obj.get_color_bar()
        color_bar.set_max_value(max_value=max(fluxes.values()))
        color_bar.set_min_value(min_value=min(fluxes.values()))
        for reaction_id in fluxes:
            color = self._get_color(color_bar, fluxes[reaction_id])
            reactions = network_obj.get_reactions_list(reaction_id)
            for reaction in reactions:
                reaction.set_colors(color)
                reaction.set_thicknesses(8)
                reaction.move_arrow_head_relative_positions_by((-2, 0))

        return True

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

    @staticmethod
    def _get_fluxes(network_obj, simulation_end_time, simulation_start_time, simulation_time_steps):
        model = network_obj.save()
        r = te.loadSBMLModel(model)
        r.simulate(start=simulation_start_time, end=simulation_end_time, steps=simulation_time_steps)
        fluxes = {}
        for i, reaction in enumerate(r.getReactionIds()):
            fluxes[reaction] = float(r.getReactionRates()[i])

        return fluxes
