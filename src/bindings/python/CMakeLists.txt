set(CMAKE_INCLUDE_CURRENT_DIR ON)

## find python packages
find_package(Python COMPONENTS Interpreter Development)

## determine local dependencies, so as to re-swig if one of them changed
file(GLOB SWIG_DEPENDENCIES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.i
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../swig/*.i
        ${CMAKE_CURRENT_SOURCE_DIR}/../swig/*.h)

## Swig bindings
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/libsbml_networkeditor_wrap.cpp
        ${CMAKE_CURRENT_BINARY_DIR}/libsbml_networkeditor.py

        COMMAND "${SWIG_EXECUTABLE}"
        ARGS  -I${CMAKE_CURRENT_SOURCE_DIR}/../swig/
        -I${CMAKE_CURRENT_SOURCE_DIR}
        -I${CMAKE_CURRENT_BINARY_DIR}
        -I${CMAKE_SOURCE_DIR}/src
        -DGENERATING_DOCS
        -c++
        -python
        ${SWIG_EXTRA_ARGS}
        -o ${CMAKE_CURRENT_BINARY_DIR}/libsbml_networkeditor_wrap.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/libsbml_networkeditor.i
        MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/libsbml_networkeditor.i
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
        ${SWIG_DEPENDENCIES}
        COMMENT "Swig Python source")

add_custom_target(binding_python_swig ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/libsbml_networkeditor_wrap.cpp)

add_library(binding_python_lib SHARED libsbml_networkeditor_wrap.cpp)

target_include_directories(binding_python_lib PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../swig
        ${GRAPHVIZ_INCLUDEDIR})

target_link_libraries(binding_python_lib
        Python::Python
        sbml_networkeditor-static
        ${GRAPHVIZ_LIBS_FIRSTHAND})

add_dependencies(binding_python_lib binding_python_swig)
set_target_properties(binding_python_lib PROPERTIES OUTPUT_NAME "_libsbml_networkeditor")

if (UNIX)
    set_target_properties (binding_python_lib PROPERTIES PREFIX "")
    set_target_properties (binding_python_lib PROPERTIES SUFFIX ".so")
else()
    if (CYGWIN)
        set_target_properties (binding_python_lib PROPERTIES PREFIX "")
        set_target_properties (binding_python_lib PROPERTIES SUFFIX ".dll")
    else()
        set_target_properties (binding_python_lib PROPERTIES SUFFIX ".pyd")
    endif()
endif()

if (APPLE)
    add_custom_command(TARGET binding_python_lib POST_BUILD
            COMMAND ${CMAKE_INSTALL_NAME_TOOL} -change
            "libsbml.5.dylib" "@rpath/libsbml.5.dylib"
            $<TARGET_FILE:binding_python_lib>
            COMMAND ${CMAKE_INSTALL_NAME_TOOL} -change
            "/usr/local/opt/graphviz/lib/libgvc.6.dylib"
            "@rpath/libgvc.6.dylib" $<TARGET_FILE:binding_python_lib>
            COMMAND ${CMAKE_INSTALL_NAME_TOOL} -change
            "/usr/local/opt/graphviz/lib/libcgraph.6.dylib"
            "@rpath/libcgraph.6.dylib" $<TARGET_FILE:binding_python_lib>
            COMMAND ${CMAKE_INSTALL_NAME_TOOL} -change
            "/usr/local/opt/graphviz/lib/libcdt.5.dylib"
            "@rpath/libcdt.5.dylib" $<TARGET_FILE:binding_python_lib>)
endif()

## determine the python installation directory
set(PYTHON_PACKAGE_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/lib/python${Python_VERSION}/site-packages)
if (UNIX OR CYGWIN)
    execute_process(COMMAND "${Python_EXECUTABLE}" -c "import sys;import platform; sys.stdout.write(platform.python_version()[:3])"
            OUTPUT_VARIABLE Python_VERSION)
endif()

## install using the configured install prefix
option (PYTHON_INSTALL_IN_PREFIX "Install python binaries using the specified install prefix." ON)
if (PYTHON_INSTALL_IN_PREFIX)
    install(TARGETS binding_python_lib DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbml_networkeditor 	COMPONENT libsbml_networkeditor_python_bindings)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libsbml_networkeditor.py  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR} COMPONENT libsbml_networkeditor_python_bindings)

    if (WIN32)
        include(InstallRequiredSystemLibraries)
        install(PROGRAMS ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS} DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbml_networkeditor COMPONENT libsbml_networkeditor_python_bindings)
        install(FILES ${LIBSBML_DLLS} ${GRAPHVIZ_DLLS} ${GRAPHVIZ_API_CONFIG} DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbml_networkeditor COMPONENT libsbml_networkeditor_python_bindings)
    endif(WIN32)
endif()

## install using setup.py
option (PYTHON_INSTALL_WITH_SETUP "Use setup.py to install the compiled python binaries." OFF)
if (PYTHON_INSTALL_WITH_SETUP)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/setup.py.cmake ${CMAKE_CURRENT_BINARY_DIR}/setup.py)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/setup.py  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR} COMPONENT libsbml_networkeditor_python_bindings)
    if (NOT EXISTS ${PYTHON_PACKAGE_INSTALL_DIR}/libsbml_networkeditor.py)
        install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libsbml_networkeditor.py DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR} COMPONENT libsbml_networkeditor_python_bindings)
    endif()
    ## __init__.py
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libsbml_networkeditor.py DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/libsbml_networkeditor RENAME __init__.py COMPONENT python_extra)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libsbml_networkeditor/__init__.py DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbml_networkeditor COMPONENT libsbml_networkeditor_python_bindings)

    install(CODE "execute_process(COMMAND \"${CMAKE_COMMAND}\" -E chdir ${PYTHON_PACKAGE_INSTALL_DIR} pip install .)" COMPONENT python_extra)
    if (UNIX)
        install(FILES ${SBML_LIBS} ${GRAPHVIZ_LIBS} DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbml_networkeditor/dependencies COMPONENT libsbml_networkeditor_python_bindings)
        install(FILES ${GRAPHVIZ_APIS} ${GRAPHVIZ_API_CONFIG} DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbml_networkeditor/dependencies/graphviz COMPONENT libsbml_networkeditor_python_bindings)
    endif()
endif()