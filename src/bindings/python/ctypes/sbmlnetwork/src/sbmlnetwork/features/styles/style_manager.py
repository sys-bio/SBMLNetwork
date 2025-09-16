class StyleManager:

    def __init__(self, network_obj):

        self.network_obj = network_obj

    def set_style(self, style_name):
        valid_styles = self.network_obj.libsbmlnetwork.getListOfStyles()
        if style_name not in valid_styles:
            raise ValueError(f"Style name must be one of {valid_styles}")
        self.network_obj.libsbmlnetwork.setStyle(style_name)
