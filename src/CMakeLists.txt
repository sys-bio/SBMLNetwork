set(CMAKE_INCLUDE_CURRENT_DIR ON)

## sources
set(SOURCES 
	libsbml_ne_common.cpp
    	libsbml_ne_layout.cpp
	libsbml_ne_autolayout.cpp
	libsbml_ne_layout_helpers.cpp
	libsbml_ne_render.cpp
	libsbml_ne_render_helpers.cpp)

## headers
set(HEADERS 
	libsbml_ne_common.h
	libsbml_ne_layout.h
	libsbml_ne_autolayout.h
	libsbml_ne_layout_helpers.h
	libsbml_ne_render.h
	libsbml_ne_render_helpers.h)

### shared library
add_library(sbml_networkeditor SHARED ${SOURCES})
target_include_directories(sbml_networkeditor PRIVATE
	${GRAPHVIZ_INCLUDEDIR})
target_link_libraries(sbml_networkeditor ${GRAPHVIZ_LIBS_FIRSTHAND})
if (WIN32)
	target_link_libraries(sbml_networkeditor libsbml ${EXTRA_LIBS})
else ()
	target_link_libraries(sbml_networkeditor sbml)
endif ()
	
# copy dependencies to the build directory
if (APPLE)
	set(DEPENDENCIES_DIR ${CMAKE_BINARY_DIR}/src/dependencies)
	add_custom_command(TARGET sbml_networkeditor POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E make_directory ${DEPENDENCIES_DIR}
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SBML_LIBS}
		${DEPENDENCIES_DIR}
		COMMAND ${CMAKE_INSTALL_NAME_TOOL} -change
		"libsbml.5.dylib"
		"@rpath/libsbml.5.dylib" $<TARGET_FILE:sbml_networkeditor>)

	add_custom_command(TARGET sbml_networkeditor POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E make_directory ${DEPENDENCIES_DIR}/graphviz
			COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GRAPHVIZ_LIBS}
			${DEPENDENCIES_DIR}
			COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GRAPHVIZ_APIS}
			${DEPENDENCIES_DIR}/graphviz
			COMMAND ${CMAKE_COMMAND} -E copy_if_different ${GRAPHVIZ_API_CONFIG}
			${DEPENDENCIES_DIR}/graphviz)

	foreach(lib1fullpath IN LISTS GRAPHVIZ_LIBS)
		get_filename_component(lib1name ${lib1fullpath} NAME)
		add_custom_command(TARGET sbml_networkeditor POST_BUILD
				COMMAND ${CMAKE_INSTALL_NAME_TOOL} -id
				"@rpath/${lib1name}"
				"${DEPENDENCIES_DIR}/${lib1name}")			

		foreach(lib2fullpath IN LISTS GRAPHVIZ_LIBS)
			get_filename_component(lib2name ${lib2fullpath} NAME)				
			add_custom_command(TARGET sbml_networkeditor POST_BUILD
				COMMAND ${CMAKE_INSTALL_NAME_TOOL} -change
				"${lib1fullpath}" "@rpath/${lib1name}"
					"${DEPENDENCIES_DIR}/${lib2name}")
		endforeach()

		foreach(lib2fullpath IN LISTS GRAPHVIZ_APIS)
			get_filename_component(lib2name ${lib2fullpath} NAME)
			add_custom_command(TARGET sbml_networkeditor POST_BUILD
				COMMAND ${CMAKE_INSTALL_NAME_TOOL} -id
				"@rpath/${lib2name}"
				"${DEPENDENCIES_DIR}/graphviz/${lib2name}")
			
			add_custom_command(TARGET sbml_networkeditor POST_BUILD
				COMMAND ${CMAKE_INSTALL_NAME_TOOL} -change
				"${lib1fullpath}" "@rpath/${lib1name}"
					"${DEPENDENCIES_DIR}/graphviz/${lib2name}")
		endforeach()
		
		#set(GRAPHVIZ_LIBS_MODIFIED ${GRAPHVIZ_LIBS_MODIFIED}
		#"${DEPENDENCIES_DIR}/${lib1name}")
	endforeach()

	add_custom_command(TARGET sbml_networkeditor POST_BUILD
			COMMAND ${CMAKE_INSTALL_NAME_TOOL} -change
			"/usr/local/opt/graphviz/lib/libgvc.6.dylib"
			"@rpath/libgvc.6.dylib" $<TARGET_FILE:sbml_networkeditor>
			COMMAND ${CMAKE_INSTALL_NAME_TOOL} -change
			"/usr/local/opt/graphviz/lib/libcgraph.6.dylib"
			"@rpath/libcgraph.6.dylib" $<TARGET_FILE:sbml_networkeditor>
			COMMAND ${CMAKE_INSTALL_NAME_TOOL} -change
			"/usr/local/opt/graphviz/lib/libcdt.5.dylib"
			"@rpath/libcdt.5.dylib" $<TARGET_FILE:sbml_networkeditor>)
endif(APPLE)

## set library dist
install(TARGETS sbml_networkeditor RUNTIME DESTINATION bin COMPONENT sbml_networkeditor_api
									LIBRARY DESTINATION lib COMPONENT sbml_networkeditor_api
									ARCHIVE DESTINATION lib COMPONENT sbml_networkeditor_api)

### static library
if (BUILD_STATIC_LIB)
	add_library(sbml_networkeditor-static STATIC ${SOURCES})
	target_include_directories(sbml_networkeditor-static PRIVATE ${GRAPHVIZ_INCLUDEDIR})
	target_link_libraries(sbml_networkeditor-static ${GRAPHVIZ_LIBS_FIRSTHAND})
	if (WIN32)
		target_link_libraries(sbml_networkeditor-static libsbml ${EXTRA_LIBS})
	else ()
		target_link_libraries(sbml_networkeditor-static sbml)
	endif ()
	install(TARGETS sbml_networkeditor-static RUNTIME DESTINATION bin COMPONENT sbm_networkeditor_api
												LIBRARY DESTINATION lib COMPONENT sbml_networkeditor_api
												ARCHIVE DESTINATION lib COMPONENT sbml_networkeditor_api)
endif()

### install
install(DIRECTORY ${CMAKE_SOURCE_DIR}/src
		DESTINATION include COMPONENT sbml_networkeditor_api FILES_MATCHING PATTERN "*.h")
install(DIRECTORY "${SBML_INCLUDEDIR}"
		DESTINATION include COMPONENT sbml_networkeditor_api FILES_MATCHING PATTERN "*.h")
if (WIN32)
	include (InstallRequiredSystemLibraries)
	install(FILES ${LIBSBML_DLLS} ${GRAPHVIZ_DLLS} ${GRAPHVIZ_API_CONFIG}
			DESTINATION bin COMPONENT sbml_networkeditor_api)
elseif (APPLE)
	install(DIRECTORY ${DEPENDENCIES_DIR}
			DESTINATION lib COMPONENT sbml_networkeditor_api)
elseif(UNIX)
	install(FILES ${SBML_LIBS} ${GRAPHVIZ_LIBS}
			DESTINATION lib/dependencies COMPONENT sbml_networkeditor_api)
	install(FILES ${GRAPHVIZ_APIS} ${GRAPHVIZ_API_CONFIG}
			DESTINATION lib/dependencies/graphviz COMPONENT sbml_networkeditor_api)
endif()