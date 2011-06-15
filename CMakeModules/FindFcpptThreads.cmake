# - Try to find the thread library and definitions
#
# This module defines the following variables
#
#	FCPPTTHREADS_FOUND        - True when fcppt was found
#	FcpptThreads_DEFINITIONS  - Additional compiler flags required
#	FcpptThreads_LIBRARIES    - All thread libraries to link to

include(
	FindPkgConfig
)

# No extra libraries needed for windows
if(
	WIN32
)
	return()
endif()

if(
	FcpptThreads_FIND_QUIETLY
)
	set(
		FCPPTTHREADS_FIND_OPTIONS
		"QUIET"
	)
endif()

if(
	FcpptThreads_FIND_REQUIRED
)
	set(
		FCPPTTHREADS_FIND_OPTIONS
		"REQUIRED"
	)
endif()

find_package(
	Threads
	${FCPPTTHREADS_FIND_OPTIONS}
)

unset(
	FCPPTTHREADS_FIND_OPTIONS
)

if(
	"${CMAKE_THREAD_LIBS_INIT}" STREQUAL "-lpthread"
)
	set(
		FcpptThreads_DEFINITIONS
		"-pthread"
	)

	set(
		FcpptThreads_LIBRARIES
		"-pthread"
	)
else()
	set(
		FcpptThreads_LIBRARIES
		"${CMAKE_THREAD_LIBS_INIT}"
	)
endif()

include(
	FindPackageHandleStandardArgs
)

find_package_handle_standard_args(
	FcpptThreads
	DEFAULT_MSG
	FcpptThreads_LIBRARIES
)
