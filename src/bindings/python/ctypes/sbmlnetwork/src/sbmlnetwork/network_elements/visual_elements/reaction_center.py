from .curve import Curve


class ReactionCenter:

    def __init__(self, libsbmlnetwork, reaction_id, reaction_glyph_index):
        self.libsbmlnetwork = libsbmlnetwork
        self.reaction_id = reaction_id
        self.reaction_glyph_index = reaction_glyph_index

    def get_reaction(self):
        from ..reaction import Reaction

        return Reaction(self.libsbmlnetwork, self.reaction_id, self.reaction_glyph_index)

    @property
    def reaction(self):
        return self.get_reaction()

    def switch_to_curve(self):
        shapes_list = self.get_shapes_list()
        reaction = self.get_reaction()
        while len(shapes_list) > 0:
            if not reaction.remove_shape(shapes_list[-1]):
                return False
            shapes_list.pop()

        return True

    def switch_to_shapes(self):
        shapes_list = self.get_shapes_list()
        reaction = self.get_reaction()
        if len(shapes_list) == 0:
            if reaction.add_shape("rectangle") is None:
                return False

        return True

    def is_curve(self):
        shapes_list = self.get_shapes_list()
        if len(shapes_list) == 0:
            return True

        return False

    def is_shapes(self):
        shapes_list = self.get_shapes_list()
        if len(shapes_list) > 0:
            return True

        return False

    def get_curve(self):
        if self.is_curve():
            return Curve(self.libsbmlnetwork, self.reaction_id, self.reaction_glyph_index, None)

        return None

    @property
    def curve(self):
        return self.get_curve()

    def get_shapes_list(self):
        return self.get_reaction().get_shapes_list()

    def get_shapes(self):
        return self.get_shapes_list()

    @property
    def shapes(self):
        return self.get_shapes_list()

    def move(self, delta: tuple[float, float]):
        if self.is_curve():
            return self.get_curve().move_by(delta)

        return True

    def get_info(self):
        result = []
        result.append(f"reaction id: {self.reaction_id}")
        if self.is_curve():
            result.append("curve:")
            result.append("\n".join(["    " + line for line in str(self.get_curve()).split("\n")]))
        else:
            result.append("shapes:")
            shapes = self.get_shapes_list()
            for shape in shapes:
                result.append("\n".join(["    " + line for line in str(shape).split("\n")]))
                if shape != shapes[-1]:
                    result.append("----")

        return "\n".join(result)

    @property
    def info(self):
        return self.get_info()

    def __repr__(self):
        if self.is_curve():
            return f"ReactionCenter({self.reaction_id}, {self.reaction_glyph_index}, {repr(self.get_curve())})"
        else:
            return f"ReactionCenter({self.reaction_id}, {self.reaction_glyph_index}, {repr(self.get_shapes_list())})"