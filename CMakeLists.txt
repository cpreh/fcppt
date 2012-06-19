cmake_minimum_required(
	VERSION 2.6
)

set(
	CMAKE_MODULE_PATH
	"${CMAKE_SOURCE_DIR}/CMakeModules;${CMAKE_MODULE_PATH}"
)

project(
	fcppt
)

include(
	FcpptCMakeUtils
)

include(
	FcpptSymbol
)

set(FCPPT_MAJOR_VERSION 0)
set(FCPPT_MINOR_VERSION 11)
set(FCPPT_MICRO_VERSION 1)

set(
	FCPPT_MAJOR_MINOR_VERSION
	"${FCPPT_MAJOR_VERSION}.${FCPPT_MINOR_VERSION}"
)

set(
	FCPPT_VERSION
	"${FCPPT_MAJOR_MINOR_VERSION}.${FCPPT_MICRO_VERSION}"
)

math(
	EXPR
	FCPPT_INT_VERSION
	"${FCPPT_MAJOR_VERSION} * 1000000 + ${FCPPT_MINOR_VERSION} * 1000 + ${FCPPT_MICRO_VERSION}"
)

set(
	FCPPT_SHARED_VERSION
	${FCPPT_VERSION}
)

include(CheckCXXSourceCompiles)
include(CheckCXXSourceRuns)
include(CheckIncludeFile)
include(FindPkgConfig)

if(WIN32)
	set(ENABLE_NARROW_STRING_DEFAULT OFF)
else()
	set(ENABLE_NARROW_STRING_DEFAULT ON)
endif()

option(
	ENABLE_SHARED
	"Build fcppt as shared libraries"
	TRUE
)

option(
	ENABLE_STATIC
	"Build fcppt as static libraries"
	FALSE
)

option(
	ENABLE_NARROW_STRING
	"Build fcppt with std::string instead of std::wstring"
	${ENABLE_NARROW_STRING_DEFAULT}
)

if(
	NOT ENABLE_SHARED AND NOT ENABLE_STATIC
)
	message(
		FATAL_ERROR
		"You disabled both STATIC and SHARED"
	)
endif()

# choose a library to link the tests to
if(
	ENABLE_SHARED
)
	set(
		FCPPT_DEFAULT_LINK_STATIC
		FALSE
	)
endif()

# static overrides shared
if(
	ENABLE_STATIC
)
	set(
		FCPPT_DEFAULT_LINK_STATIC
		TRUE
	)
endif()

if(
	FCPPT_DEFAULT_LINK_STATIC
)
	set(
		FCPPT_CONFIG_LINK_MACROS
		"-D FCPPT_STATIC_LINK"
	)
endif()

macro(
	fcppt_link_target
	LIBNAME
)
	if(
		FCPPT_DEFAULT_LINK_STATIC
	)
		set(
			${LIBNAME}_TARGET
			${LIBNAME}_static
		)
	else()
		set(
			${LIBNAME}_TARGET
			${LIBNAME}
		)
	endif()
endmacro()

function(
	generate_symbol_header
	EXPORTS_NAME
	SYMBOL_NAME
)
	string(
		REPLACE
		"_"
		"/"
		RELATIVE_PATH
		"${SYMBOL_NAME}"
	)

	string(
		TOLOWER
		"${RELATIVE_PATH}"
		RELATIVE_PATH
	)

	fcppt_generate_symbol_header(
		"FCPPT_STATIC_LINK"
		"${EXPORTS_NAME}"
		"${SYMBOL_NAME}"
		"${RELATIVE_PATH}"
	)
endfunction()

if(
	ENABLE_NARROW_STRING
)
	set(
		FCPPT_NARROW_STRING
		true
	)
endif()

if(
	CMAKE_COMPILER_IS_GNUCXX OR FCPPT_UTILS_COMPILER_IS_CLANGPP
)
	set(
		FCPPT_HAVE_GCC_VISIBILITY
		${FCPPT_UTILS_HAVE_GCC_VISIBILITY}
	)

	CHECK_CXX_SOURCE_COMPILES(
		"#include <cxxabi.h>
		 #include <cstdlib>
		int main() { int status; char *name =
		abi::__cxa_demangle(typeid(int).name(),0,0,&status); std::free(name); }"
		FCPPT_HAVE_GCC_DEMANGLE
	)

	CHECK_CXX_SOURCE_COMPILES(
		"int main()
		{
			char const *name = __PRETTY_FUNCTION__;
		}"
		FCPPT_HAVE_GCC_PRETTY_FUNCTION
	)

	set(
		CMAKE_REQUIRED_FLAGS
		"-Wall -Werror -pedantic"
	)

	check_cxx_source_compiles(
		"
		#define DO_PRAGMA(x) _Pragma(#x)
		#define DO_MESSAGE(x) DO_PRAGMA(message (#x))
		DO_MESSAGE(test)
		int main() {}
		"
		FCPPT_HAVE_GCC_PRAGMA_MESSAGE
	)

	unset(
		CMAKE_REQUIRED_FLAGS
	)

	set(
		FCPPT_HAVE_GCC_DIAGNOSTIC
		${FCPPT_UTILS_HAVE_GCC_DIAGNOSTIC}
	)
