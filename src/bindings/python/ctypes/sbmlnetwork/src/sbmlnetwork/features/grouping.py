import colorsys
from ..network_elements.reaction import Reaction
from ..network_elements.network_element_lists.reaction_list import ReactionList
from ..network_elements.network_element_lists.species_list import SpeciesList


class ReactionGroup(list):

    def group(self, network_obj, reactions: list[str, Reaction], color: str = None):
        self._populate_reaction_items(network_obj, reactions)
        return self._update_styles(network_obj, color)

    def _update_styles(self, network_obj, color: str = None):
        color = self._get_color(color, network_obj)
        for reaction in self:
            if not self.set_color(color):
                return False
            if not self.set_curve_thickness(8):
                return False
            if not self.set_font("Arial", 20):
                return False
            if not self.set_species_border_thickness(8):
                return False
            if not self.set_species_shape("ellipse"):
                return False
            if not self.set_species_size((60, 60)):
                return False
            if not reaction.set_arrow_head_sizes((15, 16)):
                return False
            if not reaction.move_arrow_head_relative_positions_to((-18, -8)):
                return False

        return True

    def _populate_reaction_items(self, network_obj, reactions):
        for reaction in reactions:
            if isinstance(reaction, str):
                reaction_obj = network_obj.get_reaction(reaction)
                if reaction is None:
                    raise ValueError(f"Reaction with id {reaction} not found")
                self.append(reaction_obj)
            elif isinstance(reaction, Reaction):
                self.append(reaction)
            else:
                raise ValueError("Reactions must be a list of reaction ids or Reaction objects")

    @staticmethod
    def _get_color(color, network_obj = None):
        if color is None and network_obj is not None:
            import random

            colors = network_obj.libsbmlnetwork.getPredefinedColorNames()
            color = colors[random.randint(0, len(colors) - 1)]
        elif isinstance(color, str):
            import webcolors as bc

            if color.startswith("#"):
                if len(color) != 7:
                    raise ValueError("Color must be a valid hex color")
                    raise ValueError("Color must be a valid hex color")
                try:
                    int(color[1:], 16)
                except ValueError:
                    raise ValueError("Color must be a valid hex color")
            else:
                try:
                    color = bc.name_to_hex(color)
                except ValueError:
                    raise ValueError("Color must be a valid color name or hex color")
        else:
            raise TypeError("Color must be a string")

        return color

    def get_reaction_ids(self):
        ids = []
        for reaction in self:
            ids.append(reaction.get_id())

        return ids

    def get_reactions_list(self):
        reaction_list = ReactionList()
        for reaction in self:
            reaction_list.append(reaction)

        return reaction_list

    def get_species_ids(self):
        species_ids = set()
        for reaction in self:
            species_list = reaction.get_species_list()
            for species in species_list:
                species_ids.add(species.get_species_id())

        return list(species_ids)

    def get_species_list(self):
        species_list = SpeciesList()
        seen_species_ids = set()

        for reaction in self:
            new_species_list = reaction.get_species_list()
            for species in new_species_list:
                if species.get_id() not in seen_species_ids:
                    species_list.append(species)
                    seen_species_ids.add(species.get_id())

        return species_list

    def set_color(self, color: str):
        color = self._get_color(color)
        for reaction in self:
            species_list = reaction.get_species_list()
            if not all(species_list.set_font_colors(self._darken_color(color))):
                return False
            if not all(species_list.set_border_colors(color)):
                return False
            if not all(species_list.set_fill_colors(self._lighten_color(color))):
                return False
            if not reaction.set_colors(color):
                return False

        return True

    def set_font(self, font: str = "Arial", size: int = 10):
        for reaction in self:
            species_list = reaction.get_species_list()
            if not all(species_list.set_fonts(font)):
                return False
            if not all(species_list.set_font_sizes(size)):
                return False
            if not reaction.set_font(font):
                return False
            if not reaction.set_font_size(size):
                return False

        return True

    def set_curve_thickness(self, thickness: float):
        for reaction in self:
            if not reaction.set_thicknesses(thickness):
                return False

        return True

    def set_curve_colors(self, color: str):
        color = self._get_color(color)
        for reaction in self:
            if not reaction.set_colors(color):
                return False

        return True

    def set_species_size(self, size: tuple[float, float]):
        for reaction in self:
            species_list = reaction.get_species_list()
            if not all(species_list.set_sizes(size)):
                return False

    def set_species_shape(self, shape: str):
        for reaction in self:
            species_list = reaction.get_species_list()
            for species in species_list:
                while len(species.get_shapes_list()) > 1:
                    species.remove_shape(0)
                if not species.set_shape(shape):
                    return False

        return True

    def set_species_border_thickness(self, thickness: float):
        for reaction in self:
            species_list = reaction.get_species_list()
            if not all(species_list.set_border_thicknesses(thickness)):
                return False

        return True

    def set_species_border_colors(self, color: str):
        color = self._get_color(color)
        for reaction in self:
            species_list = reaction.get_species_list()
            if not all(species_list.set_border_colors(color)):
                return False

        return True

    def set_species_fill_colors(self, color: str):
        color = self._get_color(color)
        for reaction in self:
            species_list = reaction.get_species_list()
            if not all(species_list.set_fill_colors(color)):
                return False

        return True

    def set_species_font_colors(self, color: str):
        color = self._get_color(color)
        for reaction in self:
            species_list = reaction.get_species_list()
            if not all(species_list.set_font_colors(color)):
                return False

        return True

    def _darken_color(self, hex_color, percent=20):
        amount = percent / 100.0
        r, g, b = self._hex_to_rgb(hex_color)
        r_f, g_f, b_f = r / 255.0, g / 255.0, b / 255.0
        h, l, s = colorsys.rgb_to_hls(r_f, g_f, b_f)
        l = l * (1.0 - amount)
        r_f, g_f, b_f = colorsys.hls_to_rgb(h, l, s)
        return self._rgb_to_hex((int(r_f * 255), int(g_f * 255), int(b_f * 255)))

    def _lighten_color(self, hex_color, percent=20):
        amount = percent / 100.0
        r, g, b = self._hex_to_rgb(hex_color)
        r_f, g_f, b_f = r / 255.0, g / 255.0, b / 255.0
        h, l, s = colorsys.rgb_to_hls(r_f, g_f, b_f)
        l = l + (1.0 - l) * amount
        r_f, g_f, b_f = colorsys.hls_to_rgb(h, l, s)
        return self._rgb_to_hex((int(r_f * 255), int(g_f * 255), int(b_f * 255)))

    @staticmethod
    def _hex_to_rgb(hex_color):
        hex_color = hex_color.lstrip('#')
        return tuple(int(hex_color[i:i + 2], 16) for i in (0, 2, 4))

    @staticmethod
    def _rgb_to_hex(rgb):
        # Convert RGB back to hex
        return '#{:02x}{:02x}{:02x}'.format(rgb[0], rgb[1], rgb[2])
