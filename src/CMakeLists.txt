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
		features/colors/libsbmlnetwork_colors.cpp
		features/styles/libsbmlnetwork_styles.cpp
		features/autolayout/libsbmlnetwork_autolayout.cpp
		features/autolayout/libsbmlnetwork_fruchterman_reingold_algorithm.cpp
		features/autolayout/libsbmlnetwork_autolayout_object_base.cpp
		features/autolayout/libsbmlnetwork_autolayout_node.cpp
		features/autolayout/libsbmlnetwork_autolayout_connection.cpp
		features/autolayout/libsbmlnetwork_autolayout_curve.cpp
		features/autolayout/libsbmlnetwork_autolayout_point.cpp
		features/error_log/libsbmlnetwork_error_log.cpp
		features/user_data/libsbmlnetwork_user_data.cpp
		features/defaults/libsbmlnetwork_defaults_layout.cpp
		features/defaults/libsbmlnetwork_defaults_render.cpp
		features/alias_elements/libsbmlnetwork_alias_element.cpp
		features/alias_elements/libsbmlnetwork_alias_species.cpp
		features/alias_elements/libsbmlnetwork_alias_reaction.cpp
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
		features/colors/libsbmlnetwork_colors.h
		features/styles/libsbmlnetwork_styles.h
		features/autolayout/libsbmlnetwork_autolayout.h
		features/autolayout/libsbmlnetwork_fruchterman_reingold_algorithm.h
		features/autolayout/libsbmlnetwork_autolayout_object_base.h
		features/autolayout/libsbmlnetwork_autolayout_node.h
		features/autolayout/libsbmlnetwork_autolayout_connection.h
		features/autolayout/libsbmlnetwork_autolayout_curve.h
		features/autolayout/libsbmlnetwork_autolayout_point.h
		features/error_log/libsbmlnetwork_error_log.h
		features/user_data/libsbmlnetwork_user_data.h
        features/defaults/libsbmlnetwork_defaults_layout.h
		features/defaults/libsbmlnetwork_defaults_render.h
		features/alias_elements/libsbmlnetwork_alias_element.h
		features/alias_elements/libsbmlnetwork_alias_species.h
		features/alias_elements/libsbmlnetwork_alias_reaction.h
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
	add_library(sbmlnetwork SHARED ${SOURCES} ${HEADERS})
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
	add_library(sbmlnetwork-static STATIC ${SOURCES} ${HEADERS})
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
install(FILES ${SOURCE_HEADERS} DESTINATION include/sbmlnetwork COMPONENT libsbmlnetwork_api)
file(GLOB AUTOLAYOUT_HEADERS "features/autolayout/*.h")
install(FILES ${AUTOLAYOUT_HEADERS} DESTINATION include/sbmlnetwork/autolayout COMPONENT libsbmlnetwork_api)
file(GLOB COLORS_HEADERS "features/colors/*.h")
install(FILES ${COLORS_HEADERS} DESTINATION include/sbmlnetwork/colors COMPONENT libsbmlnetwork_api)
file(GLOB STYLES_HEADERS "features/styles/*.h")
install(FILES ${STYLES_HEADERS} DESTINATION include/sbmlnetwork/styles COMPONENT libsbmlnetwork_api)
file(GLOB C_API_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/c_api/*.h")
install(FILES ${C_API_HEADERS} DESTINATION include/sbmlnetwork/c_api COMPONENT libsbmlnetwork_api)
if (WIN32)
	include (InstallRequiredSystemLibraries)
endif()

add_subdirectory(bindings)