endif()

include_directories(
	${CMAKE_SOURCE_DIR}/include
)

set(
	SIGNALS_BENCHMARK_BACKEND
	"fcppt"
	CACHE
	STRING
	"Which backend to use for the signal benchmark example (fcppt/boostsignals/boostsignals2)"
)

set(
	NEEDED_BOOST_LIBS
	"filesystem;system;thread"
)

if(
	${SIGNALS_BENCHMARK_BACKEND}
	STREQUAL
	"boostsignals"
)
	set(
		NEEDED_BOOST_LIBS
		"${NEEDED_BOOST_LIBS};signals"
	)
endif()

option(
	ENABLE_EXAMPLES
	"Build the examples"
	ON
)

if(
	ENABLE_EXAMPLES
)
	set(
		NEEDED_BOOST_LIBS
		"${NEEDED_BOOST_LIBS};chrono"
	)
endif()

option(
	ENABLE_TEST
	"Build the tests"
	ON
)

if(
	ENABLE_TEST
)
	set(
		NEEDED_BOOST_LIBS
		"${NEEDED_BOOST_LIBS};unit_test_framework"
	)
endif()

find_package(
	Boost 1.47.0 REQUIRED COMPONENTS
	"${NEEDED_BOOST_LIBS}"
)

unset(
	NEEDED_BOOST_LIBS
)

include_directories(
	${FCPPT_UTILS_INCLUDE_SYSTEM}
	${Boost_INCLUDE_DIRS}
)

link_directories(
	${Boost_LIBRARY_DIRS}
)

find_package(
	FcpptThreads
	REQUIRED
)

set(
	CMAKE_REQUIRED_INCLUDES
	${CMAKE_SOURCE_DIR}/include
	${Boost_INCLUDE_DIRS}
)

