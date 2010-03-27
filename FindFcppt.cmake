# - Try to find the fcppt library
#
# This module defines the following variables
#
#	FCPPT_FOUND        - True when fcppt was found
#	FCPPT_INCLUDE_DIRS - The path to the FCPPT header files
#	FCPPT_LIBRARY_DIRS - The path to the FCPPT library
#	FCPPT_LIBRARIES    - The fcppt libraries
#
# This modules accepts the following variables
#
#	FCPPT_ROOT - can be set to the path containing the fcppt library files
#               this module will search in the standard include and library directories
#               and ${FCPPT_ROOT}/include for header files
#                   ${FCPPT_ROOT}/lib for the library
#

IF (NOT FCPPT_ROOT)
	SET( FCPPT_ROOT CACHE PATH "" )
ENDIF ()

#MESSAGE("Root dirs are: ${FCPPT_ROOT}")

FIND_PATH( FCPPT_INCLUDE_DIRS
	NAMES fcppt/config.hpp
	HINTS ${FCPPT_ROOT}/include)

#MESSAGE("Include dirs are: ${FCPPT_INCLUDE_DIRS}")

FIND_LIBRARY( FCPPT_LIBRARIES
	NAMES fcppt
	HINTS ${FCPPT_ROOT}/lib) 

#MESSAGE("Libraries are: ${FCPPT_LIBRARIES}")

IF (FCPPT_LIBRARIES)
		#MESSAGE("Libraries was found: ${FCPPT_LIBRARIES}")
	GET_FILENAME_COMPONENT( FCPPT_LIBRARY_DIRS ${FCPPT_LIBRARIES} PATH )
		#MESSAGE("Library dirs are: ${FCPPT_LIBRARY_DIRS}")
ENDIF()

IF ((NOT FCPPT_INCLUDE_DIRS) AND (NOT FCPPT_LIBRARIES))
		#MESSAGE("This was found, too?")
	pkg_check_modules(FCPPT fcppt)
ENDIF()

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS( FCPPT
	DEFAULT_MSG
	FCPPT_LIBRARIES
	FCPPT_INCLUDE_DIRS)

MARK_AS_ADVANCED(FCPPT_LIBRARIES FCPPT_LIBRARY_DIRS FCPPT_INCLUDE_DIRS)
