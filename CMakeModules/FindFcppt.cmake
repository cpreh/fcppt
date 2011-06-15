# - Try to find the fcppt library
#
# This module defines the following variables
#
#	FCPPT_FOUND        - True when fcppt was found
#	Fcppt_INCLUDE_DIRS - All includes required for fcppt to work
#	Fcppt_LIBRARIES    - All libraries required for fcppt to work
#	Fcppt_DEFINITIONS  - Additional compiler flags required
#
# This modules accepts the following variables
#
#	Fcppt_WANT_DYN_LINK - Use dynamic linking with VC++.
#	                      This will not be useful for any other system.
#	FCPPT_INCLUDEDIR    - Hint where the fcppt includes might be.
#	FCPPT_LIBRARYDIR    - Hint where the fcppt libraries might be.

include(
	FindPkgConfig
)

pkg_check_modules(
	PC_FCPPT
	QUIET
	fcppt
)

if(
	Fcppt_FIND_QUIETLY
)
	set(
		FCPPT_FIND_OPTIONS
		"QUIET"
	)
endif()

if(
	Fcppt_FIND_REQUIRED
)
	set(
		FCPPT_FIND_OPTIONS
		"REQUIRED"
	)
endif()

set(
	Fcppt_DEFINITIONS
	${PC_FCPPT_CFLAGS}
)

find_package(
	Boost
	1.44.0
	${FCPPT_FIND_OPTIONS}
	COMPONENTS
	filesystem thread system
)

unset(
	FCPPT_FIND_OPTIONS
)

find_package(
	FcpptThreads
)

find_path(
	Fcppt_INCLUDE_DIR
	NAMES fcppt/version.hpp
	HINTS ${FCPPT_INCLUDEDIR} ${PC_FCPPT_INCLUDE_DIRS}
)

macro(
	FIND_FCPPT_LIBRARY name
)
	find_library(
		Fcppt_LIBRARY
		NAMES ${name}
		HINTS ${FCPPT_LIBRARYDIR} ${PC_FCPPT_LIBRARY_DIRS}
	)
endmacro()

if(
	MSVC
)
	if(
		Fcppt_WANT_DYN_LINK
	)
		FIND_FCPPT_LIBRARY(
			fcppt
		)

		set(
			Fcppt_DEFINITIONS
			"${Fcppt_DEFINITIONS} /D FCPPT_DYN_LINK"
		)
	else()
		FIND_FCPPT_LIBRARY(
			fcppt_static
		)
	endif()
else()
	FIND_FCPPT_LIBRARY(
		fcppt
	)
endif()

set(
	Fcppt_DEFINITIONS
	"${Fcppt_DEFINITIONS} ${FcpptThreads_DEFINITIONS}"
)

set(
	Fcppt_LIBRARIES
	"${Boost_LIBRARIES};${Fcppt_LIBRARY};${FcpptThreads_LIBRARIES}"
)

set(
	Fcppt_INCLUDE_DIRS
	"${Boost_INCLUDE_DIRS};${Fcppt_INCLUDE_DIR}"
)

include(
	FindPackageHandleStandardArgs
)

find_package_handle_standard_args(
	Fcppt
	DEFAULT_MSG
	Fcppt_LIBRARY
	Fcppt_INCLUDE_DIR
)

mark_as_advanced(
	Fcppt_LIBRARY
	Fcppt_INCLUDE_DIR
)
