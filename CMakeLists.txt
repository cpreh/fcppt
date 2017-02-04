cmake_minimum_required(
	VERSION
	3.1.0
)

project(
	fcppt
)

set_property(
	GLOBAL
	PROPERTY
	USE_FOLDERS
	ON
)

list(
	APPEND
	CMAKE_MODULE_PATH
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules"
)

include(
	FcpptCMakeUtils
)

include(
	FcpptSymbol
)

set(
	FCPPT_MAJOR_VERSION
	2
)

set(
	FCPPT_MINOR_VERSION
	5
)

set(
	FCPPT_MICRO_VERSION
	0
)

set(
	FCPPT_VERSION
	"${FCPPT_MAJOR_VERSION}.${FCPPT_MINOR_VERSION}.${FCPPT_MICRO_VERSION}"
)

fcppt_utils_handle_so_version(
	FCPPT_SO_VERSION
	FCPPT_USED_SO_VERSION
	"${FCPPT_MAJOR_VERSION}.${FCPPT_MINOR_VERSION}"
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
	ENABLE_NARROW_STRING
	"Build fcppt with std::string instead of std::wstring"
	${ENABLE_NARROW_STRING_DEFAULT}
)

fcppt_utils_static_shared()

set(
	FCPPT_NARROW_STRING
	${ENABLE_NARROW_STRING}
)

if(
	CMAKE_COMPILER_IS_GNUCXX
	OR
	FCPPT_UTILS_COMPILER_IS_CLANGPP
)
	CHECK_CXX_SOURCE_COMPILES(
		"#include <cxxabi.h>
		 #include <cstdlib>
		int main() { int status; char *name =
		abi::__cxa_demangle(typeid(int).name(),0,0,&status); std::free(name); }"
		FCPPT_HAVE_GCC_DEMANGLE
	)
endif()

set(
	SIGNALS_BENCHMARK_BACKEND
	"fcppt"
	CACHE
	STRING
	"Which backend to use for the signal benchmark example (fcppt/boostsignals/boostsignals2)"
)

option(
	ENABLE_FILESYSTEM
	"Build the filesystem library"
	ON
)

if(
	ENABLE_FILESYSTEM
)
	set(
		NEEDED_BOOST_LIBS
		filesystem
		system
	)
endif()

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
	Boost
	1.47.0
	REQUIRED
	COMPONENTS
	"${NEEDED_BOOST_LIBS}"
)

