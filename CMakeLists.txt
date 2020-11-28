cmake_minimum_required(
	VERSION
	3.7.0
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

list(
	APPEND
	FCPPT_UTILS_CLANG_TIDY_ADDITIONAL_CHECKS
	"-cppcoreguidelines-avoid-magic-numbers"
	"-readability-magic-numbers"
)

include(
	FcpptCMakeUtils
)

include(
	FcpptSymbol
)

set(
	FCPPT_MAJOR_VERSION
	3
)

set(
	FCPPT_MINOR_VERSION
	6
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

find_package(
	Metal
	REQUIRED
)

find_package(
	Boost
	1.47.0
)

if(
	NOT
	"${Boost_INCLUDE_DIRS}"
	STREQUAL
	""
)
	set(
		ENABLE_BOOST_DEFAULT
		ON
	)
else()
	set(
		ENABLE_BOOST_DEFAULT
		OFF
	)
endif()

find_package(
	Catch2
	CONFIG
)

option(
	ENABLE_BOOST
	"Build the boost support library"
	${ENABLE_BOOST_DEFAULT}
)

option(
	ENABLE_FILESYSTEM
	"Build the filesystem library"
	ON
)

option(
	ENABLE_CATCH
	"Build the Catch support library"
	${Catch2_FOUND}
)

option(
	ENABLE_EXAMPLES
	"Build the examples"
	ON
)

option(
	ENABLE_TEST
	"Build the tests"
	OFF
)

set(
	SIGNALS_BENCHMARK_BACKEND
	"fcppt"
	CACHE
	STRING
	"Which backend to use for the signal benchmark example {fcppt, boostsignals2}"
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
		DEPS
		TRANSITIVE_DEPS
		IMPORTED_DEPS
		TRANSITIVE_IMPORTED_DEPS
		INCLUDE_DIRS
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
		set_target_properties(
			${TARGETNAME}
			PROPERTIES
			VERSION
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
		${_INCLUDE_DIRS}
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

		fcppt_utils_link_imported_targets(
			${TARGETNAME}
			PRIVATE
			${_IMPORTED_DEPS}
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
		"$<INSTALL_INTERFACE:${CMAKE_INSTALL_FULL_INCLUDEDIR}>"
	)

	fcppt_utils_link_imported_targets(
		${TARGETNAME}
		INTERFACE
		${_TRANSITIVE_IMPORTED_DEPS}
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
			${_DEPS}
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
		IS_INTERFACE
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
		DEPS
		TRANSITIVE_DEPS
		IMPORTED_DEPS
		TRANSITIVE_IMPORTED_DEPS
		INCLUDE_DIRS
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

	if(
		NOT
		${_IS_INTERFACE}
	)
		fcppt_generate_symbol_header(
			EXPORTS_NAME
				"${FULL_NAME}"
			SYMBOL_NAME
				"${_SYMBOL_NAME}_DETAIL"
			STATIC_LINK_FLAG
				"${FCPPT_STATIC_LINK_FLAG}"
		)
	endif()

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
		AND
		NOT
		${_IS_INTERFACE}
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
		AND
		NOT
		${_IS_INTERFACE}
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
				${_TRANSITIVE_FCPPT_DEPS}
			DEPS
				${_DEPS}
			TRANSITIVE_DEPS
				${_TRANSITIVE_DEPS}
			IMPORTED_DEPS
				${_IMPORTED_DEPS}
			TRANSITIVE_IMPORTED_DEPS
				${_TRANSITIVE_IMPORTED_DEPS}
			INCLUDE_DIRS
				${_INCLUDE_DIRS}
		)
	endif()

	install(
		DIRECTORY
		${CMAKE_CURRENT_SOURCE_DIR}/include/
		DESTINATION
		${CMAKE_INSTALL_INCLUDEDIR}
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
	if(
		NOT ENABLE_CATCH
	)
		message(
			FATAL_ERROR
			"ENABLE_CATCH must be on if ENABLE_TEST is"
		)
	endif()

	fcppt_utils_setup_tests()

	enable_testing()

	add_subdirectory(
		test
	)
endif()

fcppt_utils_generate_config(
	CONFIG_PATH
		${FCPPT_UTILS_PROJECT_SOURCE_DIR}/cmake
	MODULES_PATH
		${FCPPT_UTILS_PROJECT_SOURCE_DIR}/cmake/modules
)

install(
	DIRECTORY
	${FCPPT_UTILS_PROJECT_BINARY_DIR}/include/
	DESTINATION
	${CMAKE_INSTALL_INCLUDEDIR}
)

set(
	FCPPT_CMAKE_MODULES_DIR
	${FCPPT_UTILS_PROJECT_SOURCE_DIR}/cmake/modules
)

install(
	FILES
	${FCPPT_CMAKE_MODULES_DIR}/FindFcpptThreads.cmake
	${FCPPT_CMAKE_MODULES_DIR}/FcpptCMakeUtils.cmake
	${FCPPT_CMAKE_MODULES_DIR}/FcpptCMakeUtilsPaths.cmake
	${FCPPT_CMAKE_MODULES_DIR}/FcpptCMakeUtilsSettings.cmake
	${FCPPT_CMAKE_MODULES_DIR}/FcpptCMakeUtilsClangTidy.cmake
	${FCPPT_CMAKE_MODULES_DIR}/FcpptCMakeUtilsFunctions.cmake
	${FCPPT_CMAKE_MODULES_DIR}/FcpptExport.cmake
	${FCPPT_CMAKE_MODULES_DIR}/FcpptSymbol.cmake
	DESTINATION
	${FCPPT_UTILS_INSTALL_CMAKEMODULES_DIR}
)
