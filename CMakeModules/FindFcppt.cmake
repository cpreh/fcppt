# - Try to find the fcppt library
#
# This module defines the following general variables
#
#	FCPPT_FOUND                - True when fcppt was found
#	Fcppt_INCLUDE_DIRS         - All includes required for fcppt to work
#	Fcppt_DEFINITIONS          - Additional compiler flags required
#	Fcppt_core_LIBRARIES       - All libraries required for fcppt_core to work
#	Fcppt_filesystem_LIBRARIES - All libraries required for fcppt_filesystem to work
#	Fcppt_thread_LIBRARIES     - All libraries required for fcppt_thread to work
#
# This modules accepts the following variables
#
#	Fcppt_USE_STATIC_LIBS  - Use static linking.
#	FCPPT_INCLUDEDIR       - Hint where the fcppt includes might be.
#	FCPPT_LIBRARYDIR       - Hint where the fcppt libraries might be.

include(
	FindPkgConfig
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

find_path(
	Fcppt_INCLUDE_DIR
	NAMES fcppt/version.hpp
	HINTS ${FCPPT_INCLUDEDIR}
)

macro(
	find_fcppt_library
	LIBNAME
)
	find_library(
		Fcppt_${LIBNAME}_LIBRARY
		NAMES fcppt_${LIBNAME}
		HINTS ${FCPPT_LIBRARYDIR}
	)
endmacro()

set(
	FCPPT_COMPONENTS
	"core;filesystem;thread"
)

foreach(
	COMPONENT
	${FCPPT_COMPONENTS}
)
	if(
		Fcppt_USE_STATIC_LIBS
	)
		find_fcppt_library(
			${COMPONENT}_static
		)
	else()
		find_fcppt_library(
			${COMPONENT}
		)

	endif()
endforeach()

unset(
	FCPPT_COMPONENTS
)

if(
	Fcppt_USE_STATIC_LIBS
)
	set(
		Fcppt_DEFINITIONS
		"-D FCPPT_STATIC_LINK"
	)
endif()

set(
	Fcppt_core_LIBRARIES
	"${Fcppt_core_LIBRARY}"
)

set(
	Fcppt_filesystem_LIBRARIES
	"${Boost_FILESYSTEM_LIBRARY};${Boost_SYSTEM_LIBRARY};${Fcppt_core_LIBRARIES};${Fcppt_filesystem_LIBRARY}"
)

set(
	Fcppt_thread_LIBRARIES
	"${Boost_THREAD_LIBRARY};${FcpptThreads_LIBRARIES};${Fcppt_thread_LIBRARY}"
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
	Fcppt_core_LIBRARY
	Fcppt_filesystem_LIBRARY
	Fcppt_thread_LIBRARY
	Fcppt_INCLUDE_DIR
)

mark_as_advanced(
	Fcppt_core_LIBRARY
	Fcppt_filesystem_LIBRARY
	Fcppt_thread_LIBRARY
	Fcppt_INCLUDE_DIR
)
