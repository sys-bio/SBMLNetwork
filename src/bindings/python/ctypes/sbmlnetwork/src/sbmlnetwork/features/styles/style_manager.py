import math

class StyleManager:

    def __init__(self, network_obj):

        self.network_obj = network_obj

    def set_style(self, style_name):
        valid_styles = self.network_obj.libsbmlnetwork.getListOfStyles()
        if style_name not in valid_styles:
            raise ValueError(f"Style name must be one of {valid_styles}")
        current_style_name = self.network_obj.libsbmlnetwork.getStyle()
        if style_name.lower() == "escher":
            self._set_style_to_escher()
        else:
            self.network_obj.libsbmlnetwork.setStyle(style_name)

    def _set_style_to_escher(self):
        self.network_obj.settings.show_id_as_label()
        if self.network_obj.libsbmlnetwork.setStyle("escher") == 0:
            species_list = self.network_obj.get_species_list()
            for species in species_list:
                self._update_species_features(species)
            for species in species_list:
                curves_list = species.get_curves_list()
                for curve in curves_list:
                    self._update_curve_end_point(curve)
                labels_list = species.get_labels_list()
                for label in labels_list:
                    self._update_species_label_position(label, species.get_size())
            reactions_list = self.network_obj.get_reactions_list()
            for reaction in reactions_list:
                reaction.show_reversibility(self._are_substrtes_directions_reveresed(reaction))
                self._set_reaction_center_style(reaction)
                self._add_geometric_shapes_to_multiple_curve_segments(reaction)
                labels_list = reaction.get_labels_list()
                for label in labels_list:
                    self._update_reaction_label_position(reaction, label)

            reactions_list = self.network_obj.get_reactions_list()
            reactions_list.move_arrow_head_relative_positions_to((-2, -3))
            reactions_list.set_arrow_head_sizes((4, 6))

    def _update_species_features(self, species):
        if species.get_size()[0] > 30 or species.get_size()[1] > 30:
            species.set_size((30, 30))
            species.set_font_size(12)
            species.set_font_color("black")

    def _update_curve_end_point(self, curve):
        species = curve.get_species()
        species_position = species.get_position()
        species_size = species.get_size()
        species_center = (species_position[0] + species_size[0] / 2, species_position[1] + species_size[1] / 2)
        if self._is_end_point_close_to_species(species_center, curve):
            segment = curve.get_segments()[-1]
            if abs(segment.get_end()[0] - segment.get_control_point_2()[0]) > 1e-6 or abs(segment.get_end()[1] - segment.get_control_point_2()[1]) > 1e-6:
                angle = math.atan2(segment.get_end()[1] - segment.get_control_point_2()[1], segment.get_end()[0] - segment.get_control_point_2()[0])
            else:
                angle = math.atan2(segment.get_end()[1] - segment.get_control_point_1()[1], segment.get_end()[0] - segment.get_control_point_1()[0])
            angle += math.pi
            offset = 20
            segment_end_point = (species_center[0] + (species_size[0] / 2 + offset) * math.cos(angle),
                                 species_center[1] + (species_size[1] / 2 + offset) * math.sin(angle))
            segment.set_end(segment_end_point)
            if len(curve.get_reaction().get_curves_list()) == 2:
                segment.set_control_point_2(segment_end_point)
        else:
            segment = curve.get_segments()[0]
            if abs(segment.get_start()[0] - segment.get_control_point_1()[0]) > 1e-6 or abs(segment.get_start()[1] - segment.get_control_point_1()[1]) > 1e-6:
                angle = math.atan2(segment.get_start()[1] - segment.get_control_point_1()[1], segment.get_start()[0] - segment.get_control_point_1()[0])
            else:
                angle = math.atan2(segment.get_start()[1] - segment.get_control_point_2()[1], segment.get_start()[0] - segment.get_control_point_2()[0])
            angle += math.pi
            offset = 20
            segment_start_point = (species_center[0] + (species_size[0] / 2 + offset) * math.cos(angle),
                                   species_center[1] + (species_size[1] / 2 + offset) * math.sin(angle))
            segment.set_start(segment_start_point)
            if len(curve.get_reaction().get_curves_list()) == 2:
                segment.set_control_point_1(segment_start_point)

    def _are_substrtes_directions_reveresed(self, reaction):
        curve_list = reaction.get_curves_list()
        for curve in curve_list:
            species = curve.get_species()
            species_center = (species.get_position()[0] + species.get_size()[0] / 2, species.get_position()[1] + species.get_size()[1] / 2)
            if curve.get_role() in curve.get_substrate_role_options() and not self._is_end_point_close_to_species(species_center, curve):
                return True

        return False

    @staticmethod
    def _is_end_point_close_to_species(species_center, curve):
        end_point = curve.get_segments()[-1].get_end()
        start_point = curve.get_segments()[0].get_start()
        end_point_distance = math.sqrt((species_center[0] - end_point[0]) ** 2 + (species_center[1] - end_point[1]) ** 2)
        start_point_distance = math.sqrt((species_center[0] - start_point[0]) ** 2 + (species_center[1] - start_point[1]) ** 2)
        return end_point_distance < start_point_distance

    @staticmethod
    def _update_species_label_position(label, species_size):
        relatvie_position = label.get_relative_position()
        if abs(relatvie_position[0]) <= 5 and abs(relatvie_position[1]) <= 5:
            label.move_by(species_size)
        else:
            return label.move_by((-60, 7))

    def _update_reaction_label_position(self, reaction, label):
        relatvie_position = label.get_relative_position()
        if abs(relatvie_position[0]) <= 5 and abs(relatvie_position[1]) <= 5:
            label.move_by(reaction.get_size())
        else:
            if self._is_vertical_reaction(reaction):
                if reaction.get_position()[0] + 10 < label.get_position()[0]:
                    label.move_by((reaction.get_position()[0] + 20 - label.get_position()[0], 0))
                elif label.get_position()[0] < reaction.get_position()[0] and label.get_position()[0] + label.get_size()[0] > reaction.get_position()[0]:
                    label.move_by(( reaction.get_position()[0] - (label.get_position()[0] + label.get_size()[0] + 10), 0))
                elif label.get_position()[0] + label.get_size()[0] + 10 < reaction.get_position()[0]:
                    label.move_by((reaction.get_position()[0] - (label.get_position()[0] + label.get_size()[0] + 10), 0))
            elif self._is_horizontal_reaction(reaction):
                label.move_to((reaction.get_position()[0] - label.get_size()[0] / 2, label.get_position()[1]))
                if label.get_position()[1] < reaction.get_position()[1] and abs(label.get_position()[1] - reaction.get_position()[1]) < 20:
                    label.move_by((0, reaction.get_position()[1] - (label.get_position()[1] + label.get_size()[1] + 20)))

    @staticmethod
    def _is_vertical_reaction(reaction):
        curves = reaction.get_curves_list()
        count = 0
        num_segments = 0
        for curve in curves:
            segments = curve.get_segments()
            for segment in segments:
                num_segments += 1
                if (abs(segment.get_start()[0] - segment.get_control_point_1()[0]) < 1e-6 and abs(segment.get_start()[1] - segment.get_control_point_1()[1]) > 1e-6) or \
                        (abs(segment.get_end()[0] - segment.get_control_point_2()[0]) < 1e-6 and abs(segment.get_end()[1] - segment.get_control_point_2()[1]) > 1e-6):
                    count += 1

        if count >= 0.3 * num_segments:
            return True

        return False

    @staticmethod
    def _is_horizontal_reaction(reaction):
        curves = reaction.get_curves_list()
        count = 0
        num_segments = 0
        for curve in curves:
            segments = curve.get_segments()
            for segment in segments:
                num_segments += 1
                if (abs(segment.get_start()[1] - segment.get_control_point_1()[1]) < 1e-6 and abs(segment.get_start()[0] - segment.get_control_point_1()[0]) > 1e-6) or \
                        (abs(segment.get_end()[1] - segment.get_control_point_2()[1]) < 1e-6 and abs(segment.get_end()[0] - segment.get_control_point_2()[0]) > 1e-6):
                    count += 1

        if count >= 0.3 * num_segments:
            return True

        return False

    @staticmethod
    def _set_reaction_center_style(reaction):
        reaction.switch_center_to_shapes()
        reaction.set_shape("ellipse")
        shape = reaction.get_shape()
        shape.set_radii((3.75, 3.75))
        shape.set_border_thickness(4)
        shape.set_border_color("mineshaft")
        shape.set_fill_color("waikawagray")

    @staticmethod
    def _add_geometric_shapes_to_multiple_curve_segments(reaction):
        reaction_position = reaction.get_position()
        curves = reaction.get_curves_list()
        cross_points = []
        for curve in curves:
            segments = curve.get_segments()
            if len(segments) > 1:
                cross_points.append(segments[-1].get_start())
        cross_points = list(dict.fromkeys(cross_points))
        original_shape = reaction.get_shape()
        for point in cross_points:
            shape = reaction.add_shape("ellipse")
            shape.set_relative_center((point[0] - reaction_position[0], point[1] - reaction_position[1]))
            shape.set_radii((original_shape.get_radii()[0], original_shape.get_radii()[1]))
            shape.set_border_thickness(original_shape.get_border_thickness())
            shape.set_border_color(original_shape.get_border_color())
            shape.set_fill_color(original_shape.get_fill_color())
