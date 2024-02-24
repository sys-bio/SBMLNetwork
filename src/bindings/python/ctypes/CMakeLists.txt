configure_file(${CMAKE_CURRENT_SOURCE_DIR}/libsbmlnetworkeditor.py.cmake ${CMAKE_CURRENT_BINARY_DIR}/libsbmlnetworkeditor.py)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/__init__.py.cmake ${CMAKE_CURRENT_BINARY_DIR}/__init__.py)

install(TARGETS sbmlnetworkeditor DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetworkeditor COMPONENT libsbmlnetworkeditor_python_bindings)

if (PYTHON_INSTALL_IN_PREFIX)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libsbmlnetworkeditor.py  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetworkeditor COMPONENT libsbmlnetworkeditor_python_bindings)
endif()

if (PYTHON_INSTALL_WITH_SETUP)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libsbmlnetworkeditor.py  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetworkeditor COMPONENT libsbmlnetworkeditor_python_bindings)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/__init__.py  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/libsbmlnetworkeditor COMPONENT libsbmlnetworkeditor_python_bindings)
endif()

