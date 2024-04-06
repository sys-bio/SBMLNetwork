if (${Python_REQUIRED_VERSION})
    find_package(Python ${Python_REQUIRED_VERSION} EXACT COMPONENTS Interpreter Development)
else ()
    find_package(Python COMPONENTS Interpreter Development)
endif ()

if (Python_FOUND)
    message(STATUS "Python found: ${Python_EXECUTABLE} (found version \"${Python_VERSION}\")")
else ()
    message(FATAL_ERROR "Python not found")
endif ()

## determine the python installation directory
set(PYTHON_PACKAGE_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/lib/python${Python_VERSION}/site-packages)
if (UNIX OR CYGWIN)
    execute_process(COMMAND "${Python_EXECUTABLE}" -c "import sys;import platform; sys.stdout.write(platform.python_version()[:3])"
            OUTPUT_VARIABLE Python_VERSION)
endif()

cmake_dependent_option(PYTHON_INSTALL_IN_PREFIX "Install python binaries using the specified install prefix." OFF
        "NOT ${PYTHON_INSTALL_WITH_SETUP}" OFF)
cmake_dependent_option(PYTHON_INSTALL_WITH_SETUP "Use setup.py to install the compiled python binaries." OFF
        "NOT ${PYTHON_INSTALL_IN_PREFIX}" OFF)

if (${WITH_SWIG})
    add_subdirectory(swig)
else ()
    add_subdirectory(ctypes)
endif ()


if (PYTHON_INSTALL_IN_PREFIX)
    if (WIN32)
        include(InstallRequiredSystemLibraries)
        install(PROGRAMS ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS} DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetwork COMPONENT libsbmlnetwork_python_bindings)
        install(FILES ${LIBSBML_DLLS} DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetwork COMPONENT libsbmlnetwork_python_bindings)
        install(DIRECTORY ${CMAKE_INSTALL_PREFIX}/bin/resources DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetwork COMPONENT libsbmlnetwork_python_bindings)
    elseif (UNIX)
        install(DIRECTORY ${CMAKE_INSTALL_PREFIX}/lib/dependencies DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetwork COMPONENT libsbmlnetwork_python_bindings)
        install(DIRECTORY ${CMAKE_INSTALL_PREFIX}/lib/resources DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetwork COMPONENT libsbmlnetwork_python_bindings)
    endif ()
endif()

if (PYTHON_INSTALL_WITH_SETUP)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/setup.py.cmake ${CMAKE_CURRENT_BINARY_DIR}/setup.py)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/setup.py  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR} COMPONENT libsbmlnetwork_python_bindings)
    if (WIN32)
        include(InstallRequiredSystemLibraries)
        install(PROGRAMS ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS} DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetwork COMPONENT libsbmlnetwork_python_bindings)
        install(FILES ${LIBSBML_DLLS} DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetwork COMPONENT libsbmlnetwork_python_bindings)
        install(DIRECTORY ${CMAKE_INSTALL_PREFIX}/bin/resources DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetwork COMPONENT libsbmlnetwork_python_bindings)
    elseif (UNIX)
        install(DIRECTORY ${CMAKE_INSTALL_PREFIX}/lib/dependencies DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetwork COMPONENT libsbmlnetwork_python_bindings)
        install(DIRECTORY ${CMAKE_INSTALL_PREFIX}/lib/resources DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetwork COMPONENT libsbmlnetwork_python_bindings)
    endif ()
endif()