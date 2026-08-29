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

## find dependency libraries
set(DEPENDENCIES_INSTALL_PREFIX "" CACHE PATH "Path to the libsbml, libexpat, and libz installation directory")
set(LIBSBML_INSTALL_PREFIX "" CACHE PATH "Path to the libsbml installation directory")
set(EXPAT_INSTALL_PREFIX "" CACHE PATH "Path to the expat installation directory")
if(WIN32)
	find_library(LIBSBML_LIBRARY NAMES libsbml-staticmd.lib libsbml-staticmdd.lib PATHS ${LIBSBML_INSTALL_PREFIX}/lib ${DEPENDENCIES_INSTALL_PREFIX}/lib REQUIRED)
	if (NOT TARGET EXPAT::EXPAT)
		find_library(EXPAT_LIBRARY NAMES libexpatMD.lib libexpatdMD.lib PATHS ${EXPAT_INSTALL_PREFIX}/lib ${DEPENDENCIES_INSTALL_PREFIX}/lib REQUIRED)
	else ()
		find_package(EXPAT REQUIRED)
		set(EXPAT_LIBRARY EXPAT::EXPAT)
	endif ()
	find_library(LIBZ_LIBRARY NAMES zlibstatic.lib zlibstaticd.lib zs.lib zsd.lib PATHS ${DEPENDENCIES_INSTALL_PREFIX}/lib REQUIRED)
elseif (APPLE)
	find_library(LIBSBML_LIBRARY NAMES libsbml-static.a libsbml-staticd.a PATHS ${LIBSBML_INSTALL_PREFIX}/lib ${DEPENDENCIES_INSTALL_PREFIX}/lib REQUIRED)
	find_library(EXPAT_LIBRARY NAMES libexpat.a expat PATHS ${EXPAT_INSTALL_PREFIX}/lib ${DEPENDENCIES_INSTALL_PREFIX}/lib REQUIRED)
	find_library(LIBZ_LIBRARY NAMES libz.a PATHS ${DEPENDENCIES_INSTALL_PREFIX}/lib REQUIRED)
elseif(UNIX)
	find_library(LIBSBML_LIBRARY NAMES libsbml-static.a libsbml-staticd.a
			PATHS ${LIBSBML_INSTALL_PREFIX}/lib ${DEPENDENCIES_INSTALL_PREFIX}/lib ${LIBSBML_INSTALL_PREFIX}/lib64 ${DEPENDENCIES_INSTALL_PREFIX}/lib64 REQUIRED)
	find_library(EXPAT_LIBRARY NAMES libexpat.a expat
			PATHS ${EXPAT_INSTALL_PREFIX}/lib ${DEPENDENCIES_INSTALL_PREFIX}/lib ${EXPAT_INSTALL_PREFIX}/lib64 ${DEPENDENCIES_INSTALL_PREFIX}/lib64 REQUIRED)
	find_library(LIBZ_LIBRARY NAMES libz.so
			PATHS ${DEPENDENCIES_INSTALL_PREFIX}/lib ${DEPENDENCIES_INSTALL_PREFIX}/lib64)
endif()

## set dependencies include directory if it is not set by a parent project
if (NOT DEFINED DEPENDENCIES_INCLUDE_DIR)
	set(DEPENDENCIES_INCLUDE_DIR ${LIBSBML_INSTALL_PREFIX}/include ${EXPAT_INSTALL_PREFIX}/include ${DEPENDENCIES_INSTALL_PREFIX}/include)
endif ()

## Find ZLIB
option(WITH_ZLIB "Link libsbmlnetwork against zlib." ON)
set(LIBZ_LIBRARY "")
if (WITH_ZLIB)
	find_package(ZLIB CONFIG REQUIRED)
	set(LIBZ_LIBRARY ZLIB::ZLIBSTATIC)
	get_target_property(LIBZ_LIBRARY_LOCATION ZLIB::ZLIBSTATIC LOCATION)
	message(STATUS "ZLIB Library: ${LIBZ_LIBRARY_LOCATION}")
	set(ZLIB_LIBRARY "${LIBZ_LIBRARY_LOCATION}" CACHE FILEPATH "Path to zlib library" FORCE)
	set(ZLIB_INCLUDE_DIR "${DEPENDENCIES_INSTALL_PREFIX}/include" CACHE PATH "Path to zlib include directory" FORCE)
	set(ZLIB_FOUND TRUE CACHE BOOL "ZLIB found" FORCE)
endif ()

## Find expat
if (DEFINED EXPAT_LIBRARY AND DEFINED EXPAT_INCLUDE_DIR)
	message(STATUS "Expat Library: ${EXPAT_LIBRARY}")
	message(STATUS "Expat Include: ${EXPAT_INCLUDE_DIR}")
else ()
	find_package(expat CONFIG REQUIRED)
	set(EXPAT_LIBRARY expat::expat)
	get_target_property(EXPAT_LIBRARY_LOCATION expat::expat LOCATION)
	get_target_property(EXPAT_INCLUDE_DIR expat::expat INTERFACE_INCLUDE_DIRECTORIES)
	message(STATUS "Expat Library: ${EXPAT_LIBRARY_LOCATION}")
	message(STATUS "Expat Include: ${EXPAT_INCLUDE_DIR}")
endif ()

## Find libSBML
if (DEFINED LIBSBML_LIBRARY)
	message(STATUS "libSBML Library: ${LIBSBML_LIBRARY}")
else ()
	find_package(${SBML_TARGET_NAME} CONFIG REQUIRED)
	set(LIBSBML_LIBRARY ${SBML_TARGET_NAME})
	message(STATUS "libSBML Target: ${LIBSBML_LIBRARY}")
endif ()

## Set dependencies include directory
set(DEPENDENCIES_INCLUDE_DIR "${DEPENDENCIES_INSTALL_PREFIX}/include" "${LIBSBML_INSTALL_PREFIX}/include" "${EXPAT_INCLUDE_DIR}")

## whether to build the dynamic version of the library
set(BUILD_SHARED_LIBS ON CACHE BOOL "Build the dynamic version of the library")

## whether to build the static version of the library
set(BUILD_STATIC_LIBS ON CACHE BOOL "Build the static version of the library")

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

option(WITH_PYTHON "Generate the Python language interface for libsbmlnetwork." OFF)
cmake_dependent_option(WITH_SWIG "Regenerate the programming language interface code (for Python) using SWIG." OFF "${WITH_PYTHON}" OFF)

if (${BUILD_SHARED_LIBS} OR ${BUILD_STATIC_LIBS})
	add_subdirectory(src)
else()
	message(FATAL_ERROR "No library type selected. Please select either BUILD_SHARED_LIBS or BUILD_STATIC_LIBS")
endif()