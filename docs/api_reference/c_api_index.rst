C API Reference
==================

This is the API reference for the C API of the SBMLNetwork library.

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getVersion()

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_readSBML(const char* sbml)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_writeSBMLToFile(SBMLDocument* document, const char* fileName)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_writeSBMLToString(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSBMLLevel(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_getSBMLVersion(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_freeSBMLDocument(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::c_api_isSetModel(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const int c_api_getNumGraphicalObjects(SBMLDocument* document, const char* id, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getNthGraphicalObjectId(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getNthGraphicalObjectMetaId(SBMLDocument* document, const char* id, int graphicalObjectIndex, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const int c_api_getNumCompartments(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getNthCompartmentId(SBMLDocument* document, int compartmentIndex)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const int c_api_getNumAllCompartmentGlyphs(SBMLDocument* document, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN char** c_api_getListOfCompartmentGlyphIds(SBMLDocument* document, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const int c_api_getNumCompartmentGlyphs(SBMLDocument* document, const char* compartmentId, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getNthCompartmentGlyphId(SBMLDocument* document, const char* compartmentId, int compartmentGlyphIndex, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getNthCompartmentGlyphMetaId(SBMLDocument* document, const char* compartmentId, int compartmentGlyphIndex, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isCompartmentGlyph(SBMLDocument* document, const char* compartmentId, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getCompartmentId(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const int c_api_getNumSpecies(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getNthSpeciesId(SBMLDocument* document, int speciesIndex)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const int c_api_getNumAllSpeciesGlyphs(SBMLDocument* document, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const int c_api_getNumSpeciesGlyphs(SBMLDocument* document, const char* speciesId, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getNthSpeciesGlyphId(SBMLDocument* document, const char* speciesId, int speciesGlyphIndex, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getNthSpeciesGlyphMetaId(SBMLDocument* document, const char* speciesId, int speciesGlyphIndex, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isSpeciesGlyph(SBMLDocument* document, const char* speciesId, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const int c_api_getNumReactions(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getNthReactionId(SBMLDocument* document, int reactionIndex)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const int c_api_getNumAllReactionsGlyphs(SBMLDocument* document, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const int c_api_getNumReactionGlyphs(SBMLDocument* document, const char* reactionId, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getNthReactionGlyphId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getNthReactionGlyphMetaId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isReactionGlyph(SBMLDocument* document, const char* reactionId, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const int c_api_getNumSpeciesReferences(SBMLDocument* document, const char* reactionId)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const int c_api_getNumReactants(SBMLDocument* document, const char* reactionId)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const int c_api_getNumProducts(SBMLDocument* document, const char* reactionId)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const int c_api_getNumModifiers(SBMLDocument* document, const char* reactionId)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getNthReactantId(SBMLDocument* document, const char* reactionId, int reactantIndex)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getNthProductId(SBMLDocument* document, const char* reactionId, int productIndex)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getNthModifierId(SBMLDocument* document, const char* reactionId, int modifierIndex)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const int c_api_getNumSpeciesReferenceGlyphs(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceSpeciesId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceSpeciesGlyphId(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceRole(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceRole(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceRole(SBMLDocument* document, const char* reactionId, const char* role, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const int c_api_getNumSpeciesReferenceCurveSegments(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isSpeciesReferenceCurveSegmentCubicBezier(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentStartPointX(SBMLDocument* document, const char* reactionId, double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentStartPointY(SBMLDocument* document, const char* reactionId, double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentEndPointX(SBMLDocument* document, const char* reactionId, double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentEndPointY(SBMLDocument* document, const char* reactionId, double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentBasePoint1X(SBMLDocument* document, const char* reactionId, double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentBasePoint1Y(SBMLDocument* document, const char* reactionId, double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentBasePoint2X(SBMLDocument* document, const char* reactionId, double x, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceCurveSegmentBasePoint2Y(SBMLDocument* document, const char* reactionId, double y, int reactionGlyphIndex = 0, int speciesReferenceIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceBorderColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceBorderColor(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceBorderColor(SBMLDocument* document, const char* reactionId, const char* stroke, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceBorderWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getSpeciesReferenceBorderWidth(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceBorderWidth(SBMLDocument* document, const char* reactionId, const double strokeWidth, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_getNumSpeciesReferenceBorderDashes(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const int c_api_getSpeciesReferenceNthBorderDash(SBMLDocument* document, const char* reactionId, int borderDashIndex, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceNthBorderDash(SBMLDocument* document, const char* reactionId, const int borderDash, int borderDashIndex, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceStartHead(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceStartHead(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceStartHead(SBMLDocument* document, const char* reactionId, const char* startHead, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isSetSpeciesReferenceEndHead(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getSpeciesReferenceEndHead(SBMLDocument* document, const char* reactionId, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setSpeciesReferenceEndHead(SBMLDocument* document, const char* reactionId, const char* endHead, int reactionGlyphIndex = 0, int speciesReferenceGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const int c_api_getNumAllTextGlyphs(SBMLDocument* document, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const int c_api_getNumTextGlyphs(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getText(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0, bool checkForName = true)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setText(SBMLDocument* document, const char* id, const char* text, int graphicalObjectIndex = 0, int textGlyphIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getX(SBMLDocument* document, const char* id, const int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setX(SBMLDocument* document, const char* id, const double x, const int graphicalObjectIndex = 0, int layoutIndex = 0, bool isLayoutAdded = true)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getY(SBMLDocument* document, const char* id, const int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setY(SBMLDocument* document, const char* id, const double y, const int graphicalObjectIndex = 0, int layoutIndex = 0, bool isLayoutAdded = true)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setPosition(SBMLDocument* document, const char* id, const double x, const double y, const int graphicalObjectIndex = 0, int layoutIndex = 0, bool isLayoutAdded = true)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getWidth(SBMLDocument* document, const char* id, const int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setWidth(SBMLDocument* document, const char* id, const double width, const int graphicalObjectIndex = 0, int layoutIndex = 0, bool isLayoutAdded = true)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getHeight(SBMLDocument* document, const char* id, const int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setHeight(SBMLDocument* document, const char* id, const double height, const int graphicalObjectIndex = 0, int layoutIndex = 0, bool isLayoutAdded = true)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getTextX(SBMLDocument* document, const char* id, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setTextX(SBMLDocument* document, const char* id, const double x, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getTextY(SBMLDocument* document, const char* id, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setTextY(SBMLDocument* document, const char* id, const double y, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setTextPosition(SBMLDocument* document, const char* id, const double x, const double y, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getTextWidth(SBMLDocument* document, const char* id, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setTextWidth(SBMLDocument* document, const char* id, const double width, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getTextHeight(SBMLDocument* document, const char* id, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setTextHeight(SBMLDocument* document, const char* id, const double height, const int graphicalObjectIndex, const int textGlyphIndex, int layoutIndex)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isSetCurve(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const int c_api_getNumCurveSegments(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isCurveSegmentCubicBezier(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getCurveSegmentStartPointX(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setCurveSegmentStartPointX(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getCurveSegmentStartPointY(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setCurveSegmentStartPointY(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getCurveSegmentEndPointX(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setCurveSegmentEndPointX(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getCurveSegmentEndPointY(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setCurveSegmentEndPointY(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getCurveSegmentBasePoint1X(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setCurveSegmentBasePoint1X(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getCurveSegmentBasePoint1Y(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setCurveSegmentBasePoint1Y(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getCurveSegmentBasePoint2X(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setCurveSegmentBasePoint2X(SBMLDocument* document, const char* id, const double x, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getCurveSegmentBasePoint2Y(SBMLDocument* document, const char* id, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setSegmentCurveBasePoint2Y(SBMLDocument* document, const char* id, const double y, int graphicalObjectIndex = 0, int curveSegmentIndex = 0, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumGlobalRenderInformation(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumLocalRenderInformation(SBMLDocument* document, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::removeRenderInformation(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::removeGlobalRenderInformation(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::removeLocalRenderInformation(SBMLDocument* document, int layoutIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createDefaultGlobalRenderInformation(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::createDefaultLocalRenderInformation(SBMLDocument* document)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetBackgroundColor(SBMLDocument* document, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getBackgroundColor(SBMLDocument* document, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setBackgroundColor(SBMLDocument* document, const char* backgroundColor, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumColors(SBMLDocument* document, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumGlobalColors(SBMLDocument* document, int renderIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumLocalColors(SBMLDocument* document, int renderIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthGlobalColorId(SBMLDocument* document, int colorIndex, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthLocalColorId(SBMLDocument* document, int colorIndex, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isSetColorValue(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getColorValue(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::setColorValue(SBMLDocument* document, const char* id, const char* value, int renderIndex)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumGradients(SBMLDocument* document, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumGlobalGradients(SBMLDocument* document, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNumLocalGradients(SBMLDocument* document, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthGlobalGradientId(SBMLDocument* document, int gradientIndex, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::getNthLocalGradientId(SBMLDocument* document, int gradientIndex, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isLinearGradient(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_CPP_NAMESPACE::isRadialGradient(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isSetSpreadMethod(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getSpreadMethod(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setSpreadMethod(SBMLDocument* document, const char* id, const char* spreadMethod, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_getNumGradientStops(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isSetOffset(SBMLDocument* document, const char* id, int gradientStopIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getOffset(SBMLDocument* document, const char* id, int gradientStopIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setOffset(SBMLDocument* document, const char* id, const double offset, int gradientStopIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isSetStopColor(SBMLDocument* document, const char* id, int gradientStopIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const char* c_api_getStopColor(SBMLDocument* document, const char* id, int gradientStopIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setStopColor(SBMLDocument* document, const char* id, const char* stopColor, int gradientStopIndex = 0, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isSetLinearGradientX1(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getLinearGradientX1(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setLinearGradientX1(SBMLDocument* document, const char* id, const double x1, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isSetLinearGradientY1(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getLinearGradientY1(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setLinearGradientY1(SBMLDocument* document, const char* id, const double y1, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isSetLinearGradientX2(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getLinearGradientX2(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setLinearGradientX2(SBMLDocument* document, const char* id, const double x2, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isSetLinearGradientY2(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getLinearGradientY2(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setLinearGradientY2(SBMLDocument* document, const char* id, const double y2, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isSetRadialGradientCenterX(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getRadialGradientCenterX(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setRadialGradientCenterX(SBMLDocument* document, const char* id, const double cx, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isSetRadialGradientCenterY(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getRadialGradientCenterY(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setRadialGradientCenterY(SBMLDocument* document, const char* id, const double cy, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isSetRadialGradientFocalX(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getRadialGradientFocalX(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setRadialGradientFocalX(SBMLDocument* document, const char* id, const double fx, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isSetRadialGradientFocalY(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getRadialGradientFocalY(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setRadialGradientFocalY(SBMLDocument* document, const char* id, const double fy, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN bool c_api_isSetRadialGradientRadius(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN const double c_api_getRadialGradientRadius(SBMLDocument* document, const char* id, int renderIndex = 0)

.. doxygenfunction:: LIBSBMLNETWORK_EXTERN int c_api_setRadialGradientRadius(SBMLDocument* document, const char* id, const double r, int renderIndex = 0)