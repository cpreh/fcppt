# - Try to find the fcppt library
#
# This module defines the following variables
#
#	FCPPT_FOUND        - True when fcppt was found
#	FCPPT_INCLUDE_DIRS - The path to the FCPPT header files
#	FCPPT_LIBRARY_DIRS - The path to the FCPPT library
#	FCPPT_LIBRARIES    - The fcppt libraries
#	FCPPT_DEFINITIONS  - Additional compiler flags required
#
# This modules accepts the following variables
#
#	FCPPT_ROOT - can be set to the path containing the fcppt library files
#		this module will search in the standard include and library directories
#		and ${FCPPT_ROOT}/include for header files
#		${FCPPT_ROOT}/lib for the library
#
#	FCPPT_WANT_DYN_LINK - prefer a dynamic link over a static one when using VC++.
#		This will not be useful for any other system.

IF (NOT FCPPT_ROOT)
	SET( FCPPT_ROOT CACHE PATH "" )
ENDIF ()

FIND_PATH( FCPPT_INCLUDE_DIRS
	NAMES fcppt/version.hpp
	HINTS ${FCPPT_ROOT}/include)

MACRO(FIND_FCPPT_LIBRARY name)
	FIND_LIBRARY(
		FCPPT_LIBRARIES
		NAMES ${name}
		HINTS ${FCPPT_ROOT}/lib
	)
ENDMACRO()

IF(MSVC)
	IF(NOT FCPPT_WANT_DYN_LINK)
		FIND_FCPPT_LIBRARY(fcppt_static)
	ENDIF()

	IF(NOT FCPPT_LIBRARIES)
		FIND_FCPPT_LIBRARY(fcppt)

		SET (FCPPT_DEFINITIONS "/D FCPPT_DYN_LINK")
	ENDIF()
ELSE()
	FIND_FCPPT_LIBRARY(fcppt)
ENDIF()

IF (FCPPT_LIBRARIES)
	GET_FILENAME_COMPONENT( FCPPT_LIBRARY_DIRS ${FCPPT_LIBRARIES} PATH )
ENDIF()

IF ((NOT FCPPT_INCLUDE_DIRS) AND (NOT FCPPT_LIBRARIES))
	INCLUDE (FindPkgConfig)
	pkg_check_modules(FCPPT fcppt)
ENDIF()

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS( FCPPT
	DEFAULT_MSG
	FCPPT_LIBRARIES
	FCPPT_INCLUDE_DIRS)

MARK_AS_ADVANCED(FCPPT_LIBRARIES FCPPT_LIBRARY_DIRS FCPPT_INCLUDE_DIRS)