unset(
	NEEDED_BOOST_LIBS
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

include(
	TestBigEndian
)

test_big_endian(
	FCPPT_IS_BIG_ENDIAN
)

configure_file(
	${FCPPT_UTILS_PROJECT_SOURCE_DIR}/cmake/version.hpp.in
	${FCPPT_UTILS_PROJECT_BINARY_DIR}/include/fcppt/version.hpp
)

configure_file(
	${FCPPT_UTILS_PROJECT_SOURCE_DIR}/cmake/public_config.hpp.in
	${FCPPT_UTILS_PROJECT_BINARY_DIR}/include/fcppt/public_config.hpp
)

configure_file(
	${FCPPT_UTILS_PROJECT_SOURCE_DIR}/cmake/private_config.hpp.in
	${FCPPT_UTILS_PROJECT_BINARY_DIR}/impl/include/fcppt/impl/private_config.hpp
)

include(
	CMakeParseArguments
)

set(
	FCPPT_STATIC_LINK_FLAG
	FCPPT_STATIC_LINK
)

function(
	make_fcppt_library_base
	TARGETNAME
	CUR_FILES
)
	set(
		OPTION_ARGS
		HAS_IMPL_DIR
	)

	set(
		SINGLE_ARGS
		VARIANT
	)

	set(
		MULTI_ARGS
		FCPPT_DEPS
		TRANSITIVE_FCPPT_DEPS
		OTHER_DEPS
		TRANSITIVE_DEPS
	)

	cmake_parse_arguments(
		""
		"${HAS_IMPL_DIR}"
		"${SINGLE_ARGS}"
		"${MULTI_ARGS}"
		${ARGN}
	)

	fcppt_utils_append_source_dir_and_make_groups(
		"${CUR_FILES}"
		FCPPT_${TARGETNAME}_FILES
	)

	if(
		${_VARIANT}
		STREQUAL
		INTERFACE
	)
		add_library(
			${TARGETNAME}
			${_VARIANT}
		)
	else()
		add_library(
			${TARGETNAME}
			${_VARIANT}
			${FCPPT_${TARGETNAME}_FILES}
		)
	endif()

	if(
		NOT
		${_VARIANT}
		STREQUAL
		INTERFACE
	)
		fcppt_utils_set_so_version(
			${TARGETNAME}
			${FCPPT_USED_SO_VERSION}
		)

		fcppt_utils_set_target_compiler_flags(
			${TARGETNAME}
		)

		set_target_properties(
			${TARGETNAME}
			PROPERTIES
			FOLDER
			fcppt
		)
	endif()

	fcppt_utils_interface_static_link(
		${TARGETNAME}
		${_VARIANT}
		${FCPPT_STATIC_LINK_FLAG}
	)

	set(
		PUBLIC_INCLUDES
		"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
		"$<BUILD_INTERFACE:${FCPPT_UTILS_PROJECT_BINARY_DIR}/include>"
		${Boost_INCLUDE_DIRS}
	)

	if(
		NOT
		${_VARIANT}
		STREQUAL
		INTERFACE
	)
		target_include_directories(
			${TARGETNAME}
			PUBLIC
			${PUBLIC_INCLUDES}
			PRIVATE
			"$<BUILD_INTERFACE:${FCPPT_UTILS_PROJECT_BINARY_DIR}/impl/include>"
		)

		if(
			${_HAS_IMPL_DIR}
		)
			target_include_directories(
				${TARGETNAME}
				PRIVATE
				"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/impl/include>"
			)
		endif()
	endif()

	target_include_directories(
		${TARGETNAME}
		INTERFACE
		${PUBLIC_INCLUDES}
		"$<INSTALL_INTERFACE:${INSTALL_INCLUDE_DIR}>"
	)

	if(
		NOT
		${_VARIANT}
		STREQUAL
		INTERFACE
	)
		target_link_libraries(
			${TARGETNAME}
			PRIVATE
			${_FCPPT_DEPS}
			${_OTHER_DEPS}
		)
	endif()

	target_link_libraries(
		${TARGETNAME}
		INTERFACE
		${_TRANSITIVE_DEPS}
		${_TRANSITIVE_FCPPT_DEPS}
	)

	fcppt_utils_export_install_target(
		${TARGETNAME}
	)
endfunction()

function(
	make_fcppt_library
	LIB_NAME
	CUR_FILES
)
	set(
		OPTION_ARGS
		HAS_IMPL_DIR
	)

	set(
		SINGLE_ARGS
		SYMBOL_NAME
	)

	set(
		MULTI_ARGS
		FCPPT_DEPS
		TRANSITIVE_FCPPT_DEPS
		OTHER_DEPS
		TRANSITIVE_DEPS
	)

	set(
		FULL_NAME
		fcppt_${LIB_NAME}
	)

	cmake_parse_arguments(
		""
		"${OPTION_ARGS}"
		"${SINGLE_ARGS}"
		"${MULTI_ARGS}"
		${ARGN}
	)

	string(
		TOUPPER
		${LIB_NAME}
		LIB_NAME_UPPER
	)

	if(
		"${_SYMBOL_NAME}"
		STREQUAL
		""
	)
		set(
			_SYMBOL_NAME
			FCPPT_${LIB_NAME_UPPER}
		)
	endif()

	fcppt_generate_symbol_header(
		EXPORTS_NAME
			"${FULL_NAME}"
		SYMBOL_NAME
			"${_SYMBOL_NAME}_DETAIL"
		STATIC_LINK_FLAG
			"${FCPPT_STATIC_LINK_FLAG}"
	)

	fcppt_utils_interface_link_name(
		${FULL_NAME}
		INTERFACE_NAME
	)

	make_fcppt_library_base(
		"${INTERFACE_NAME}"
		""
		VARIANT
			"INTERFACE"
		${ARGN}
	)

	if(
		ENABLE_SHARED
	)
		make_fcppt_library_base(
			"${FULL_NAME}"
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
			fcppt_utils_static_link_name(
				${FCPPTDEP}
				STATIC_NAME
			)

			list(
				APPEND
				REAL_FCPPT_DEPS
				${STATIC_NAME}
			)
		endforeach()

		foreach(
			FCPPTDEP
			${_TRANSITIVE_FCPPT_DEPS}
		)
			fcppt_utils_static_link_name(
				${FCPPTDEP}
				STATIC_NAME
			)

			list(
				APPEND
				REAL_TRANSITIVE_FCPPT_DEPS
				${STATIC_NAME}
			)
		endforeach()

		fcppt_utils_static_link_name(
			${FULL_NAME}
			STATIC_NAME
		)

		make_fcppt_library_base(
			"${STATIC_NAME}"
			"${CUR_FILES}"
			VARIANT
				"STATIC"
			FCPPT_DEPS
				${REAL_FCPPT_DEPS}
			TRANSITIVE_FCPPT_DEPS
				${REAL_TRANSITIVE_FCPPT_DEPS}
			OTHER_DEPS
				${_OTHER_DEPS}
			TRANSITIVE_DEPS
				${_TRANSITIVE_DEPS}
		)
	endif()

	install(
		DIRECTORY
		${CMAKE_CURRENT_SOURCE_DIR}/include/
		DESTINATION
		${INSTALL_INCLUDE_DIR}
	)
endfunction()

add_subdirectory(
	libs
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
	CONFIG_PATH
	${FCPPT_UTILS_PROJECT_SOURCE_DIR}/cmake
)

install(
	DIRECTORY
	${FCPPT_UTILS_PROJECT_BINARY_DIR}/include/
	DESTINATION
	${INSTALL_INCLUDE_DIR}
)

set(
	FCPPT_CMAKE_MODULES_DIR
	${FCPPT_UTILS_PROJECT_SOURCE_DIR}/cmake/modules
)

install(
	FILES
	${FCPPT_CMAKE_MODULES_DIR}/FindFcpptThreads.cmake
	${FCPPT_CMAKE_MODULES_DIR}/FcpptCMakeUtils.cmake
	${FCPPT_CMAKE_MODULES_DIR}/FcpptExport.cmake
	${FCPPT_CMAKE_MODULES_DIR}/FcpptSymbol.cmake
	DESTINATION
	${INSTALL_CMAKEMODULES_DIR}
)
