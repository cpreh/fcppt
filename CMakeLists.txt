CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET (CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)

PROJECT (fcppt)

IF(${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
	message(FATAL_ERROR "In-source builds are not permitted. Make a separate folder for building:\nmkdir build; cd build; cmake ..\nBefore that, remove the files that cmake just created:\nrm -rf CMakeCache.txt CMakeFiles")
ENDIF()

INCLUDE (CheckIncludeFile)
INCLUDE (CheckCXXCompilerFlag)
INCLUDE (CheckCXXSourceCompiles)
INCLUDE (CheckCXXSourceRuns)
INCLUDE (FindPkgConfig)

SET (CMAKE_VERBOSE_MAKEFILE ON)

IF (MSVC)
	OPTION (ENABLE_NARROW_STRING "Build fcppt with std::string instead of std::wstring" OFF)
ELSE ()
	OPTION (ENABLE_NARROW_STRING "Build fcppt with std::string instead of std::wstring" ON)
ENDIF ()

IF (ENABLE_NARROW_STRING)
       SET (FCPPT_NARROW_STRING true)
ENDIF()

ADD_DEFINITIONS(-D BOOST_FILESYSTEM_NO_DEPRECATED)

IF (CMAKE_COMPILER_IS_GNUCXX)
	#CHECK_CXX_COMPILER_FLAG(
	#	"-std=c++0x"
	#	FCPPT_HAVE_VARIADIC_TEMPLATES
	#)

	IF(UNIX)
		SET (FCPPT_STRING_IS_UTF8 true)
	ENDIF()

	CHECK_CXX_COMPILER_FLAG(
		"-fvisibility=hidden"
		FCPPT_HAVE_GCC_VISIBILITY
	)

	OPTION (ENABLE_DEBUG_WARNINGS "Enable -Wpadded and -Weffc++" OFF)

	ADD_DEFINITIONS ("-pedantic-errors -Wall -Wextra -Wconversion"
	"-Wfloat-equal -Wredundant-decls -Wstrict-null-sentinel -Winit-self"
	"-Woverloaded-virtual -Wnon-virtual-dtor -Wctor-dtor-privacy"
	"-Wsign-promo -Wstrict-aliasing=1 -Wmissing-declarations"
	"-Wold-style-cast")

	IF(ENABLE_DEBUG_WARNINGS)
		SET (CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG}" -Wpadded -Weffc++")
	ENDIF()

	SET (CMAKE_CXX_FLAGS_RELEASE "-O3 -fomit-frame-pointer -DNDEBUG")

	IF (FCPPT_HAVE_GCC_VISIBILITY)
		ADD_DEFINITIONS(-fvisibility=hidden)
	ENDIF ()

	#IF (FCPPT_HAVE_VARIADIC_TEMPLATES)
	#	ADD_DEFINITIONS ("-std=c++0x")
	#ELSE ()
		# C++ 98 has no long long but boost insists on using it anyway
		ADD_DEFINITIONS ("-Wno-long-long -ansi")
	#ENDIF ()

	CHECK_CXX_SOURCE_COMPILES(
		"#include <cxxabi.h>
		 #include <cstdlib>
		int main() { int status; char *name =
		abi::__cxa_demangle(typeid(int).name(),0,0,&status); std::free(name); }"
		FCPPT_HAS_GNU_DEMANGLE
	)
	
	SET (CMAKE_REQUIRED_FLAGS "-Wall -Werror -pedantic")

	CHECK_CXX_SOURCE_COMPILES(
		"
		#define DO_PRAGMA(x) _Pragma(#x)
		#define DO_MESSAGE(x) DO_PRAGMA(message (#x))
		DO_MESSAGE(test)
		int main() {}
		"
		FCPPT_HAVE_GCC_PRAGMA_MESSAGE
	)

	SET (CMAKE_REQUIRED_FLAGS "")
ELSEIF (MSVC)
	ADD_DEFINITIONS ("/W3 /wd4512 /wd4355 /wd4800 /wd4996 /wd4714 /EHa /D_BIND_TO_CURRENT_VCLIBS_VERSION=1")

	ADD_DEFINITIONS (-DUNICODE=1 -D_UNICODE=1)
ENDIF ()

INCLUDE_DIRECTORIES (${CMAKE_SOURCE_DIR}/include)

SET (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
SET (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# Create package file for relocateable package
SET (pkgfile "${CMAKE_BINARY_DIR}/fcppt.pc")
FILE(WRITE ${pkgfile}
	"prefix=${CMAKE_INSTALL_PREFIX}\n"
	"exec_prefix=\${prefix}\n"
	"libdir=\${prefix}/lib\n"
	"includedir=\${prefix}/include\n"
	"\n"
	"Name: fcppt\n"
	"Description: Freundlich's C++ Toolkit\n"
	"Version: 0.1\n"
	"Requires:\n"
	"Libs: -L\${libdir} -lfcppt\n"
	"Cflags: -I\${includedir}/fcppt")
#IF(FCPPT_HAVE_VARIADIC_TEMPLATES)
#	FILE(APPEND ${pkgfile} " -std=c++0x")
#ENDIF()
INSTALL (FILES ${pkgfile} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig)

CHECK_CXX_SOURCE_RUNS(
	"
	#include <unistd.h>
	#include <cstdlib>
	int main()
	{
		return _POSIX_VERSION >= 200100
			? EXIT_SUCCESS
			: EXIT_FAILURE;
	}"
	FCPPT_HAVE_POSIX
)

CHECK_CXX_SOURCE_RUNS(
	"
	#include <unistd.h>
	#include <cstdlib>
	int main()
	{
		return _POSIX_TIMERS > 0
			? EXIT_SUCCESS
			: EXIT_FAILURE;
	}"
	FCPPT_HAVE_CLOCK_GETTIME
)

# NOTE: we can't use this right now because -std=c++0x is broken with proto
#CHECK_CXX_SOURCE_COMPILES(
#	"struct test {
#	   test(test const &) = delete;
#	   test &operator=(test const &) = default;
#	 };
#	 int main()
#	 {}"
#	 FCPPT_HAVE_DEFAULTED_AND_DELETED_FUNCTIONS)

FIND_PACKAGE(
	Boost 1.41.0 COMPONENTS
	filesystem
	system
	thread
)

IF(NOT Boost_FOUND)
	MESSAGE(FATAL_ERROR "Boost not found!")
ENDIF()

CHECK_CXX_SOURCE_COMPILES(
	"#include <boost/cstdint.hpp>
	int main()
	{
	   boost::uint_least64_t test;
	}"
	FCPPT_HAVE_ATLEAST_UINT64
)

CHECK_CXX_SOURCE_RUNS(
	"#include <unistd.h>
	#include <cstdlib>
	int main()
	{
	  return _POSIX_VERSION >= 200100
	         ? EXIT_SUCCESS
	         : EXIT_FAILURE;
	}"
	FCPPT_HAVE_POSIX
)

CONFIGURE_FILE(
	${CMAKE_SOURCE_DIR}/config.h.in
	${CMAKE_SOURCE_DIR}/include/fcppt/config.h
)

ADD_SUBDIRECTORY (src)

OPTION(ENABLE_TEST "Build the tests" OFF)

IF (ENABLE_TEST)
	ADD_SUBDIRECTORY (test)
ENDIF ()

INSTALL (
	DIRECTORY include/
	DESTINATION include/
)
