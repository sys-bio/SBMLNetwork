C++ API Reference
==================

This is the API reference for the C++ API of the SBMLNetwork library.

************************
SBMLDocument Functions
************************

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getVersion()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurrentDirectoryOfLibrary()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::readSBML(const std::string &sbml)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::writeSBML(SBMLDocument* document, const std::string &fileName)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::writeSBML(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSBMLLevel(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSBMLVersion(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::freeSBMLDocument(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetModel(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::autolayout(SBMLDocument* document, const int maxNumConnectedEdges = 3, bool useNameAsTextLabel = true, bool resetLockedNodes = false, std::set<std::string> lockedNodeIds = std::set<std::string>())

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::autorender(SBMLDocument* document, const int maxNumConnectedEdges = 3)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::align(SBMLDocument* document, std::set<std::string> nodeIds, const std::string& alignment, const bool ignoreLockedNodes = false)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::distribute(SBMLDocument* document, std::set<std::pair<std::string, unsigned int>> nodeIds, const std::string& direction, const double spacing = -1)

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

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDefaultLayoutLocations(SBMLDocument* document, Layout* layout, const int maxNumConnectedEdges = 3, bool useNameAsTextLabel = true, bool resetLockedNodes = false, const std::set<std::string> lockedNodeIds = std::set<std::string>())

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createDefaultLayoutLocations(SBMLDocument* document, const int maxNumConnectedEdges = 3, bool useNameAsTextLabel = true, bool resetLockedNodes = false, const std::set<std::string> lockedNodeIds = std::set<std::string>())

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createDefaultLayoutFeatures(SBMLDocument* document, const int maxNumConnectedEdges = 3)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::updateLayoutCurves(SBMLDocument* document, Layout* layout)

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

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceGlyphIndex = 0, unsigned int curveSegmentIndex = 0)

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

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex = 0, unsigned int speciesReferenceIndex = 0, unsigned int curveSegmentIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int curveSegmentIndex, const double& x)

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

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGraphicalObjectId(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& graphicalObjectId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGraphicalObjectId(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int textGlyphIndex, const std::string& graphicalObjectId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isTextGlyph(SBMLDocument* document, const std::string& id, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isTextGlyph(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setPositionX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& x, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setPositionY(SBMLDocument* document, const std::string& id, const double& y, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& y, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setPositionY(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& y, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setPositionY(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& y, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setPosition(SBMLDocument* document, const std::string& id, const double& x, const double& y, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& x, const double& y, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setPosition(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& x, const double& y, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setPosition(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& x, const double& y, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionWidth(SBMLDocument* document, const std::string& id, const double& width, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& width, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionWidth(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& width, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& width, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const double& width, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesDimensionWidth()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const double& width, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionDimensionWidth()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionDimensionWidth(SBMLDocument* document, unsigned int layoutIndex, const double& width, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionHeight(SBMLDocument* document, const std::string& id, const double& height, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, const double& height, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionHeight(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, const double& height, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, const double& height, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const double& height, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesDimensionHeight()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const double& height, bool updateCurves = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionDimensionHeight()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionDimensionHeight(SBMLDocument* document, unsigned int layoutIndex, const double& height, bool updateCurves = true)

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

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetCurve(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetCurve(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurve(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurve(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumCurveSegments(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumCurveSegments(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegment(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createLineCurveSegment(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createLineCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createCubicBezierCurveSegment(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createCubicBezierCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::removeCurveSegment(SBMLDocument* document, const std::string& id, unsigned int curveSegmentIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::removeCurveSegment(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int curveSegmentIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isCubicBezier(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isCubicBezier(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegmentStartPointX(SBMLDocument* document, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCurveSegmentStartPointX(SBMLDocument* document, unsigned int layoutIndex, const std::string& id, unsigned int graphicalObjectIndex, unsigned int curveSegmentIndex)

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

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getListOfGlobalRenderInformation(SBMLDocument* document)

.. doxygenfunction::  LIBSBMLNETWORK_CPP_NAMESPACE::getNumGlobalRenderInformation(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGlobalRenderInformation(SBMLDocument* document, unsigned int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::addGlobalRenderInformation(SBMLDocument* document, GlobalRenderInformation* globalRenderInformation)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createGlobalRenderInformation(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::removeAllGlobalRenderInformation(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDefaultGlobalRenderInformationFeatures(SBMLDocument* document, GlobalRenderInformation* globalRenderInformation)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getListOfLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex = 0, unsigned int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::addLocalRenderInformation(SBMLDocument* document, LocalRenderInformation* localRenderInformation)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::addLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex, LocalRenderInformation* localRenderInformation)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::removeAllLocalRenderInformation(SBMLDocument* document, unsigned int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDefaultLocalRenderInformationFeatures(SBMLDocument* document, LocalRenderInformation* localRenderInformation)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setDefaultLocalRenderInformationFeatures(SBMLDocument* document, unsigned int layoutIndex, LocalRenderInformation* localRenderInformation)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createDefaultRenderInformation(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createDefaultGlobalRenderInformation(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createDefaultLocalRenderInformation(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::removeRenderInformation(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetBackgroundColor(SBMLDocument* document, unsigned int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getBackgroundColor(SBMLDocument* document, unsigned int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setBackgroundColor(SBMLDocument* document, const std::string& backgroundColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setBackgroundColor(SBMLDocument* document, unsigned int renderIndex, const std::string& backgroundColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumGlobalColorDefinitions(SBMLDocument* document, unsigned int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthGlobalColorDefinitionId(SBMLDocument* document, unsigned int renderIndex = 0, unsigned int colorIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumLocalColorDefinitions(SBMLDocument* document, unsigned int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthLocalColorDefinitionId(SBMLDocument* document, unsigned int renderIndex = 0, unsigned int colorIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getColorDefinition(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getColorDefinition(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getColorDefinition(SBMLDocument* document, unsigned int renderIndex = 0, unsigned int colorIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetValue(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetValue(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getValue(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getValue(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setValue(SBMLDocument* document, const std::string& sid, const std::string& value)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setValue(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const std::string& value)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumGlobalGradientDefinitions(SBMLDocument* document, unsigned int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumLocalGradientDefinitions(SBMLDocument* document, unsigned int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthGlobalGradientDefinitionId(SBMLDocument* document, unsigned int renderIndex = 0, unsigned int gradientIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthLocalGradientDefinitionId(SBMLDocument* document, unsigned int renderIndex = 0, unsigned int gradientIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGradientDefinition(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGradientDefinition(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGradientDefinition(SBMLDocument* document, unsigned int renderIndex = 0, unsigned int gradientIndex = 0)

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

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGradientStop(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGradientStop(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetOffset(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetOffset(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getOffset(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getOffset(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getOffsetAsDouble(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getOffsetAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setOffset(SBMLDocument* document, const std::string& sid, const RelAbsVector& offset)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setOffset(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& offset)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setOffset(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex, const RelAbsVector& offset)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setOffset(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex, const RelAbsVector& offset)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setOffsetAsDouble(SBMLDocument* document, const std::string& sid, const double& offset)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setOffsetAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const double& offset)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setOffsetAsDouble(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex, const double& offset)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setOffsetAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex, const double& offset)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetStopColor(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetStopColor(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStopColor(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStopColor(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStopColor(SBMLDocument* document, const std::string& sid, const std::string& stopColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStopColor(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const std::string& stopColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStopColor(SBMLDocument* document, const std::string& sid, unsigned int gradientStopIndex, const std::string& stopColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStopColor(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, unsigned int gradientStopIndex, const std::string& stopColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLinearGradientX1(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLinearGradientX1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientX1(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientX1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientX1AsDouble(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientX1AsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientX1(SBMLDocument* document, const std::string& sid, const RelAbsVector& x1)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientX1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& x1)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientX1AsDouble(SBMLDocument* document, const std::string& sid, const double& x1)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientX1AsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const double& x1)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLinearGradientX2(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLinearGradientX2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientX2(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientX2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientX2AsDouble(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientX2AsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientX2(SBMLDocument* document, const std::string& sid, const RelAbsVector& x2)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientX2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& x2)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientX2AsDouble(SBMLDocument* document, const std::string& sid, const double& x2)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientX2AsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const double& x2)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLinearGradientY1(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLinearGradientY1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientY1(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientY1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientY1AsDouble(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientY1AsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientY1(SBMLDocument* document, const std::string& sid, const RelAbsVector& y1)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientY1(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& y1)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientY1AsDouble(SBMLDocument* document, const std::string& sid, const double& y1)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientY1AsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const double& y1)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLinearGradientY2(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLinearGradientY2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientY2(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientY2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientY2AsDouble(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLinearGradientY2AsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientY2(SBMLDocument* document, const std::string& sid, const RelAbsVector& y2)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientY2(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& y2)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientY2AsDouble(SBMLDocument* document, const std::string& sid, const double& y2)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLinearGradientY2AsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const double& y2)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetRadialGradientCx(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetRadialGradientCx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientCx(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientCx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientCxAsDouble(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientCxAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientCx(SBMLDocument* document, const std::string& sid, const RelAbsVector& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientCx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientCxAsDouble(SBMLDocument* document, const std::string& sid, const double& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientCxAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const double& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetRadialGradientCy(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetRadialGradientCy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientCy(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientCy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientCyAsDouble(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientCyAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientCy(SBMLDocument* document, const std::string& sid, const RelAbsVector& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientCy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientCyAsDouble(SBMLDocument* document, const std::string& sid, const double& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientCyAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const double& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetRadialGradientFx(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetRadialGradientFx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientFx(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientFx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientFxAsDouble(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientFxAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientFx(SBMLDocument* document, const std::string& sid, const RelAbsVector& fx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientFx(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& fx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientFxAsDouble(SBMLDocument* document, const std::string& sid, const double& fx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientFxAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const double& fx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetRadialGradientFy(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetRadialGradientFy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientFy(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientFy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientFyAsDouble(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientFyAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientFy(SBMLDocument* document, const std::string& sid, const RelAbsVector& fy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientFy(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& fy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientFyAsDouble(SBMLDocument* document, const std::string& sid, const double& fy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientFyAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const double& fy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetRadialGradientR(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetRadialGradientR(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientR(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientR(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientRAsDouble(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getRadialGradientRAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientR(SBMLDocument* document, const std::string& sid, const RelAbsVector& r)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientR(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const RelAbsVector& r)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientRAsDouble(SBMLDocument* document, const std::string& sid, const double& r)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setRadialGradientRAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, const double& r)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumGlobalLineEndings(SBMLDocument* document, unsigned int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumLocalLineEndings(SBMLDocument* document, unsigned int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthGlobalLineEndingId(SBMLDocument* document, unsigned int renderIndex = 0, unsigned int lineEndingIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthLocalLineEndingId(SBMLDocument* document, unsigned int renderIndex = 0, unsigned int lineEndingIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEnding(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEnding(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEnding(SBMLDocument* document, unsigned int renderIndex = 0, unsigned int lineEndingIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createLocalLineEnding(SBMLDocument* document, LineEnding* globalLineEnding, SpeciesReferenceGlyph* speciesReferenceGlyph)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEnding(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLocalLineEnding(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLocalLineEnding(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetEnableRotationalMapping(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetEnableRotationalMapping(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getEnableRotationalMapping(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getEnableRotationalMapping(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setEnableRotationalMapping(SBMLDocument* document, const std::string& sid, bool enableRotationalMapping)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setEnableRotationalMapping(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, bool enableRotationalMapping)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingBoundingBox(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingBoundingBox(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingBoundingBox(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingBoundingBox(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingBoundingBoxX(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingBoundingBoxX(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingBoundingBoxX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingBoundingBoxX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingBoundingBoxX(SBMLDocument* document, const std::string& sid, double x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingBoundingBoxX(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, double x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingBoundingBoxX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const double x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingBoundingBoxX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const double x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingBoundingBoxX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, const double x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingBoundingBoxX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, const double x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingBoundingBoxY(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingBoundingBoxY(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingBoundingBoxY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingBoundingBoxY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingBoundingBoxY(SBMLDocument* document, const std::string& sid, double y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingBoundingBoxY(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, double y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingBoundingBoxY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const double y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingBoundingBoxY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const double y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingBoundingBoxY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, const double y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingBoundingBoxY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, const double y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingBoundingBoxWidth(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingBoundingBoxWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingBoundingBoxWidth(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingBoundingBoxWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingBoundingBoxWidth(SBMLDocument* document, const std::string& sid, double width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingBoundingBoxWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, double width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingBoundingBoxWidth(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const double width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingBoundingBoxWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const double width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingBoundingBoxWidth(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, const double width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingBoundingBoxWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, const double width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingBoundingBoxHeight(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingBoundingBoxHeight(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingBoundingBoxHeight(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingBoundingBoxHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingBoundingBoxHeight(SBMLDocument* document, const std::string& sid, double height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingBoundingBoxWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingBoundingBoxHeight(SBMLDocument* document, unsigned int renderIndex, const std::string& sid, double height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingBoundingBoxHeight(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const double height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingBoundingBoxHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const double height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingBoundingBoxHeight(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, const double height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingBoundingBoxHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, const double height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingRenderGroup(SBMLDocument* document, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingRenderGroup(SBMLDocument* document, unsigned int renderIndex, const std::string& sid)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingStrokeColor(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingStrokeColor(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingStrokeColor(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingStrokeColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingStrokeColor(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingStrokeColor(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingStrokeColor(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingStrokeColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingStrokeColor(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingStrokeColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeColor(SBMLDocument* document, const std::string& id, const std::string& stroke)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeColor(SBMLDocument* document, unsigned int renderIndex, const std::string& id, const std::string& stroke)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingStrokeColor(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const std::string& strokeColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingStrokeColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const std::string& strokeColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingStrokeColor(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, const std::string& strokeColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingStrokeColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, const std::string& strokeColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingStrokeWidth(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingStrokeWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingStrokeWidth(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingStrokeWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingStrokeWidth(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingStrokeWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingStrokeWidth(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingStrokeWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeWidth(SBMLDocument* document, const std::string& id, double strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& id, double strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingStrokeWidth(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const double strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingStrokeWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const double strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingStrokeWidth(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, const double strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingStrokeWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, const double strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingStrokeDashArray(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingStrokeDashArray(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumSpeciesReferenceLineEndingStrokeDashes(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumSpeciesReferenceLineEndingStrokeDashes(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingStrokeDashArray(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingStrokeDashArray(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeDashArray(SBMLDocument* document, const std::string& id, const std::vector<unsigned int>& strokeDashArray)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeDashArray(SBMLDocument* document, unsigned int renderIndex, const std::string& id, const std::vector<unsigned int>& strokeDashArray)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumLineEndingStrokeDashes(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumLineEndingStrokeDashes(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingStrokeDash(SBMLDocument* document, const std::string& id, unsigned int dashIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingStrokeDash(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int dashIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingStrokeDash(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int dashIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingStrokeDash(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int dashIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeDash(SBMLDocument* document, const std::string& id, unsigned int dash)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeDash(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int dash)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeDash(SBMLDocument* document, const std::string& id, unsigned int dashIndex, unsigned int dash)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeDash(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int dashIndex, unsigned int dash)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingStrokeDash(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int dashIndex, unsigned int dash)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingStrokeDash(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int dashIndex, unsigned int dash)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingStrokeDash(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int dashIndex, unsigned int dash)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingStrokeDash(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int dashIndex, unsigned int dash)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingFillColor(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingFillColor(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingFillColor(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingFillColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingFillColor(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingFillColor(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingFillColor(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingFillColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingFillColor(SBMLDocument* document, const std::string& id, const std::string& fill)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingFillColorAsGradient(SBMLDocument* document, const std::string& id, const std::string& gradientType, std::vector<std::pair<std::string, double>> stopsVector)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingFillColor(SBMLDocument* document, unsigned int renderIndex, const std::string& id, const std::string& fill)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingFillColorAsGradient(SBMLDocument* document, unsigned int renderIndex, const std::string& id, const std::string& gradientType, std::vector<std::pair<std::string, double>> stopsVector)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingFillColor(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingFillColorAsGradient(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const std::string& gradientType, std::vector<std::pair<std::string, double>> stopsVector)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingFillColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingFillColorAsGradient(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const std::string& gradientType, std::vector<std::pair<std::string, double>> stopsVector)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingFillColor(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingFillColorAsGradient(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, const std::string& gradientType, std::vector<std::pair<std::string, double>> stopsVector)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingFillColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingFillColorAsGradient(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, const std::string& gradientType, std::vector<std::pair<std::string, double>> stopsVector)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingFillRule(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingFillRule(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingFillRule(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingFillRule(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingFillRule(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingFillRule(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingFillRule(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingFillRule(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingFillRule(SBMLDocument* document, const std::string& id, const std::string& fillRule)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingFillRule(SBMLDocument* document, unsigned int renderIndex, const std::string& id, const std::string& fillRule)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingFillRule(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const std::string& fillRule)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingFillRule(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, const std::string& fillRule)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingFillRule(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, const std::string& fillRule)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingFillRule(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, const std::string& fillRule)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumLineEndingGeometricShapes(SBMLDocument* document, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumLineEndingGeometricShapes(SBMLDocument* document, unsigned int renderIndex, const std::string& id)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumSpeciesReferenceLineEndingGeometricShapes(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumSpeciesReferenceLineEndingGeometricShapes(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingRectangle(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingRectangle(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSpeciesReferenceLineEndingRectangle(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSpeciesReferenceLineEndingRectangle(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingEllipse(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingEllipse(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSpeciesReferenceLineEndingEllipse(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSpeciesReferenceLineEndingEllipse(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingPolygon(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingPolygon(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSpeciesReferenceLineEndingPolygon(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSpeciesReferenceLineEndingPolygon(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingImage(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingImage(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSpeciesReferenceLineEndingImage(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSpeciesReferenceLineEndingImage(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingRenderCurve(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingRenderCurve(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSpeciesReferenceLineEndingRenderCurve(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSpeciesReferenceLineEndingRenderCurve(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingText(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingText(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSpeciesReferenceLineEndingText(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSpeciesReferenceLineEndingText(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeXAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeXAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeXAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeXAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeXAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeXAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeXAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeYAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeYAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeYAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeYAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeYAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeYAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeYAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeWidth(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeWidth(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeWidth(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeWidth(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeWidthAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeWidthAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeWidthAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeWidthAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeWidth(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeWidth(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeWidth(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeWidth(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeWidth(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeWidthAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeWidthAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeWidthAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeWidthAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeWidthAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeWidthAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeHeight(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeHeight(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeHeight(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeHeight(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeHeight(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeHeight(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeHeightAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeHeightAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeHeightAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeHeightAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeHeight(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeHeight(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeHeight(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeHeight(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeHeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeHeightAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeHeightAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeHeightAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeHeightAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeHeightAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeHeightAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeRatio(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeRatio(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeRatio(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeRatio(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeRatio(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeRatio(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeRatio(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeRatio(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeRatio(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, double ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeRatio(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, double ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeRatio(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeRatio(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeRatio(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeRatio(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& CornerCurvatureRadiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& CornerCurvatureRadiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const RelAbsVector& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const RelAbsVector& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const RelAbsVector& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const RelAbsVector& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const double& CornerCurvatureRadiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const double& CornerCurvatureRadiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& CornerCurvatureRadiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& CornerCurvatureRadiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const RelAbsVector& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const RelAbsVector& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const RelAbsVector& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const RelAbsVector& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const double& CornerCurvatureRadiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const double& CornerCurvatureRadiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeCenterX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeCenterX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeCenterX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeCenterX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCenterX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCenterX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeCenterX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeCenterX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCenterXAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCenterXAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeCenterXAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeCenterXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCenterX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& centerX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCenterX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& centerX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeCenterX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const RelAbsVector& centerX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeCenterX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const RelAbsVector& centerX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeCenterX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const RelAbsVector& centerX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeCenterX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const RelAbsVector& centerX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCenterXAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const double& centerX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCenterXAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const double& centerX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeCenterXAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& centerX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeCenterXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& centerX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeCenterXAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& centerX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeCenterXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& centerX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeCenterY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeCenterY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeCenterY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeCenterY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCenterY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCenterY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeCenterY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeCenterY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCenterYAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeCenterYAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeCenterYAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeCenterYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCenterY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& centerY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCenterY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& centerY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeCenterY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const RelAbsVector& centerY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeCenterY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const RelAbsVector& centerY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeCenterY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const RelAbsVector& centerY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeCenterY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const RelAbsVector& centerY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCenterYAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const double& centerY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeCenterYAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const double& centerY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeCenterYAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& centerY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeCenterYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& centerY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeCenterYAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& centerY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeCenterYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& centerY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeRadiusX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeRadiusX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeRadiusX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeRadiusX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeRadiusX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeRadiusX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeRadiusX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeRadiusX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeRadiusXAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeRadiusXAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeRadiusXAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeRadiusX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeRadiusX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeRadiusX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const RelAbsVector& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeRadiusX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const RelAbsVector& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeRadiusX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const RelAbsVector& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeRadiusX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const RelAbsVector& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeRadiusXAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const double& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeRadiusXAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const double& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeRadiusXAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeRadiusXAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& radiusX)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeRadiusY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeRadiusY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeRadiusY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeRadiusY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeRadiusY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeRadiusY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeRadiusY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeRadiusY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeRadiusYAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeRadiusYAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeRadiusYAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeRadiusY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeRadiusY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const RelAbsVector& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeRadiusY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const RelAbsVector& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeRadiusY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const RelAbsVector& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeRadiusY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const RelAbsVector& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeRadiusY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const RelAbsVector& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeRadiusYAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const double& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeRadiusYAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const double& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeRadiusYAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const double& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeRadiusYAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const double& radiusY)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeNumElements(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeNumElements(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeNumElements(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeNumElements(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingGeometricShapeElementCubicBezier(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLineEndingGeometricShapeElementCubicBezier(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSpeciesReferenceLineEndingGeometricShapeElementCubicBezier(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSpeciesReferenceLineEndingGeometricShapeElementCubicBezier(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeElementX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeElementX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeElementX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeElementX(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeElementX(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeElementX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeElementX(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeElementY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeElementY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeElementY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeElementY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeElementYAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeElementYAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeElementYAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeElementYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeElementY(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeElementY(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeElementY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeElementY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeElementY(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeElementY(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeElementYAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeElementYAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeElementYAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeElementYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeElementYAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeElementYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const std::string& reactionId

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint1X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint1X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint1X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint1X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint1X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint1X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint1X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint1X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint1X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint1X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint1X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint1X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint1Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint1Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint1Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint1Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint1Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint1Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint1Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint1Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint1Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint1Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint2X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint2X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint2X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint2X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint2X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint2X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint2X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint2X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint2X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint2X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint2X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint2X)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint2Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint2Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint2Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint2Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint2Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& basePoint2Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint2Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint2Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint2Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint2Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint2Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& basePoint2Y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeHref(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetLineEndingGeometricShapeHref(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeHref(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetSpeciesReferenceLineEndingGeometricShapeHref(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeHref(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getLineEndingGeometricShapeHref(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeHref(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesReferenceLineEndingGeometricShapeHref(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeHref(SBMLDocument* document, const std::string& id, unsigned int geometricShapeIndex, const std::string& href)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingGeometricShapeHref(SBMLDocument* document, unsigned int renderIndex, const std::string& id, unsigned int geometricShapeIndex, const std::string& href)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeHref(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const std::string& href)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesReferenceLineEndingGeometricShapeHref(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int speciesReferenceIndex, unsigned int geometricShapeIndex, const std::string& href)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeHref(SBMLDocument* document, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const std::string& href)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionLineEndingGeometricShapeHref(SBMLDocument* document, unsigned int layoutIndex, const std::string& reactionId, unsigned int reactionGlyphIndex, unsigned int geometricShapeIndex, const std::string& href)

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

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentStrokeColor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentStrokeColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& stroke)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesStrokeColor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesStrokeColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& stroke)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionStrokeColor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionStrokeColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& stroke, bool setSpeciesReferenceGlyphs = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& stroke)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& stroke)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetStrokeWidth(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetStrokeWidth(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStrokeWidth(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStrokeWidth(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, const double& strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStrokeWidth(SBMLDocument* document, const std::string& attribute, const double& strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentStrokeWidth(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentStrokeWidth(SBMLDocument* document, unsigned int layoutIndex, const double& strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesStrokeWidth(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesStrokeWidth(SBMLDocument* document, unsigned int layoutIndex, const double& strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionStrokeWidth(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionStrokeWidth(SBMLDocument* document, unsigned int layoutIndex, const double& strokeWidth, bool setSpeciesReferenceGlyphs = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingStrokeWidth(SBMLDocument* document, unsigned int layoutIndex, const double& strokeWidth)

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

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontColor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFontColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFontColor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFontColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFontColor(SBMLDocument* document)

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

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontFamily(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFontFamily(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontFamily)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFontFamily(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFontFamily(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontFamily)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFontFamily(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFontFamily(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontFamily)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontFamily(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontFamily)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFontSize(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFontSize(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFontSize(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFontSize(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFontSizeAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFontSizeAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontSize(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontSize(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const RelAbsVector& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontSize(SBMLDocument* document, const std::string& attribute, const RelAbsVector& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontSize(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex, const RelAbsVector& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontSizeAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontSizeAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const double& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontSizeAsDouble(SBMLDocument* document, const std::string& attribute, const double& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontSizeAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex, const double& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontSize(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFontSize(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontSizeAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFontSizeAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFontSize(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFontSize(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFontSizeAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFontSizeAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFontSize(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFontSize(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFontSizeAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFontSizeAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontSize(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontSizeAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& fontSize)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFontWeight(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFontWeight(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFontWeight(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFontWeight(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontWeight(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fontWeight)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontWeight(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const std::string& fontWeight)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontWeight(SBMLDocument* document, const std::string& attribute, const std::string& fontWeight)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFontWeight(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex, const std::string& fontWeight)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontWeight(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFontWeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontWeight)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFontWeight(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFontWeight(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontWeight)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFontWeight(SBMLDocument* document)

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

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFontStyle(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFontStyle(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontStyle)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFontStyle(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFontStyle(SBMLDocument* document, unsigned int layoutIndex, const std::string& fontStyle)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFontStyle(SBMLDocument* document)

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

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentTextAnchor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& textAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesTextAnchor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& textAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionTextAnchor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& textAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& textAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetVTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetVTextAnchor(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getVTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getVTextAnchor(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setVTextAnchor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int textGlyphIndex, const std::string& vtextAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setVTextAnchor(SBMLDocument* document, const std::string& attribute, unsigned int textGlyphIndex, const std::string& vtextAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentVTextAnchor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentVTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& vtextAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesVTextAnchor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesVTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& vtextAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionVTextAnchor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionVTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& vtextAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setVTextAnchor(SBMLDocument* document, unsigned int layoutIndex, const std::string& vtextAnchor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFillColor(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFillColor(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFillColor(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFillColor(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFillColor(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFillColor(SBMLDocument* document, const std::string& attribute, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFillColorAsGradient(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& gradientType, std::vector<std::pair<std::string, double>> stopsVector)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFillColorAsGradient(SBMLDocument* document, const std::string& attribute, const std::string& gradientType, std::vector<std::pair<std::string, double>> stopsVector)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFillColor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFillColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFillColorAsGradient(SBMLDocument* document, unsigned int layoutIndex, const std::string& gradientType, std::vector<std::pair<std::string, double>> stopsVector)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFillColor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFillColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFillColorAsGradient(SBMLDocument* document, unsigned int layoutIndex, const std::string& gradientType, std::vector<std::pair<std::string, double>> stopsVector)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFillColor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFillColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFillColorAsGradient(SBMLDocument* document, unsigned int layoutIndex, const std::string& gradientType, std::vector<std::pair<std::string, double>> stopsVector)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingFillColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingFillColorAsGradient(SBMLDocument* document, unsigned int layoutIndex, const std::string& gradientType, std::vector<std::pair<std::string, double>> stopsVector)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFillColor(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFillColorAsGradient(SBMLDocument* document, unsigned int layoutIndex, const std::string& gradientType, std::vector<std::pair<std::string, double>> stopsVector)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFillRule(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetFillRule(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFillRule(SBMLDocument* document, GraphicalObject* graphicalObject)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getFillRule(SBMLDocument* document, const std::string& attribute)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFillRule(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fillRule)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setFillRule(SBMLDocument* document, const std::string& attribute, const std::string& fillRule)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentFillRule(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentFillRule(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillRule)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesFillRule(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesFillRule(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillRule)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionFillRule(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionFillRule(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillRule)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setLineEndingFillRule(SBMLDocument* document, unsigned int layoutIndex, const std::string& fillRule)

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

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeType(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeType(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeType(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& shape)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeType(SBMLDocument* document, const std::string& attribute, const std::string& shape)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeType(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeType(SBMLDocument* document, unsigned int layoutIndex, const std::string& shape)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeType(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeType(SBMLDocument* document, unsigned int layoutIndex, const std::string& shape)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeType(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeType(SBMLDocument* document, unsigned int layoutIndex, const std::string& shape)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeType(SBMLDocument* document, unsigned int layoutIndex, const std::string& shape)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isRectangle(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isRectangle(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSquare(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSquare(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isEllipse(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isEllipse(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isCircle(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isCircle(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isPolygon(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isPolygon(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isRenderCurve(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isRenderCurve(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isImage(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isImage(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isText(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isText(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeStrokeColor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeStrokeColor(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeStrokeColor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeStrokeColor(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeStrokeColor(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& strokeColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeStrokeColor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const std::string& strokeColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeStrokeColor(SBMLDocument* document, const std::string& attribute, const std::string& strokeColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeStrokeColor(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const std::string& strokeColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeStrokeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeStrokeWidth(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeStrokeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeStrokeWidth(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeStrokeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, const double& strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeStrokeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeStrokeWidth(SBMLDocument* document, const std::string& attribute, const double& strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeStrokeWidth(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& strokeWidth)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeFillColor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeFillColor(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeFillColor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeFillColor(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeFillColor(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeFillColorAsGradient(SBMLDocument* document, GraphicalObject* graphicalObject, const std::string& gradientType, std::vector<std::pair<std::string, double>> stopsVector)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeFillColor(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeFillColorAsGradient(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const std::string& gradientType, std::vector<std::pair<std::string, double>> stopsVector)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeFillColor(SBMLDocument* document, const std::string& attribute, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeFillColorAsGradient(SBMLDocument* document, const std::string& attribute, const std::string& gradientType, std::vector<std::pair<std::string, double>> stopsVector)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeFillColor(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const std::string& fillColor)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeFillColorAsGradient(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const std::string& gradientType, std::vector<std::pair<std::string, double>> stopsVector)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeX(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeX(SBMLDocument* document, const std::string& attribute, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeXAsDouble(SBMLDocument* document, const std::string& attribute, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeYAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeY(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeY(SBMLDocument* document, const std::string& attribute, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeYAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeYAsDouble(SBMLDocument* document, const std::string& attribute, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeYAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeYAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeYAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeWidth(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeWidth(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeWidthAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeWidthAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeWidth(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeWidth(SBMLDocument* document, const std::string& attribute, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeWidth(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeWidthAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeWidthAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeWidthAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeWidthAsDouble(SBMLDocument* document, const std::string& attribute, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeWidth(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeWidth(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeWidthAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeWidthAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeWidth(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeWidth(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeWidthAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeWidthAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeWidth(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeWidth(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeWidthAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeWidthAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeWidth(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeWidthAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& width)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeHeight(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeHeight(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeHeight(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeHeight(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeHeightAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeHeightAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeHeight(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeHeight(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeHeight(SBMLDocument* document, const std::string& attribute, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeHeight(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeHeightAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeHeightAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeHeight(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeHeight(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeHeightAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeHeightAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeHeight(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeHeight(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeHeightAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeHeightAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeHeight(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeHeight(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeHeightAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeHeightAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeHeight(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeHeightAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& height)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeRatio(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeRatio(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeRatio(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeRatio(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRatio(SBMLDocument* document, GraphicalObject* graphicalObject, const double& ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRatio(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRatio(SBMLDocument* document, const std::string& attribute, const double& ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRatio(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeRatio(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeRatio(SBMLDocument* document, unsigned int layoutIndex, const double& ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeRatio(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeRatio(SBMLDocument* document, unsigned int layoutIndex, const double& ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeRatio(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeRatio(SBMLDocument* document, unsigned int layoutIndex, const double& ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRatio(SBMLDocument* document, unsigned int layoutIndex, const double& ratio)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& attribute, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, const std::string& attribute, const double& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& attribute, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, const std::string& attribute, const double& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeCornerCurvatureRadiusX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCornerCurvatureRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeCenterX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeCenterX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeCenterX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeCenterX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeCenterXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeCenterXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterX(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterX(SBMLDocument* document, const std::string& attribute, const RelAbsVector& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterXAsDouble(SBMLDocument* document, const std::string& attribute, const double& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeCenterX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeCenterX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeCenterXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeCenterXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeCenterX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeCenterX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeCenterXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeCenterXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeCenterX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeCenterX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeCenterXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeCenterXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& cx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeCenterY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeCenterY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeCenterY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeCenterY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeCenterYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeCenterYAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterY(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterY(SBMLDocument* document, const std::string& attribute, const RelAbsVector& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterYAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterYAsDouble(SBMLDocument* document, const std::string& attribute, const double& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeCenterY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeCenterY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeCenterYAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeCenterYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeCenterY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeCenterY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeCenterYAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeCenterYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeCenterY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeCenterY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeCenterYAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeCenterYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeCenterYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& cy)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeRadiusX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeRadiusX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeRadiusXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeRadiusXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusX(SBMLDocument* document, const std::string& attribute, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusXAsDouble(SBMLDocument* document, const std::string& attribute, const double& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeRadiusX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeRadiusXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeRadiusX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeRadiusXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeRadiusX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeRadiusXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusX(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusXAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& rx)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetGeometricShapeRadiusY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeRadiusY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeRadiusYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeRadiusYAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusY(SBMLDocument* document, const std::string& attribute, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusY(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, const double& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusYAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, const double& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusYAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusYAsDouble(SBMLDocument* document, const std::string& attribute, const double& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeRadiusX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeRadiusYAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeRadiusY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeRadiusYAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeRadiusY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeRadiusYAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusY(SBMLDocument* document, unsigned int layoutIndex, const RelAbsVector& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeRadiusYAsDouble(SBMLDocument* document, unsigned int layoutIndex, const double& ry)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeNumElements(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeNumElements(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isGeometricShapeElementCubicBezier(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isGeometricShapeElementCubicBezier(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeElementX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeElementX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeElementXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementX(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementX(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementX(SBMLDocument* document, const std::string& attribute, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementX(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementX(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& attribute, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeElementX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeElementXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeElementX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeElementXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeElementX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeElementXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeElementY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& attribute, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeElementX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeElementXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeElementX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeElementXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeElementX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeElementXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeElementY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& attribute, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeElementX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeElementXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeElementX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeElementXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeElementX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeElementXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeElementY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& attribute, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeElementX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeElementXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeElementX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeElementXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeElementX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeElementXAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementX(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeElementXAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeElementY(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)/// @brief Sets the value of the "x" attribute of the base point 1 of the first element of the first Transformation2D of the RenderGroup of the Style that matches this attribute (id, role, type) of a GraphicalObject as a double.

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, const std::string& attribute, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeBasePoint1X(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeBasePoint1XAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeBasePoint1X(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeBasePoint1XAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeBasePoint1X(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeBasePoint1XAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1X(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1XAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeBasePoint1Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1Y(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& attribute, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1Y(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, const std::string& attribute, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeBasePoint1Y(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeBasePoint1YAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeBasePoint1Y(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeBasePoint1YAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeBasePoint1Y(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeBasePoint1YAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint1YAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeBasePoint2X(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2X(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2X(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2X(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& attribute, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2X(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, const std::string& attribute, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeBasePoint2X(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeBasePoint2XAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeBasePoint2X(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeBasePoint2XAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeBasePoint2X(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeBasePoint2XAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2X(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2XAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& x)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeBasePoint2Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex = 0, unsigned int elementIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2Y(SBMLDocument* document, GraphicalObject* graphicalObject, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2Y(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& attribute, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2Y(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int elementIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, GraphicalObject* graphicalObject, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, const std::string& attribute, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int elementIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, const std::string& attribute, unsigned int geometricShapeIndex, unsigned int elementIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeBasePoint2Y(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeBasePoint2YAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeBasePoint2Y(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeBasePoint2YAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeBasePoint2Y(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeBasePoint2YAsDouble(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2Y(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const RelAbsVector& y)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeBasePoint2YAsDouble(SBMLDocument* document, unsigned int layoutIndex, unsigned int elementIndex, const double& y)

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

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getCompartmentGeometricShapeHref(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setCompartmentGeometricShapeHref(SBMLDocument* document, unsigned int layoutIndex, const std::string& href)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesGeometricShapeHref(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setSpeciesGeometricShapeHref(SBMLDocument* document, unsigned int layoutIndex, const std::string& href)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionGeometricShapeHref(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setReactionGeometricShapeHref(SBMLDocument* document, unsigned int layoutIndex, const std::string& href)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setGeometricShapeHref(SBMLDocument* document, unsigned int layoutIndex, const std::string& href)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getStyle(SBMLDocument* document, unsigned int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setStyle(SBMLDocument* document, unsigned int renderIndex, const std::string& styleName)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::whetherDisplayReactionTextLabel(const std::string& styleName)