CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET (CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)

SET (CMAKE_USER_MAKE_RULES_OVERRIDE_CXX ${CMAKE_CURRENT_SOURCE_DIR}/cxx_flag_overrides.cmake)

SET (CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules)

PROJECT (fcppt)

SET (FCPPT_MAJOR_VERSION 0)
SET (FCPPT_MINOR_VERSION 2)
SET (FCPPT_MICRO_VERSION 0)
SET (FCPPT_VERSION "${FCPPT_MAJOR_VERSION}.${FCPPT_MINOR_VERSION}.${FCPPT_MICRO_VERSION}")
SET (FCPPT_INT_VERSION 2000) # TODO generate this automatically! (see version.hpp.in)
SET (FCPPT_SHARED_VERSION ${FCPPT_VERSION})

IF(${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
	message(FATAL_ERROR "In-source builds are not permitted. Make a separate folder for building:\nmkdir build; cd build; cmake ..\nBefore that, remove the files that cmake just created:\nrm -rf CMakeCache.txt CMakeFiles")
ENDIF()

INCLUDE (CheckCXXCompilerFlag)
INCLUDE (CheckCXXSourceCompiles)
INCLUDE (CheckCXXSourceRuns)
INCLUDE (CheckIncludeFile)
INCLUDE (FindPkgConfig)

IF (MSVC)
	SET (ENABLE_NARROW_STRING_DEFAULT OFF)
	SET (ENABLE_SHARED_DEFAULT OFF)
	SET (ENABLE_STATIC_DEFAULT ON)
ELSE ()
	SET (ENABLE_NARROW_STRING_DEFAULT ON)
	SET (ENABLE_SHARED_DEFAULT ON)
	SET (ENABLE_STATIC_DEFAULT OFF)
ENDIF ()

OPTION(ENABLE_SHARED "Build fcppt as a shared library" ${ENABLE_SHARED_DEFAULT})

OPTION(ENABLE_STATIC "Build fcppt as a static library" ${ENABLE_STATIC_DEFAULT})

OPTION(ENABLE_NARROW_STRING "Build fcppt with std::string instead of std::wstring" ${ENABLE_NARROW_STRING_DEFAULT})

IF(NOT ENABLE_SHARED AND NOT ENABLE_STATIC)
	MESSAGE(FATAL_ERROR "You disabled both STATIC and SHARED")
ENDIF()

# choose a library to link the tests to
IF(ENABLE_SHARED)
	SET(FCPPT_DEFAULT_LINK_TARGET fcppt)
ENDIF()

# static overrides shared
IF(ENABLE_STATIC)
	SET(FCPPT_DEFAULT_LINK_TARGET fcppt_static)
ENDIF()

IF(MSVC AND ${FCPPT_DEFAULT_LINK_TARGET} STREQUAL "fcppt")
	SET (FCPPT_CONFIG_LINK_MACROS "-D FCPPT_DYN_LINK")
ENDIF()

IF (ENABLE_NARROW_STRING)
       SET (FCPPT_NARROW_STRING true)
ENDIF()

ADD_DEFINITIONS(-D BOOST_FILESYSTEM_NO_DEPRECATED)

IF (CMAKE_COMPILER_IS_GNUCXX)
	IF(UNIX)
		SET (FCPPT_STRING_IS_UTF8 true)
	ENDIF()

	CHECK_CXX_COMPILER_FLAG(
		"-fvisibility=hidden"
		FCPPT_HAVE_GCC_VISIBILITY
	)

	OPTION (ENABLE_DEBUG_WARNINGS "Enable -Wpadded and -Weffc++" OFF)

	ADD_DEFINITIONS (
		"-pedantic-errors -Wall -Wextra -Wconversion"
		"-Wfloat-equal -Wredundant-decls -Wstrict-null-sentinel -Winit-self"
		"-Woverloaded-virtual -Wnon-virtual-dtor"
		"-Wsign-promo -Wstrict-aliasing=1 -Wold-style-cast"
	)

	IF(ENABLE_DEBUG_WARNINGS)
		SET (CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG}" -Wpadded -Weffc++")
	ENDIF()

	SET (CMAKE_CXX_FLAGS_RELEASE "-O3 -fomit-frame-pointer -DNDEBUG")

	IF (FCPPT_HAVE_GCC_VISIBILITY)
		ADD_DEFINITIONS(-fvisibility=hidden)
	ENDIF ()

	# C++ 98 has no long long but boost insists on using it anyway
	ADD_DEFINITIONS ("-Wno-long-long")

	IF(NOT APPLE)
		# -ansi breaks tr1 on darwin
		ADD_DEFINITIONS ("-ansi")
	ENDIF()

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

	CHECK_CXX_COMPILER_FLAG("-Wmissing-declarations" FCPPT_HAVE_MISSING_DECLARATIONS_FLAG)

	IF(FCPPT_HAVE_MISSING_DECLARATIONS_FLAG)
		ADD_DEFINITIONS ("-Wmissing-declarations")
	ENDIF()

	SET (CMAKE_REQUIRED_FLAGS "")
ELSEIF (MSVC)
	ADD_DEFINITIONS ("/W4 /wd4996 /EHa /D_BIND_TO_CURRENT_VCLIBS_VERSION=1")
	#4996 - unsafe standard C++ functions

	IF (NOT ENABLE_NARROW_STRING)
		ADD_DEFINITIONS (/D UNICODE /D _UNICODE)
	ENDIF()
ENDIF ()

INCLUDE_DIRECTORIES (${CMAKE_SOURCE_DIR}/include)

SET (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
SET (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

SET (pkgfile "${CMAKE_BINARY_DIR}/fcppt.pc")

FILE(WRITE ${pkgfile}
	"prefix=${CMAKE_INSTALL_PREFIX}\n"
	"exec_prefix=\${prefix}\n"
	"libdir=\${prefix}/lib\n"
	"includedir=\${prefix}/include\n"
	"\n"
	"Name: fcppt\n"
	"Description: Freundlich's C++ Toolkit\n"
	"Version: ${FCPPT_VERSION}\n"
	"Requires:\n"
	"Libs: -L\${libdir} -lfcppt\n"
	"Cflags: -I\${includedir}/"
)

INSTALL (FILES ${pkgfile} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig)

# NOTE: we can't use this right now because -std=c++0x is broken with proto
#CHECK_CXX_SOURCE_COMPILES(
#	"struct test {
#	   test(test const &) = delete;
#	   test &operator=(test const &) = default;
#	 };
#	 int main()
#	 {}"
#	 FCPPT_HAVE_DEFAULTED_AND_DELETED_FUNCTIONS)

SET (Boost_ADDITIONAL_VERSIONS "1.41" "1.41.0" "1.42" "1.42.0" "1.43" "1.43.0" "1.44" "1.44.0")

IF(MSVC)
	SET(Boost_USE_STATIC_LIBS ON)
ENDIF()

FIND_PACKAGE(
	Boost 1.40.0 REQUIRED COMPONENTS
	filesystem
	system
	thread
)

INCLUDE_DIRECTORIES(SYSTEM ${Boost_INCLUDE_DIR})

LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

SET (CMAKE_REQUIRED_INCLUDES ${CMAKE_SOURCE_DIR}/include ${Boost_INCLUDE_DIR})

CHECK_CXX_SOURCE_COMPILES(
	"#include <boost/cstdint.hpp>
	int main()
	{
	   boost::uint_least64_t test;
	}"
	FCPPT_HAVE_ATLEAST_UINT64
)

CHECK_CXX_SOURCE_COMPILES(
	"int main()
	{
		long long test = 1LL;
	}"
	FCPPT_HAVE_LONG_LONG
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

CHECK_CXX_SOURCE_COMPILES(
	"#include <fcppt/alignment/align.hpp>
	#include <cstddef>
	template<
		std::size_t N
	>
	struct test
	{
		char FCPPT_ALIGNMENT_ALIGN(N) testmember;
	};

	int main()
	{
		test<8> tmp;
	}
	"
	FCPPT_ALIGN_TEMPLATE_PARAMETER
)

CHECK_INCLUDE_FILE(
	mach/mach_time.h
	FCPPT_HAVE_MACH_TIME
)

SET(CMAKE_REQUIRED_LIBRARIES rt)

CHECK_CXX_SOURCE_COMPILES(
	"#include <time.h>
	int main()
	{
		int (*tmp)(clockid_t, struct timespec *) = clock_gettime;
	}"
	FCPPT_HAVE_CLOCK_GETTIME
)

SET(CMAKE_REQUIRED_LIBRARIES)

CONFIGURE_FILE(
	${CMAKE_SOURCE_DIR}/config.hpp.in
	${CMAKE_SOURCE_DIR}/include/fcppt/config.hpp
)

CONFIGURE_FILE(
	${CMAKE_SOURCE_DIR}/version.hpp.in
	${CMAKE_SOURCE_DIR}/include/fcppt/version.hpp
)

MACRO(ADD_FCPPT_SOURCE_GROUP GROUPPATH PATTERN)
	FILE(GLOB GROUPFILES ${GROUPPATH}/${PATTERN})

	STRING(REPLACE "/" "\\" GROUPFOLDER ${GROUPPATH})

	SOURCE_GROUP(${GROUPFOLDER} FILES ${GROUPFILES})

	SET(FCPPTFILES ${FCPPTFILES} ${GROUPFILES})
ENDMACRO()

MACRO(ADD_FCPPT_HEADER_GROUP GROUPPATH)
	ADD_FCPPT_SOURCE_GROUP(${GROUPPATH} "*.?pp")
ENDMACRO()

ADD_FCPPT_HEADER_GROUP(include)
ADD_FCPPT_HEADER_GROUP(include/fcppt)
ADD_FCPPT_HEADER_GROUP(include/fcppt/algorithm)
ADD_FCPPT_HEADER_GROUP(include/fcppt/algorithm/impl)
ADD_FCPPT_HEADER_GROUP(include/fcppt/alignment)
ADD_FCPPT_HEADER_GROUP(include/fcppt/alignment/detail)
ADD_FCPPT_HEADER_GROUP(include/fcppt/assign)
ADD_FCPPT_HEADER_GROUP(include/fcppt/assign/detail)
ADD_FCPPT_HEADER_GROUP(include/fcppt/chrono)
ADD_FCPPT_HEADER_GROUP(include/fcppt/chrono/convert)
ADD_FCPPT_HEADER_GROUP(include/fcppt/chrono/detail)
ADD_FCPPT_HEADER_GROUP(include/fcppt/chrono/impl)
ADD_FCPPT_HEADER_GROUP(include/fcppt/container)
ADD_FCPPT_HEADER_GROUP(include/fcppt/container/bitfield)
ADD_FCPPT_HEADER_GROUP(include/fcppt/container/bitfield/detail)
ADD_FCPPT_HEADER_GROUP(include/fcppt/container/impl)
ADD_FCPPT_HEADER_GROUP(include/fcppt/container/tree)
ADD_FCPPT_HEADER_GROUP(include/fcppt/detail)
ADD_FCPPT_HEADER_GROUP(include/fcppt/endianness)
ADD_FCPPT_HEADER_GROUP(include/fcppt/error)
ADD_FCPPT_HEADER_GROUP(include/fcppt/filesystem)
ADD_FCPPT_HEADER_GROUP(include/fcppt/filesystem/detail)
ADD_FCPPT_HEADER_GROUP(include/fcppt/filesystem/impl)
ADD_FCPPT_HEADER_GROUP(include/fcppt/function)
ADD_FCPPT_HEADER_GROUP(include/fcppt/function/detail)
ADD_FCPPT_HEADER_GROUP(include/fcppt/impl)
ADD_FCPPT_HEADER_GROUP(include/fcppt/io)
ADD_FCPPT_HEADER_GROUP(include/fcppt/log)
ADD_FCPPT_HEADER_GROUP(include/fcppt/log/detail)
ADD_FCPPT_HEADER_GROUP(include/fcppt/log/format)
ADD_FCPPT_HEADER_GROUP(include/fcppt/log/impl)
ADD_FCPPT_HEADER_GROUP(include/fcppt/log/parameters)
ADD_FCPPT_HEADER_GROUP(include/fcppt/math)
ADD_FCPPT_HEADER_GROUP(include/fcppt/math/box)
ADD_FCPPT_HEADER_GROUP(include/fcppt/math/detail)
ADD_FCPPT_HEADER_GROUP(include/fcppt/math/dim)
ADD_FCPPT_HEADER_GROUP(include/fcppt/math/impl)
ADD_FCPPT_HEADER_GROUP(include/fcppt/math/matrix)
ADD_FCPPT_HEADER_GROUP(include/fcppt/math/matrix/detail)
ADD_FCPPT_HEADER_GROUP(include/fcppt/math/quaternion)
ADD_FCPPT_HEADER_GROUP(include/fcppt/math/sphere)
ADD_FCPPT_HEADER_GROUP(include/fcppt/math/vector)
ADD_FCPPT_HEADER_GROUP(include/fcppt/mpl)
ADD_FCPPT_HEADER_GROUP(include/fcppt/mpl/detail)
ADD_FCPPT_HEADER_GROUP(include/fcppt/mpl/impl)
ADD_FCPPT_HEADER_GROUP(include/fcppt/preprocessor)
ADD_FCPPT_HEADER_GROUP(include/fcppt/preprocessor/detail)
ADD_FCPPT_HEADER_GROUP(include/fcppt/random)
ADD_FCPPT_HEADER_GROUP(include/fcppt/random/actor)
ADD_FCPPT_HEADER_GROUP(include/fcppt/random/detail)
ADD_FCPPT_HEADER_GROUP(include/fcppt/random/impl)
ADD_FCPPT_HEADER_GROUP(include/fcppt/ratio)
ADD_FCPPT_HEADER_GROUP(include/fcppt/ratio/detail)
ADD_FCPPT_HEADER_GROUP(include/fcppt/signal)
ADD_FCPPT_HEADER_GROUP(include/fcppt/signal/detail)
ADD_FCPPT_HEADER_GROUP(include/fcppt/thread)
ADD_FCPPT_HEADER_GROUP(include/fcppt/thread/detail)
ADD_FCPPT_HEADER_GROUP(include/fcppt/thread/impl)
ADD_FCPPT_HEADER_GROUP(include/fcppt/time)
ADD_FCPPT_HEADER_GROUP(include/fcppt/time/detail)
ADD_FCPPT_HEADER_GROUP(include/fcppt/time/impl)
ADD_FCPPT_HEADER_GROUP(include/fcppt/tr1)
ADD_FCPPT_HEADER_GROUP(include/fcppt/tr1/detail)
ADD_FCPPT_HEADER_GROUP(include/fcppt/type_traits)
ADD_FCPPT_HEADER_GROUP(include/fcppt/utf8)
ADD_FCPPT_HEADER_GROUP(include/fcppt/variant)
ADD_FCPPT_HEADER_GROUP(include/fcppt/variant/detail)
ADD_FCPPT_HEADER_GROUP(include/fcppt/variant/impl)

MACRO(ADD_FCPPT_CPP_GROUP GROUPPATH)
	ADD_FCPPT_SOURCE_GROUP(${GROUPPATH} "*.?pp")
ENDMACRO()

ADD_FCPPT_CPP_GROUP(src)
ADD_FCPPT_CPP_GROUP(src/chrono)
ADD_FCPPT_CPP_GROUP(src/endianness)
ADD_FCPPT_CPP_GROUP(src/error)
ADD_FCPPT_CPP_GROUP(src/filesystem)
ADD_FCPPT_CPP_GROUP(src/io)
ADD_FCPPT_CPP_GROUP(src/log)
ADD_FCPPT_CPP_GROUP(src/log/detail)
ADD_FCPPT_CPP_GROUP(src/log/format)
ADD_FCPPT_CPP_GROUP(src/log/parameters)
ADD_FCPPT_CPP_GROUP(src/random)
ADD_FCPPT_CPP_GROUP(src/random/actor)
ADD_FCPPT_CPP_GROUP(src/signal)
ADD_FCPPT_CPP_GROUP(src/signal/detail)
ADD_FCPPT_CPP_GROUP(src/thread)
ADD_FCPPT_CPP_GROUP(src/time)
ADD_FCPPT_CPP_GROUP(src/utf8)

MACRO(MAKE_FCPPT_LIBRARY TARGETNAME VARIANT)
	ADD_LIBRARY (${TARGETNAME} ${VARIANT} ${FCPPTFILES})

	SET_TARGET_PROPERTIES(${TARGETNAME} PROPERTIES VERSION ${FCPPT_VERSION})

	IF(${TARGETNAME} STREQUAL fcppt)
		SET_TARGET_PROPERTIES(
			${TARGETNAME} PROPERTIES SOVERSION ${FCPPT_SHARED_VERSION}
		)
	ENDIF()

	#rename fcppt_static into fcppt for UNIX
	IF(${TARGETNAME} STREQUAL fcppt_static AND UNIX)
		SET_TARGET_PROPERTIES(
			${TARGETNAME} PROPERTIES OUTPUT_NAME fcppt
		)
	ENDIF()

	IF (NOT MSVC)
		TARGET_LINK_LIBRARIES (
			${TARGETNAME}
			${Boost_LIBRARIES}
		)
	ENDIF ()

	IF(FCPPT_HAVE_CLOCK_GETTIME)
		TARGET_LINK_LIBRARIES(${TARGETNAME} rt)
	ENDIF()

	INSTALL (TARGETS ${TARGETNAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
ENDMACRO()

IF (ENABLE_SHARED)
	MAKE_FCPPT_LIBRARY(fcppt SHARED)
ENDIF()

IF (ENABLE_STATIC)
	MAKE_FCPPT_LIBRARY(fcppt_static STATIC)
ENDIF()

OPTION(ENABLE_EXAMPLES "Build the examples" ON)

IF (ENABLE_EXAMPLES)
	ADD_SUBDIRECTORY (examples)
ENDIF ()

OPTION(ENABLE_DOC "Build the documentation" OFF)

IF (ENABLE_DOC)
	ADD_SUBDIRECTORY (doc)
ENDIF ()

OPTION(ENABLE_TEST "Build the tests" ON)

IF (ENABLE_TEST)
	ENABLE_TESTING()

	ADD_SUBDIRECTORY (test)
ENDIF ()

INSTALL (
	DIRECTORY include/
	DESTINATION include
	PATTERN dummy.hpp EXCLUDE
)
