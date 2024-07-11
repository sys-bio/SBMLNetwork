C API Reference
==================

This is the API reference for the C API of the SBMLNetwork library.

**********
Functions
**********

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getVersion()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_readSBML(const char* sbml)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_writeSBMLToFile(SBMLDocument* document, const char* fileName)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_writeSBMLToString(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSBMLLevel(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSBMLVersion(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_freeSBMLDocument(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetModel(SBMLDocument* document)

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

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceSpeciesId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceSpeciesGlyphId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetSpeciesReferenceRole(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceRole(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceRole(SBMLDocument* document, const char* reactionId, const char* role, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumSpeciesReferenceCurveSegments(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSpeciesReferenceCurveSegmentCubicBezier(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const char* reactionId, double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const char* reactionId, double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const char* reactionId, double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const char* reactionId, double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const char* reactionId, double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const char* reactionId, double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const char* reactionId, double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const char* reactionId, double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

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

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setX(SBMLDocument* document, const char* id, const double x, const int graphicalObjectIndex = 0, int layoutIndex = 0, bool isLayoutAdded = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getY(SBMLDocument* document, const char* id, const int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setY(SBMLDocument* document, const char* id, const double y, const int graphicalObjectIndex = 0, int layoutIndex = 0, bool isLayoutAdded = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setPosition(SBMLDocument* document, const char* id, const double x, const double y, const int graphicalObjectIndex = 0, int layoutIndex = 0, bool isLayoutAdded = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getWidth(SBMLDocument* document, const char* id, const int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setWidth(SBMLDocument* document, const char* id, const double width, const int graphicalObjectIndex = 0, int layoutIndex = 0, bool isLayoutAdded = true)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getHeight(SBMLDocument* document, const char* id, const int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setHeight(SBMLDocument* document, const char* id, const double height, const int graphicalObjectIndex = 0, int layoutIndex = 0, bool isLayoutAdded = true)

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

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingBoundingBoxY(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingBoundingBoxY(SBMLDocument* document, const char* id, const double y, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingBoundingBoxWidth(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingBoundingBoxWidth(SBMLDocument* document, const char* id, const double width, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingBoundingBoxHeight(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingBoundingBoxHeight(SBMLDocument* document, const char* id, const double height, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingBorderColor(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingBorderColor(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingBorderColor(SBMLDocument* document, const char* id, const char* borderColor, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingBorderWidth(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingBorderWidth(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingBorderWidth(SBMLDocument* document, const char* id, const double borderWidth, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumLineEndingBorderDashes(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingNthBorderDash(SBMLDocument* document, const char* id, int borderDashIndex, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingNthBorderDash(SBMLDocument* document, const char* id, const int dash, int borderDashIndex, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingFillColor(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingFillColor(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingFillColor(SBMLDocument* document, const char* id, const char* fillColor, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingFillRule(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingFillRule(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingFillRule(SBMLDocument* document, const char* id, const char* fillRule, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumLineEndingGeometricShapes(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isLineEndingRectangle(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isLineEndingEllipse(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isLineEndingPolygon(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isLineEndingImage(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isLineEndingRenderCurve(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isLineEndingText(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeX(SBMLDocument* document, const char* id, const double x, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeY(SBMLDocument* document, const char* id, const double y, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeWidth(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeWidth(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeWidth(SBMLDocument* document, const char* id, const double width, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeHeight(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeHeight(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeHeight(SBMLDocument* document, const char* id, const double height, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeRatio(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeRatio(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeRatio(SBMLDocument* document, const char* id, const double ratio, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeHeight(SBMLDocument* document, const char* id, const double height, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeRatio(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeRatio(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeRatio(SBMLDocument* document, const char* id, const double ratio, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, const double rx, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, const double ry, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeCenterX(SBMLDocument* document, const char* id, const double cx, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeCenterY(SBMLDocument* document, const char* id, const double cy, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeRadiusX(SBMLDocument* document, const char* id, const double rx, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeRadiusY(SBMLDocument* document, const char* id, const double ry, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeNumSegments(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isLineEndingGeometricShapeSegmentCubicBezier(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeSegmentX(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeSegmentX(SBMLDocument* document, const char* id, const double x, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeSegmentY(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeSegmentY(SBMLDocument* document, const char* id, const double y, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeBasePoint1X(SBMLDocument* document, const char* id, const double x, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeBasePoint1Y(SBMLDocument* document, const char* id, const double y, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeBasePoint2X(SBMLDocument* document, const char* id, const double x, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const char* id, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeBasePoint2Y(SBMLDocument* document, const char* id, const double y, int segmentIndex, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineEndingGeometricShapeHref(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineEndingGeometricShapeHref(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingGeometricShapeSegmentHref(SBMLDocument* document, const char* id, const char* href, int geometricShapeIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetBorderColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getBorderColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setBorderColor(SBMLDocument* document, const char* id, const char* borderColor, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineColor(SBMLDocument* document, const char* id, const char* lineColor, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsBorderColors(SBMLDocument* document, const char* borderColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesBorderColors(SBMLDocument* document, const char* borderColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsLineColors(SBMLDocument* document, const char* lineColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingsBorderColors(SBMLDocument* document, const char* borderColor, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setBorderColors(SBMLDocument* document, const char* borderColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetBorderWidth(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetLineWidth(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getBorderWidth(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getLineWidth(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setBorderWidth(SBMLDocument* document, const char* id, const double borderWidth, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineWidth(SBMLDocument* document, const char* id, const double lineWidth, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsBorderWidths(SBMLDocument* document, const double borderWidth, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesBorderWidths(SBMLDocument* document, const double borderWidth, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsLineWidths(SBMLDocument* document, const double lineWidth, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingsBorderWidths(SBMLDocument* document, const double borderWidth, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setBorderWidths(SBMLDocument* document, const double borderWidth, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumBorderDashes(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthBorderDash(SBMLDocument* document, const char* id, int borderDashIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setNthBorderDash(SBMLDocument* document, const char* id, const int dash, int borderDashIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetFillColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getFillColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFillColor(SBMLDocument* document, const char* id, const char* fillColor, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsFillColors(SBMLDocument* document, const char* fillColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesFillColors(SBMLDocument* document, const char* fillColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsFillColors(SBMLDocument* document, const char* fillColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setLineEndingsFillColors(SBMLDocument* document, const char* fillColor, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFillColors(SBMLDocument* document, const char* fillColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetFillRule(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getFillRule(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFillRule(SBMLDocument* document, const char* id, const char* fillRule, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsFillRules(SBMLDocument* document, const char* fillRule, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesFillRules(SBMLDocument* document, const char* fillRule, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFillRules(SBMLDocument* document, const char* fillRule, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetFontColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getFontColor(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFontColor(SBMLDocument* document, const char* id, const char* fontColor, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsFontColors(SBMLDocument* document, const char* fontColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesFontColors(SBMLDocument* document, const char* fontColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsFontColors(SBMLDocument* document, const char* fontColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFontColors(SBMLDocument* document, const char* fontColor, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetFontFamily(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getFontFamily(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFontFamily(SBMLDocument* document, const char* id, const char* fontFamily, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsFontFamilies(SBMLDocument* document, const char* fontFamily, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesFontFamilies(SBMLDocument* document, const char* fontFamily, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsFontFamilies(SBMLDocument* document, const char* fontFamily, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFontFamilies(SBMLDocument* document, const char* fontFamily, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetFontSize(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getFontSize(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFontSize(SBMLDocument* document, const char* id, const double fontSize, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsFontSizes(SBMLDocument* document, const double fontSize, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesFontSizes(SBMLDocument* document, const double fontSize, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsFontSizes(SBMLDocument* document, const double fontSize, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFontSizes(SBMLDocument* document, const double fontSize, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetFontWeight(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getFontWeight(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFontWeight(SBMLDocument* document, const char* id, const char* fontWeight, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsFontWeights(SBMLDocument* document, const char* fontWeight, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesFontWeights(SBMLDocument* document, const char* fontWeight, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsFontWeights(SBMLDocument* document, const char* fontWeight, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFontWeights(SBMLDocument* document, const char* fontWeight, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetFontStyle(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getFontStyle(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFontStyle(SBMLDocument* document, const char* id, const char* fontStyle, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsFontStyles(SBMLDocument* document, const char* fontStyle, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesFontStyles(SBMLDocument* document, const char* fontStyle, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsFontStyles(SBMLDocument* document, const char* fontStyle, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setFontStyles(SBMLDocument* document, const char* fontStyle, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetTextHorizontalAlignment(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getTextHorizontalAlignment(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setTextHorizontalAlignment(SBMLDocument* document, const char* id, const char* textHorizontalAlignment, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsTextHorizontalAlignments(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesTextHorizontalAlignments(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsTextHorizontalAlignments(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setTextHorizontalAlignments(SBMLDocument* document, const char* textHorizontalAlignment, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetTextVerticalAlignment(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getTextVerticalAlignment(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setTextVerticalAlignment(SBMLDocument* document, const char* id, const char* textVerticalAlignment, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsTextVerticalAlignments(SBMLDocument* document, const char* textVerticalAlignment, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesTextVerticalAlignments(SBMLDocument* document, const char* textVerticalAlignment, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsTextVerticalAlignments(SBMLDocument* document, const char* textVerticalAlignment, int layoutIndex = 0)

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

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShape(SBMLDocument* document, const char* id, const char* shape, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapes(SBMLDocument* document, const char* shape, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionGeometricShapes(SBMLDocument* document, const char* shape, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapes(SBMLDocument* document, const char* shape, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isRectangle(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isEllipse(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isPolygon(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isImage(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isRenderCurve(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isText(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeX(SBMLDocument* document, const char* id, const double x, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeXs(SBMLDocument* document, const double x, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeXs(SBMLDocument* document, const double x, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeXs(SBMLDocument* document, const double x, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeXs(SBMLDocument* document, const double x, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeY(SBMLDocument* document, const char* id, const double y, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeYs(SBMLDocument* document, const double y, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeYs(SBMLDocument* document, const double y, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeYs(SBMLDocument* document, const double y, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeYs(SBMLDocument* document, const double y, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeWidth(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeWidth(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeWidth(SBMLDocument* document, const char* id, const double width, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeWidths(SBMLDocument* document, const double width, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeWidths(SBMLDocument* document, const double width, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeWidths(SBMLDocument* document, const double width, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeWidths(SBMLDocument* document, const double width, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeHeight(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeHeight(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeHeight(SBMLDocument* document, const char* id, const double height, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeHeights(SBMLDocument* document, const double height, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeHeights(SBMLDocument* document, const double height, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeHeights(SBMLDocument* document, const double height, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeHeights(SBMLDocument* document, const double height, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeRatio(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeRatio(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeRatio(SBMLDocument* document, const char* id, const double ratio, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeRatios(SBMLDocument* document, const double ratio, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeRatios(SBMLDocument* document, const double ratio, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeRatios(SBMLDocument* document, const double ratio, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeRatios(SBMLDocument* document, const double ratio, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeBorderRadiusX(SBMLDocument* document, const char* id, const double borderRadiusX, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeBorderRadiusXs(SBMLDocument* document, const double borderRadiusX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeBorderRadiusXs(SBMLDocument* document, const double borderRadiusX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeBorderRadiusXs(SBMLDocument* document, const double borderRadiusX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeBorderRadiusXs(SBMLDocument* document, const double borderRadiusX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeBorderRadiusY(SBMLDocument* document, const char* id, const double borderRadiusY, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeBorderRadiusYs(SBMLDocument* document, const double borderRadiusY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeBorderRadiusYs(SBMLDocument* document, const double borderRadiusY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeBorderRadiusYs(SBMLDocument* document, const double borderRadiusY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeBorderRadiusYs(SBMLDocument* document, const double borderRadiusY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeCenterX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeCenterX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeCenterX(SBMLDocument* document, const char* id, const double centerX, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeCenterXs(SBMLDocument* document, const double centerX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeCenterXs(SBMLDocument* document, const double centerX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeCenterXs(SBMLDocument* document, const double centerX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeCenterXs(SBMLDocument* document, const double centerX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeCenterY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeCenterY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeCenterY(SBMLDocument* document, const char* id, const double centerY, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeCenterYs(SBMLDocument* document, const double centerY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeCenterYs(SBMLDocument* document, const double centerY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeCenterYs(SBMLDocument* document, const double centerY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeCenterYs(SBMLDocument* document, const double centerY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeRadiusX(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeRadiusX(SBMLDocument* document, const char* id, const double radiusX, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeRadiusXs(SBMLDocument* document, const double radiusX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeRadiusXs(SBMLDocument* document, const double radiusX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeRadiusXs(SBMLDocument* document, const double radiusX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeRadiusXs(SBMLDocument* document, const double radiusX, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeRadiusY(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeRadiusY(SBMLDocument* document, const char* id, const double radiusY, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeRadiusYs(SBMLDocument* document, const double radiusY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeRadiusYs(SBMLDocument* document, const double radiusY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeRadiusYs(SBMLDocument* document, const double radiusY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeRadiusYs(SBMLDocument* document, const double radiusY, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeNumSegments(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isGeometricShapeSegmentCubicBezier(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeSegmentX(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentX(SBMLDocument* document, const char* id, const double x, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeSegmentXs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeSegmentXs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeSegmentXs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentXs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeSegmentY(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentY(SBMLDocument* document, const char* id, const double y, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeSegmentYs(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeSegmentYs(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeSegmentYs(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentYs(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentBasePoint1X(SBMLDocument* document, const char* id, const double x, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeSegmentBasePoint1Xs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeSegmentBasePoint1Xs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeSegmentBasePoint1Xs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentBasePoint1Xs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentBasePoint1Y(SBMLDocument* document, const char* id, const double y, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeSegmentBasePoint1Ys(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeSegmentBasePoint1Ys(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeSegmentBasePoint1Ys(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentBasePoint1Ys(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentBasePoint2X(SBMLDocument* document, const char* id, const double x, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeSegmentBasePoint2Xs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeSegmentBasePoint2Xs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeSegmentBasePoint2Xs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentBasePoint2Xs(SBMLDocument* document, const double x, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const char* id, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentBasePoint2Y(SBMLDocument* document, const char* id, const double y, int segmentIndex = 0, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeSegmentBasePoint2Ys(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeSegmentBasePoint2Ys(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeSegmentBasePoint2Ys(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeSegmentBasePoint2Ys(SBMLDocument* document, const double y, int segmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetGeometricShapeHref(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getGeometricShapeHref(SBMLDocument* document, const char* id, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeHref(SBMLDocument* document, const char* id, const char* href, int geometricShapeIndex = 0, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setCompartmentsGeometricShapeHrefs(SBMLDocument* document, const char* href, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setSpeciesGeometricShapeHrefs(SBMLDocument* document, const char* href, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setReactionsGeometricShapeHrefs(SBMLDocument* document, const char* href, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_setGeometricShapeHrefs(SBMLDocument* document, const char* href, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumValidRoleValues()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthValidRoleValue(int index)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumValidAlignmentValues()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthValidAlignmentValue(int index)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumValidDistributionDirectionValues()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthValidDistributionDirectionValue(int index)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumValidColorNameValues()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthValidColorNameValue(int index)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumValidHexColorCodeValues()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthValidHexColorCodeValue(int index)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumValidSpreadMethodValues()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthValidSpreadMethodValue(int index)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumValidFontWeightValues()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthValidFontWeightValue(int index)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumValidFontStyleValues()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthValidFontStyleValue(int index)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumValidHorizontalTextAlignmentValues()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthValidHorizontalTextAlignmentValue(int index)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumValidVerticalTextAlignmentValues()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthValidVerticalTextAlignmentValue(int index)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumValidFillRuleValues()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthValidFillRuleValue(int index)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNumValidGeometricShapeValues()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getNthValidGeometricShapeValue(int index)