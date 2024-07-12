C++ API Reference
==================

This is the API reference for the C++ API of the SBMLNetwork library.

************************
SBMLDocument Functions
************************

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getVersion()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::readSBML(const std::string &sbml)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::writeSBML(SBMLDocument* document, const std::string &fileName)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::writeSBML(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSBMLLevel(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSBMLVersion(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::freeSBMLDocument(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetModel(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::autolayout(SBMLDocument* document, const double& stiffness = 10.0, const double& gravity = 15.0, bool useMagnetism = false, bool useBoundary = false, bool useGrid = false, bool useNameAsTextLabel = true, std::vector <std::string> lockedNodeIds = std::vector<std::string>())

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::updateLayoutCurves(SBMLDocument* document, GraphicalObject* updatedGraphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::updateLayoutCurves(SBMLDocument* document, std::vector<GraphicalObject*> updatedGraphicalObjects)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::align(SBMLDocument* document, std::vector <std::string> nodeIds,  const std::string& alignment)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::distribute(SBMLDocument* document, std::vector <std::string> nodeIds, const std::string& direction, const double& spacing = -1)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSBMLObject(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetId(SBase* object)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getId(SBase* object)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setId(SBase* object, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetName(SBase* object)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getName(SBase* object)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setName(SBase* object, const std::string& name)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetMetaId(SBase* object)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getMetaId(SBase* object)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setMetaId(SBase* object, const std::string& metaid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumCompartments(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthCompartmentId(SBMLDocument* document, unsigned int index)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartment(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumSpecies(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthSpeciesId(SBMLDocument* document, unsigned int index)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpecies(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumReactions(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthReactionId(SBMLDocument* document, unsigned int index)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReaction(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumSpeciesReferences(SBMLDocument* document, const std::string& reactionId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumReactants(SBMLDocument* document, const std::string& reactionId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumProducts(SBMLDocument* document, const std::string& reactionId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumModifiers(SBMLDocument* document, const std::string& reactionId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthReactantId(SBMLDocument* document, const std::string& reactionId, unsigned int index)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthProductId(SBMLDocument* document, const std::string& reactionId, unsigned int index)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthModifierId(SBMLDocument* document, const std::string& reactionId, unsigned int index)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReference(SBMLDocument* document, const std::string& reactionId, const std::string& speciesId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getModifierSpeciesReference(SBMLDocument* document, const std::string& reactionId, const std::string& speciesId)


*****************
Layout Functions
*****************

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getListOfLayouts(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumLayouts(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLayout(SBMLDocument* document, unsigned int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::addLayout(SBMLDocument* document, Layout* layout)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createLayout(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::removeAllLayouts(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDefaultLayoutFeatures(SBMLDocument* document, Layout* layout, const double& stiffness = 10.0, const double& gravity = 15.0, bool useMagnetism = false, bool useBoundary = false, bool useGrid = false, bool useNameAsTextLabel = true, const std::vector<std::string>& lockedNodeIds = std::vector<std::string>())

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createDefaultLayout(SBMLDocument* document, const double& stiffness = 10.0, const double& gravity = 15.0, bool useMagnetism = false, bool useBoundary = false, bool useGrid = false, bool useNameAsTextLabel = true, const std::vector<std::string>& lockedNodeIds = std::vector<std::string>())

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getDimensions(SBMLDocument* document, unsigned int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionWidth(SBMLDocument* document, unsigned int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionWidth(SBMLDocument* document, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionHeight(SBMLDocument* document, unsigned int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionHeight(SBMLDocument* document, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumGraphicalObjects(SBMLDocument* document, unsigned int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumGraphicalObjects(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumGraphicalObjects(SBMLDocument* document, unsigned int layoutIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGraphicalObjects(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGraphicalObjects(SBMLDocument* document, unsigned int layoutIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGraphicalObject(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGraphicalObject(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumCompartmentGlyphs(SBMLDocument* document, unsigned int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumCompartmentGlyphs(SBMLDocument* document, const std::string& compartmentId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumCompartmentGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& compartmentId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGlyphs(SBMLDocument* document, const std::string& compartmentId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& compartmentId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGlyph(SBMLDocument* document, const std::string& compartmentId, unsigned int compartmentGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& compartmentId, unsigned int compartmentGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGlyph(SBMLDocument* document, unsigned int layoutIndex = 0, unsigned int compartmentGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isCompartmentGlyph(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isCompartmentGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentId(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getAssociatedCompartment(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getAssociatedCompartment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getAssociatedCompartment(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGlyphsIds(SBMLDocument* document, unsigned int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumSpeciesGlyphs(SBMLDocument* document, unsigned int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumSpeciesGlyphs(SBMLDocument* document, const std::string& speciesId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumSpeciesGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGlyphs(SBMLDocument* document, const std::string& speciesId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGlyph(SBMLDocument* document, const std::string& speciesId, unsigned int speciesGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& speciesId, unsigned int speciesGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGlyph(SBMLDocument* document, unsigned int layoutIndex = 0, unsigned int speciesGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSpeciesGlyph(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSpeciesGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGlyphsIds(SBMLDocument* document, unsigned int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumReactionGlyphs(SBMLDocument* document, unsigned int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumReactionGlyphs(SBMLDocument* document, const std::string& reactionId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumReactionGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGlyphs(SBMLDocument* document, const std::string& reactionId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGlyph(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGlyph(SBMLDocument* document, unsigned int layoutIndex = 0, unsigned int reactionGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isReactionGlyph(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isReactionGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumSpeciesReferenceGlyphs(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumSpeciesReferenceGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceGlyphs(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceGlyph(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceId(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceId(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceSpeciesId(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceSpeciesGlyphId(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceSpeciesGlyphId(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceRole(SBMLDocument* document, const std::string& reactionId, const std::string& role)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, const std::string& role)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, const std::string& role)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, const std::string& role)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceRole(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceGlyphIndex, const std::string& role)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceRole(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceGlyphIndex, const std::string& role)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceCurve(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceCurve(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurve(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurve(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumSpeciesReferenceCurveSegments(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumSpeciesReferenceCurveSegments(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegment(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createSpeciesReferenceLineCurveSegment(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createSpeciesReferenceLineCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createSpeciesReferenceCubicBezierCurveSegment(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createSpeciesReferenceCubicBezierCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::removeSpeciesReferenceCurveSegment(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::removeSpeciesReferenceCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSpeciesReferenceCurveSegmentCubicBezier(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSpeciesReferenceCurveSegmentCubicBezier(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumTextGlyphs(SBMLDocument* document, unsigned int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumTextGlyphs(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumTextGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getTextGlyphs(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getTextGlyphs(SBMLDocument* document, unsigned int layoutIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getTextGlyph(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getTextGlyph(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getTextGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getTextGlyph(SBMLDocument* document, unsigned int layoutIndex, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetText(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getText(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setText(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const std::string& text)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const std::string& text)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setText(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& text)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& text)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::addText(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const std::string& text)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::addText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const std::string& text)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::removeText(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::removeText(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetOriginOfTextId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getOriginOfTextId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setOriginOfTextId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const std::string& orig)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const std::string& orig)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setOriginOfTextId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& orig)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setOriginOfTextId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& orig)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGraphicalObjectId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGraphicalObjectId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGraphicalObjectId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const std::string& graphicalObjectId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const std::string& graphicalObjectId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& graphicalObjectId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isTextGlyph(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isTextGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getBoundingBox(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getBoundingBox(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setPositionX(SBMLDocument* document, const std::string& id, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setPositionX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setPositionY(SBMLDocument* document, const std::string& id, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setPosition(SBMLDocument* document, const std::string& id, const double& x, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& x, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setPosition(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& x, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& x, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionWidth(SBMLDocument* document, const std::string& id, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionHeight(SBMLDocument* document, const std::string& id, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getTextPositionX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getTextPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextPositionX(SBMLDocument* document, const std::string& id, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextPositionX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextPositionX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getTextPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getTextPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextPositionY(SBMLDocument* document, const std::string& id, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextPosition(SBMLDocument* document, const std::string& id, const double& x, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& x, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextPosition(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& x, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& x, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextPosition(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& x, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& x, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getTextDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getTextDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextDimensionWidth(SBMLDocument* document, const std::string& id, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getTextDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getTextDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextDimensionHeight(SBMLDocument* document, const std::string& id, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetCurve(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetCurve(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurve(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurve(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumCurveSegments(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumCurveSegments(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegment(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createLineCurveSegment(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createLineCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createCubicBezierCurveSegment(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createCubicBezierCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::removeCurveSegment(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::removeCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isCubicBezier(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isCubicBezier(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegmentStartPointX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentStartPointX(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentStartPointX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegmentStartPointY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentStartPointY(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentStartPointY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentStartPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegmentEndPointX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentEndPointX(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentEndPointX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegmentEndPointY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentEndPointY(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentEndPointY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentEndPointY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentBasePoint1X(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentBasePoint1Y(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentBasePoint2Y(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCurveSegmentBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex, const double& y)

*****************
Render Functions
*****************

.. doxygenfunction::  LIBSBMLNETWORK_CPP_NAMESPACE::getListOfGlobalRenderInformation(SBMLDocument* document)

.. doxygenfunction::  LIBSBMLNETWORK_CPP_NAMESPACE::getNumGlobalRenderInformation(SBMLDocument* document)

.. doxygenfunction::  LIBSBMLNETWORK_CPP_NAMESPACE::getGlobalRenderInformation(SBMLDocument* document, unsigned int renderIndex)

.. doxygenfunction::  LIBSBMLNETWORK_CPP_NAMESPACE::addGlobalRenderInformation(SBMLDocument* document, GlobalRenderInformation* globalRenderInformation)

.. doxygenfunction::  LIBSBMLNETWORK_CPP_NAMESPACE::createGlobalRenderInformation(SBMLDocument* document)

.. doxygenfunction::  LIBSBMLNETWORK_CPP_NAMESPACE::removeAllGlobalRenderInformation(SBMLDocument* document)

.. doxygenfunction::  LIBSBMLNETWORK_CPP_NAMESPACE::setDefaultGlobalRenderInformationFeatures(SBMLDocument* document, GlobalRenderInformation* globalRenderInformation)

.. doxygenfunction::  LIBSBMLNETWORK_CPP_NAMESPACE::getListOfLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex)

.. doxygenfunction::  LIBSBMLNETWORK_CPP_NAMESPACE::getNumLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex)

.. doxygenfunction::  LIBSBMLNETWORK_CPP_NAMESPACE::getLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex, unsigned int renderIndex)

.. doxygenfunction::  LIBSBMLNETWORK_CPP_NAMESPACE::addLocalRenderInformation(SBMLDocument* document, LocalRenderInformation* localRenderInformation)

.. doxygenfunction::  LIBSBMLNETWORK_CPP_NAMESPACE::addLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex, LocalRenderInformation* localRenderInformation)

.. doxygenfunction::  LIBSBMLNETWORK_CPP_NAMESPACE::createLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex)

.. doxygenfunction::  LIBSBMLNETWORK_CPP_NAMESPACE::removeAllLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDefaultLocalRenderInformationFeatures(SBMLDocument* document, LocalRenderInformation* localRenderInformation)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDefaultLocalRenderInformationFeatures(SBMLDocument* document, unsigned int layoutIndex, LocalRenderInformation* localRenderInformation)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createDefaultRenderInformation(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createDefaultGlobalRenderInformation(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createDefaultLocalRenderInformation(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetBackgroundColor(SBMLDocument* document, unsigned int renderIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getBackgroundColor(SBMLDocument* document, unsigned int renderIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setBackgroundColor(SBMLDocument* document, const std::string& backgroundColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setBackgroundColor(SBMLDocument* document, unsigned int renderIndex, const std::string& backgroundColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumGlobalColorDefinitions(SBMLDocument* document, unsigned int renderIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthGlobalColorDefinitionId(SBMLDocument* document, unsigned int renderIndex, unsigned int colorIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumLocalColorDefinitions(SBMLDocument* document, unsigned int renderIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthLocalColorDefinitionId(SBMLDocument* document, unsigned int renderIndex, unsigned int colorIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getColorDefinition(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getColorDefinition(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getColorDefinition(SBMLDocument* document, unsigned int renderIndex, unsigned int colorIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetValue(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetValue(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getValue(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getValue(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setValue(SBMLDocument* document, const std::string& sid, const std::string& value)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setValue(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const std::string& value)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumGlobalGradientDefinitions(SBMLDocument* document, unsigned int renderIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumLocalGradientDefinitions(SBMLDocument* document, unsigned int renderIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthGlobalGradientDefinitionId(SBMLDocument* document, unsigned int renderIndex, unsigned int gradientIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthLocalGradientDefinitionId(SBMLDocument* document, unsigned int renderIndex, unsigned int gradientIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGradientDefinition(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGradientDefinition(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGradientDefinition(SBMLDocument* document, unsigned int renderIndex, unsigned int gradientIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLinearGradient(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLinearGradient(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isRadialGradient(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isRadialGradient(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpreadMethod(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpreadMethod(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpreadMethod(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpreadMethod(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpreadMethod(SBMLDocument* document, const std::string& sid, const std::string& spreadMethod)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpreadMethod(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const std::string& spreadMethod)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumGradientStops(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumGradientStops(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGradientStop(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGradientStop(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetOffset(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetOffset(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getOffset(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getOffset(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setOffset(SBMLDocument* document, const std::string& sid, const RelAbsVector& offset)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setOffset(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& offset)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setOffset(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex, const RelAbsVector& offset)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setOffset(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex, const RelAbsVector& offset)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetStopColor(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetStopColor(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStopColor(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStopColor(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStopColor(SBMLDocument* document, const std::string& sid, const std::string& stopColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStopColor(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const std::string& stopColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStopColor(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex, const std::string& stopColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStopColor(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex, const std::string& stopColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLinearGradientX1(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLinearGradientX1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientX1(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientX1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientX1(SBMLDocument* document, const std::string& sid, const RelAbsVector& x1)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientX1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& x1)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLinearGradientX2(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLinearGradientX2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientX2(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientX2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientX2(SBMLDocument* document, const std::string& sid, const RelAbsVector& x2)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientX2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& x2)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLinearGradientY1(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLinearGradientY1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientY1(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientY1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientY1(SBMLDocument* document, const std::string& sid, const RelAbsVector& y1)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientY1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& y1)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLinearGradientY2(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLinearGradientY2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientY2(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientY2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientY2(SBMLDocument* document, const std::string& sid, const RelAbsVector& y2)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientY2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& y2)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetRadialGradientCx(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetRadialGradientCx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientCx(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientCx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientCx(SBMLDocument* document, const std::string& sid, const RelAbsVector& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientCx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetRadialGradientCy(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetRadialGradientCy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientCy(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientCy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientCy(SBMLDocument* document, const std::string& sid, const RelAbsVector& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientCy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetRadialGradientFx(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetRadialGradientFx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientFx(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientFx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientFx(SBMLDocument* document, const std::string& sid, const RelAbsVector& fx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientFx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& fx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetRadialGradientFy(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetRadialGradientFy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientFy(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientFy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientFy(SBMLDocument* document, const std::string& sid, const RelAbsVector& fy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientFy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& fy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetRadialGradientR(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetRadialGradientR(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientR(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientR(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientR(SBMLDocument* document, const std::string& sid, const RelAbsVector& r)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientR(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& r)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumGlobalLineEndings(SBMLDocument* document, unsigned int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumLocalLineEndings(SBMLDocument* document, unsigned int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthGlobalLineEndingId(SBMLDocument* document, unsigned int renderIndex = 0, unsigned int lineEndingIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthLocalLineEndingId(SBMLDocument* document, unsigned int renderIndex = 0, unsigned int lineEndingIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEnding(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEnding(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEnding(SBMLDocument* document, unsigned int renderIndex, unsigned int lineEndingIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetEnableRotationalMapping(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetEnableRotationalMapping(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getEnableRotationalMapping(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getEnableRotationalMapping(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setEnableRotationalMapping(SBMLDocument* document, const std::string& sid, bool enableRotationalMapping)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setEnableRotationalMapping(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, bool enableRotationalMapping)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingBoundingBox(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingBoundingBox(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingBoundingBoxX(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingBoundingBoxX(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingBoundingBoxX(SBMLDocument* document, const std::string& sid, double x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingBoundingBoxX(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, double x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingBoundingBoxY(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingBoundingBoxY(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingBoundingBoxY(SBMLDocument* document, const std::string& sid, double y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingBoundingBoxY(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, double y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingBoundingBoxWidth(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingBoundingBoxWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingBoundingBoxWidth(SBMLDocument* document, const std::string& sid, double width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingBoundingBoxWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, double width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingBoundingBoxHeight(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingBoundingBoxHeight(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingBoundingBoxHeight(SBMLDocument* document, const std::string& sid, double height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingBoundingBoxHeight(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, double height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingRenderGroup(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingRenderGroup(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingStrokeColor(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingStrokeColor(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingStrokeColor(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingStrokeColor(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeColor(SBMLDocument* document, const std::string& id, const std::string& stroke)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeColor(SBMLDocument* document, unsigned int renderIndex, const std::string& id, const std::string& stroke)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingStrokeWidth(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingStrokeWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingStrokeWidth(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingStrokeWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeWidth(SBMLDocument* document, const std::string& id, double strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& id, double strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingStrokeDashArray(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingStrokeDashArray(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingStrokeDashArray(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingStrokeDashArray(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeDashArray(SBMLDocument* document, const std::string& id, const std::vector<unsigned int>& strokeDashArray)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeDashArray(SBMLDocument* document, unsigned int renderIndex, const std::string& id, const std::vector<unsigned int>& strokeDashArray)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumLineEndingStrokeDashes(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumLineEndingStrokeDashes(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingStrokeDash(SBMLDocument* document, const std::string& id, unsigned int dashIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingStrokeDash(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int dashIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeDash(SBMLDocument* document, const std::string& id, unsigned int dash)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeDash(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int dash)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeDash(SBMLDocument* document, const std::string& id, unsigned int dashIndex, unsigned int dash)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeDash(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int dashIndex, unsigned int dash)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingFillColor(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingFillColor(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingFillColor(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingFillColor(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingFillColor(SBMLDocument* document, const std::string& id, const std::string& fill)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingFillColor(SBMLDocument* document, unsigned int renderIndex, const std::string& id, const std::string& fill)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingFillRule(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingFillRule(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingFillRule(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingFillRule(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingFillRule(SBMLDocument* document, const std::string& id, const std::string& fillRule)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingFillRule(SBMLDocument* document, unsigned int renderIndex, const std::string& id, const std::string& fillRule)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumLineEndingGeometricShapes(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumLineEndingGeometricShapes(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingRectangle(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingRectangle(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingEllipse(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingEllipse(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingPolygon(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingPolygon(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingImage(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingImage(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingRenderCurve(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingRenderCurve(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingText(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingText(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeWidth(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeWidth(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeWidth(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeHeight(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeHeight(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeHeight(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeHeight(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeHeight(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeHeight(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeRatio(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeRatio(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeRatio(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeRatio(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeRatio(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, double ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeRatio(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, double ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& CornerCurvatureRadiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& CornerCurvatureRadiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& CornerCurvatureRadiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& CornerCurvatureRadiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeCenterX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeCenterX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCenterX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCenterX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCenterX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& centerX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCenterX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& centerX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeCenterY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeCenterY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCenterY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCenterY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCenterY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& centerY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCenterY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& centerY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeRadiusX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeRadiusX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeRadiusX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeRadiusX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeRadiusX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeRadiusX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeRadiusY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeRadiusY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeRadiusY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeRadiusY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeRadiusY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeRadiusY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeNumElements(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeNumElements(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingGeometricShapeElementCubicBezier(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingGeometricShapeElementCubicBezier(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeElementX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeElementX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeElementX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeElementX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeElementY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeElementY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeElementY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeElementY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint1X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint1X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint1Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint1Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint2X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint2X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint2Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint2Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeHref(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeHref(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeHref(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeHref(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeHref(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const std::string& href)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeHref(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const std::string& href)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStyle(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLocalStyle(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGlobalStyle(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createLocalStyle(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createLocalStyle(SBMLDocument* document, TextGlyph* textGlyph, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStyle(SBMLDocument* document, unsigned int renderIndex, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLocalStyle(SBMLDocument* document, unsigned int renderIndex, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGlobalStyle(SBMLDocument* document, unsigned int renderIndex, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createLocalStyle(SBMLDocument* document, unsigned int renderIndex, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStyle(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLocalStyle(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGlobalStyle(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createLocalStyle(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStyle(SBMLDocument* document, unsigned int renderIndex, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLocalStyle(SBMLDocument* document, unsigned int renderIndex, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGlobalStyle(SBMLDocument* document, unsigned int renderIndex, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createLocalStyle(SBMLDocument* document, unsigned int renderIndex, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStyleById(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStyleById(SBMLDocument* document, unsigned int renderIndex, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStyleById(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStyleById(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStyleByRole(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStyleByRole(SBMLDocument* document, unsigned int renderIndex, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStyleByRole(SBMLDocument* document, const std::string& role)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStyleByRole(SBMLDocument* document, unsigned int renderIndex, const std::string& role)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStyleByType(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStyleByType(SBMLDocument* document, unsigned int renderIndex, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStyleByType(SBMLDocument* document, const std::string& type)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStyleByType(SBMLDocument* document, unsigned int renderIndex, const std::string& type)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRenderGroup(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRenderGroup(SBMLDocument* document, unsigned int renderIndex, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRenderGroup(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRenderGroup(SBMLDocument* document, unsigned int renderIndex, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetStrokeColor(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetStrokeColor(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStrokeColor(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStrokeColor(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeColor(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& stroke)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeColor(SBMLDocument* document, const std::string& attribute, const std::string& stroke)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentStrokeColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& stroke)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesStrokeColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& stroke)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionStrokeColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& stroke, bool setSpeciesReferenceGlyphs)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingsStrokeColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& stroke)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& stroke)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetStrokeWidth(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetStrokeWidth(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStrokeWidth(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStrokeWidth(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, const double& strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeWidth(SBMLDocument* document, const std::string& attribute, const double& strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentStrokeWidth(SBMLDocument* document, unsigned int layoutIndex, const double& strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesStrokeWidth(SBMLDocument* document, unsigned int layoutIndex, const double& strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionStrokeWidth(SBMLDocument* document, unsigned int layoutIndex, const double& strokeWidth, bool setSpeciesReferenceGlyphs = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingsStrokeWidth(SBMLDocument* document, unsigned int layoutIndex, const double& strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeWidth(SBMLDocument* document, unsigned int layoutIndex, const double& strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetStrokeDashArray(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetStrokeDashArray(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStrokeDashArray(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStrokeDashArray(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeDashArray(SBMLDocument* document, GraphicalObject* graphicalObject, const std::vector<unsigned int>& strokeDashArray)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeDashArray(SBMLDocument* document, const std::string& attribute, const std::vector<unsigned int>& strokeDashArray)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumStrokeDashes(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumStrokeDashes(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStrokeDash(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int dashIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStrokeDash(SBMLDocument* document, const std::string& attribute, unsigned int dashIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeDash(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int dash)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeDash(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int dashIndex, unsigned int dash)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeDash(SBMLDocument* document, const std::string& attribute, unsigned int dash)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeDash(SBMLDocument* document, const std::string& attribute, unsigned int dashIndex, unsigned int dash)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFontColor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFontColor(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFontColor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFontColor(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontColor(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fontColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontColor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const std::string& fontColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontColor(SBMLDocument* document, const std::string& attribute, const std::string& fontColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontColor(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex, const std::string& fontColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFontColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFontColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFontColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFontFamily(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFontFamily(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFontFamily(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFontFamily(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontFamily(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fontFamily)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontFamily(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const std::string& fontFamily)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontFamily(SBMLDocument* document, const std::string& attribute, const std::string& fontFamily)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontFamily(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex, const std::string& fontFamily)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFontFamily(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontFamily)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFontFamily(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontFamily)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFontFamily(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontFamily)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontFamily(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontFamily)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFontSize(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFontSize(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFontSize(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFontSize(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontSize(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontSize(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const RelAbsVector& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontSize(SBMLDocument* document, const std::string& attribute, const RelAbsVector& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontSize(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex, const RelAbsVector& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFontSize(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFontSize(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFontSize(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontSize(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFontWeight(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFontWeight(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFontWeight(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFontWeight(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontWeight(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fontWeight)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontWeight(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const std::string& fontWeight)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontWeight(SBMLDocument* document, const std::string& attribute, const std::string& fontWeight)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontWeight(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex, const std::string& fontWeight)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFontWeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontWeight)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFontWeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontWeight)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFontWeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontWeight)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontWeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontWeight)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFontStyle(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFontStyle(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFontStyle(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFontStyle(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontStyle(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fontStyle)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontStyle(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const std::string& fontStyle)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontStyle(SBMLDocument* document, const std::string& attribute, const std::string& fontStyle)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontStyle(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex, const std::string& fontStyle)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFontStyle(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontStyle)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFontStyle(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontStyle)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFontStyle(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontStyle)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontStyle(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontStyle)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetTextAnchor(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getTextAnchor(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& textAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const std::string& textAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextAnchor(SBMLDocument* document, const std::string& attribute, const std::string& textAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextAnchor(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex, const std::string& textAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& textAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& textAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& textAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& textAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getVTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getVTextAnchor(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setVTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const std::string& vtextAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setVTextAnchor(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex, const std::string& vtextAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentVTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& vtextAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesVTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& vtextAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionVTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& vtextAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setVTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& vtextAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFillColor(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFillColor(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFillColor(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFillColor(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFillColor(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFillColor(SBMLDocument* document, const std::string& attribute, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFillColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFillColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFillColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingsFillColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFillColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFillRule(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFillRule(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFillRule(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFillRule(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFillRule(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fillRule)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFillRule(SBMLDocument* document, const std::string& attribute, const std::string& fillRule)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFillRule(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillRule)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFillRule(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillRule)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFillRule(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillRule)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingsFillRule(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillRule)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFillRule(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillRule)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetStartHead(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetStartHead(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStartHead(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStartHead(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStartHead(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& startHead)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStartHead(SBMLDocument* document, const std::string& attribute, const std::string& startHead)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetEndHead(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetEndHead(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getEndHead(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getEndHead(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setEndHead(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& endHead)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setEndHead(SBMLDocument* document, const std::string& attribute, const std::string& endHead)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumGeometricShapes(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumGeometricShapes(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShape(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShape(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::addGeometricShape(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& shape)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::addGeometricShape(SBMLDocument* document, const std::string& attribute, const std::string& shape)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::removeGeometricShape(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::removeGeometricShape(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShape(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& shape)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShape(SBMLDocument* document, const std::string& attribute, const std::string& shape)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShape(SBMLDocument* document, unsigned int layoutIndex, const std::string& shape)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShape(SBMLDocument* document, unsigned int layoutIndex, const std::string& shape)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShape(SBMLDocument* document, unsigned int layoutIndex, const std::string& shape)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShape(SBMLDocument* document, unsigned int layoutIndex, const std::string& shape)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isRectangle(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isRectangle(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isEllipse(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isEllipse(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isPolygon(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isPolygon(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isRenderCurve(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isRenderCurve(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isImage(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isImage(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isText(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isText(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeWidth(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeWidth(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeWidth(SBMLDocument* document, const std::string& attribute, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeWidth(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeWidth(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeWidth(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeWidth(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeWidth(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeHeight(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeHeight(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeHeight(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeHeight(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeHeight(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeHeight(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeHeight(SBMLDocument* document, const std::string& attribute, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeHeight(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeHeight(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeHeight(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeHeight(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeHeight(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeRatio(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeRatio(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeRatio(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeRatio(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRatio(SBMLDocument* document, GraphicalObject* graphicalObject, const double& ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRatio(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRatio(SBMLDocument* document, const std::string& attribute, const double& ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRatio(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeRatio(SBMLDocument* document, unsigned int layoutIndex, const double& ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeRatio(SBMLDocument* document, unsigned int layoutIndex, const double& ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeRatio(SBMLDocument* document, unsigned int layoutIndex, const double& ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRatio(SBMLDocument* document, unsigned int layoutIndex, const double& ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& attribute, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& attribute, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterY(SBMLDocument* document, const std::string& attribute, const RelAbsVector& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeCenterY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeCenterY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeCenterY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeRadiusX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeRadiusX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusX(SBMLDocument* document, const std::string& attribute, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeRadiusY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeRadiusY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusY(SBMLDocument* document, const std::string& attribute, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1Y(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& attribute, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeBasePoint2X(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2X(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2X(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2X(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& attribute, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeBasePoint2Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2Y(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& attribute, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::addRenderPointToGeometricShape(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::addRenderPointToGeometricShape(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::addRenderCubicBezierToGeometricShape(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::addRenderCubicBezierToGeometricShape(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::removeElementFromGeometricShape(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::removeElementFromGeometricShape(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isRenderCubicBezier(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isRenderCubicBezier(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeHref(SBMLDocument* document, GraphicalObject* graphicalObject = 0, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeHref(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeHref(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeHref(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeHref(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& href)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeHref(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const std::string& href)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeHref(SBMLDocument* document, const std::string& attribute, const std::string& href)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeHref(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const std::string& href)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeHref(SBMLDocument* document, unsigned int layoutIndex, const std::string& href)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeHref(SBMLDocument* document, unsigned int layoutIndex, const std::string& href)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeHref(SBMLDocument* document, unsigned int layoutIndex, const std::string& href)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeHref(SBMLDocument* document, unsigned int layoutIndex, const std::string& href)