# - Try to find the thread library and definitions
#
# This module defines the following variables
#
#	FCPPTTHREADS_FOUND        - True when fcppt was found
#	FcpptThreads_DEFINITIONS  - Additional compiler flags required
#	FcpptThreads_LIBRARIES    - All thread libraries to link to

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

set(
	FcpptThreads_LIBRARIES
	"${CMAKE_THREAD_LIBS_INIT}"
)

# If FindThreads.cmake thinks we should use -lpthread, we are obviously on a
# pthread supporting system. However, the Linux manpages for pthreads say that
# we should use -pthread both as compiler and linker flag. So we check if
# that's supported and add it to the definitions.
if(
	"${CMAKE_THREAD_LIBS_INIT}" STREQUAL "-lpthread"
)
	include(
		CheckCXXCompilerFlag
	)

	# Hopefully we have something that understands these flags.
	set(
		CMAKE_REQUIRED_FLAGS "-Wall -Werror -pedantic"
	)

	check_cxx_compiler_flag(
		"-pthread"
		FCPPTTHREADS_HAVE_PTHREAD_COMPILER_FLAG
	)

	set(
		CMAKE_REQUIRED_FLAGS
		"${CMAKE_REQUIRED_FLAGS} -pthread"
	)

	check_cxx_compiler_flag(
		""
		FCPPTTHREADS_HAVE_PTHREAD_LINKER_FLAG
	)

	unset(
		CMAKE_REQUIRED_FLAGS
	)

	if(
		FCPPTTHREADS_HAVE_PTHREAD_COMPILER_FLAG
		AND
		FCPPTTHREADS_HAVE_PTHREAD_LINKER_FLAG
	)
		set(
			FcpptThreads_DEFINITIONS
			"-pthread"
		)
	endif()
endif()

include(
	FindPackageHandleStandardArgs
)

find_package_handle_standard_args(
	FcpptThreads
	DEFAULT_MSG
	FcpptThreads_LIBRARIES
)
