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

# If FindThreads.cmake thinks we should use -lpthread,
# we are obviously on a pthread supporting system.
# However, the manpages for pthreads say that
# we should use -pthread both as compiler and linker flag.
# So we will check here if that is supported and use that instead.
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

		set(
			FcpptThreads_LIBRARIES
			"-pthread"
		)
	endif()
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
