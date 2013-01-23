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

fcppt_utils_prepare_config()

include(
	FcpptSymbol
)

set(FCPPT_MAJOR_VERSION 0)
set(FCPPT_MINOR_VERSION 12)
set(FCPPT_MICRO_VERSION 0)

set(
	FCPPT_VERSION
	"${FCPPT_MAJOR_VERSION}.${FCPPT_MINOR_VERSION}.${FCPPT_MICRO_VERSION}"
)

set(
	FCPPT_SO_VERSION
	"0.11.1"
)

math(
	EXPR
	FCPPT_INT_VERSION
	"${FCPPT_MAJOR_VERSION} * 1000000 + ${FCPPT_MINOR_VERSION} * 1000 + ${FCPPT_MICRO_VERSION}"
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
elseif(
	WIN32
)
	add_definitions(
		"-D UNICODE -D _UNICODE"
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
	"chrono;filesystem;system"
)

if(
	${SIGNALS_BENCHMARK_BACKEND}
	STREQUAL
	"boostsignals"
)
	list(
		APPEND
		NEEDED_BOOST_LIBS
		"signals"
	)
endif()

option(
	ENABLE_EXAMPLES
	"Build the examples"
	ON
)

option(
	ENABLE_TEST
	"Build the tests"
	ON
)

if(
	ENABLE_TEST
)
	list(
		APPEND
		NEEDED_BOOST_LIBS
		"unit_test_framework"
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

CHECK_CXX_SOURCE_COMPILES(
	"struct foo { foo(foo const &) = delete; }; int main() {}"
	FCPPT_HAVE_DEFAULTED_AND_DELETED_FUNCTIONS
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

foreach(
	CUR_WARNING
	${FCPPT_UTILS_GCC_CLANG_WARNINGS}
)
	fcppt_utils_gcc_clang_warning_to_var_name(
		"${CUR_WARNING}"
		"OUT_WARNING"
	)

	set(
		FCPPT_CONFIG_HAVE_${OUT_WARNING}_WARNING
		${FCPPT_UTILS_HAVE_${OUT_WARNING}_FLAG}
	)
endforeach()

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
	fcppt_utils_append_source_dir_and_make_groups(
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
		${FCPPT_SO_VERSION}
	)

	if(
		${VARIANT} STREQUAL "STATIC"
	)
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
		NOT ${VARIANT} STREQUAL "STATIC"
	)
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
	endif()

	fcppt_utils_export_install_target(
		${TARGETNAME}
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

fcppt_utils_generate_config()

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
	${CMAKE_SOURCE_DIR}/CMakeModules/FindFcpptThreads.cmake
	${CMAKE_SOURCE_DIR}/CMakeModules/FcpptCMakeUtils.cmake
	${CMAKE_SOURCE_DIR}/CMakeModules/FcpptExport.cmake
	${CMAKE_SOURCE_DIR}/CMakeModules/FcpptSymbol.cmake
	DESTINATION
	${INSTALL_CMAKEMODULES_DIR}
)
