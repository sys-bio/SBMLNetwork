C API Reference
==================

This is the API reference for the C API of the SBMLNetwork library.

**********
Functions
**********

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getVersion()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCurrentDirectoryOfLibrary()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_readSBML(const char* sbml)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_writeSBMLToFile(SBMLDocument* document, const char* fileName)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_writeSBMLToString(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSBMLLevel(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSBMLVersion(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_freeSBMLDocument(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetModel(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_autolayout(SBMLDocument* document, const int maxNumConnectedEdges = 3, bool useNameAsTextLabel = true, bool resetLockedNodes = false, const char** lockedNodeIds = NULL, const int lockedNodesSize = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_autorender(SBMLDocument *document, const int maxNumConnectedEdges = 3)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_align(SBMLDocument* document, const char **nodeIds, const int nodesSize,  const char* alignment, bool ignoreLockedNodes = false)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_distribute(SBMLDocument* document, const char **nodeIds, const int nodesSize,  const char* direction, const double spacing = -1.0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumLayouts(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_removeLayouts(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_createDefaultLayoutFeatures(SBMLDocument* document, const int maxNumConnectedEdges = 3)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_createDefaultLayoutLocations(SBMLDocument* document, const int maxNumConnectedEdges = 3, bool useNameAsTextLabel= true, bool resetLockedNodes = false, const char** lockedNodeIds = NULL, const int lockedNodesSize = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCanvasWidth(SBMLDocument* document, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCanvasWidth(SBMLDocument* document, const double width, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCanvasHeight(SBMLDocument* document, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCanvasHeight(SBMLDocument* document, const double height, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumAllGraphicalObjects(SBMLDocument* document, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumGraphicalObjects(SBMLDocument* document, const char* id, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthGraphicalObjectId(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthGraphicalObjectMetaId(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumCompartments(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthCompartmentId(SBMLDocument* document, int compartmentIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumAllCompartmentGlyphs(SBMLDocument* document, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumCompartmentGlyphs(SBMLDocument* document, const char* compartmentId, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthCompartmentGlyphId(SBMLDocument* document, const char* compartmentId, int compartmentGlyphIndex, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthCompartmentGlyphMetaId(SBMLDocument* document, const char* compartmentId, int compartmentGlyphIndex, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isCompartmentGlyph(SBMLDocument* document, const char* compartmentId, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentId(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumSpecies(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthSpeciesId(SBMLDocument* document, int speciesIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumAllSpeciesGlyphs(SBMLDocument* document, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumSpeciesGlyphs(SBMLDocument* document, const char* speciesId, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthSpeciesGlyphId(SBMLDocument* document, const char* speciesId, int speciesGlyphIndex, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthSpeciesGlyphMetaId(SBMLDocument* document, const char* speciesId, int speciesGlyphIndex, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSpeciesGlyph(SBMLDocument* document, const char* speciesId, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumReactions(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthReactionId(SBMLDocument* document, int reactionIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumAllReactionGlyphs(SBMLDocument* document, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumReactionGlyphs(SBMLDocument* document, const char* reactionId, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthReactionGlyphId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthReactionGlyphMetaId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isReactionGlyph(SBMLDocument* document, const char* reactionId, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumSpeciesReferences(SBMLDocument* document, const char* reactionId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumReactants(SBMLDocument* document, const char* reactionId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumProducts(SBMLDocument* document, const char* reactionId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumModifiers(SBMLDocument* document, const char* reactionId)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthReactantId(SBMLDocument* document, const char* reactionId, int reactantIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthProductId(SBMLDocument* document, const char* reactionId, int productIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthModifierId(SBMLDocument* document, const char* reactionId, int modifierIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumSpeciesReferenceGlyphs(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthSpeciesReferenceGlyphId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthSpeciesReferenceGlyphMetaId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthSpeciesReferenceGlyphSpeciesReferenceId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceSpeciesId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceSpeciesGlyphId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceRole(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceRole(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceRole(SBMLDocument* document, const char* reactionId, const char* role, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumSpeciesReferenceCurveSegments(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSpeciesReferenceCurveSegmentCubicBezier(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceBorderColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceBorderColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceBorderColor(SBMLDocument* document, const char* reactionId, const char* stroke, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceBorderWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceBorderWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceBorderWidth(SBMLDocument* document, const char* reactionId, const double strokeWidth, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumSpeciesReferenceBorderDashes(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceNthBorderDash(SBMLDocument* document, const char* reactionId, int borderDashIndex, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceNthBorderDash(SBMLDocument* document, const char* reactionId, const int borderDash, int borderDashIndex, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceStartHead(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceStartHead(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceStartHead(SBMLDocument* document, const char* reactionId, const char* startHead, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceEndHead(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceEndHead(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceEndHead(SBMLDocument* document, const char* reactionId, const char* endHead, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumAllTextGlyphs(SBMLDocument* document, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumTextGlyphs(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getText(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0, bool checkForName = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setText(SBMLDocument* document, const char* id, const char* text, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getX(SBMLDocument* document, const char* id, const int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setX(SBMLDocument* document, const char* id, const double x, const int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getY(SBMLDocument* document, const char* id, const int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setY(SBMLDocument* document, const char* id, const double y, const int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setPosition(SBMLDocument* document, const char* id, const double x, const double y, const int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getWidth(SBMLDocument* document, const char* id, const int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setWidth(SBMLDocument* document, const char* id, const double width, const int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsWidth(SBMLDocument* document, const double width, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesWidth(

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesWidth(SBMLDocument* document, const double width, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionsWidth()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsWidth(SBMLDocument* document, const double width, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getHeight(SBMLDocument* document, const char* id, const int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setHeight(SBMLDocument* document, const char* id, const double height, const int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsHeight(SBMLDocument* document, const double height, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getSpeciesHeight()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesHeights(SBMLDocument* document, const double height, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getReactionsHeight()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsHeights(SBMLDocument* document, const double height, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getTextX(SBMLDocument* document, const char* id, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setTextX(SBMLDocument* document, const char* id, const double x, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getTextY(SBMLDocument* document, const char* id, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setTextY(SBMLDocument* document, const char* id, const double y, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setTextPosition(SBMLDocument* document, const char* id, const double x, const double y, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getTextWidth(SBMLDocument* document, const char* id, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setTextWidth(SBMLDocument* document, const char* id, const double width, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getTextHeight(SBMLDocument* document, const char* id, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setTextHeight(SBMLDocument* document, const char* id, const double height, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetCurve(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumCurveSegments(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isCurveSegmentCubicBezier(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCurveSegmentStartPointX(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCurveSegmentStartPointX(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCurveSegmentStartPointY(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCurveSegmentStartPointY(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCurveSegmentEndPointX(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCurveSegmentEndPointX(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCurveSegmentEndPointY(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCurveSegmentEndPointY(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCurveSegmentBasePoint1X(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCurveSegmentBasePoint1X(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCurveSegmentBasePoint1Y(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCurveSegmentBasePoint1Y(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCurveSegmentBasePoint2X(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCurveSegmentBasePoint2X(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCurveSegmentBasePoint2Y(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCurveSegmentBasePoint2Y(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumGlobalRenderInformation(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumLocalRenderInformation(SBMLDocument* document, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_removeRenderInformation(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_removeGlobalRenderInformation(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_removeLocalRenderInformation(SBMLDocument* document, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_createDefaultGlobalRenderInformation(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_createDefaultLocalRenderInformation(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetBackgroundColor(SBMLDocument* document, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getBackgroundColor(SBMLDocument* document, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setBackgroundColor(SBMLDocument* document, const char* backgroundColor, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumColors(SBMLDocument* document, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumGlobalColors(SBMLDocument* document, int renderIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumLocalColors(SBMLDocument* document, int renderIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthGlobalColorId(SBMLDocument* document, int colorIndex, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthLocalColorId(SBMLDocument* document, int colorIndex, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetColorValue(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getColorValue(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setColorValue(SBMLDocument* document, const char* id, const char* value, int renderIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumGradients(SBMLDocument* document, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumGlobalGradients(SBMLDocument* document, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumLocalGradients(SBMLDocument* document, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthGlobalGradientId(SBMLDocument* document, int gradientIndex, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthLocalGradientId(SBMLDocument* document, int gradientIndex, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isLinearGradient(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isRadialGradient(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpreadMethod(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpreadMethod(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpreadMethod(SBMLDocument* document, const char* id, const char* spreadMethod, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumGradientStops(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetOffset(SBMLDocument* document, const char* id, int gradientStopIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getOffset(SBMLDocument* document, const char* id, int gradientStopIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setOffset(SBMLDocument* document, const char* id, const double offset, int gradientStopIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetStopColor(SBMLDocument* document, const char* id, int gradientStopIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getStopColor(SBMLDocument* document, const char* id, int gradientStopIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setStopColor(SBMLDocument* document, const char* id, const char* stopColor, int gradientStopIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLinearGradientX1(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLinearGradientX1(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLinearGradientX1(SBMLDocument* document, const char* id, const double x1, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLinearGradientY1(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLinearGradientY1(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLinearGradientY1(SBMLDocument* document, const char* id, const double y1, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLinearGradientX2(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLinearGradientX2(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLinearGradientX2(SBMLDocument* document, const char* id, const double x2, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLinearGradientY2(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLinearGradientY2(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLinearGradientY2(SBMLDocument* document, const char* id, const double y2, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetRadialGradientCenterX(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getRadialGradientCenterX(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setRadialGradientCenterX(SBMLDocument* document, const char* id, const double cx, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetRadialGradientCenterY(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getRadialGradientCenterY(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setRadialGradientCenterY(SBMLDocument* document, const char* id, const double cy, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetRadialGradientFocalX(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getRadialGradientFocalX(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setRadialGradientFocalX(SBMLDocument* document, const char* id, const double fx, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetRadialGradientFocalY(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getRadialGradientFocalY(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setRadialGradientFocalY(SBMLDocument* document, const char* id, const double fy, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetRadialGradientRadius(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getRadialGradientRadius(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setRadialGradientRadius(SBMLDocument* document, const char* id, const double r, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumLineEndings(SBMLDocument* document, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumGlobalLineEndings(SBMLDocument* document, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumLocalLineEndings(SBMLDocument* document, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthGlobalLineEndingId(SBMLDocument* document, int lineEndingIndex, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthLocalLineEndingId(SBMLDocument* document, int lineEndingIndex, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingBoundingBoxX(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingBoundingBoxX(SBMLDocument* document, const char* id, const double x, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingBoundingBoxX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingBoundingBoxX(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingBoundingBoxX(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingBoundingBoxY(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingBoundingBoxY(SBMLDocument* document, const char* id, const double y, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingBoundingBoxY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingBoundingBoxY(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingBoundingBoxY(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingBoundingBoxWidth(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingBoundingBoxWidth(SBMLDocument* document, const char* id, const double width, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingBoundingBoxWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingBoundingBoxWidth(SBMLDocument* document, const char* reactionId, const double width, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingBoundingBoxWidth(SBMLDocument* document, const char* reactionId, const double width, int reactionGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingBoundingBoxHeight(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingBoundingBoxHeight(SBMLDocument* document, const char* id, const double height, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingBoundingBoxHeight(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingBoundingBoxHeight(SBMLDocument* document, const char* reactionId, const double height, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingBoundingBoxHeight(SBMLDocument* document, const char* reactionId, const double height, int reactionGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingBorderColor(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingBorderColor(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingBorderColor(SBMLDocument* document, const char* id, const char* borderColor, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceLineEndingBorderColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingBorderColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingBorderColor(SBMLDocument* document, const char* reactionId, const char* borderColor, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingBorderColor(SBMLDocument* document, const char* reactionId, const char* borderColor, int reactionGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingBorderWidth(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingBorderWidth(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingBorderWidth(SBMLDocument* document, const char* id, const double borderWidth, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceLineEndingBorderWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingBorderWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingBorderWidth(SBMLDocument* document, const char* reactionId, const double borderWidth, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingBorderWidth(SBMLDocument* document, const char* reactionId, const double borderWidth, int reactionGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumLineEndingBorderDashes(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingNthBorderDash(SBMLDocument* document, const char* id, int borderDashIndex, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingNthBorderDash(SBMLDocument* document, const char* id, const int dash, int borderDashIndex, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumSpeciesReferenceLineEndingBorderDashes(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingNthBorderDash(SBMLDocument* document, const char* reactionId, int borderDashIndex, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingNthBorderDash(SBMLDocument* document, const char* reactionId, const int dash, int borderDashIndex, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingNthBorderDash(SBMLDocument* document, const char* reactionId, const int dash, int borderDashIndex, int reactionGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingFillColor(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingFillColor(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingFillColor(SBMLDocument* document, const char* id, const char* fillColor, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingFillColorAsGradient(SBMLDocument* document, const char* id, const char* gradientType = "linear", const char** stopColors = NULL, const double* stopOffsets = NULL, const int stopsSize = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceLineEndingFillColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingFillColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingFillColor(SBMLDocument* document, const char* reactionId, const char* fillColor, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingFillColorAsGradient(SBMLDocument* document, const char* reactionId, const char* gradientType = "linear", const char** stopColors = NULL, const double* stopOffsets = NULL, const int stopsSize = 0, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingFillColor(SBMLDocument* document, const char* reactionId, const char* fillColor, int reactionGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingFillColorAsGradient(SBMLDocument* document, const char* reactionId, const char* gradientType = "linear", const char** stopColors = NULL, const double* stopOffsets = NULL, const int stopsSize = 0, int reactionGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingFillRule(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingFillRule(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingFillRule(SBMLDocument* document, const char* id, const char* fillRule, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceLineEndingFillRule(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingFillRule(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingFillRule(SBMLDocument* document, const char* reactionId, const char* fillRule, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingFillRule(SBMLDocument* document, const char* reactionId, const char* fillRule, int reactionGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumLineEndingGeometricShapes(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumSpeciesReferenceLineEndingGeometricShapes(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isLineEndingRectangle(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSpeciesReferenceLineEndingRectangle(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isLineEndingEllipse(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSpeciesReferenceLineEndingEllipse(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isLineEndingPolygon(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSpeciesReferenceLineEndingPolygon(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isLineEndingImage(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSpeciesReferenceLineEndingImage(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isLineEndingRenderCurve(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSpeciesReferenceLineEndingRenderCurve(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isLineEndingText(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSpeciesReferenceLineEndingText(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeX(SBMLDocument* document, const char* id, const double x, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceLineEndingGeometricShapeX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingGeometricShapeX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingGeometricShapeX(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingGeometricShapeX(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeY(SBMLDocument* document, const char* id, const double y, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceLineEndingGeometricShapeY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingGeometricShapeY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingGeometricShapeY(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingGeometricShapeY(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeWidth(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeWidth(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeWidth(SBMLDocument* document, const char* id, const double width, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceLineEndingGeometricShapeWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingGeometricShapeWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingGeometricShapeWidth(SBMLDocument* document, const char* reactionId, const double width, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingGeometricShapeWidth(SBMLDocument* document, const char* reactionId, const double width, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeHeight(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeHeight(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeHeight(SBMLDocument* document, const char* id, const double height, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceLineEndingGeometricShapeHeight(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingGeometricShapeHeight(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingGeometricShapeHeight(SBMLDocument* document, const char* reactionId, const double height, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingGeometricShapeHeight(SBMLDocument* document, const char* reactionId, const double height, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeRatio(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeRatio(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeRatio(SBMLDocument* document, const char* id, const double ratio, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceLineEndingGeometricShapeRatio(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingGeometricShapeRatio(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingGeometricShapeRatio(SBMLDocument* document, const char* reactionId, const double ratio, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingGeometricShapeRatio(SBMLDocument* document, const char* reactionId, const double ratio, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, const double rx, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* reactionId, const double rx, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* reactionId, const double rx, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, const double ry, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* reactionId, const double ry, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* reactionId, const double ry, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* id, const double cx, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* reactionId, const double cx, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* reactionId, const double cx, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* id, const double cy, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* reactionId, const double cy, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* reactionId, const double cy, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* id, const double rx, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* reactionId, const double rx, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* reactionId, const double rx, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* id, const double ry, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* reactionId, const double ry, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* reactionId, const double ry, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeNumSegments(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingGeometricShapeNumSegments(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isLineEndingGeometricShapeSegmentCubicBezier(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSpeciesReferenceLineEndingGeometricShapeSegmentCubicBezier(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeSegmentX(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeSegmentX(SBMLDocument* document, const char* id, const double x, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingGeometricShapeSegmentX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingGeometricShapeSegmentX(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingGeometricShapeSegmentX(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeSegmentY(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeSegmentY(SBMLDocument* document, const char* id, const double y, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingGeometricShapeSegmentY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingGeometricShapeSegmentY(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingGeometricShapeSegmentY(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const char* id, const double x, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const char* id, const double y, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const char* id, const double x, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const char* reactionId, const double x, int reactionGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const char* id, const double y, int segmentIndex = 0, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const char* reactionId, const double y, int reactionGlyphIndex = 0, int layoutIndex = 0, int segmentIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeHref(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeHref(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeHref(SBMLDocument* document, const char* id, const char* href, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceLineEndingGeometricShapeHref(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceLineEndingGeometricShapeHref(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceLineEndingGeometricShapeHref(SBMLDocument* document, const char* reactionId, const char* href, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionLineEndingGeometricShapeHref(SBMLDocument* document, const char* reactionId, const char* href, int reactionGlyphIndex = 0, int layoutIndex = 0, int geometricShapeIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetBorderColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getBorderColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setBorderColor(SBMLDocument* document, const char* id, const char* borderColor, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineColor(SBMLDocument* document, const char* id, const char* lineColor, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsBorderColor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsBorderColor(SBMLDocument* document, const char* borderColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesBorderColor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesBorderColor(SBMLDocument* document, const char* borderColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsLineColor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsLineColor(SBMLDocument* document, const char* lineColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingsBorderColor(SBMLDocument* document, const char* borderColor, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setBorderColors(SBMLDocument* document, const char* borderColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetBorderWidth(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineWidth(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getBorderWidth(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineWidth(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setBorderWidth(SBMLDocument* document, const char* id, const double borderWidth, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineWidth(SBMLDocument* document, const char* id, const double lineWidth, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsBorderWidth(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsBorderWidth(SBMLDocument* document, const double borderWidth, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesBorderWidth(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesBorderWidth(SBMLDocument* document, const double borderWidth, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsLineWidth(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsLineWidth(SBMLDocument* document, const double lineWidth, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingsBorderWidth(SBMLDocument* document, const double borderWidth, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setBorderWidths(SBMLDocument* document, const double borderWidth, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumBorderDashes(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthBorderDash(SBMLDocument* document, const char* id, int borderDashIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setNthBorderDash(SBMLDocument* document, const char* id, const int dash, int borderDashIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetFillColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFillColorAsGradient(SBMLDocument* document, const char* id, const char* gradientType = "linear", const char** stopColors = NULL, const double* stopOffsets = NULL, const int stopsSize = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getFillColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFillColor(SBMLDocument* document, const char* id, const char* fillColor, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsFillColor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsFillColor(SBMLDocument* document, const char* fillColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsFillColorAsGradient(SBMLDocument* document, const char* gradientType = "linear", const char** stopColors = NULL, const double* stopOffsets = NULL, const int stopsSize = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesFillColor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesFillColor(SBMLDocument* document, const char* fillColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesFillColorAsGradient(SBMLDocument* document, const char* gradientType = "linear", const char** stopColors = NULL, const double* stopOffsets = NULL, const int stopsSize = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsFillColor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsFillColor(SBMLDocument* document, const char* fillColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsFillColorAsGradient(SBMLDocument* document, const char* gradientType = "linear", const char** stopColors = NULL, const double* stopOffsets = NULL, const int stopsSize = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingsFillColor(SBMLDocument* document, const char* fillColor, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingsFillColorAsGradient(SBMLDocument* document, const char* gradientType = "linear", const char** stopColors = NULL, const double* stopOffsets = NULL, const int stopsSize = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFillColors(SBMLDocument* document, const char* fillColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFillColorsAsGradient(SBMLDocument* document, const char* gradientType = "linear", const char** stopColors = NULL, const double* stopOffsets = NULL, const int stopsSize = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetFillRule(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getFillRule(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFillRule(SBMLDocument* document, const char* id, const char* fillRule, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsFillRule(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsFillRule(SBMLDocument* document, const char* fillRule, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesFillRule(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesFillRule(SBMLDocument* document, const char* fillRule, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsFillRule(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsFillRule(SBMLDocument* document, const char* fillRule, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFillRules(SBMLDocument* document, const char* fillRule, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetFontColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getFontColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFontColor(SBMLDocument* document, const char* id, const char* fontColor, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsFontColor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsFontColor(SBMLDocument* document, const char* fontColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesFontColor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesFontColor(SBMLDocument* document, const char* fontColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsFontColor(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsFontColor(SBMLDocument* document, const char* fontColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFontColors(SBMLDocument* document, const char* fontColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetFontFamily(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getFontFamily(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFontFamily(SBMLDocument* document, const char* id, const char* fontFamily, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsFontFamily(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsFontFamily(SBMLDocument* document, const char* fontFamily, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesFontFamily(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesFontFamily(SBMLDocument* document, const char* fontFamily, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsFontFamily(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsFontFamily(SBMLDocument* document, const char* fontFamily, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFontFamilies(SBMLDocument* document, const char* fontFamily, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetFontSize(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getFontSize(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFontSize(SBMLDocument* document, const char* id, const double fontSize, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsFontSize(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsFontSize(SBMLDocument* document, const double fontSize, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesFontSize(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesFontSize(SBMLDocument* document, const double fontSize, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsFontSize(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsFontSize(SBMLDocument* document, const double fontSize, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFontSizes(SBMLDocument* document, const double fontSize, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetFontWeight(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getFontWeight(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFontWeight(SBMLDocument* document, const char* id, const char* fontWeight, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsFontWeight(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsFontWeight(SBMLDocument* document, const char* fontWeight, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesFontWeight(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesFontWeight(SBMLDocument* document, const char* fontWeight, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsFontWeight(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsFontWeight(SBMLDocument* document, const char* fontWeight, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFontWeights(SBMLDocument* document, const char* fontWeight, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetFontStyle(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getFontStyle(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFontStyle(SBMLDocument* document, const char* id, const char* fontStyle, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsFontStyle(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsFontStyle(SBMLDocument* document, const char* fontStyle, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesFontStyle(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesFontStyle(SBMLDocument* document, const char* fontStyle, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsFontStyle(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsFontStyle(SBMLDocument* document, const char* fontStyle, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFontStyles(SBMLDocument* document, const char* fontStyle, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetTextHorizontalAlignment(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getTextHorizontalAlignment(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setTextHorizontalAlignment(SBMLDocument* document, const char* id, const char* textHorizontalAlignment, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsTextHorizontalAlignment(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsTextHorizontalAlignment(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesTextHorizontalAlignment(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesTextHorizontalAlignment(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsTextHorizontalAlignment(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsTextHorizontalAlignment(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setTextHorizontalAlignments(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetTextVerticalAlignment(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getTextVerticalAlignment(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setTextVerticalAlignment(SBMLDocument* document, const char* id, const char* textVerticalAlignment, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsTextVerticalAlignment(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsTextVerticalAlignment(SBMLDocument* document, const char* textVerticalAlignment, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesTextVerticalAlignment(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesTextVerticalAlignment(SBMLDocument* document, const char* textVerticalAlignment, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsTextVerticalAlignment(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsTextVerticalAlignment(SBMLDocument* document, const char* textVerticalAlignment, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setTextVerticalAlignments(SBMLDocument* document, const char* textVerticalAlignment, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetStartHead(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getStartHead(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setStartHead(SBMLDocument* document, const char* id, const char* startHead, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetEndHead(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getEndHead(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setEndHead(SBMLDocument* document, const char* id, const char* endHead, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumGeometricShapes(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_addGeometricShape(SBMLDocument* document, const char* id, const char* shape, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_removeGeometricShape(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeType(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeType(SBMLDocument* document, const char* id, const char* shape, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeType(SBMLDocument* document, const char* shape, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapesType(SBMLDocument* document, const char* shape, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapesType(SBMLDocument* document, const char* shape, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isRectangle(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSquare(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isEllipse(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isCircle(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isPolygon(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isImage(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isRenderCurve(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isText(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeBorderColor(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeBorderColor(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeBorderColor(SBMLDocument* document, const char* id, const char* borderColor, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeBorderWidth(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeBorderWidth(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeBorderWidth(SBMLDocument* document, const char* id, const double borderWidth, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeFillColor(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeFillColor(SBMLDocument* document, const char* id, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeFillColor(SBMLDocument* document, const char* id, const char* fillColor, int geometricShapeIndex, int graphicalObjectIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeFillColorAsGradient(SBMLDocument* document, const char* id, const char* gradientType = "linear", const char** stopColors = NULL, const double* stopOffsets = NULL, const int stopsSize = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeX(SBMLDocument* document, const char* id, const double x, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsGeometricShapeX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeX(SBMLDocument* document, const double x, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesGeometricShapeX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeX(SBMLDocument* document, const double x, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsGeometricShapeX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeX(SBMLDocument* document, const double x, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeXs(SBMLDocument* document, const double x, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeY(SBMLDocument* document, const char* id, const double y, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsGeometricShapeY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeY(SBMLDocument* document, const double y, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesGeometricShapeY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeY(SBMLDocument* document, const double y, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsGeometricShapeY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeY(SBMLDocument* document, const double y, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeYs(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeYs(SBMLDocument* document, const double y, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeWidth(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeWidth(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeWidth(SBMLDocument* document, const char* id, const double width, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsGeometricShapeWidth(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeWidth(SBMLDocument* document, const double width, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesGeometricShapeWidth(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeWidth(SBMLDocument* document, const double width, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsGeometricShapeWidth(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeWidth(SBMLDocument* document, const double width, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeWidths(SBMLDocument* document, const double width, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeHeight(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeHeight(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeHeight(SBMLDocument* document, const char* id, const double height, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsGeometricShapeHeight(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeHeight(SBMLDocument* document, const double height, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesGeometricShapeHeight(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeHeight(SBMLDocument* document, const double height, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsGeometricShapeHeight(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeHeight(SBMLDocument* document, const double height, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeHeights(SBMLDocument* document, const double height, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeRatio(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeRatio(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeRatio(SBMLDocument* document, const char* id, const double ratio, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsGeometricShapeRatio(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeRatio(SBMLDocument* document, const double ratio, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesGeometricShapeRatio(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeRatio(SBMLDocument* document, const double ratio, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsGeometricShapeRatio(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeRatio(SBMLDocument* document, const double ratio, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeRatios(SBMLDocument* document, const double ratio, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, const double borderRadiusX, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsGeometricShapeBorderRadiusX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeBorderRadiusX(SBMLDocument* document, const double borderRadiusX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesGeometricShapeBorderRadiusX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeBorderRadiusX(SBMLDocument* document, const double borderRadiusX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsGeometricShapeBorderRadiusX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeBorderRadiusX(SBMLDocument* document, const double borderRadiusX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeBorderRadiusXs(SBMLDocument* document, const double borderRadiusX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, const double borderRadiusY, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsGeometricShapeBorderRadiusY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeBorderRadiusY(SBMLDocument* document, const double borderRadiusY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesGeometricShapeBorderRadiusY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeBorderRadiusY(SBMLDocument* document, const double borderRadiusY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsGeometricShapeBorderRadiusY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeBorderRadiusY(SBMLDocument* document, const double borderRadiusY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeBorderRadiusYs(SBMLDocument* document, const double borderRadiusY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeCenterX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeCenterX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeCenterX(SBMLDocument* document, const char* id, const double centerX, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsGeometricShapeCenterX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeCenterX(SBMLDocument* document, const double centerX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesGeometricShapeCenterX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeCenterX(SBMLDocument* document, const double centerX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsGeometricShapeCenterX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeCenterX(SBMLDocument* document, const double centerX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeCenterXs(SBMLDocument* document, const double centerX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeCenterY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeCenterY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeCenterY(SBMLDocument* document, const char* id, const double centerY, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsGeometricShapeCenterY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeCenterY(SBMLDocument* document, const double centerY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesGeometricShapeCenterY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeCenterY(SBMLDocument* document, const double centerY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsGeometricShapeCenterY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeCenterY(SBMLDocument* document, const double centerY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeCenterYs(SBMLDocument* document, const double centerY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeRadiusX(SBMLDocument* document, const char* id, const double radiusX, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsGeometricShapeRadiusX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeRadiusX(SBMLDocument* document, const double radiusX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesGeometricShapeRadiusX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeRadiusX(SBMLDocument* document, const double radiusX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsGeometricShapeRadiusX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeRadiusX(SBMLDocument* document, const double radiusX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeRadiusXs(SBMLDocument* document, const double radiusX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeRadiusY(SBMLDocument* document, const char* id, const double radiusY, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsGeometricShapeRadiusY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeRadiusY(SBMLDocument* document, const double radiusY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesGeometricShapeRadiusY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeRadiusY(SBMLDocument* document, const double radiusY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsGeometricShapeRadiusY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeRadiusY(SBMLDocument* document, const double radiusY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeRadiusYs(SBMLDocument* document, const double radiusY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeNumSegments(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isGeometricShapeSegmentCubicBezier(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeSegmentX(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentX(SBMLDocument* document, const char* id, const double x, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsGeometricShapeSegmentX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeSegmentX(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesGeometricShapeSegmentX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeSegmentX(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsGeometricShapeSegmentX(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeSegmentX(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentXs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeSegmentY(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentY(SBMLDocument* document, const char* id, const double y, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsGeometricShapeSegmentY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeSegmentY(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesGeometricShapeSegmentY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeSegmentY(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsGeometricShapeSegmentY(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeSegmentY(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentYs(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const char* id, const double x, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsGeometricShapeSegmentBasePoint1X(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesGeometricShapeSegmentBasePoint1X(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsGeometricShapeSegmentBasePoint1X(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentBasePoint1Xs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const char* id, const double y, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsGeometricShapeSegmentBasePoint1Y(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesGeometricShapeSegmentBasePoint1Y(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsGeometricShapeSegmentBasePoint1Y(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentBasePoint1Ys(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const char* id, const double x, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsGeometricShapeSegmentBasePoint2X(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesGeometricShapeSegmentBasePoint2X(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsGeometricShapeSegmentBasePoint2X(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentBasePoint2Xs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const char* id, const double y, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsGeometricShapeSegmentBasePoint2Y(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesGeometricShapeSegmentBasePoint2Y(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsGeometricShapeSegmentBasePoint2Y(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentBasePoint2Ys(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeHref(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeHref(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeHref(SBMLDocument* document, const char* id, const char* href, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getCompartmentsGeometricShapeHref(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeHref(SBMLDocument* document, const char* href, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesGeometricShapeHref(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeHref(SBMLDocument* document, const char* href, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getReactionsGeometricShapeHref(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeHref(SBMLDocument* document, const char* href, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeHrefs(SBMLDocument* document, const char* href, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getStyle(SBMLDocument* document, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setStyle(SBMLDocument* document, const char* styleName, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_whetherDisplayReactionTextLabel(const char* styleName)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumPredefinedStyles()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthPredefinedStyleName(int index)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumValidRoleValues()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthValidRoleValue(int index)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumValidAlignmentValues()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthValidAlignmentValue(int index)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumValidDistributionDirectionValues()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthValidDistributionDirectionValue(int index)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumValidSpreadMethodValues()