# - Try to find the fcppt library
#
# This module defines the following variables
#
#	FCPPT_FOUND        - True when fcppt was found
#	FCPPT_INCLUDE_DIRS - The path to the FCPPT header files
#	FCPPT_LIBRARIES    - The fcppt libraries
#	FCPPT_DEFINITIONS  - Additional compiler flags required
#
# This modules accepts the following variables
#
#	FCPPT_WANT_DYN_LINK - prefer a dynamic link over a static one when using VC++.
#		This will not be useful for any other system.

FIND_PATH(
	FCPPT_INCLUDE_DIRS
	NAMES fcppt/version.hpp
)

MACRO(FIND_FCPPT_LIBRARY name)
	FIND_LIBRARY(
		FCPPT_LIBRARIES
		NAMES ${name}
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

IF ((NOT FCPPT_INCLUDE_DIRS) AND (NOT FCPPT_LIBRARIES))
	INCLUDE (FindPkgConfig)
	pkg_check_modules(FCPPT fcppt)
ENDIF()

INCLUDE(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(
	FCPPT
	DEFAULT_MSG
	FCPPT_LIBRARIES
	FCPPT_INCLUDE_DIRS
)

MARK_AS_ADVANCED(FCPPT_LIBRARIES FCPPT_INCLUDE_DIRS)
