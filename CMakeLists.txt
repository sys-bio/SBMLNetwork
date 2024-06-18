cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(libsbmlnetwork)
add_definitions(-DLIBSBMLNETWORK_EXPORTS=true)

include(GNUInstallDirs)
include(CMakeDependentOption)

## Determine the version
set(LIBSBMLNETWORK_VERSION_MAJOR)
set(LIBSBMLNETWORK_VERSION_MINOR)
set(LIBSBMLNETWORK_VERSION_PATCH)
set(LIBSBMLNETWORK_DOTTED_VERSION)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/VERSION.txt")
	file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/VERSION.txt" VersionString NEWLINE_CONSUME)
	string(STRIP "${VersionString}" VersionString)
	set(LIBSBMLNETWORK_DOTTED_VERSION ${VersionString})
	string(REPLACE "." ";" VersionString "${VersionString}" )
	string(REPLACE "-" ";" VersionString "${VersionString}" )
	list(LENGTH VersionString versionLength)
	list(GET VersionString 0 LIBSBMLNETWORK_VERSION_MAJOR)
	list(GET VersionString 1 LIBSBMLNETWORK_VERSION_MINOR)
	list(GET VersionString 2 LIBSBMLNETWORK_VERSION_PATCH)
endif()

add_definitions(-DLIBSBMLNETWORK_VERSION="${LIBSBMLNETWORK_DOTTED_VERSION}")

## find dependencies
set(DEPENDENCIES_INSTALL_PREFIX "" CACHE PATH "Path to the libsbml, libexpat, and libz installation directory")
if(WIN32)
	find_library(LIBSBML_LIBRARY NAMES libsbml-staticmd.lib libsbml-staticmdd.lib PATHS ${DEPENDENCIES_INSTALL_PREFIX}/lib REQUIRED)
	if(NOT TARGET EXPAT::EXPAT)
		find_package(EXPAT REQUIRED)
	endif()
	# find_library(LIBEXPAT_LIBRARY NAMES libexpatMD.lib libexpatdMD.lib PATHS ${DEPENDENCIES_INSTALL_PREFIX}/lib REQUIRED)
	find_library(LIBZ_LIBRARY NAMES zlibstatic.lib zlibstaticd.lib PATHS ${DEPENDENCIES_INSTALL_PREFIX}/lib REQUIRED)
elseif (APPLE)
	find_library(LIBSBML_LIBRARY NAMES libsbml-static.a libsbml-staticd.a PATHS ${DEPENDENCIES_INSTALL_PREFIX}/lib REQUIRED)
	if(NOT TARGET EXPAT::EXPAT)
		find_library(LIBEXPAT_LIBRARY NAMES libexpat.a PATHS ${DEPENDENCIES_INSTALL_PREFIX}/lib REQUIRED)
	endif()
	find_library(LIBZ_LIBRARY NAMES libz.a PATHS ${DEPENDENCIES_INSTALL_PREFIX}/lib REQUIRED)
elseif(UNIX)
	find_library(LIBSBML_LIBRARY NAMES libsbml-static.a libsbml-staticd.a
			PATHS ${DEPENDENCIES_INSTALL_PREFIX}/lib ${DEPENDENCIES_INSTALL_PREFIX}/lib64 REQUIRED)
	if(NOT TARGET EXPAT::EXPAT)
		find_library(LIBEXPAT_LIBRARY NAMES libexpat.a
				PATHS ${DEPENDENCIES_INSTALL_PREFIX}/lib ${DEPENDENCIES_INSTALL_PREFIX}/lib64 REQUIRED)
	endif()
	find_library(LIBZ_LIBRARY NAMES libz.so
			PATHS ${DEPENDENCIES_INSTALL_PREFIX}/lib ${DEPENDENCIES_INSTALL_PREFIX}/lib64 REQUIRED)
endif()
set(DEPENDENCIES_INCLUDE_DIR ${DEPENDENCIES_INSTALL_PREFIX}/include)

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

## gather resources
file(GLOB_RECURSE RESOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/resources/*")

option(WITH_PYTHON "Generate the Python language interface for libsbmlnetwork." OFF)
cmake_dependent_option(WITH_SWIG "Regenerate the programming language interface code (for Python) using SWIG." OFF "${WITH_PYTHON}" OFF)

add_subdirectory(src)