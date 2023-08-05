cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(libsbmlnetworkeditor)
add_definitions(-DLIBSBML_NETWORKEDITOR_EXPORTS=true)

include(GNUInstallDirs)

## Determine the version
set(LIBSBML_NETWORKEDITOR_VERSION_MAJOR)
set(LIBSBML_NETWORKEDITOR_VERSION_MINOR)
set(LIBSBML_NETWORKEDITOR_VERSION_PATCH)
set(LIBSBML_NETWORKEDITOR_DOTTED_VERSION)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/VERSION.txt")
    file(STRINGS "${CMAKE_SOURCE_DIR}/VERSION.txt" VersionString NEWLINE_CONSUME)
    string(STRIP "${VersionString}" VersionString)
    set(LIBSBML_NETWORKEDITOR_DOTTED_VERSION ${VersionString})
    string(REPLACE "." ";" VersionString "${VersionString}" )
    string(REPLACE "-" ";" VersionString "${VersionString}" )
    list(LENGTH VersionString versionLength)
    list(GET VersionString 0 LIBSBML_NETWORKEDITOR_VERSION_MAJOR)
    list(GET VersionString 1 LIBSBML_NETWORKEDITOR_VERSION_MINOR)
    list(GET VersionString 2 LIBSBML_NETWORKEDITOR_VERSION_PATCH)
endif()

## find sbml package
if(WIN32)
	find_package(libsbml REQUIRED)
	file(GLOB LIBSBML_DLLS "${libsbml_DIR}/../../bin/libsbml.dll")
	set(SBML_INCLUDEDIR "${libsbml_DIR}/../../include/sbml")
else()
	find_package(sbml REQUIRED)
	file(GLOB SBML_LIBS "${sbml_DIR}/../libsbml.*")
	set(SBML_INCLUDEDIR "${sbml_DIR}/../../include/sbml")
endif()

if(WIN32)
		set(GRAPHVIZ_PREFIX "GRAPHVIZ_DIR-NOTFOUND" CACHE PATH "graphviz root directory containing lib, include, etc.")
		set(GRAPHVIZ_INCLUDEDIR ${GRAPHVIZ_PREFIX}/include)
		set(GRAPHVIZ_LIBDIR ${GRAPHVIZ_PREFIX}/lib)
		file(GLOB GRAPHVIZ_LIBS_FIRSTHAND "${GRAPHVIZ_LIBDIR}/*.a")
		file(GLOB GRAPHVIZ_DLLS "${GRAPHVIZ_PREFIX}/bin/*.dll")
		set(GRAPHVIZ_API_CONFIG "${GRAPHVIZ_PREFIX}/bin/config6")
elseif(UNIX)
	if(APPLE)
		set(GRAPHVIZ_PREFIX "GRAPHVIZ_DIR-NOTFOUND" CACHE PATH "graphviz root directory containing lib, include, etc.")
		set(GRAPHVIZ_INCLUDEDIR ${GRAPHVIZ_PREFIX}/include)
		set(GRAPHVIZ_LIBDIR ${GRAPHVIZ_PREFIX}/lib)
		set(GRAPHVIZ_API_CONFIG "${GRAPHVIZ_LIBDIR}/graphviz/config6")
		file(GLOB GRAPHVIZ_LIBS_FIRSTHAND "${GRAPHVIZ_LIBDIR}/libgvc.*" "${GRAPHVIZ_LIBDIR}/libcgraph.*" "${GRAPHVIZ_LIBDIR}/libcdt.*")
		file(GLOB GRAPHVIZ_LIBS "${GRAPHVIZ_LIBDIR}/libxdot.*" "${GRAPHVIZ_LIBDIR}/libpathplan.*")
		file(GLOB GRAPHVIZ_APIS "${GRAPHVIZ_LIBDIR}/graphviz/libgvplugin_neato_layout.*" "${GRAPHVIZ_LIBDIR}/graphviz/libgvplugin_pango.*")
	else()
		set(GRAPHVIZ_INCLUDEDIR /usr/include)
		set(GRAPHVIZ_LIBDIR /usr/lib/x86_64-linux-gnu)
		set(GRAPHVIZ_API_CONFIG "${GRAPHVIZ_LIBDIR}/graphviz/config6a")
		file(GLOB GRAPHVIZ_LIBS_FIRSTHAND "${GRAPHVIZ_LIBDIR}/libgvc.*" "${GRAPHVIZ_LIBDIR}/libcgraph.*" "${GRAPHVIZ_LIBDIR}/libcdt.*" "${GRAPHVIZ_LIBDIR}/libexpat.so*")
		file(GLOB GRAPHVIZ_LIBS "${GRAPHVIZ_LIBDIR}/libxdot.*" "${GRAPHVIZ_LIBDIR}/libpathplan.*")
		file(GLOB GRAPHVIZ_APIS "${GRAPHVIZ_LIBDIR}/graphviz/libgvplugin_neato_layout.*" "${GRAPHVIZ_LIBDIR}/graphviz/libgvplugin_pango.*")
	endif()
	set(GRAPHVIZ_LIBS ${GRAPHVIZ_LIBS} ${GRAPHVIZ_LIBS_FIRSTHAND})
