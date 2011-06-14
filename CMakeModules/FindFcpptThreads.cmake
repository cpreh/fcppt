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

find_package(
	Threads
	${FcpptThreads_FIND_REQUIRED}
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
