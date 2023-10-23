set(CMAKE_INCLUDE_CURRENT_DIR ON)

## sources
set(SOURCES 
		libsbml_ne_common.cpp
		libsbml_ne_layout.cpp
		autolayout/libsbml_ne_autolayout.cpp
		libsbml_ne_layout_helpers.cpp
		libsbml_ne_render.cpp
		libsbml_ne_render_helpers.cpp
		libsbml_ne_sbmldocument.cpp
		libsbml_ne_sbmldocument_layout.cpp
		libsbml_ne_layout_render.cpp
		libsbml_ne_sbmldocument_render.cpp
		autolayout/libsbml_ne_autolayout.cpp
		autolayout/libsbml_ne_fruchterman_reingold_algorithm.cpp
		autolayout/libsbml_ne_autolayout_node.cpp
		autolayout/libsbml_ne_autolayout_connection.cpp
		autolayout/libsbml_ne_autolayout_point.cpp)

## headers
set(HEADERS 
		libsbml_ne_common.h
		libsbml_ne_layout.h
		autolayout/libsbml_ne_autolayout.h
		libsbml_ne_layout_helpers.h
		libsbml_ne_render.h
		libsbml_ne_render_helpers.h
		libsbml_ne_sbmldocument.h
		libsbml_ne_sbmldocument_layout.h
		libsbml_ne_layout_render.h
		libsbml_ne_sbmldocument_render.h
		autolayout/libsbml_ne_autolayout.h
		autolayout/libsbml_ne_fruchterman_reingold_algorithm.h
		autolayout/libsbml_ne_autolayout_node.h
		autolayout/libsbml_ne_autolayout_connection.h
		autolayout/libsbml_ne_autolayout_point.h)

### shared library
add_library(sbmlnetworkeditor SHARED ${SOURCES})
set_target_properties(sbmlnetworkeditor PROPERTIES
		VERSION ${LIBSBML_NETWORKEDITOR_DOTTED_VERSION}
		SOVERSION ${LIBSBML_NETWORKEDITOR_VERSION_MAJOR})

if (WIN32)
	target_link_libraries(sbmlnetworkeditor libsbml ${EXTRA_LIBS})
else ()
	target_link_libraries(sbmlnetworkeditor sbml)
endif ()
	
# copy dependencies to the build directory
if (APPLE)
	set(DEPENDENCIES_DIR ${CMAKE_BINARY_DIR}/src/dependencies)
	add_custom_command(TARGET sbmlnetworkeditor POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E make_directory ${DEPENDENCIES_DIR}
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SBML_LIBS}
		${DEPENDENCIES_DIR}
		COMMAND ${CMAKE_INSTALL_NAME_TOOL} -change
		"libsbml.5.dylib"
		"@rpath/libsbml.5.dylib" $<TARGET_FILE:sbmlnetworkeditor>)
endif(APPLE)

## set library dist
install(TARGETS sbmlnetworkeditor RUNTIME DESTINATION bin COMPONENT libsbmlnetworkeditor_api
									LIBRARY DESTINATION lib COMPONENT libsbmlnetworkeditor_api
									ARCHIVE DESTINATION lib COMPONENT libsbmlnetworkeditor_api)

### static library
if (BUILD_STATIC_LIB)
	add_library(sbmlnetworkeditor-static STATIC ${SOURCES})
	if (WIN32)
		target_link_libraries(sbmlnetworkeditor-static libsbml ${EXTRA_LIBS})
	else ()
		target_link_libraries(sbmlnetworkeditor-static sbml)
	endif ()
	install(TARGETS sbmlnetworkeditor-static RUNTIME DESTINATION bin COMPONENT sbm_networkeditor_api
												LIBRARY DESTINATION lib COMPONENT libsbmlnetworkeditor_api
												ARCHIVE DESTINATION lib COMPONENT libsbmlnetworkeditor_api)
endif()

### install
install(DIRECTORY ${CMAKE_SOURCE_DIR}/src
		DESTINATION include COMPONENT libsbmlnetworkeditor_api FILES_MATCHING PATTERN "*.h")
install(DIRECTORY "${SBML_INCLUDEDIR}"
		DESTINATION include COMPONENT libsbmlnetworkeditor_api FILES_MATCHING PATTERN "*.h")
if (WIN32)
	include (InstallRequiredSystemLibraries)
	install(FILES ${LIBSBML_DLLS}
			DESTINATION bin COMPONENT libsbmlnetworkeditor_api)
elseif (APPLE)
	install(DIRECTORY ${DEPENDENCIES_DIR}
			DESTINATION lib COMPONENT libsbmlnetworkeditor_api)
elseif(UNIX)
	install(FILES ${SBML_LIBS}
			DESTINATION lib/dependencies COMPONENT libsbmlnetworkeditor_api)
endif()

### build language bindings
if (WITH_SWIG)
	add_subdirectory(bindings)
endif()