from ..network_elements.reaction import Reaction
from ..network_elements.species import Species

import math


class AlignBase:

    def __init__(self, net):
        self.net = net
        self.padding = 30

    def align(self, *args, **kwargs):
        pass

    @staticmethod
    def _get_extents(species_list):
        x_min = math.inf
        y_min = math.inf
        x_max = -math.inf
        y_max = -math.inf
        for species in species_list:
            if species.get_position()[0] < x_min:
                x_min = species.get_position()[0]
            if species.get_position()[1] < y_min:
                y_min = species.get_position()[1]
            if species.get_position()[0] + species.get_size()[0] > x_max:
                x_max = species.get_position()[0] + species.get_size()[0]
            if species.get_position()[1] + species.get_size()[1] > y_max:
                y_max = species.get_position()[1] + species.get_size()[1]
        return x_max, x_min, y_max, y_min

    @staticmethod
    def _get_species_order(species_list, species_order):
        if species_order is None or len(species_order) == 0:
            species_list.sort(key=lambda x: x.get_position()[0])
            return species_list

        ordered_species = []
        for species in species_order:
            if isinstance(species, str):
                for i in range(len(species_list)):
                    if species_list[i].get_species_id() == species:
                        ordered_species.append(species_list[i])
                        species_list.remove(species_list[i])
                        break
            elif isinstance(species, Species):
                for i in range(len(species_list)):
                    if species_list[i].get_id() == species.get_id():
                        ordered_species.append(species_list[i])
                        species_list.remove(species_list[i])
                        break
        ordered_species.extend(species_list)
        return ordered_species

    @staticmethod
    def _get_product_species(reaction, species_list):
        return [species for species in species_list if
                species.get_role(reaction) in species.get_product_role_options()]

    @staticmethod
    def _get_reactant_species(reaction, species_list):
        return [species for species in species_list if
                species.get_role(reaction) in species.get_substrate_role_options()]

    @staticmethod
    def _get_modifier_species(reaction, species_list):
        return [species for species in species_list if
                species.get_role(reaction) in species.get_modifier_role_options()]


