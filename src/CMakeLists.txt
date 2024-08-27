set(CMAKE_INCLUDE_CURRENT_DIR ON)

## sources
set(SOURCES 
		libsbmlnetwork_common.cpp
		libsbmlnetwork_layout.cpp
		libsbmlnetwork_layout_helpers.cpp
		libsbmlnetwork_render.cpp
		libsbmlnetwork_render_helpers.cpp
		libsbmlnetwork_sbmldocument.cpp
		libsbmlnetwork_sbmldocument_layout.cpp
		libsbmlnetwork_layout_render.cpp
		libsbmlnetwork_sbmldocument_render.cpp
		colors/libsbmlnetwork_colors.cpp
		styles/libsbmlnetwork_styles.cpp
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
		libsbmlnetwork_layout_helpers.h
		libsbmlnetwork_render.h
		libsbmlnetwork_render_helpers.h
		libsbmlnetwork_sbmldocument.h
		libsbmlnetwork_sbmldocument_layout.h
		libsbmlnetwork_layout_render.h
		libsbmlnetwork_sbmldocument_render.h
		colors/libsbmlnetwork_colors.h
		styles/libsbmlnetwork_styles.h
		autolayout/libsbmlnetwork_autolayout.h
		autolayout/libsbmlnetwork_fruchterman_reingold_algorithm.h
		autolayout/libsbmlnetwork_autolayout_object_base.h
		autolayout/libsbmlnetwork_autolayout_node.h
		autolayout/libsbmlnetwork_autolayout_connection.h
		autolayout/libsbmlnetwork_autolayout_curve.h
		autolayout/libsbmlnetwork_autolayout_point.h
		c_api/libsbmlnetwork_c_api.h)

#### dependencies
add_library(libsbml STATIC IMPORTED)
set_target_properties(libsbml PROPERTIES IMPORTED_LOCATION ${LIBSBML_LIBRARY})
add_library(libexpat STATIC IMPORTED)
set_target_properties(libexpat PROPERTIES IMPORTED_LOCATION ${LIBEXPAT_LIBRARY})
add_library(libz STATIC IMPORTED)
set_target_properties(libz PROPERTIES IMPORTED_LOCATION ${LIBZ_LIBRARY})

### shared library
if (BUILD_SHARED_LIBS)
	add_library(sbmlnetwork SHARED ${SOURCES})
	set_target_properties(sbmlnetwork PROPERTIES
			VERSION ${LIBSBMLNETWORK_DOTTED_VERSION}
			SOVERSION ${LIBSBMLNETWORK_VERSION_MAJOR})
	target_link_libraries(sbmlnetwork PUBLIC libsbml)
	target_link_libraries(sbmlnetwork PUBLIC libexpat)
	target_link_libraries(sbmlnetwork PUBLIC libz)
	target_link_libraries(sbmlnetwork PUBLIC ${EXTRA_LIBS})
	target_include_directories(sbmlnetwork PUBLIC ${DEPENDENCIES_INCLUDE_DIR})
	if (WIN32)
		set_target_properties(sbmlnetwork PROPERTIES OUTPUT_NAME "libsbmlnetwork")
	endif ()
	install(TARGETS sbmlnetwork RUNTIME DESTINATION bin COMPONENT libsbmlnetwork_api
			LIBRARY DESTINATION lib COMPONENT libsbmlnetwork_api
			ARCHIVE DESTINATION lib COMPONENT libsbmlnetwork_api)
endif ()

### static library
if (BUILD_STATIC_LIBS)
	add_library(sbmlnetwork-static STATIC ${SOURCES})
	target_link_libraries(sbmlnetwork-static ${LIBSBML_LIBRARY} ${EXTRA_LIBS})
	target_include_directories(sbmlnetwork-static PUBLIC ${DEPENDENCIES_INCLUDE_DIR})
	if (WIN32)
		set_target_properties(sbmlnetwork-static PROPERTIES OUTPUT_NAME "libsbmlnetwork-static")
	endif ()
	install(TARGETS sbmlnetwork-static RUNTIME DESTINATION bin COMPONENT sbm_network_api
												LIBRARY DESTINATION lib COMPONENT libsbmlnetwork_api
												ARCHIVE DESTINATION lib COMPONENT libsbmlnetwork_api)
endif()

### install
file(GLOB SOURCE_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
install(FILES ${SOURCE_HEADERS} DESTINATION include COMPONENT libsbmlnetwork_api)
file(GLOB AUTOLAYOUT_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/autolayout/*.h")
install(FILES ${AUTOLAYOUT_HEADERS} DESTINATION include/autolayout COMPONENT libsbmlnetwork_api)
file(GLOB COLORS_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/colors/*.h")
install(FILES ${COLORS_HEADERS} DESTINATION include/colors COMPONENT libsbmlnetwork_api)
file(GLOB STYLES_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/styles/*.h")
install(FILES ${STYLES_HEADERS} DESTINATION include/styles COMPONENT libsbmlnetwork_api)
file(GLOB C_API_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/c_api/*.h")
install(FILES ${C_API_HEADERS} DESTINATION include/c_api COMPONENT libsbmlnetwork_api)
if (WIN32)
	include (InstallRequiredSystemLibraries)
endif()

add_subdirectory(bindings)