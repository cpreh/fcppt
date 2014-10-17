cmake_minimum_required(
	VERSION
	2.8.12
)

project(
	fcppt
)

set(
	CMAKE_MODULE_PATH
	"${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules;${CMAKE_MODULE_PATH}"
)

include(
	FcpptCMakeUtils
)

fcppt_utils_prepare_config()

include(
	FcpptSymbol
)

set(FCPPT_MAJOR_VERSION 1)
set(FCPPT_MINOR_VERSION 0)
set(FCPPT_MICRO_VERSION 0)

set(
	FCPPT_VERSION
	"${FCPPT_MAJOR_VERSION}.${FCPPT_MINOR_VERSION}.${FCPPT_MICRO_VERSION}"
)

fcppt_utils_handle_so_version(
	FCPPT_SO_VERSION
	FCPPT_USED_SO_VERSION
	"1.0.0"
)

math(
	EXPR
	FCPPT_INT_VERSION
	"${FCPPT_MAJOR_VERSION} * 1000000 + ${FCPPT_MINOR_VERSION} * 1000 + ${FCPPT_MICRO_VERSION}"
)

include(
	CheckCXXSourceCompiles
)

include(
	CheckCXXSourceRuns
)

if(
	WIN32
)
	set(
		ENABLE_NARROW_STRING_DEFAULT
		OFF
	)
else()
	set(
		ENABLE_NARROW_STRING_DEFAULT
		ON
	)
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

set(
	FCPPT_NARROW_STRING
	${ENABLE_NARROW_STRING}
)

if(
	CMAKE_COMPILER_IS_GNUCXX OR FCPPT_UTILS_COMPILER_IS_CLANGPP
)
	CHECK_CXX_SOURCE_COMPILES(
		"#include <cxxabi.h>
		 #include <cstdlib>
		int main() { int status; char *name =
		abi::__cxa_demangle(typeid(int).name(),0,0,&status); std::free(name); }"
		FCPPT_HAVE_GCC_DEMANGLE
	)
endif()

include_directories(
	${FCPPT_UTILS_PROJECT_SOURCE_DIR}/include
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
	"filesystem;system"
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
	${Boost_INCLUDE_DIRS}
)

link_directories(
	${Boost_LIBRARY_DIRS}
)

set(
	CMAKE_REQUIRED_INCLUDES
	${FCPPT_UTILS_PROJECT_SOURCE_DIR}/include
	${Boost_INCLUDE_DIRS}
)

CHECK_CXX_SOURCE_COMPILES(
	"#include <execinfo.h>
	int main()
	{
		static_cast<void>(static_cast<int (*)(void**,int)>(::backtrace));
		static_cast<void>(static_cast<char **(*)(void* const *,int)>(::backtrace_symbols));
	}"
	FCPPT_HAVE_BACKTRACE
)

function(
	configure_fcppt_file
	FILE_RELPATH
)
	configure_file(
		${FCPPT_UTILS_PROJECT_SOURCE_DIR}/src/${FILE_RELPATH}.in
		${FCPPT_UTILS_PROJECT_BINARY_DIR}/include/fcppt/${FILE_RELPATH}
	)
endfunction()

configure_fcppt_file(
	public_config.hpp
)

configure_fcppt_file(
	version.hpp
)

configure_file(
	${FCPPT_UTILS_PROJECT_SOURCE_DIR}/src/private_config.hpp.in
	${FCPPT_UTILS_PROJECT_BINARY_DIR}/src/include/fcppt/private_config.hpp
)

include_directories(
	${FCPPT_UTILS_PROJECT_BINARY_DIR}/include
	${FCPPT_UTILS_PROJECT_BINARY_DIR}/src/include
)

include(
	CMakeParseArguments
)

function(
	make_fcppt_library_base
	TARGETNAME
	CUR_FILES
)
	set(
		SINGLE_ARGS
		VARIANT
	)

	set(
		MULTI_ARGS
		FCPPT_DEPS
		OTHER_DEPS
		TRANSITIVE_DEPS
	)

	cmake_parse_arguments(
		""
		""
		"${SINGLE_ARGS}"
		"${MULTI_ARGS}"
		${ARGN}
	)

	fcppt_utils_append_source_dir_and_make_groups(
		"${CUR_FILES}"
		FCPPT_${TARGETNAME}_FILES
	)

	add_library(
		${TARGETNAME}
		${_VARIANT}
		${FCPPT_${TARGETNAME}_FILES}
	)

	fcppt_utils_set_so_version(
		${TARGETNAME}
		${FCPPT_USED_SO_VERSION}
	)

	fcppt_utils_set_target_compiler_flags(
		${TARGETNAME}
	)

	fcppt_utils_interface_static_link(
		${TARGETNAME}
		${_VARIANT}
		"FCPPT_STATIC_LINK"
	)

	target_include_directories(
		${TARGETNAME}
		INTERFACE
		${Boost_INCLUDE_DIRS}
	)

	fcppt_utils_add_target_include_dir(
		${TARGETNAME}
		TRUE
	)

	target_link_libraries(
		${TARGETNAME}
		PRIVATE
		${_FCPPT_DEPS}
		${_OTHER_DEPS}
		INTERFACE
		${_TRANSITIVE_DEPS}
	)

	fcppt_utils_export_install_target(
		${TARGETNAME}
	)
endfunction()

function(
	make_fcppt_library
	LIBNAME
	CUR_FILES
)
	set(
		MULTI_ARGS
		FCPPT_DEPS
		OTHER_DEPS
		TRANSITIVE_DEPS
	)

	cmake_parse_arguments(
		""
		""
		""
		"${MULTI_ARGS}"
		${ARGN}
	)


	if(
		ENABLE_SHARED
	)
		make_fcppt_library_base(
			"${LIBNAME}"
			"${CUR_FILES}"
			VARIANT
				"SHARED"
			${ARGN}
		)
	endif()

	if(
		ENABLE_STATIC
	)
		foreach(
			FCPPTDEP
			${_FCPPT_DEPS}
		)
			list(
				APPEND
				REAL_FCPPT_DEPS
				"${FCPPTDEP}_static"
			)
		endforeach()

		make_fcppt_library_base(
			"${LIBNAME}_static"
			"${CUR_FILES}"
			VARIANT
				"STATIC"
			FCPPT_DEPS
				${REAL_FCPPT_DEPS}
			OTHER_DEPS
				${_OTHER_DEPS}
			TRANSITIVE_DEPS
				${_TRANSITIVE_DEPS}
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

fcppt_utils_generate_config(
	TRUE
)

install(
	DIRECTORY
	${FCPPT_UTILS_PROJECT_SOURCE_DIR}/include/
	DESTINATION
	${INSTALL_INCLUDE_DIR}
)

install(
	DIRECTORY
	${FCPPT_UTILS_PROJECT_BINARY_DIR}/include/
	DESTINATION
	${INSTALL_INCLUDE_DIR}
)

install(
	FILES
	${FCPPT_UTILS_PROJECT_SOURCE_DIR}/CMakeModules/FindFcpptThreads.cmake
	${FCPPT_UTILS_PROJECT_SOURCE_DIR}/CMakeModules/FcpptCMakeUtils.cmake
	${FCPPT_UTILS_PROJECT_SOURCE_DIR}/CMakeModules/FcpptExport.cmake
	${FCPPT_UTILS_PROJECT_SOURCE_DIR}/CMakeModules/FcpptSymbol.cmake
	DESTINATION
	${INSTALL_CMAKEMODULES_DIR}
)