check_cxx_source_compiles(
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

find_library(
	RT_LIBRARY
	rt
)

set(
	CMAKE_REQUIRED_LIBRARIES
	${RT_LIBRARY}
)

CHECK_CXX_SOURCE_COMPILES(
	"#include <time.h>
	int main()
	{
		int (*tmp)(clockid_t, struct timespec *) = clock_gettime;
	}"
	FCPPT_HAVE_CLOCK_GETTIME
)

unset(
	CMAKE_REQUIRED_LIBRARIES
)

CHECK_CXX_SOURCE_COMPILES(
	"#include <execinfo.h>
	int main()
	{
		int (*tmp)(void**,int) throw() = ::backtrace;
		char **(*tmp2)(void* const *,int) throw() = ::backtrace_symbols;
		void(*tmp3)(void* const*,int,int) throw() = ::backtrace_symbols_fd;
	}"
	FCPPT_HAVE_BACKTRACE
)

CHECK_CXX_SOURCE_COMPILES(
	"int purefunction() __attribute__((const));int main() {}"
	FCPPT_HAVE_CONST_ATTRIBUTE
)

CHECK_CXX_SOURCE_COMPILES(
	"int purefunction() __attribute__((pure));int main() {}"
	FCPPT_HAVE_PURE_ATTRIBUTE
)

CHECK_CXX_SOURCE_COMPILES(
	"int unused_result_function() __attribute__((warn_unused_result)); int main() {}"
	FCPPT_HAVE_WARN_UNUSED_RESULT_ATTRIBUTE
)

function(
	configure_fcppt_file
	FILE_RELPATH
)
	configure_file(
		${CMAKE_SOURCE_DIR}/src/${FILE_RELPATH}.in
		${CMAKE_BINARY_DIR}/include/fcppt/${FILE_RELPATH}
	)
endfunction()

configure_fcppt_file(
	config.hpp
)

configure_fcppt_file(
	version.hpp
)

macro(
	fcppt_set_utils_warning
	WARNING_NAME
)
	set(
		FCPPT_CONFIG_HAVE_${WARNING_NAME}_WARNING
		${FCPPT_UTILS_HAVE_${WARNING_NAME}_FLAG}
	)
endmacro()

fcppt_set_utils_warning(
	CONDITIONAL_UNINITIALIZED
)

fcppt_set_utils_warning(
	CONVERSION_NULL
)

fcppt_set_utils_warning(
	DELETE_NON_VIRTUAL_DTOR
)

fcppt_set_utils_warning(
	DOUBLE_PROMOTION
)

fcppt_set_utils_warning(
	EXTRA_SEMI
)

fcppt_set_utils_warning(
	IMPLICIT_FALLTHROUGH
)

fcppt_set_utils_warning(
	LOGICAL_OP
)

fcppt_set_utils_warning(
	MAYBE_UNINITIALIZED
)

fcppt_set_utils_warning(
	MISSING_DECLARATIONS
)

fcppt_set_utils_warning(
	SIGN_CONVERSION
)

fcppt_set_utils_warning(
	UNNEEDED_MEMBER_FUNCTION
)

fcppt_set_utils_warning(
	UNUSED_LOCAL_TYPEDEFS
)

fcppt_set_utils_warning(
	UNUSED_MEMBER_FUNCTION
)

fcppt_set_utils_warning(
	UNREACHABLE_CODE
)

fcppt_set_utils_warning(
	ZERO_AS_NULL_POINTER_CONSTANT
)

configure_fcppt_file(
	config/warnings.hpp
)

include_directories(
	${CMAKE_BINARY_DIR}/include
)

function(
	make_fcppt_library_base
	TARGETNAME
	VARIANT
	CUR_FILES
	FCPPT_DEPS
	OTHER_DEPS
	TRANSITIVE_DEPS
)
	FCPPT_UTILS_APPEND_SOURCE_DIR_AND_MAKE_GROUPS(
		"${CUR_FILES}"
		FCPPT_${TARGETNAME}_FILES
	)

	add_library(
		${TARGETNAME}
		${VARIANT}
		${FCPPT_${TARGETNAME}_FILES}
	)

	set_target_properties(
		${TARGETNAME}
		PROPERTIES
		VERSION
		${FCPPT_VERSION}
	)

	if(
		${VARIANT} STREQUAL "SHARED"
	)
		set_target_properties(
			${TARGETNAME}
			PROPERTIES
			SOVERSION
			${FCPPT_SHARED_VERSION}
		)
	else()
		set_target_properties(
			${TARGETNAME}
			PROPERTIES
			COMPILE_DEFINITIONS
			"FCPPT_STATIC_LINK"
		)
	endif()

	target_link_libraries(
		${TARGETNAME}
		${FCPPT_DEPS}
		${OTHER_DEPS}
	)

	if(
		FCPPT_HAVE_CLOCK_GETTIME
	)
		target_link_libraries(
			${TARGETNAME}
			${RT_LIBRARY}
		)
	endif()

	set_target_properties(
		${TARGETNAME}
		PROPERTIES
		LINK_INTERFACE_LIBRARIES
		""
	)

	target_link_libraries(
		${TARGETNAME}
		LINK_INTERFACE_LIBRARIES
		${TRANSITIVE_DEPS}
	)

	install(
		TARGETS
		${TARGETNAME}
		DESTINATION
		${INSTALL_LIBRARY_DIR}
		EXPORT
		FcpptTargets
	)
endfunction()

function(
	make_fcppt_library
	LIBNAME
	CUR_FILES
	FCPPT_DEPS
	OTHER_DEPS
	TRANSITIVE_DEPS
)
	if(
		ENABLE_SHARED
	)
		make_fcppt_library_base(
			"${LIBNAME}"
			"SHARED"
			"${CUR_FILES}"
			"${FCPPT_DEPS}"
			"${OTHER_DEPS}"
			"${TRANSITIVE_DEPS}"
		)
	endif()

	if(
		ENABLE_STATIC
	)
		foreach(
			FCPPTDEP
			${FCPPT_DEPS}
		)
			set(
				REAL_FCPPT_DEPS
				"${REAL_FCPPT_DEPS};${FCPPTDEP}_static"
			)
		endforeach()

		make_fcppt_library_base(
			"${LIBNAME}_static"
			"STATIC"
			"${CUR_FILES}"
			"${REAL_FCPPT_DEPS}"
			"${OTHER_DEPS}"
			"${TRANSITIVE_DEPS}"
		)
	endif()
endfunction()

add_subdirectory(
	src
)

add_subdirectory(
	src/filesystem
)

add_subdirectory(
	src/thread
)

if(
	ENABLE_EXAMPLES
)
	add_subdirectory(
		examples
	)
endif()

option(
	ENABLE_DOC
	"Build the documentation"
	OFF
)

if(
	ENABLE_DOC
)
	add_subdirectory(
		doc
	)
endif()

if(
	ENABLE_TEST
)
	enable_testing()

	add_subdirectory(
		test
	)
endif()

set(
	Fcppt_INCLUDE_DIR
	${INSTALL_INCLUDE_DIR}
)

configure_file(
	${CMAKE_SOURCE_DIR}/FcpptConfig.cmake.in
	${CMAKE_BINARY_DIR}/FcpptConfig.cmake
	@ONLY
)

install(
	FILES
	${CMAKE_BINARY_DIR}/FcpptConfig.cmake
	DESTINATION
	${INSTALL_CMAKECONFIG_DIR}
)

install(
	DIRECTORY
	include/
	DESTINATION
	${INSTALL_INCLUDE_DIR}
)

install(
	DIRECTORY
	${CMAKE_BINARY_DIR}/include/
	DESTINATION
	${INSTALL_INCLUDE_DIR}
)

install(
	FILES
	${CMAKE_SOURCE_DIR}/CMakeModules/FindFcppt.cmake
	${CMAKE_SOURCE_DIR}/CMakeModules/FindFcpptThreads.cmake
	${CMAKE_SOURCE_DIR}/CMakeModules/FcpptCMakeUtils.cmake
	${CMAKE_SOURCE_DIR}/CMakeModules/FcpptSymbol.cmake
	DESTINATION
	${INSTALL_CMAKEMODULES_DIR}
)

install(
	EXPORT
	FcpptTargets
	DESTINATION
	${INSTALL_CMAKECONFIG_DIR}
)
