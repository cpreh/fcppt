# - Try to find the fcppt library
#
# This module defines the following variables
#
#	FCPPT_FOUND       - True when fcppt was found
#	FCPPT_INCLUDE_DIR - The path to the FCPPT header files
#	FCPPT_LIBRARY_DIR - The path to the FCPPT library
#	FCPPT_LIBRARIES   - The fcppt libraries
#
# This modules accepts the following variables
#
#	FCPPT_ROOT - can be set to the path containing the fcppt library files
#               this module will search in the standard include and library directories
#               and ${FCPPT_ROOT}/include for header files
#                   ${FCPPT_ROOT}/lib for the library
#

SET( FCPPT_ROOT CACHE PATH "" )

FIND_PATH( FCPPT_INCLUDE_DIR
	NAMES fcppt/config.h
	HINTS ${FCPPT_ROOT}/include
	)
MARK_AS_ADVANCED( FCPPT_INCLUDE_DIR )

FIND_LIBRARY( FCPPT_LIBRARY
	NAMES fcppt
	HINTS ${FCPPT_ROOT}/lib
	      ${FCPPT_LIBRARY_DIR}
	)
SET( FCPPT_LIBRARIES ${FCPPT_LIBRARY} )
GET_FILENAME_COMPONENT( FCPPT_LIBRARY_DIR ${FCPPT_LIBRARY} PATH )
MARK_AS_ADVANCED( FCPPT_LIBRARY_DIR )

IF ((NOT FCPPT_INCLUDE_DIR) AND (NOT FCPPT_LIBRARIES))
	pkg_check_modules(FCPPT fcppt)

	IF(NOT FCPPT_FOUND)
		FIND_PATH(FCPPT_INCLUDE_DIR NAMES fcppt/config.h)
		MARK_AS_ADVANCED(FCPPT_INCLUDE_DIR)

		FIND_LIBRARY(FCPPT_LIBRARY NAMES fcppt)
		MARK_AS_ADVANCED(FCPPT_LIBRARY)

		SET(FCPPT_LIBRARIES ${FCPPT_LIBRARY})
		GET_FILENAME_COMPONENT( FCPPT_LIBRARY_DIR ${FCPPT_LIBRARY} PATH )
		MARK_AS_ADVANCED( FCPPT_LIBRARY_DIR )
	ENDIF()
ENDIF()

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS( FCPPT
	DEFAULT_MSG
	FCPPT_ROOT
	FCPPT_LIBRARY_DIR
	FCPPT_INCLUDE_DIR
	)
