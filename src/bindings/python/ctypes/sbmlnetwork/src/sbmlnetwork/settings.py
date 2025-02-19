class Settings:

    def __init__(self, libsbmlnetwork):
        self.libsbmlnetwork = libsbmlnetwork
        self.compartment_labels = True
        self.species_labels = True
        self.reaction_labels = True
        self.label = "name"
        self.stoichiometric_curves = True

    @property
    def compartment_labels(self):
        return self._compartment_labels

    @compartment_labels.setter
    def compartment_labels(self, value):
        self._compartment_labels = value
        if self.libsbmlnetwork.sbml_object is not None:
            self.libsbmlnetwork.enableDisplayCompartmentsTextLabel(value)

    def show_compartment_labels(self):
        self.compartment_labels = True
        if self.libsbmlnetwork.sbml_object is not None:
            if self.libsbmlnetwork.enableDisplayCompartmentsTextLabel(True) == 0:
                return True
            return False

        return True

    def hide_compartment_labels(self):
        self.compartment_labels = False
        if self.libsbmlnetwork.sbml_object is not None:
            if self.libsbmlnetwork.enableDisplayCompartmentsTextLabel(False) == 0:
                return True
            return False

        return True

    @property
    def species_labels(self):
        return self._species_labels

    @species_labels.setter
    def species_labels(self, value):
        self._species_labels = value
        if self.libsbmlnetwork.sbml_object is not None:
            self.libsbmlnetwork.enableDisplaySpeciesTextLabel(value)

    def show_species_labels(self):
        self.species_labels = True
        if self.libsbmlnetwork.sbml_object is not None:
            if self.libsbmlnetwork.enableDisplaySpeciesTextLabel(True) == 0:
                return True
            return False

        return True

    def hide_species_labels(self):
        self.species_labels = False
        if self.libsbmlnetwork.sbml_object is not None:
            if self.libsbmlnetwork.enableDisplaySpeciesTextLabel(False) == 0:
                return True
            return False

        return True

    @property
    def reaction_labels(self):
        return self._reaction_labels

    @reaction_labels.setter
    def reaction_labels(self, value):
        self._reaction_labels = value
        if self.libsbmlnetwork.sbml_object is not None:
            self.libsbmlnetwork.enableDisplayReactionsTextLabel(value)

    def show_reaction_labels(self):
        self.reaction_labels = True
        if self.libsbmlnetwork.sbml_object is not None:
            if self.libsbmlnetwork.enableDisplayReactionsTextLabel(True) == 0:
                return True
            return False

        return True

    def hide_reaction_labels(self):
        self.reaction_labels = False
        if self.libsbmlnetwork.sbml_object is not None:
            if self.libsbmlnetwork.enableDisplayReactionsTextLabel(False) == 0:
                return True
            return False

        return True

    @property
    def label(self):
        return self._label

    @label.setter
    def label(self, value):
        if value not in ["id", "name"]:
            raise ValueError("Label type must be one of 'id' or 'name'")

        self._label = value
        if self.libsbmlnetwork.sbml_object is not None:
            if value == "id":
                self.libsbmlnetwork.setUseNameAsTextLabel(False)
            else:
                self.libsbmlnetwork.setUseNameAsTextLabel(True)

    def show_id_as_label(self):
        self.label = "id"
        if self.libsbmlnetwork.sbml_object is not None:
            if self.libsbmlnetwork.setUseNameAsTextLabel(False) == 0:
                return True
            return False

        return True

    def show_name_as_label(self):
        self.label = "name"
        if self.libsbmlnetwork.sbml_object is not None:
            if self.libsbmlnetwork.setUseNameAsTextLabel(True) == 0:
                return True
            return False

        return True

    @property
    def stoichiometric_curves(self):
        return self._stoichiometric_curves

    @stoichiometric_curves.setter
    def stoichiometric_curves(self, value):
        self._stoichiometric_curves = value
        if self.libsbmlnetwork.sbml_object is not None:
            self.libsbmlnetwork.setStoichiometricSpeciesReference(value)

    def enable_stoichiometric_curves(self):
        self.stoichiometric_curves = True
        if self.libsbmlnetwork.sbml_object is not None:
            if self.libsbmlnetwork.setStoichiometricSpeciesReference(True) == 0:
                return True
            return False

        return True

    def disable_stoichiometric_curves(self):
        self.stoichiometric_curves = False
        if self.libsbmlnetwork.sbml_object is not None:
            if self.libsbmlnetwork.setStoichiometricSpeciesReference(False) == 0:
                return True
            return False

        return True

    def __str__(self):
        return (
            f"Settings(\n"
            f"  Compartment Labels: {'Enabled' if self.compartment_labels else 'Disabled'},\n"
            f"  Species Labels: {'Enabled' if self.species_labels else 'Disabled'},\n"
            f"  Reaction Labels: {'Enabled' if self.reaction_labels else 'Disabled'},\n"
            f"  Label Type: {self.label.capitalize()},\n"
            f"  Stoichiometric Curves: {'Enabled' if self.stoichiometric_curves else 'Disabled'}\n"
            f")"
        )
