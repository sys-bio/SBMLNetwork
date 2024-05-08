configure_file(${CMAKE_CURRENT_SOURCE_DIR}/libsbmlnetwork.py.cmake ${CMAKE_CURRENT_BINARY_DIR}/libsbmlnetwork.py)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/__init__.py.cmake ${CMAKE_CURRENT_BINARY_DIR}/__init__.py)

if (WIN32)
    install(TARGETS sbmlnetwork DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetwork/libsbmlnetwork COMPONENT libsbmlnetwork_python_bindings)
elseif (UNIX)
    install(TARGETS sbmlnetwork DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetwork/libsbmlnetwork/libs COMPONENT libsbmlnetwork_python_bindings)
endif ()

if (PYTHON_INSTALL_IN_PREFIX)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libsbmlnetwork.py  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetwork/libsbmlnetwork COMPONENT libsbmlnetwork_python_bindings)
endif()

if (PYTHON_INSTALL_WITH_SETUP)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libsbmlnetwork.py  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetwork/libsbmlnetwork COMPONENT libsbmlnetwork_python_bindings)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/__init__.py  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetwork/libsbmlnetwork COMPONENT libsbmlnetwork_python_bindings)
    add_subdirectory(sbmlnetwork)
endif()

