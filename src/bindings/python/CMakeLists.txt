include(CMakeDependentOption)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

## find python packages
if (${Python_REQUIRED_VERSION})
    find_package(Python ${Python_REQUIRED_VERSION} EXACT COMPONENTS Interpreter Development)
else ()
    find_package(Python COMPONENTS Interpreter Development)
endif ()

## determine local dependencies, so as to re-swig if one of them changed
file(GLOB SWIG_DEPENDENCIES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.i
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cmake
        ${CMAKE_CURRENT_SOURCE_DIR}/../swig/*.i
        ${CMAKE_CURRENT_SOURCE_DIR}/../swig/*.h)

## Swig bindings
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/libsbmlnetworkeditor_wrap.cpp
        ${CMAKE_CURRENT_BINARY_DIR}/libsbmlnetworkeditor.py

        COMMAND "${SWIG_EXECUTABLE}"
        ARGS  -I${CMAKE_CURRENT_SOURCE_DIR}/../swig/
        -I${CMAKE_CURRENT_SOURCE_DIR}
        -I${CMAKE_CURRENT_BINARY_DIR}
        -I${CMAKE_SOURCE_DIR}/src
        -DGENERATING_DOCS
        -c++
        -python
        ${SWIG_EXTRA_ARGS}
        -o ${CMAKE_CURRENT_BINARY_DIR}/libsbmlnetworkeditor_wrap.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/libsbmlnetworkeditor.i
        MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/libsbmlnetworkeditor.i
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
        ${SWIG_DEPENDENCIES}
        COMMENT "Swig Python source")

add_custom_target(binding_python_swig ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/libsbmlnetworkeditor_wrap.cpp)

add_library(binding_python_lib SHARED libsbmlnetworkeditor_wrap.cpp)

target_include_directories(binding_python_lib PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../swig)

target_link_libraries(binding_python_lib
        Python::Python
        sbmlnetworkeditor-static)

add_dependencies(binding_python_lib binding_python_swig)
set_target_properties(binding_python_lib PROPERTIES OUTPUT_NAME "_libsbmlnetworkeditor")

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
            $<TARGET_FILE:binding_python_lib>)
endif()

## determine the python installation directory
set(PYTHON_PACKAGE_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/lib/python${Python_VERSION}/site-packages)
if (UNIX OR CYGWIN)
    execute_process(COMMAND "${Python_EXECUTABLE}" -c "import sys;import platform; sys.stdout.write(platform.python_version()[:3])"
            OUTPUT_VARIABLE Python_VERSION)
endif()

## install using the configured install prefix
cmake_dependent_option(PYTHON_INSTALL_IN_PREFIX "Install python binaries using the specified install prefix." OFF
        "NOT ${PYTHON_INSTALL_WITH_SETUP}; NOT ${PYTHON_INSTALL_WITH_SETUP_WITH_WRAPPER_CLASS}" OFF)
if (PYTHON_INSTALL_IN_PREFIX)
    install(TARGETS binding_python_lib DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetworkeditor 	COMPONENT libsbmlnetworkeditor_python_bindings)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libsbmlnetworkeditor.py  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR} COMPONENT libsbmlnetworkeditor_python_bindings)

    if (WIN32)
        include(InstallRequiredSystemLibraries)
        install(PROGRAMS ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS} DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetworkeditor COMPONENT libsbmlnetworkeditor_python_bindings)
        install(FILES ${LIBSBML_DLLS} DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetworkeditor COMPONENT libsbmlnetworkeditor_python_bindings)
    elseif (UNIX)
        install(DIRECTORY ${CMAKE_INSTALL_PREFIX}/lib/dependencies DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetworkeditor COMPONENT libsbmlnetworkeditor_python_bindings)
    endif ()
endif()

## install using setup.py
cmake_dependent_option(PYTHON_INSTALL_WITH_SETUP "Use setup.py to install the compiled python binaries." OFF
        "NOT ${PYTHON_INSTALL_WITH_SETUP_WITH_WRAPPER_CLASS}; NOT ${PYTHON_INSTALL_IN_PREFIX}" OFF)
if (PYTHON_INSTALL_WITH_SETUP)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/setup.py.cmake ${CMAKE_CURRENT_BINARY_DIR}/setup.py)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/setup.py  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR} COMPONENT libsbmlnetworkeditor_python_bindings)
    install(TARGETS binding_python_lib DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetworkeditor 	COMPONENT libsbmlnetworkeditor_python_bindings)
    if (NOT EXISTS ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetworkeditor.py)
        install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libsbmlnetworkeditor.py DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR} COMPONENT libsbmlnetworkeditor_python_bindings)
    endif()
    ## __init__.py
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libsbmlnetworkeditor.py DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/libsbmlnetworkeditor RENAME __init__.py COMPONENT python_extra)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libsbmlnetworkeditor/__init__.py DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetworkeditor COMPONENT libsbmlnetworkeditor_python_bindings)
    install(CODE "execute_process(COMMAND \"${CMAKE_COMMAND}\" -E chdir ${PYTHON_PACKAGE_INSTALL_DIR} pip install .)" COMPONENT python_extra)
    if (WIN32)
        include(InstallRequiredSystemLibraries)
        install(PROGRAMS ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS} DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetworkeditor COMPONENT libsbmlnetworkeditor_python_bindings)
        install(FILES ${LIBSBML_DLLS} DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetworkeditor COMPONENT libsbmlnetworkeditor_python_bindings)
    elseif (UNIX)
        install(DIRECTORY ${CMAKE_INSTALL_PREFIX}/lib/dependencies DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetworkeditor COMPONENT libsbmlnetworkeditor_python_bindings)
    endif ()
endif()