endif()

## whether to build the static version of the library
set(BUILD_STATIC_LIB ON CACHE BOOL "Build the static version of the library")

if(WIN32)
	## on windows Ws2_32.lib is needed to be included for the dll
    	list(APPEND EXTRA_LIBS "Ws2_32.lib")
elseif(UNIX)
	## set use of RPATH for Mac
	if (APPLE)
		set(CMAKE_MACOSX_RPATH true)
		set(CMAKE_BUILD_RPATH "${CMAKE_BINARY_DIR}/src;${CMAKE_BINARY_DIR}/src/dependencies")
		set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_RPATH} "@loader_path;@loader_path/dependencies")
		## set C/C++ compiler flags
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -Wall -Wno-inline -Wno-deprecated")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -fPIC -std=gnu++11 -Wno-deprecated")
	else()
		set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_RPATH} "$ORIGIN;$ORIGIN/dependencies")
		## set C/C++ compiler flags
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -Wall -Wno-inline -Wno-deprecated")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -fPIC -std=gnu++11 -Wl,--disable-new-dtags -Wno-deprecated")
	endif()

	## set RPATH features
	set(CMAKE_SKIP_BUILD_RPATH FALSE)
	set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
	set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
endif()

option(WITH_SWIG "Regenerate the programming language interface code (for Python) using SWIG."  ON)

if(WITH_SWIG)
	find_program(SWIG_EXECUTABLE
			NAMES swig
			PATHS
			c:/swigwin-3.0.10
			c:/swigwin-3.0.9
			c:/swigwin-3.0.8
			c:/swigwin-3.0.7
			c:/swigwin-3.0.6
			c:/swigwin-3.0.5
			c:/swigwin-3.0.4
			c:/swigwin-3.0.3
			c:/swigwin-3.0.2
			c:/swigwin-3.0.1
			c:/swigwin-2.0.12
			c:/swigwin-2.0.11
			c:/swigwin-2.0.10
			c:/swigwin-2.0.9
			c:/swigwin-2.0.8
			c:/swigwin-2.0.7
			c:/swigwin-2.0.6
			c:/swigwin-2.0.5
			c:/swigwin-2.0.4
			c:/swigwin-2.0.3
			c:/swigwin-2.0.2
			c:/swigwin-2.0.1
			c:/swigwin-2.0.0
			/usr/local/bin
			/opt/local/bin
			/usr/bin
			"C:/Program Files (x86)/Swig"
			"C:/Program Files/Swig"
			DOC "The file name of the SWIG executable.")
	find_package(SWIG)
endif(WITH_SWIG)

option(WITH_PYTHON "Generate the Python language interface for libsbmlnetworkeditor." OFF)

add_subdirectory(src)