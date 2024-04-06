set(CMAKE_INCLUDE_CURRENT_DIR ON)

## sources
set(SOURCES 
		libsbmlnetwork_common.cpp
		libsbmlnetwork_layout.cpp
        autolayout/libsbmlnetwork_autolayout.cpp
		libsbmlnetwork_layout_helpers.cpp
		libsbmlnetwork_render.cpp
		libsbmlnetwork_render_helpers.cpp
		libsbmlnetwork_sbmldocument.cpp
		libsbmlnetwork_sbmldocument_layout.cpp
		libsbmlnetwork_layout_render.cpp
		libsbmlnetwork_sbmldocument_render.cpp
        autolayout/libsbmlnetwork_autolayout.cpp
		autolayout/libsbmlnetwork_fruchterman_reingold_algorithm.cpp
		autolayout/libsbmlnetwork_autolayout_object_base.cpp
		autolayout/libsbmlnetwork_autolayout_node.cpp
		autolayout/libsbmlnetwork_autolayout_connection.cpp
		autolayout/libsbmlnetwork_autolayout_curve.cpp
		autolayout/libsbmlnetwork_autolayout_point.cpp
		c_api/libsbmlnetwork_c_api.cpp)

## headers
set(HEADERS 
		libsbmlnetwork_common.h
		libsbmlnetwork_layout.h
		autolayout/libsbmlnetwork_autolayout.h
		libsbmlnetwork_layout_helpers.h
		libsbmlnetwork_render.h
		libsbmlnetwork_render_helpers.h
		libsbmlnetwork_sbmldocument.h
		libsbmlnetwork_sbmldocument_layout.h
		libsbmlnetwork_layout_render.h
		libsbmlnetwork_sbmldocument_render.h
		autolayout/libsbmlnetwork_autolayout.h
		autolayout/libsbmlnetwork_fruchterman_reingold_algorithm.h
		autolayout/libsbmlnetwork_autolayout_object_base.h
		autolayout/libsbmlnetwork_autolayout_node.h
		autolayout/libsbmlnetwork_autolayout_connection.h
		autolayout/libsbmlnetwork_autolayout_curve.h
		autolayout/libsbmlnetwork_autolayout_point.h
		c_api/libsbmlnetwork_c_api.h)

### shared library
add_library(sbmlnetwork SHARED ${SOURCES})
set_target_properties(sbmlnetwork PROPERTIES
		VERSION ${LIBSBMLNETWORK_DOTTED_VERSION}
		SOVERSION ${LIBSBMLNETWORK_VERSION_MAJOR})

if (WIN32)
	target_link_libraries(sbmlnetwork libsbml ${EXTRA_LIBS})
	set_target_properties(sbmlnetwork PROPERTIES OUTPUT_NAME "libsbmlnetwork")
else ()
	target_link_libraries(sbmlnetwork sbml)
endif ()

# copy dependencies to the build directory
if (APPLE)
	set(DEPENDENCIES_DIR ${CMAKE_BINARY_DIR}/src/dependencies)
	set(RESOURCES_DIR ${CMAKE_BINARY_DIR}/src/resources)
	add_custom_command(TARGET sbmlnetwork POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E make_directory ${DEPENDENCIES_DIR}
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SBML_LIBS}
		${DEPENDENCIES_DIR}
		COMMAND ${CMAKE_COMMAND} -E make_directory ${RESOURCES_DIR}
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${RESOURCES}
		${RESOURCES_DIR}
		COMMAND ${CMAKE_INSTALL_NAME_TOOL} -change
		"libsbml.5.dylib"
		"@rpath/libsbml.5.dylib" $<TARGET_FILE:sbmlnetwork>)
endif(APPLE)

## set library dist
install(TARGETS sbmlnetwork RUNTIME DESTINATION bin COMPONENT libsbmlnetwork_api
									LIBRARY DESTINATION lib COMPONENT libsbmlnetwork_api
									ARCHIVE DESTINATION lib COMPONENT libsbmlnetwork_api)

### static library
if (BUILD_STATIC_LIB)
	add_library(sbmlnetwork-static STATIC ${SOURCES})
	if (WIN32)
		target_link_libraries(sbmlnetwork-static libsbml ${EXTRA_LIBS})
		set_target_properties(sbmlnetwork-static PROPERTIES OUTPUT_NAME "libsbmlnetwork-static")
	else ()
		target_link_libraries(sbmlnetwork-static sbml)
	endif ()
	install(TARGETS sbmlnetwork-static RUNTIME DESTINATION bin COMPONENT sbm_network_api
												LIBRARY DESTINATION lib COMPONENT libsbmlnetwork_api
												ARCHIVE DESTINATION lib COMPONENT libsbmlnetwork_api)
endif()

### install
file(GLOB SOURCE_HEADERS "${CMAKE_SOURCE_DIR}/src/*.h")
install(FILES ${SOURCE_HEADERS} DESTINATION include/libsbmlnetwork COMPONENT libsbmlnetwork_api)
file(GLOB AUTOLAYOUT_HEADERS "${CMAKE_SOURCE_DIR}/src/autolayout/*.h")
install(FILES ${AUTOLAYOUT_HEADERS} DESTINATION include/libsbmlnetwork/autolayout COMPONENT libsbmlnetwork_api)
install(DIRECTORY "${SBML_INCLUDEDIR}"
		DESTINATION include COMPONENT libsbmlnetwork_api FILES_MATCHING PATTERN "*.h")
if (WIN32)
	include (InstallRequiredSystemLibraries)
	install(FILES ${LIBSBML_DLLS}
			DESTINATION bin COMPONENT libsbmlnetwork_api)
	install(FILES ${RESOURCES}
			DESTINATION bin/resources COMPONENT libsbmlnetwork_api)
elseif (APPLE)
	install(DIRECTORY ${DEPENDENCIES_DIR}
			DESTINATION lib COMPONENT libsbmlnetwork_api)
	install(DIRECTORY ${RESOURCES_DIR}
			DESTINATION lib COMPONENT libsbmlnetwork_api)
elseif(UNIX)
	install(FILES ${SBML_LIBS} DESTINATION lib/dependencies COMPONENT libsbmlnetwork_api)
	install(FILES ${RESOURCES} DESTINATION lib/resources COMPONENT libsbmlnetwork_api)
endif()

add_subdirectory(bindings)