class HorizontalAlign(AlignBase):

    def align(self, reaction: Reaction, center_at: tuple[float, float], spread: float,
              reactants_order: list[str or Species], products_order: list[str or Species],
              modifiers_order: list[str or Species],
              reactants_placement: str, products_placement: str, modifiers_placement: str):
        species_list = reaction.get_species_list()
        x_min, x_max, x_center, y_center = self._get_positional_parameters(center_at, species_list, spread)
        reactant_species = self._get_reactant_species(reaction, species_list)
        if len(reactant_species) == 0:
            empty_species = reaction.get_empty_species()
            if empty_species is None:
                raise ValueError(f"Reaction \"{reaction.get_reaction_id()}\" has no reactants and no empty species.")
            else:
                reactant_species = [empty_species]
        product_species = self._get_product_species(reaction, species_list)
        if len(product_species) == 0:
            empty_species = reaction.get_empty_species()
            if empty_species is None:
                raise ValueError(f"Reaction \"{reaction.get_reaction_id()}\" has no products and no empty species.")
            else:
                product_species = [empty_species]
        modifier_species = self._get_modifier_species(reaction, species_list)
        reactant_species = self._get_species_order(reactant_species, reactants_order)
        product_species = self._get_species_order(product_species, products_order)
        modifier_species = self._get_species_order(modifier_species, modifiers_order)
        try:
            reactant_species[0].move_to((x_min, y_center - 0.5 * reactant_species[0].get_size()[1]))
            product_species[-1].move_to((x_max - product_species[-1].get_size()[0], y_center - 0.5 * product_species[-1].get_size()[1]))
        except ValueError:
            raise ValueError(f"Using this 'center_at' or 'spread_width' for the reaction \"{reaction.get_reaction_id()}\" will cause the species to be placed outside the canvas.")

        if len(reactant_species) == 1 and len(product_species) == 1 and len(modifier_species) == 0:
            return True

        self._set_reaction_center_features(reaction, x_center, y_center)
        self._set_first_reactant_features(reactant_species, reaction, x_center, y_center)
        self._set_last_product_features(product_species, reaction, x_center, y_center)

        if len(reactant_species) > 1 and not self._set_extra_reactant_features(reactant_species, reaction, x_center,
                                                                               y_center, reactants_placement):
            return False

        if len(product_species) > 1 and not self._set_extra_product_features(product_species, reaction, x_center,
                                                                             y_center, products_placement):
            return False

        if len(modifier_species) > 0 and not self._set_modifier_features(modifier_species, reaction, x_center, y_center,
                                                                         modifiers_placement):
            return False

        return True

    def _set_last_product_features(self, product_species, reaction, x_center, y_center):
        curves = reaction.get_curves_list(product_species[-1])
        for curve in curves:
            while (len(curve.get_segments()) > 1):
                curve.remove_segment(curve.get_segment())
            curve_segment = curve.get_segment()
            curve_segment.set_start((x_center, y_center))
            curve_segment.set_end((product_species[-1].get_position()[0] - self.padding,
                                   product_species[-1].get_position()[1] + 0.5 * product_species[-1].get_size()[1]))
            curve_segment.set_control_point_1(curve_segment.get_start())
            curve_segment.set_control_point_2(curve_segment.get_end())

        return True

    def _set_first_reactant_features(self, reactant_species, reaction, x_center, y_center):
        curves = reaction.get_curves_list(reactant_species[0])
        for curve in curves:
            while len(curve.get_segments()) > 1:
                curve.remove_segment(curve.get_segment())
            curve_segment = curve.get_segment()
            curve_segment.set_start((x_center, y_center))
            curve_segment.set_end(
                (reactant_species[0].get_position()[0] + reactant_species[0].get_size()[0] + self.padding,
                 reactant_species[0].get_position()[1] + 0.5 * reactant_species[0].get_size()[1]))
            curve_segment.set_control_point_1(curve_segment.get_start())
            curve_segment.set_control_point_2(curve_segment.get_end())

        return True

    def _get_positional_parameters(self, center_at, species_list, spread_width):
        x_max, x_min, y_max, y_min = self._get_extents(species_list)
        x_center = (x_min + x_max) / 2
        y_center = (y_min + y_max) / 2
        if center_at is not None:
            x_min = (x_min - x_center) + center_at[0]
            x_max = (x_max - x_center) + center_at[0]
            x_center = center_at[0]
            y_min = (y_min - y_center) + center_at[1]
            y_max = (y_max - y_center) + center_at[1]
            y_center = center_at[1]
        if spread_width is not None:
            x_min = x_center - spread_width / 2
            x_max = x_center + spread_width / 2

        if center_at is None and spread_width is None:
            if x_min < 0:
                x_center = x_center - x_min + 100
                x_min = 100
            if y_min < 0:
                y_center = y_center - y_min + 100
                y_min = 100
            if x_max - x_min < 200:
                x_max = x_min + 200
                x_center = (x_min + x_max) / 2

        return x_min, x_max, x_center, y_center

    def _set_reaction_center_features(self, reaction, x_center, y_center):
        reaction.set_position((x_center, y_center))
        reaction.get_labels_list().set_positions((x_center, y_center + self.padding))
        return True

    def _set_extra_reactant_features(self, reactant_species, reaction, x_center, y_center, species_placement):
        default_horizontal_padding = 0.5 * max([species.get_size()[0] for species in reactant_species])
        default_vertical_padding = 2 * max([species.get_size()[1] for species in reactant_species])
        for i, species in enumerate(reactant_species):
            if i == 0:
                continue
            new_position_x = reactant_species[i - 1].get_position()[0] + reactant_species[i - 1].get_size()[
                0] + default_horizontal_padding
            new_position_y = y_center + default_vertical_padding
            new_curve_position_x = new_position_x + 0.5 * species.get_size()[0]
            new_curve_position_y = new_position_y - self.padding
            if species_placement == "up":
                new_position_y = y_center - species.get_size()[1] - default_vertical_padding
                new_curve_position_y = new_position_y + species.get_size()[1] + self.padding
            elif species_placement == "both":
                new_position_x = reactant_species[i - 1].get_position()[0] + (
                        (i % 2) * (reactant_species[i - 1].get_size()[0] + default_horizontal_padding))
                new_curve_position_x = new_position_x + 0.5 * species.get_size()[0]
                if (i - 1) % 2 == 0:
                    new_position_y = y_center - species.get_size()[1] - default_vertical_padding
                    new_curve_position_y = new_position_y + species.get_size()[1] + self.padding
                else:
                    new_position_y = y_center + default_vertical_padding
                    new_curve_position_y = new_position_y - self.padding
            try:
                species.move_to((new_position_x, new_position_y))
            except ValueError:
                raise ValueError(f"Using this 'center_at' or 'spread_width' for the reaction \"{reaction.get_reaction_id()}\" will cause the species to be placed outside the canvas.")

            curves = reaction.get_curves_list(species=species)
            for curve in curves:
                while (len(curve.get_segments()) > 1):
                    curve.remove_segment(curve.get_segment())
                curve_segment = curve.get_segment()
                curve_segment.set_start((x_center, y_center))
                curve_segment.set_end((new_curve_position_x, new_curve_position_y))
                curve_segment.set_control_point_1((species.get_position()[0] + 0.5 * species.get_size()[0], y_center))
                curve_segment.set_control_point_2((species.get_position()[0] + 0.5 * species.get_size()[0], y_center))

        return True

    def _set_extra_product_features(self, product_species, reaction, x_center, y_center, species_placement):
        default_horizontal_padding = 0.5 * max([species.get_size()[0] for species in product_species])
        default_vertical_padding = 2 * max([species.get_size()[1] for species in product_species])
        product_species.reverse()
        for i, species in enumerate(product_species):
            if i == 0:
                continue
            new_position_x = product_species[i - 1].get_position()[0] - product_species[i].get_size()[
                0] - default_horizontal_padding
            new_position_y = y_center + default_vertical_padding
            new_curve_position_x = new_position_x + 0.5 * species.get_size()[0]
            new_curve_position_y = new_position_y - self.padding
            if species_placement == "up":
                new_position_y = y_center - species.get_size()[1] - default_vertical_padding
                new_curve_position_y = new_position_y + species.get_size()[1] + self.padding
            elif species_placement == "both":
                new_position_x = product_species[i - 1].get_position()[0] - (
                        (i % 2) * (product_species[i].get_size()[0] + default_horizontal_padding))
                new_curve_position_x = new_position_x + 0.5 * species.get_size()[0]
                if (i - 1) % 2 == 0:
                    new_position_y = y_center - species.get_size()[1] - default_vertical_padding
                    new_curve_position_y = new_position_y + species.get_size()[1] + self.padding
                else:
                    new_position_y = y_center + default_vertical_padding
                    new_curve_position_y = new_position_y - self.padding
            try:
                species.move_to((new_position_x, new_position_y))
            except ValueError:
                raise ValueError(f"Using this 'center_at' or 'spread_width' for the reaction \"{reaction.get_reaction_id()}\" will cause the species to be placed outside the canvas.")

            curves = reaction.get_curves_list(species=species)
            for curve in curves:
                while (len(curve.get_segments()) > 1):
                    curve.remove_segment(curve.get_segment())
                curve_segment = curve.get_segment()
                curve_segment.set_start((x_center, y_center))
                curve_segment.set_end((new_curve_position_x, new_curve_position_y))
                curve_segment.set_control_point_1((species.get_position()[0] + 0.5 * species.get_size()[0], y_center))
                curve_segment.set_control_point_2((species.get_position()[0] + 0.5 * species.get_size()[0], y_center))

        return True

    def _set_modifier_features(self, modifier_species, reaction, x_center, y_center, species_placement):
        default_horizontal_padding = 0.5 * max([species.get_size()[0] for species in modifier_species])
        default_vertical_padding = 4 * max([species.get_size()[1] for species in modifier_species])
        for i, species in enumerate(modifier_species):
            arrow_head_size = (0, 0)
            arrow_head = reaction.get_curves_list(species=species)[0].get_arrow_head()
            if arrow_head is not None:
                arrow_head_size = arrow_head.get_size()
            offset_unit = species.get_size()[0] + default_horizontal_padding
            new_position_x = x_center - 0.5 * species.get_size()[0]
            new_position_y = y_center + default_vertical_padding
            new_reaction_point_x = x_center
            new_reaction_point_y = y_center + 0.5 * arrow_head_size[0]
            if len(modifier_species) % 2 == 1:
                if i == 0:
                    pass
                elif i % 2 == 1:
                    new_position_x += offset_unit * ((i + 1) // 2)
                    new_reaction_point_x += 1.5 * arrow_head_size[1] * ((i + 1) // 2)
                else:
                    new_position_x += - offset_unit * (i // 2)
                    new_reaction_point_x += - 1.5 * arrow_head_size[1] * (i // 2)
            else:
                if i % 2 == 0:
                    new_position_x += - offset_unit * ((i // 2) + 0.5)
                    new_reaction_point_x += - 1.5 * arrow_head_size[1] * ((i // 2) + 0.5)
                else:
                    new_position_x += offset_unit * ((i // 2) + 0.5)
                    new_reaction_point_x += 1.5 * arrow_head_size[1] * ((i // 2) + 0.5)
            new_curve_position_x = new_position_x + 0.5 * species.get_size()[0]
            new_curve_position_y = new_position_y - self.padding
            if species_placement == "up":
                new_position_y = y_center - default_vertical_padding
                new_curve_position_y = new_position_y + species.get_size()[1] + self.padding
                new_reaction_point_y = y_center - 0.5 * arrow_head_size[0]
            elif species_placement == "both":
                pass
                # ToDo: Implement the case when the placement is "both"

            try:
                species.move_to((new_position_x, new_position_y))
            except ValueError:
                raise ValueError(f"Using this 'center_at' or 'spread_width' for the reaction \"{reaction.get_reaction_id()}\" will cause the species to be placed outside the canvas.")

            curves = reaction.get_curves_list(species=species)
            for curve in curves:
                while (len(curve.get_segments()) > 1):
                    curve.remove_segment(curve.get_segment())
                curve_segment = curve.get_segment()
                curve_segment.set_start((new_curve_position_x, new_curve_position_y))
                curve_segment.set_end((new_reaction_point_x, new_reaction_point_y))
                curve_segment.set_control_point_1(curve_segment.get_start())
                curve_segment.set_control_point_2(curve_segment.get_end())

        return True


class VerticalAlign(AlignBase):

    def align(self, reaction: Reaction, center_at: tuple[float, float], spread: float,
              reactants_order: list[str or Species], products_order: list[str or Species],
              modifiers_order: list[str or Species],
              reactants_placement: str, products_placement: str, modifiers_placement: str):
        species_list = reaction.get_species_list()
        y_min, y_max, x_center, y_center = self._get_positional_parameters(center_at, species_list, spread)
        reactant_species = self._get_reactant_species(reaction, species_list)
        product_species = self._get_product_species(reaction, species_list)
        modifier_species = self._get_modifier_species(reaction, species_list)
        reactant_species = self._get_species_order(reactant_species, reactants_order)
        product_species = self._get_species_order(product_species, products_order)
        modifier_species = self._get_species_order(modifier_species, modifiers_order)
        try :
            reactant_species[0].move_to((x_center - 0.5 * reactant_species[0].get_size()[0], y_min))
            product_species[-1].move_to((x_center - 0.5 * product_species[-1].get_size()[0], y_max - product_species[-1].get_size()[1]))
        except ValueError:
            raise ValueError(f"Using this 'center_at' or 'spread_height' for the reaction \"{reaction.get_reaction_id()}\" will cause the species to be placed outside the canvas.")

        if len(reactant_species) == 1 and len(product_species) == 1:
            return True

        self._set_reaction_center_features(reaction, x_center, y_center)
        self._set_first_reactant_features(reactant_species, reaction, x_center, y_center)
        self._set_last_product_features(product_species, reaction, x_center, y_center)

        if len(reactant_species) > 1 and not self._set_extra_reactant_features(reactant_species, reaction, x_center,
                                                                               y_center, reactants_placement):
            return False

        if len(product_species) > 1 and not self._set_extra_product_features(product_species, reaction, x_center,
                                                                             y_center, products_placement):
            return False

        if len(modifier_species) > 0 and not self._set_modifier_features(modifier_species, reaction, x_center, y_center,
                                                                         modifiers_placement):
            return False

        return True

    def _set_last_product_features(self, product_species, reaction, x_center, y_center):
        curves = reaction.get_curves_list(product_species[-1])
        for curve in curves:
            while (len(curve.get_segments()) > 1):
                curve.remove_segment(curve.get_segment())
            curve_segment = curve.get_segment()
            curve_segment.set_start((x_center, y_center))
            curve_segment.set_end((product_species[-1].get_position()[0] + 0.5 * product_species[-1].get_size()[0],
                                   product_species[-1].get_position()[1] - self.padding))
            curve_segment.set_control_point_1(curve_segment.get_start())
            curve_segment.set_control_point_2(curve_segment.get_end())

        return True

    def _set_first_reactant_features(self, reactant_species, reaction, x_center, y_center):
        curves = reaction.get_curves_list(reactant_species[0])
        for curve in curves:
            while len(curve.get_segments()) > 1:
                curve.remove_segment(curve.get_segment())
            curve_segment = curve.get_segment()
            curve_segment.set_start((x_center, y_center))
            curve_segment.set_end((reactant_species[0].get_position()[0] + 0.5 * reactant_species[0].get_size()[0],
                                   reactant_species[0].get_position()[1] + reactant_species[0].get_size()[
                                       1] + self.padding))
            curve_segment.set_control_point_1(curve_segment.get_start())
            curve_segment.set_control_point_2(curve_segment.get_end())

        return True

    def _get_positional_parameters(self, center_at, species_list, spread_height):
        x_max, x_min, y_max, y_min = self._get_extents(species_list)
        x_center = (x_min + x_max) / 2
        y_center = (y_min + y_max) / 2
        if center_at is not None:
            x_min = (x_min - x_center) + center_at[0]
            x_max = (x_max - x_center) + center_at[0]
            x_center = center_at[0]
            y_min = (y_min - y_center) + center_at[1]
            y_max = (y_max - y_center) + center_at[1]
            y_center = center_at[1]
        if spread_height is not None:
            y_min = y_center - spread_height / 2
            y_max = y_center + spread_height / 2

        if center_at is None and spread_height is None:
            if x_min < 0:
                x_center = x_center - x_min + 100
                x_min = 100
            if y_min < 0:
                y_center = y_center - y_min + 100
                y_min = 100
            if y_max - y_min < 200:
                y_max = y_min + 200
                y_center = (y_min + y_max) / 2

        return y_min, y_max, x_center, y_center

    def _set_reaction_center_features(self, reaction, x_center, y_center):
        reaction.set_position((x_center, y_center))
        reaction.get_labels_list().set_positions((x_center - self.padding, y_center))
        return True

    def _set_extra_reactant_features(self, reactant_species, reaction, x_center, y_center, species_placement):
        default_horizontal_padding = 1.5 * max([species.get_size()[0] for species in reactant_species])
        default_vertical_padding = max([species.get_size()[1] for species in reactant_species])
        for i, species in enumerate(reactant_species):
            if i == 0:
                continue
            new_position_x = x_center + default_horizontal_padding
            new_position_y = reactant_species[i - 1].get_position()[1] + reactant_species[i - 1].get_size()[
                1] + default_vertical_padding
            new_curve_position_x = new_position_x - self.padding
            new_curve_position_y = new_position_y + 0.5 * species.get_size()[1]
            if species_placement == "left":
                new_position_x = x_center - default_horizontal_padding - species.get_size()[0]
                new_curve_position_x = new_position_x + species.get_size()[0] + self.padding
            elif species_placement == "both":
                new_position_y = reactant_species[i - 1].get_position()[1] + (
                        (i % 2) * (reactant_species[i - 1].get_size()[1] + default_vertical_padding))
                new_curve_position_y = new_position_y + 0.5 * species.get_size()[1]
                if (i - 1) % 2 == 0:
                    new_position_x = x_center - species.get_size()[0] - default_horizontal_padding
                    new_curve_position_x = new_position_x + species.get_size()[0] + self.padding
                else:
                    new_position_x = x_center + default_horizontal_padding
                    new_curve_position_x = new_position_x - self.padding
            try:
                species.move_to((new_position_x, new_position_y))
            except ValueError:
                raise ValueError(f"Using this 'center_at' or 'spread_height' for the reaction \"{reaction.get_reaction_id()}\" will cause the species to be placed outside the canvas.")

            curves = reaction.get_curves_list(species=species)
            for curve in curves:
                while (len(curve.get_segments()) > 1):
                    curve.remove_segment(curve.get_segment())
                curve_segment = curve.get_segment()
                curve_segment.set_start((x_center, y_center))
                curve_segment.set_end((new_curve_position_x, new_curve_position_y))
                curve_segment.set_control_point_1((x_center, species.get_position()[1] + 0.5 * species.get_size()[1]))
                curve_segment.set_control_point_2((x_center, species.get_position()[1] + 0.5 * species.get_size()[1]))

        return True

    def _set_extra_product_features(self, product_species, reaction, x_center, y_center, species_placement):
        default_horizontal_padding = 1.5 * max([species.get_size()[0] for species in product_species])
        default_vertical_padding = max([species.get_size()[1] for species in product_species])
        product_species.reverse()
        for i, species in enumerate(product_species):
            if i == 0:
                continue
            new_position_x = x_center + default_horizontal_padding
            new_position_y = product_species[i - 1].get_position()[1] - product_species[i].get_size()[
                1] - default_vertical_padding
            new_curve_position_x = new_position_x - self.padding
            new_curve_position_y = new_position_y + 0.5 * species.get_size()[1]
            if species_placement == "left":
                new_position_x = x_center - default_horizontal_padding - species.get_size()[0]
                new_curve_position_x = new_position_x + species.get_size()[0] + self.padding
            elif species_placement == "both":
                new_position_y = product_species[i - 1].get_position()[1] - (
                        (i % 2) * (product_species[i].get_size()[1] + default_vertical_padding))
                new_curve_position_y = new_position_y + 0.5 * species.get_size()[1]
                if (i - 1) % 2 == 0:
                    new_position_x = x_center - species.get_size()[0] - default_horizontal_padding
                    new_curve_position_x = new_position_x + species.get_size()[0] + self.padding
                else:
                    new_position_x = x_center + default_horizontal_padding
                    new_curve_position_x = new_position_x - self.padding
            try:
                species.move_to((new_position_x, new_position_y))
            except ValueError:
                raise ValueError(f"Using this 'center_at' or 'spread_height' for the reaction \"{reaction.get_reaction_id()}\" will cause the species to be placed outside the canvas.")

            curves = reaction.get_curves_list(species=species)
            for curve in curves:
                while (len(curve.get_segments()) > 1):
                    curve.remove_segment(curve.get_segment())
                curve_segment = curve.get_segment()
                curve_segment.set_start((x_center, y_center))
                curve_segment.set_end((new_curve_position_x, new_curve_position_y))
                curve_segment.set_control_point_1((x_center, species.get_position()[1] + 0.5 * species.get_size()[1]))
                curve_segment.set_control_point_2((x_center, species.get_position()[1] + 0.5 * species.get_size()[1]))

        return True

    def _set_modifier_features(self, modifier_species, reaction, x_center, y_center, species_placement):
        default_horizontal_padding = 3 * max([species.get_size()[0] for species in modifier_species])
        default_vertical_padding = max([species.get_size()[1] for species in modifier_species])
        for i, species in enumerate(modifier_species):
            arrow_head_size = (0, 0)
            arrow_head = reaction.get_curves_list(species=species)[0].get_arrow_head()
            if arrow_head is not None:
                arrow_head_size = arrow_head.get_size()
            offset_unit = species.get_size()[1] + default_vertical_padding
            new_position_x = x_center + default_horizontal_padding
            new_position_y = y_center - 0.5 * species.get_size()[1]
            new_reaction_point_x = x_center + 0.5 * arrow_head.get_size()[0]
            new_reaction_point_y = y_center
            if len(modifier_species) % 2 == 1:
                if i == 0:
                    pass
                elif i % 2 == 1:
                    new_position_y += offset_unit * ((i + 1) // 2)
                    new_reaction_point_y += 1.5 * arrow_head_size[1] * ((i + 1) // 2)
                else:
                    new_position_y += - offset_unit * (i // 2)
                    new_reaction_point_y += - 1.5 * arrow_head_size[1] * (i // 2)
            else:
                if i % 2 == 0:
                    new_position_y += - offset_unit * (((i) // 2) + 0.5)
                    new_reaction_point_y += - 1.5 * arrow_head_size[1] * (((i) // 2) + 0.5)
                else:
                    new_position_y += offset_unit * (((i) // 2) + 0.5)
                    new_reaction_point_y += 1.5 * arrow_head_size[1] * (((i) // 2) + 0.5)
            new_curve_position_x = new_position_x - self.padding
            new_curve_position_y = new_position_y + 0.5 * species.get_size()[1]
            if species_placement == "left":
                new_position_x = x_center - default_horizontal_padding - species.get_size()[0]
                new_curve_position_x = new_position_x + species.get_size()[0] + self.padding
                new_reaction_point_x = x_center - 0.5 * arrow_head_size[0]
            elif species_placement == "both":
                pass
                # ToDo: Implement the case when the placement is "both"

            try:
                species.move_to((new_position_x, new_position_y))
            except ValueError:
                raise ValueError(f"Using this 'center_at' or 'spread_height' for the reaction \"{reaction.get_reaction_id()}\" will cause the species to be placed outside the canvas.")

            curves = reaction.get_curves_list(species=species)
            for curve in curves:
                while (len(curve.get_segments()) > 1):
                    curve.remove_segment(curve.get_segment())
                curve_segment = curve.get_segment()
                curve_segment.set_start((new_curve_position_x, new_curve_position_y))
                curve_segment.set_end((new_reaction_point_x, new_reaction_point_y))
                curve_segment.set_control_point_1((curve_segment.get_start()))
                curve_segment.set_control_point_2((curve_segment.get_end()))

        return True


class CircleAlign(AlignBase):

    def align(self, reaction: Reaction, center_at: tuple[float, float], radius: float, arc_start: float, arc_end: float, clockwise: bool,
              reactants_order: list[str or Species], products_order: list[str or Species],
              modifiers_order: list[str or Species],
              reactants_placement: str, products_placement: str, modifiers_placement: str):
        arc_start_rad, arc_end_rad = self._get_arc_parameters(arc_start, arc_end)
        species_list = reaction.get_species_list()
        x_center, y_center, radius = self._get_positional_parameters(center_at, species_list, radius)
        reactant_species = self._get_reactant_species(reaction, species_list)
        product_species = self._get_product_species(reaction, species_list)
        modifier_species = self._get_modifier_species(reaction, species_list)
        reactant_species = self._get_species_order(reactant_species, reactants_order)
        product_species = self._get_species_order(product_species, products_order)
        modifier_species = self._get_species_order(modifier_species, modifiers_order)
        try:
            reactant_species[0].move_to(
                (x_center + radius * math.cos(arc_start_rad) - 0.5 * reactant_species[0].get_size()[0],
                 y_center - radius * math.sin(arc_start_rad) - 0.5 * reactant_species[0].get_size()[1]))
            product_species[-1].move_to(
                (x_center + radius * math.cos(arc_end_rad) - 0.5 * product_species[-1].get_size()[0],
                 y_center - radius * math.sin(arc_end_rad) - 0.5 * product_species[-1].get_size()[1]))
        except ValueError:
            raise ValueError(f"Using this 'center_at' or 'radius' for the reaction \"{reaction.get_reaction_id()}\" will cause the species to be placed outside the canvas.")

        self._set_reaction_center_features(reaction, x_center, y_center, radius, arc_start_rad, arc_end_rad, clockwise)
        self._set_first_reactant_features(reactant_species, reaction, x_center, y_center, radius, arc_start_rad,
                                          arc_end_rad, clockwise)
        self._set_last_product_features(product_species, reaction, x_center, y_center, radius, arc_start_rad,
                                        arc_end_rad, clockwise)

        if len(reactant_species) == 1 and len(product_species) == 1:
            return True

        if len(reactant_species) > 1 and not self._set_extra_reactant_features(reactant_species, reaction, x_center,
                                                                               y_center, radius, arc_start_rad,
                                                                               arc_end_rad, clockwise, reactants_placement):
            return False

        if len(product_species) > 1 and not self._set_extra_product_features(product_species, reaction, x_center,
                                                                             y_center, radius, arc_start_rad,
                                                                             arc_end_rad, clockwise, products_placement):
            return False

        if len(modifier_species) > 0 and not self._set_modifier_features(modifier_species, reaction, x_center, y_center,
                                                                         radius, arc_start_rad, arc_end_rad, clockwise,
                                                                         modifiers_placement):
            return False

        return True

    def _set_reaction_center_features(self, reaction, x_center, y_center, radius, arc_start_rad, arc_end_rad, clockwise):
        arc_reaction_point = self._get_arc_reaction_point(arc_start_rad, arc_end_rad, clockwise)
        reaction.set_position(
            (x_center + radius * math.cos(arc_reaction_point), y_center - radius * math.sin(arc_reaction_point)))
        reaction.get_labels_list().set_positions((x_center + radius * math.cos(arc_reaction_point),
                                                  y_center - radius * math.sin(arc_reaction_point) + self.padding))
        return True

    def _set_first_reactant_features(self, reactant_species, reaction, x_center, y_center, radius, arc_start_rad,
                                     arc_end_rad, clockwise):
        arc_reaction_point = self._get_arc_reaction_point(arc_start_rad, arc_end_rad, clockwise)
        curves = reaction.get_curves_list(reactant_species[0])
        for curve in curves:
            while len(curve.get_segments()) > 1:
                curve.remove_segment(curve.get_segment())
            offset_x, offset_y = self._get_reactant_point_offsets(arc_start_rad, reactant_species[0], clockwise)
            curve_segment = curve.get_segment()
            start_x = x_center + radius * math.cos(arc_reaction_point)
            start_y = y_center - radius * math.sin(arc_reaction_point)
            curve_segment.set_start((start_x, start_y))
            end_x = x_center + radius * math.cos(arc_start_rad) + offset_x
            end_y = y_center - radius * math.sin(arc_start_rad) + offset_y
            curve_segment.set_end((end_x, end_y))
            if clockwise and arc_start_rad < arc_reaction_point:
                arc_start_rad += 2 * math.pi
            elif not clockwise and arc_start_rad > arc_reaction_point:
                arc_reaction_point += 2 * math.pi
            delta = arc_start_rad - arc_reaction_point
            k = (4.0 / 3.0) * math.tan(delta / 4.0)
            p1 = (x_center + radius * (math.cos(arc_reaction_point) - k * math.sin(arc_reaction_point)),
                  y_center - radius * (math.sin(arc_reaction_point) + k * math.cos(arc_reaction_point)))
            p2 = (x_center + radius * (math.cos(arc_start_rad) + k * math.sin(arc_start_rad)),
                  y_center - radius * (math.sin(arc_start_rad) - k * math.cos(arc_start_rad)))
            curve_segment.set_control_point_1(p1)
            curve_segment.set_control_point_2(p2)

        return True

    def _set_last_product_features(self, product_species, reaction, x_center, y_center, radius, arc_start_rad,
                                   arc_end_rad, clockwise):
        arc_reaction_point = self._get_arc_reaction_point(arc_start_rad, arc_end_rad, clockwise)
        curves = reaction.get_curves_list(product_species[-1])
        for curve in curves:
            while len(curve.get_segments()) > 1:
                curve.remove_segment(curve.get_segment())
            offset_x, offset_y = self._get_product_point_offsets(arc_end_rad, product_species[-1], clockwise)
            curve_segment = curve.get_segment()
            start_x = x_center + radius * math.cos(arc_reaction_point)
            start_y = y_center - radius * math.sin(arc_reaction_point)
            curve_segment.set_start((start_x, start_y))
            end_x = x_center + radius * math.cos(arc_end_rad) + offset_x
            end_y = y_center - radius * math.sin(arc_end_rad) + offset_y
            curve_segment.set_end((end_x, end_y))
            if clockwise and arc_reaction_point < arc_end_rad:
                arc_reaction_point += 2 * math.pi
            elif not clockwise and arc_reaction_point > arc_end_rad:
                arc_end_rad += 2 * math.pi
            delta = arc_end_rad - arc_reaction_point
            k = (4.0 / 3.0) * math.tan(delta / 4.0)
            p1 = (x_center + radius * (math.cos(arc_reaction_point) - k * math.sin(arc_reaction_point)),
                  y_center - radius * (math.sin(arc_reaction_point) + k * math.cos(arc_reaction_point)))
            p2 = (x_center + radius * (math.cos(arc_end_rad) + k * math.sin(arc_end_rad)),
                  y_center - radius * (math.sin(arc_end_rad) - k * math.cos(arc_end_rad)))
            curve_segment.set_control_point_1(p1)
            curve_segment.set_control_point_2(p2)

        return True

    def _set_extra_reactant_features(self, reactant_species, reaction, x_center, y_center, radius, arc_start_rad,
                                     arc_end_rad, clockwise, species_placement):
        arc_reaction_point = self._get_arc_reaction_point(arc_start_rad, arc_end_rad, clockwise)
        max_width = max([species.get_size()[0] for species in reactant_species])
        max_height = max([species.get_size()[1] for species in reactant_species])
        default_radial_padding = 2 * math.sqrt((max_width ** 2 + max_height ** 2) / 2)
        if clockwise:
            default_angular_padding_arc = -min(((arc_end_rad - arc_start_rad) / (len(reactant_species) - 1)),
                                               (2 * math.sqrt((max_width ** 2 + max_height ** 2) / 2) / radius))
        else:
            default_angular_padding_arc = min(((arc_end_rad - arc_start_rad) / (len(reactant_species) - 1)),
                                              (2 * math.sqrt((max_width ** 2 + max_height ** 2) / 2) / radius))
        control_point_angular_padding_arc = 0.5 * default_angular_padding_arc
        for i, species in enumerate(reactant_species):
            if i == 0:
                continue
            new_position_x = x_center + (radius + default_radial_padding) * math.cos(
                arc_start_rad + i * default_angular_padding_arc)
            new_position_y = y_center - (radius + default_radial_padding) * math.sin(
                arc_start_rad + i * default_angular_padding_arc)
            new_curve_control_point_1_x = x_center + radius * math.cos(arc_start_rad + i * default_angular_padding_arc)
            new_curve_start_position_x = x_center + radius * math.cos(
                arc_start_rad + i * (default_angular_padding_arc) + control_point_angular_padding_arc)
            new_curve_control_point_1_y = y_center - radius * math.sin(arc_start_rad + i * default_angular_padding_arc)
            new_curve_start_position_y = y_center - radius * math.sin(
                arc_start_rad + i * (default_angular_padding_arc) + control_point_angular_padding_arc)
            offset_x, offset_y = self._get_extra_reactant_point_offsets(arc_start_rad + i * default_angular_padding_arc,
                                                                        species)
            if species_placement == "in":
                new_position_x = x_center + (radius - default_radial_padding) * math.cos(
                    arc_start_rad + i * default_angular_padding_arc)
                new_position_y = y_center - (radius - default_radial_padding) * math.sin(
                    arc_start_rad + i * default_angular_padding_arc)
                offset_x = -offset_x
                offset_y = -offset_y
            elif species_placement == "both":
                if (i - 1) % 2 == 0:
                    new_position_x = x_center + (radius + default_radial_padding) * math.cos(
                        arc_start_rad + ((i / 2) + 1) * default_angular_padding_arc)
                    new_position_y = y_center - (radius + default_radial_padding) * math.sin(
                        arc_start_rad + ((i / 2) + 1) * default_angular_padding_arc)
                    new_curve_control_point_1_x = x_center + radius * math.cos(
                        arc_start_rad + ((i / 2) + 1) * default_angular_padding_arc)
                    new_curve_control_point_1_y = y_center - radius * math.sin(
                        arc_start_rad + ((i / 2) + 1) * default_angular_padding_arc)
                    new_curve_start_position_x = x_center + radius * math.cos(
                        arc_start_rad + ((i / 2) + 1) * default_angular_padding_arc + control_point_angular_padding_arc)
                    new_curve_start_position_y = y_center - radius * math.sin(
                        arc_start_rad + ((i / 2) + 1) * default_angular_padding_arc + control_point_angular_padding_arc)
                else:
                    new_position_x = x_center + (radius - default_radial_padding) * math.cos(
                        arc_start_rad + (((i - 1) / 2) + 1) * default_angular_padding_arc)
                    new_position_y = y_center - (radius - default_radial_padding) * math.sin(
                        arc_start_rad + (((i - 1) / 2) + 1) * default_angular_padding_arc)
                    new_curve_control_point_1_x = x_center + radius * math.cos(
                        arc_start_rad + (((i - 1) / 2) + 1) * default_angular_padding_arc)
                    new_curve_control_point_1_y = y_center - radius * math.sin(
                        arc_start_rad + (((i - 1) / 2) + 1) * default_angular_padding_arc)
                    new_curve_start_position_x = x_center + radius * math.cos(arc_start_rad + (
                            ((i - 1) / 2) + 1) * default_angular_padding_arc + control_point_angular_padding_arc)
                    new_curve_start_position_y = y_center - radius * math.sin(arc_start_rad + (
                            ((i - 1) / 2) + 1) * default_angular_padding_arc + control_point_angular_padding_arc)
                    offset_x = -offset_x
                    offset_y = -offset_y
            new_curve_end_position_x = new_position_x + offset_x
            new_curve_end_position_y = new_position_y + offset_y
            try:
                species.move_to((new_position_x - 0.5 * species.get_size()[0], new_position_y - 0.5 * species.get_size()[1]))
            except ValueError:
                raise ValueError(f"Using this 'center_at' or 'radius' for the reaction \"{reaction.get_reaction_id()}\" will cause the species to be placed outside the canvas.")

            curves = reaction.get_curves_list(species=species)
            for curve in curves:
                while (len(curve.get_segments()) > 1):
                    curve.remove_segment(curve.get_segment())
                curve_segment = curve.get_segment()
                curve_segment.set_start((new_curve_start_position_x, new_curve_start_position_y))
                curve_segment.set_end((new_curve_end_position_x, new_curve_end_position_y))
                curve_segment.set_control_point_1((new_curve_control_point_1_x, new_curve_control_point_1_y))
                curve_segment.set_control_point_2((new_curve_end_position_x, new_curve_end_position_y))

        return True

    def _set_extra_product_features(self, product_species, reaction, x_center, y_center, radius, arc_start_rad,
                                    arc_end_rad, clockwise, species_placement):
        arc_reaction_point = self._get_arc_reaction_point(arc_start_rad, arc_end_rad, clockwise)
        max_width = max([species.get_size()[0] for species in product_species])
        max_height = max([species.get_size()[1] for species in product_species])
        default_radial_padding = 2 * math.sqrt((max_width ** 2 + max_height ** 2) / 2)
        if clockwise:
            default_angular_padding_arc = -min(((arc_end_rad - arc_start_rad) / (len(product_species) - 1)),
                                               (2 * math.sqrt((max_width ** 2 + max_height ** 2) / 2) / radius))
        else:
            default_angular_padding_arc = min(((arc_end_rad - arc_start_rad) / (len(product_species) - 1)),
                                              (2 * math.sqrt((max_width ** 2 + max_height ** 2) / 2) / radius))
        control_point_angular_padding_arc = 0.5 * default_angular_padding_arc
        product_species.reverse()
        for i, species in enumerate(product_species):
            if i == 0:
                continue
            new_position_x = x_center + (radius + default_radial_padding) * math.cos(
                arc_end_rad - i * default_angular_padding_arc)
            new_position_y = y_center - (radius + default_radial_padding) * math.sin(
                arc_end_rad - i * default_angular_padding_arc)
            new_curve_control_point_1_x = x_center + radius * math.cos(arc_end_rad - i * default_angular_padding_arc)
            new_curve_start_position_x = x_center + radius * math.cos(
                arc_end_rad - i * (default_angular_padding_arc) - control_point_angular_padding_arc)
            new_curve_control_point_1_y = y_center - radius * math.sin(arc_end_rad - i * default_angular_padding_arc)
            new_curve_start_position_y = y_center - radius * math.sin(
                arc_end_rad - i * (default_angular_padding_arc) - control_point_angular_padding_arc)
            offset_x, offset_y = self._get_extra_product_point_offsets(arc_end_rad - i * default_angular_padding_arc,
                                                                       species)
            if species_placement == "in":
                new_position_x = x_center + (radius - default_radial_padding) * math.cos(
                    arc_end_rad - i * default_angular_padding_arc)
                new_position_y = y_center - (radius - default_radial_padding) * math.sin(
                    arc_end_rad - i * default_angular_padding_arc)
                offset_x = -offset_x
                offset_y = -offset_y
            elif species_placement == "both":
                if (i - 1) % 2 == 0:
                    new_position_x = x_center + (radius + default_radial_padding) * math.cos(
                        arc_end_rad - ((i / 2) + 1) * default_angular_padding_arc)
                    new_position_y = y_center - (radius + default_radial_padding) * math.sin(
                        arc_end_rad - ((i / 2) + 1) * default_angular_padding_arc)
                    new_curve_control_point_1_x = x_center + radius * math.cos(
                        arc_end_rad - ((i / 2) + 1) * default_angular_padding_arc)
                    new_curve_control_point_1_y = y_center - radius * math.sin(
                        arc_end_rad - ((i / 2) + 1) * default_angular_padding_arc)
                    new_curve_start_position_x = x_center + radius * math.cos(
                        arc_end_rad - ((i / 2) + 1) * default_angular_padding_arc - control_point_angular_padding_arc)
                    new_curve_start_position_y = y_center - radius * math.sin(
                        arc_end_rad - ((i / 2) + 1) * default_angular_padding_arc - control_point_angular_padding_arc)
                else:
                    new_position_x = x_center + (radius - default_radial_padding) * math.cos(
                        arc_end_rad - (((i - 1) / 2) + 1) * default_angular_padding_arc)
                    new_position_y = y_center - (radius - default_radial_padding) * math.sin(
                        arc_end_rad - (((i - 1) / 2) + 1) * default_angular_padding_arc)
                    new_curve_control_point_1_x = x_center + radius * math.cos(
                        arc_end_rad - (((i - 1) / 2) + 1) * default_angular_padding_arc)
                    new_curve_control_point_1_y = y_center - radius * math.sin(
                        arc_end_rad - (((i - 1) / 2) + 1) * default_angular_padding_arc)
                    new_curve_start_position_x = x_center + radius * math.cos(arc_end_rad - (
                            ((i - 1) / 2) + 1) * default_angular_padding_arc - control_point_angular_padding_arc)
                    new_curve_start_position_y = y_center - radius * math.sin(arc_end_rad - (
                            ((i - 1) / 2) + 1) * default_angular_padding_arc - control_point_angular_padding_arc)
                    offset_x = -offset_x
                    offset_y = -offset_y
            new_curve_end_position_x = new_position_x + offset_x
            new_curve_end_position_y = new_position_y + offset_y
            try:
                species.move_to((new_position_x - 0.5 * species.get_size()[0], new_position_y - 0.5 * species.get_size()[1]))
            except ValueError:
                raise ValueError(f"Using this 'center_at' or 'radius' for the reaction \"{reaction.get_reaction_id()}\" will cause the species to be placed outside the canvas.")

            curves = reaction.get_curves_list(species=species)
            for curve in curves:
                while (len(curve.get_segments()) > 1):
                    curve.remove_segment(curve.get_segment())
                curve_segment = curve.get_segment()
                curve_segment.set_start((new_curve_start_position_x, new_curve_start_position_y))
                curve_segment.set_end((new_curve_end_position_x, new_curve_end_position_y))
                curve_segment.set_control_point_1((new_curve_control_point_1_x, new_curve_control_point_1_y))
                curve_segment.set_control_point_2((new_curve_end_position_x, new_curve_end_position_y))

        return True

    def _set_modifier_features(self, modifier_species, reaction, x_center, y_center, radius,
                               arc_start_rad, arc_end_rad, clockwise, species_placement):
        arc_reaction_point = self._get_arc_reaction_point(arc_start_rad, arc_end_rad, clockwise)
        max_width = max([species.get_size()[0] for species in modifier_species])
        max_height = max([species.get_size()[1] for species in modifier_species])
        default_angular_padding_arc = 2 * math.sqrt((max_width ** 2 + max_height ** 2) / 2) / radius
        default_radial_padding = 2 * math.sqrt((max_width ** 2 + max_height ** 2) / 2)
        if species_placement == "in":
            default_radial_padding = -default_radial_padding
        for i, species in enumerate(modifier_species):
            arrow_head_size = (0, 0)
            arrow_head = reaction.get_curves_list(species=species)[0].get_arrow_head()
            if arrow_head is not None:
                arrow_head_size = arrow_head.get_size()
            if i == 0:
                angular_offset = 0
                if species_placement == "in":
                    new_reaction_point_x = x_center + (radius - 0.5 * arrow_head_size[0]) * math.cos(arc_reaction_point)
                    new_reaction_point_y = y_center - (radius - 0.5 * arrow_head_size[1]) * math.sin(arc_reaction_point)
                else:
                    new_reaction_point_x = x_center + (radius + 0.5 * arrow_head_size[0]) * math.cos(arc_reaction_point)
                    new_reaction_point_y = y_center - (radius + 0.5 * arrow_head_size[1]) * math.sin(arc_reaction_point)
            else:
                angular_offset = ((-1) ** i) * math.ceil(i / 2) * default_angular_padding_arc
                if species_placement == "in":
                    new_reaction_point_x = x_center + (radius - 0.5 * arrow_head_size[0]) * math.cos(arc_reaction_point + ((-1) ** i) * math.ceil(i / 2) * arrow_head_size[0] / (radius - arrow_head_size[0]))
                    new_reaction_point_y = y_center - (radius - 0.5 * arrow_head_size[1]) * math.sin(arc_reaction_point + ((-1) ** i) * math.ceil(i / 2) * arrow_head_size[1] / (radius - arrow_head_size[1]))
                else:
                    new_reaction_point_x = x_center + (radius + 0.5 * arrow_head_size[0]) * math.cos(arc_reaction_point + ((-1) ** i) * math.ceil(i / 2) * arrow_head_size[0] / (radius + arrow_head_size[0]))
                    new_reaction_point_y = y_center - (radius + 0.5 * arrow_head_size[1]) * math.sin(arc_reaction_point + ((-1) ** i) * math.ceil(i / 2) * arrow_head_size[1] / (radius + arrow_head_size[1]))
            placement_angle = arc_reaction_point + angular_offset
            new_position_x = x_center + (radius + default_radial_padding) * math.cos(placement_angle)
            new_position_y = y_center - (radius + default_radial_padding) * math.sin(placement_angle)
            curve_angle = arc_end_rad + angular_offset
            new_curve_start_position_x = x_center + radius * math.cos(curve_angle)
            new_curve_start_position_y = y_center - radius * math.sin(curve_angle)
            modifier_relative_arc = math.atan2(
                (y_center - radius * math.sin(arc_reaction_point) - new_position_y),
                new_position_x - (x_center + radius * math.cos(arc_reaction_point))
            )
            offset_x, offset_y = self._get_modifier_point_offsets(modifier_relative_arc, species)
            new_curve_start_position_x = new_position_x + offset_x
            new_curve_start_position_y = new_position_y + offset_y
            if not species.move_to(
                    (new_position_x - 0.5 * species.get_size()[0],
                     new_position_y - 0.5 * species.get_size()[1])):
                return False
            curves = reaction.get_curves_list(species=species)
            for curve in curves:
                while (len(curve.get_segments()) > 1):
                    curve.remove_segment(curve.get_segment())
                curve_segment = curve.get_segment()
                curve_segment.set_start((new_curve_start_position_x, new_curve_start_position_y))
                curve_segment.set_end((new_reaction_point_x, new_reaction_point_y))
                curve_segment.set_control_point_1((new_curve_start_position_x, new_curve_start_position_y))
                curve_segment.set_control_point_2((new_reaction_point_x, new_reaction_point_y))

        return True

    def _get_positional_parameters(self, center_at, species_list, radius):
        x_max, x_min, y_max, y_min = self._get_extents(species_list)
        x_center = (x_min + x_max) / 2
        y_center = (y_min + y_max) / 2
        if center_at is not None:
            x_min = (x_min - x_center) + center_at[0]
            x_max = (x_max - x_center) + center_at[0]
            x_center = center_at[0]
            y_min = (y_min - y_center) + center_at[1]
            y_max = (y_max - y_center) + center_at[1]
            y_center = center_at[1]
        new_radius = radius
        if radius is None:
            new_radius = math.sqrt((x_max - x_min) ** 2 + (y_max - y_min) ** 2) / 2

        if center_at is None and radius is None:
            if x_center - new_radius < 0:
                x_center = new_radius + 100
            if y_center - new_radius < 0:
                y_center = new_radius + 100

        return x_center, y_center, new_radius

    @staticmethod
    def _get_arc_parameters(arc_start, arc_end):
        if arc_start < 0:
            arc_start += 360
        elif arc_start >= 360:
            arc_start -= 360
        if arc_end < 0:
            arc_end += 360
        elif arc_end >= 360:
            arc_end -= 360
        if arc_start > arc_end:
            arc_end += 360
        return math.radians(arc_start), math.radians(arc_end)

    @staticmethod
    def _get_arc_reaction_point(arc_start_rad, arc_end_rad, clockwise):
        start = arc_start_rad % (2 * math.pi)
        end = arc_end_rad % (2 * math.pi)
        if clockwise:
            diff = (start - end) % (2 * math.pi)
            return start - diff / 2.0
        else:
            diff = (end - start) % (2 * math.pi)
            return start + diff / 2.0

    def _get_reactant_point_offsets(self, arc_reactant_rad, species, clockwise):
        width, height = species.get_size()
        hw = width / 2.0
        hh = height / 2.0
        if clockwise:
            dx = math.sin(arc_reactant_rad)
            dy = math.cos(arc_reactant_rad)
        else:
            dx = -math.sin(arc_reactant_rad)
            dy = -math.cos(arc_reactant_rad)
        epsilon = 1e-6
        scale_x = hw / abs(dx) if abs(dx) > epsilon else float('inf')
        scale_y = hh / abs(dy) if abs(dy) > epsilon else float('inf')
        scale = min(scale_x, scale_y)
        offset_x = dx * (scale + self.padding)
        offset_y = dy * (scale + self.padding)
        return offset_x, offset_y

    def _get_extra_reactant_point_offsets(self, arc_reactant_rad, species):
        width, height = species.get_size()
        hw, hh = width / 2.0, height / 2.0
        dx = -math.cos(arc_reactant_rad)
        dy = math.sin(arc_reactant_rad)
        epsilon = 1e-6
        scale_x = hw / abs(dx) if abs(dx) > epsilon else float('inf')
        scale_y = hh / abs(dy) if abs(dy) > epsilon else float('inf')
        scale = min(scale_x, scale_y)
        offset_x = dx * (scale + self.padding)
        offset_y = dy * (scale + self.padding)

        return offset_x, offset_y

    def _get_product_point_offsets(self, arc_product_rad, species, clockwise):
        width, height = species.get_size()
        hw = width / 2.0
        hh = height / 2.0
        if clockwise:
            dx = -math.sin(arc_product_rad)
            dy = -math.cos(arc_product_rad)
        else:
            dx = math.sin(arc_product_rad)
            dy = math.cos(arc_product_rad)
        epsilon = 1e-6
        scale_x = hw / abs(dx) if abs(dx) > epsilon else float('inf')
        scale_y = hh / abs(dy) if abs(dy) > epsilon else float('inf')
        scale = min(scale_x, scale_y)
        offset_x = dx * (scale + self.padding)
        offset_y = dy * (scale + self.padding)
        return offset_x, offset_y

    def _get_extra_product_point_offsets(self, arc_product_rad, species):
        width, height = species.get_size()
        hw, hh = width / 2.0, height / 2.0
        dx = - math.cos(arc_product_rad)
        dy = math.sin(arc_product_rad)
        epsilon = 1e-6
        scale_x = hw / abs(dx) if abs(dx) > epsilon else float('inf')
        scale_y = hh / abs(dy) if abs(dy) > epsilon else float('inf')
        scale = min(scale_x, scale_y)
        offset_x = dx * (scale + self.padding)
        offset_y = dy * (scale + self.padding)

        return offset_x, offset_y

    def _get_modifier_point_offsets(self, arc_modifier_rad, species):
        width, height = species.get_size()
        hw = width / 2.0
        hh = height / 2.0
        dx = - math.cos(arc_modifier_rad)
        dy = math.sin(arc_modifier_rad)
        epsilon = 1e-6
        scale_x = hw / abs(dx) if abs(dx) > epsilon else float('inf')
        scale_y = hh / abs(dy) if abs(dy) > epsilon else float('inf')
        scale = min(scale_x, scale_y)
        offset_x = dx * (scale + self.padding)
        offset_y = dy * (scale + self.padding)
        return offset_x, offset_y
