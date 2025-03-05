from ..network_elements.reaction import Reaction


class ReactionGrouping:

    def group(self, network_obj, reactions: list[str, Reaction], color: str = None):
        valid_reactions = self._get_valid_reactions(network_obj, reactions)
        color = self._get_color(network_obj, color)

        for reaction in valid_reactions:
            if not self._set_reaction_properties(reaction, color):
                return False

        return True

    @staticmethod
    def _get_valid_reactions(network_obj, reactions):
        valid_reactions = []
        for reaction in reactions:
            if isinstance(reaction, str):
                reaction_obj = network_obj.get_reaction(reaction)
                if reaction is None:
                    raise ValueError(f"Reaction with id {reaction} not found")
                valid_reactions.append(reaction_obj)
            elif isinstance(reaction, Reaction):
                valid_reactions.append(reaction)
            else:
                raise ValueError("Reactions must be a list of reaction ids or Reaction objects")

        return valid_reactions

    @staticmethod
    def _get_color(network_obj, color):
        if color is None:
            import random

            colors = network_obj.libsbmlnetwork.getPredefinedColorNames()
            color = colors[random.randint(0, len(colors) - 1)]

        if isinstance(color, str):
            if color.startswith("#"):
                if len(color) != 7:
                    raise ValueError("Color must be a valid hex color")
                try:
                    int(color[1:], 16)
                except ValueError:
                    raise ValueError("Color must be a valid hex color")

        return color

    @staticmethod
    def _set_reaction_properties(reaction, color):
        if not reaction.set_colors(color):
            return False
        if not reaction.set_thicknesses(8):
            return False
        if not reaction.set_arrow_head_sizes((15, 16)):
            return False
        if not reaction.move_arrow_head_relative_positions_to((-18, -8)):
            return False
        if not reaction.set_font_color(color):
            return False
        species_list = reaction.get_species_list()
        if not all(species_list.set_border_colors(color)):
            return False
        if not all(species_list.set_border_thicknesses(8)):
            return False
        if not all(species_list.set_font_colors(color)):
            return False

        return True
