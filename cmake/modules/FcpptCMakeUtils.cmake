#Disallow in source builds everywhere
if(
	"${CMAKE_BINARY_DIR}"
	STREQUAL
	"${CMAKE_SOURCE_DIR}"
)
	message(
		FATAL_ERROR
		"In-source builds are not permitted. Make a separate folder for building:\nmkdir build; cd build; cmake ..\nBefore that, remove the files that cmake just created:\nrm -rf CMakeCache.txt CMakeFiles"
	)
endif()

if(
	NOT
	${PROJECT_NAME}
	STREQUAL
	"fcppt"
	AND
	NOT
	fcppt_FOUND
)
	message(
		FATAL_ERROR
		"FcpptCMakeUtils included without prior find_package(fcppt)"
	)
endif()

include(
	CMakeDetermineCXXCompiler
)

include(
	CheckCXXCompilerFlag
)

include(
	CMakeParseArguments
)

include(
	GNUInstallDirs
)

set(
	FCPPT_UTILS_PROJECT_SOURCE_DIR
	"${${PROJECT_NAME}_SOURCE_DIR}"
)

set(
	FCPPT_UTILS_PROJECT_BINARY_DIR
	"${${PROJECT_NAME}_BINARY_DIR}"
)

set(
	FCPPT_UTILS_INSTALL_DATA_DIR
	"${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}"
)

set(
	FCPPT_UTILS_INSTALL_CMAKEMODULES_DIR
	"${FCPPT_UTILS_INSTALL_DATA_DIR}/cmake"
)

set(
	FCPPT_UTILS_INSTALL_CMAKECONFIG_DIR_BASE
	"${CMAKE_INSTALL_LIBDIR}/cmake"
)

set(
	FCPPT_UTILS_INSTALL_CMAKECONFIG_DIR
	"${FCPPT_UTILS_INSTALL_CMAKECONFIG_DIR_BASE}/${PROJECT_NAME}"
)

foreach(
	curdir
	DATA_DIR
	CMAKEMODULES_DIR
	CMAKECONFIG_DIR_BASE
	CMAKECONFIG_DIR
)
	GNUInstallDirs_get_absolute_install_dir(
		FCPPT_UTILS_INSTALL_FULL_${curdir}
		FCPPT_UTILS_INSTALL_${curdir}
	)
endforeach()

if(
	${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang"
	OR
	${CMAKE_CXX_COMPILER_ID} STREQUAL "AppleClang"
)
	set(
		FCPPT_UTILS_COMPILER_IS_CLANGPP
		ON
	)
endif()

if(
	${CMAKE_CXX_COMPILER_ID} STREQUAL "Intel"
)
	set(
		FCPPT_UTILS_COMPILER_IS_INTELCPP
		ON
	)
endif()

# Setup default compiler flags
if(
	CMAKE_COMPILER_IS_GNUCXX OR FCPPT_UTILS_COMPILER_IS_CLANGPP
)
	set(
		CMAKE_CXX_FLAGS_RELEASE
		"-O3 -fomit-frame-pointer -DNDEBUG"
	)

	# cmake tries to grep for warning messages which will fail in a lot of cases
	set(
		CMAKE_REQUIRED_FLAGS_BASE
		"-Wall -Werror -pedantic"
	)

	set(
		CMAKE_REQUIRED_FLAGS
		${CMAKE_REQUIRED_FLAGS_BASE}
	)

	CHECK_CXX_COMPILER_FLAG(
		"-fvisibility=hidden"
		FCPPT_UTILS_HAVE_GCC_VISIBILITY
	)

	list(
		APPEND
		FCPPT_UTILS_COMPILE_OPTIONS
		"-pedantic"
		"-pedantic-errors"
		"-Wall"
		"-Wextra"
		"-Wcast-align"
		"-Wcast-qual"
		"-Wconversion"
		"-Wconversion-null"
		"-Wdelete-non-virtual-dtor"
		"-Wfloat-equal"
		"-Winit-self"
		"-Wmissing-declarations"
		"-Wnon-virtual-dtor"
		"-Wold-style-cast"
		"-Woverloaded-virtual"
		"-Wredundant-decls"
		"-Wsign-promo"
		"-Wsign-conversion"
		"-Wshadow"
		"-Wstrict-aliasing=1"
		"-Wuninitialized"
		"-Wunused"
		"-Wunused-function"
		#currently, -Wundef cannot be disabled via a pragma
	)

	if(
		FCPPT_UTILS_COMPILER_IS_CLANGPP
	)
		list(
			APPEND
			FCPPT_UTILS_COMPILE_OPTIONS
			"-Wconditional-uninitialized"
			"-Wdocumentation"
			"-Wextra-semi"
			"-Wimplicit-fallthrough"
			"-Wundef"
			"-Wunneeded-member-function"
			"-Wunused-member-function"
		)
	else()
		list(
			APPEND
			FCPPT_UTILS_COMPILE_OPTIONS
			"-Wdouble-promotion"
			"-Wlogical-op"
			"-Wmaybe-uninitialized"
			"-Wmissing-include-dirs"
			"-Wsuggest-override"
			"-Wunused-local-typedefs"
		)

		#"-Wzero-as-null-pointer-constant" - too many warnings from boost that cannot be disabled

		if(
			CMAKE_CXX_COMPILER_VERSION
			VERSION_GREATER
			6.0
		)
			list(
				APPEND
				FCPPT_UTILS_COMPILE_OPTIONS
				"-Wduplicated-cond"
				"-Wnull-dereference"
			)
		endif()
	endif()

	if(
		FCPPT_UTILS_HAVE_GCC_VISIBILITY
	)
		option(
			FCPPT_ENABLE_VISIBILITY_HIDDEN
			"Enable -fvisbility=hidden"
			TRUE
		)
	endif()

	if(
		FCPPT_ENABLE_VISIBILITY_HIDDEN
	)
		list(
			APPEND
			FCPPT_UTILS_COMPILE_OPTIONS
			"-fvisibility=hidden"
		)
	endif()
elseif(
	MSVC
)
	list(
		APPEND
		FCPPT_UTILS_COMPILE_OPTIONS
		/W4
		/Wall
		/EHa
		/D_BIND_TO_CURRENT_VCLIBS_VERSION=1
		/wd4435
		/wd4996
		/wd4061
		/wd4350
		/wd4371
		/wd4503
		/wd4514
		/wd4710
		/wd4711
		/wd4714
		/wd4738
		/wd4820
		/wd4868
		/wd5031
	)

	# /W4 warnings
	#4996 - unsafe standard C++ functions

	# /Wall warnings
	#4061 - warning for not handled cases in switchs even with default
	#4350 - behaviour change due to implicit conversions (needed for unique_ptr)
	#4371 - layout of class may have changed from previous compiler version
	#4435 - layout change because of virtual base class
	#4503 - decorated name length exceeded
	#4514 - unreferenced inline function removed
	#4710 - function not inlined
	#4711 - function selected for automatic inline expansion
	#4714 - function marked as __forceinline not inlined
	#4738 - storing 32-bit float result in memory
	#4820 - byte padding after data members
	#4868 - compiler may not enforce left-to-right evaluation order in braced initializer list
	#5031 - warning(pop) in different file
endif()

# FIXME: Check for -municode flag
if(
	NOT
	ENABLE_NARROW_STRING
	AND
	WIN32
	AND
	CMAKE_COMPILER_IS_GNUCXX
)
	set(
		FCPPT_UTILS_MAIN_COMPILE_OPTIONS
		"-municode"
	)

	set(
		FCPPT_UTILS_MAIN_LINK_LIBS
		"-municode"
	)
endif()

# setup platform specific flags
if(
	UNIX
)
	# we need -fPIC for libraries on AMD64
	if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86_64")
		list(
			APPEND
			FCPPT_UTILS_COMPILE_OPTIONS
			"-fPIC"
		)
	endif()

	# To check for linker flags, CMAKE_REQUIRED_FLAGS has to be expanded
	function(
		fcppt_check_gcc_linker_flag
		FLAG
		VARIABLE
	)
		set(
			CMAKE_REQUIRED_FLAGS
			"${CMAKE_REQUIRED_FLAGS_BASE} ${FLAG}"
		)

		CHECK_CXX_COMPILER_FLAG(
			""
			${VARIABLE}
		)
	endfunction()

	fcppt_check_gcc_linker_flag(
		"-Wl,--as-needed"
		FCPPT_UTILS_HAVE_AS_NEEDED_LINKER_FLAG
	)

	fcppt_check_gcc_linker_flag(
		"-Wl,--no-undefined"
		FCPPT_UTILS_HAVE_NO_UNDEFINED_LINKER_FLAG
	)

	fcppt_check_gcc_linker_flag(
		"-Wl,--no-copy-dt-needed-entries"
		FCPPT_UTILS_HAVE_NO_COPY_DT_NEEDED_ENTRIES_LINKER_FLAG
	)

	if(
		FCPPT_UTILS_HAVE_AS_NEEDED_LINKER_FLAG
	)
		list(
			APPEND
			FCPPT_UTILS_SHARED_LINKER_FLAGS
			"-Wl,--as-needed"
		)
	endif()

	if(
		FCPPT_UTILS_HAVE_NO_UNDEFINED_LINKER_FLAG
	)
		list(
			APPEND
			FCPPT_UTILS_SHARED_LINKER_FLAGS
			"-Wl,--no-undefined"
		)
	endif()

	if(
		FCPPT_UTILS_HAVE_NO_COPY_DT_NEEDED_ENTRIES_LINKER_FLAG
	)
		list(
			APPEND
			FCPPT_UTILS_SHARED_LINKER_FLAGS
			"-Wl,--no-copy-dt-needed-entries"
		)

		list(
			APPEND
			FCPPT_UTILS_EXE_LINKER_FLAGS
			"-Wl,--no-copy-dt-needed-entries"
		)
	endif()
endif()

# Ignore Boost's deprecated features
set(
	FCPPT_UTILS_COMPILE_DEFINITIONS
	"BOOST_FILESYSTEM_NO_DEPRECATED"
	"BOOST_SYSTEM_NO_DEPRECATED"
)

# configure standard CMake build paths
set(
	CMAKE_RUNTIME_OUTPUT_DIRECTORY
	${FCPPT_UTILS_PROJECT_BINARY_DIR}/bin
)

set(
	CMAKE_LIBRARY_OUTPUT_DIRECTORY
	${FCPPT_UTILS_PROJECT_BINARY_DIR}/lib
)

set(
	CMAKE_ARCHIVE_OUTPUT_DIRECTORY
	${FCPPT_UTILS_PROJECT_BINARY_DIR}/lib
)

option(
	FCPPT_UTILS_BUILD_HEADERS
	"Build header files as well. This is useful for compile_commands.json. Don't use it to do an actual build."
	FALSE
)

function(
	fcppt_utils_add_headers
	ALL_FILES
)
	foreach(
		CUR_FILE
		${ALL_FILES}
	)
		get_filename_component(
			CUR_EXT
			"${CUR_FILE}"
			EXT
		)

		if(
			"${CUR_EXT}"
			STREQUAL
			".hpp"
		)
			set(
				LANGUAGE
				"CXX"
			)
		elseif(
			"${CUR_EXT}"
			STREQUAL
			".h"
		)
			set(
				LANGUAGE
				"C"
			)
		endif()

		if(
			DEFINED LANGUAGE
		)
			set_source_files_properties(
				"${CUR_FILE}"
				PROPERTIES
				LANGUAGE
				${LANGUAGE}
			)
		endif()
	endforeach()
endfunction()

function(
	fcppt_utils_add_source_groups
	ALL_FILES
)
	foreach(
		CURFILE
		${ALL_FILES}
	)
		get_filename_component(
			REL_PATH
			"${CURFILE}"
			PATH
		)

		string(
			REPLACE
			"/"
			"\\"
			GROUPFOLDER
			"${REL_PATH}"
		)

		source_group(
			${GROUPFOLDER}
			FILES
			${CURFILE}
		)
	endforeach()

	if(
		FCPPT_UTILS_BUILD_HEADERS
	)
		fcppt_utils_add_headers(
			"${ALL_FILES}"
		)
	endif()
endfunction()

function(
	fcppt_utils_append_source_dir
	FILES
	RESULT
)
	foreach(
		CUR_FILE
		${FILES}
	)
		set(
			WHOLE_FILE
			${FCPPT_UTILS_PROJECT_SOURCE_DIR}/${CUR_FILE}
		)

		list(
			APPEND
			${RESULT}
			${WHOLE_FILE}
		)
	endforeach()

	set(
		${RESULT}
		${${RESULT}}
		PARENT_SCOPE
	)
endfunction()

function(
	fcppt_utils_append_source_dir_and_make_groups
	FILES
	RESULT
)
	foreach(
		CUR_FILE
		${FILES}
	)
		set(
			WHOLE_FILE
			${FCPPT_UTILS_PROJECT_SOURCE_DIR}/${CUR_FILE}
		)

		get_filename_component(
			REL_PATH
			${CUR_FILE}
			DIRECTORY
		)

		string(
			REPLACE
			"/"
			"\\"
			GROUPFOLDER
			"${REL_PATH}"
		)

		source_group(
			${GROUPFOLDER}
			FILES
			${WHOLE_FILE}
		)

		list(
			APPEND
			TEMP_RESULT
			${WHOLE_FILE}
		)
	endforeach()

	set(
		${RESULT}
		"${TEMP_RESULT}"
		PARENT_SCOPE
	)

	if(
		FCPPT_UTILS_BUILD_HEADERS
	)
		fcppt_utils_add_headers(
			"${TEMP_RESULT}"
		)
	endif()
endfunction()

set(
	FCPPT_UTILS_EXPORT_NAME
	"${PROJECT_NAME}Export"
)

function(
	fcppt_utils_export_install_target
	TARGETNAME
)
	install(
		TARGETS
		${TARGETNAME}
		DESTINATION
		"${CMAKE_INSTALL_LIBDIR}"
		EXPORT
		"${FCPPT_UTILS_EXPORT_NAME}"
	)
endfunction()

# CONFIG_PATH : PATH
# - The path where the ${PROJECT_NAME}-config.cmake.in resides.
# [MODULES_PATH : PATH]
# - The path that is appended to CMAKE_MODULE_PATH.
function(
	fcppt_utils_generate_config
)
	set(
		SINGLE_ARGS
		CONFIG_PATH
		MODULES_PATH
	)

	cmake_parse_arguments(
		""
		""
		"${SINGLE_ARGS}"
		""
		${ARGN}
	)

	if(
		NOT
		"${_UNPARSED_ARGUMENTS}"
		STREQUAL
		""
	)
		message(
			FATAL_ERROR
			"Invalid parameters ${_UNPARSED_ARGUMENTS}"
		)
	endif()

	if(
		"${_CONFIG_PATH}"
		STREQUAL
		""
	)
		message(
			FATAL_ERROR
			"Missing CONFIG_PATH argument."
		)
	endif()

	set(
		CONFIG_NAME
		"${PROJECT_NAME}-config.cmake"
	)

	set(
		CONFIG_IN_FILE
		"${_CONFIG_PATH}/${CONFIG_NAME}.in"
	)

	set(
		BUILD_CONFIG_DIR
		"${FCPPT_UTILS_PROJECT_BINARY_DIR}/config"
	)

	set(
		TARGETS_FILE_NAME
		"${PROJECT_NAME}Targets.cmake"
	)

	#Build config
	set(
		ADDITIONAL_MODULE_PATH
		${_MODULES_PATH}
	)

	configure_file(
		${CONFIG_IN_FILE}
		"${BUILD_CONFIG_DIR}/${CONFIG_NAME}"
		@ONLY
	)

	export(
		EXPORT
		"${FCPPT_UTILS_EXPORT_NAME}"
		FILE
		"${BUILD_CONFIG_DIR}/${TARGETS_FILE_NAME}"
	)

	#Install config
	set(
		ADDITIONAL_MODULE_PATH
		${FCPPT_UTILS_INSTALL_FULL_CMAKEMODULES_DIR}
	)

	set(
		CONFIG_DEST_INSTALL
		"${BUILD_CONFIG_DIR}_install/${CONFIG_NAME}"
	)

	configure_file(
		${CONFIG_IN_FILE}
		${CONFIG_DEST_INSTALL}
		@ONLY
	)

	install(
		FILES
		"${CONFIG_DEST_INSTALL}"
		DESTINATION
		"${FCPPT_UTILS_INSTALL_CMAKECONFIG_DIR}"
	)

	install(
		EXPORT
		"${FCPPT_UTILS_EXPORT_NAME}"
		FILE
		"${TARGETS_FILE_NAME}"
		DESTINATION
		"${FCPPT_UTILS_INSTALL_CMAKECONFIG_DIR}"
	)
endfunction()

function(
	fcppt_utils_handle_so_version
	CACHE_VAR
	OUT_VAR
	DEFAULT_VERSION
)
	set(
		"${CACHE_VAR}"
		""
		CACHE
		STRING
		"The custom .so version to use. If empty, the default will be used."
	)

	if(
		"${${CACHE_VAR}}"
		STREQUAL
		""
	)
		set(
			"${OUT_VAR}"
			"${DEFAULT_VERSION}"
			PARENT_SCOPE
		)
	else()
		set(
			"${OUT_VAR}"
			"${${CACHE_VAR}}"
			PARENT_SCOPE
		)
	endif()
endfunction()

function(
	fcppt_utils_add_dummy_target
	TARGET_NAME
	TARGET_FILES
)
	set(
		MULTI_ARGS
		INCLUDE_DIRS
		LINK_LIBS
	)

	cmake_parse_arguments(
		""
		""
		""
		"${MULTI_ARGS}"
		${ARGN}
	)

	if(
		NOT
		"${_UNPARSED_ARGUMENTS}"
		STREQUAL
		""
	)
		message(
			FATAL_ERROR
			"Invalid parameters ${_UNPARSED_ARGUMENTS}"
		)
	endif()


	set(
		LIBNAME
		"${TARGET_NAME}_dummy"
	)

	add_library(
		"${LIBNAME}"
		STATIC
		${TARGET_FILES}
	)

	set_target_properties(
		"${LIBNAME}"
		PROPERTIES
		LINKER_LANGUAGE
		"CXX"
	)

	target_include_directories(
		${LIBNAME}
		PRIVATE
		${_INCLUDE_DIRS}
	)

	target_link_libraries(
		${LIBNAME}
		PRIVATE
		${_LINK_LIBS}
	)
endfunction()

function(
	fcppt_utils_set_target_compiler_flags
	TARGET_NAME
)
	set(
		MULTI_ARGS
		ADDITIONAL_FLAGS
	)

	cmake_parse_arguments(
		""
		""
		""
		"${MULTI_ARGS}"
		${ARGN}
	)

	target_compile_definitions(
		${TARGET_NAME}
		PRIVATE
		${FCPPT_UTILS_COMPILE_DEFINITIONS}
	)

	target_compile_options(
		${TARGET_NAME}
		PRIVATE
		${FCPPT_UTILS_COMPILE_OPTIONS}
		${_ADDITIONAL_FLAGS}
	)

	set_target_properties(
		${TARGET_NAME}
		PROPERTIES
		CXX_EXTENSIONS
			FALSE
		CXX_STANDARD
			14
		CXX_STANDARD_REQUIRED
			14
		NO_SYSTEM_FROM_IMPORTED
			TRUE
	)

	get_target_property(
		TARGET_TYPE
		${TARGET_NAME}
		TYPE
	)

	if(
		${TARGET_TYPE}
		STREQUAL
		"SHARED_LIBRARY"
	)
		target_link_libraries(
			${TARGET_NAME}
			PRIVATE
			${FCPPT_UTILS_SHARED_LINKER_FLAGS}
		)
	endif()

	if(
		${TARGET_TYPE}
		STREQUAL
		"EXECUTABLE"
	)
		target_link_libraries(
			${TARGET_NAME}
			PRIVATE
			${FCPPT_UTILS_EXE_LINKER_FLAGS}
		)
	endif()
endfunction()

function(
	fcppt_utils_static_shared
)
	option(
		ENABLE_SHARED
		"Build shared libraries"
		ON
	)

	option(
		ENABLE_STATIC
		"Build static libraries"
		OFF
	)

	if(
		NOT ENABLE_SHARED AND NOT ENABLE_STATIC
	)
		message(
			FATAL_ERROR
			"You disabled both STATIC and SHARED"
		)
	endif()

	if(
		ENABLE_STATIC
	)
		set(
			FCPPT_UTILS_DEFAULT_LINK_STATIC
			TRUE
			PARENT_SCOPE
		)
	endif()

	# shared overrides static
	if(
		ENABLE_SHARED
	)
		set(
			FCPPT_UTILS_DEFAULT_LINK_STATIC
			FALSE
			PARENT_SCOPE
		)
	endif()
endfunction()

function(
	fcppt_utils_static_link_name
	LIBNAME
	RESULT
)
	set(
		${RESULT}
		${LIBNAME}_static
		PARENT_SCOPE
	)
endfunction()

function(
	fcppt_utils_interface_link_name
	LIBNAME
	RESULT
)
	set(
		${RESULT}
		${LIBNAME}_interface
		PARENT_SCOPE
	)
endfunction()

function(
	fcppt_utils_link_target
	LIBNAME
)
	set(
		TARGET_NAME
		${LIBNAME}_TARGET
	)

	if(
		FCPPT_UTILS_DEFAULT_LINK_STATIC
	)
		fcppt_utils_static_link_name(
			${LIBNAME}
			STATIC_NAME
		)

		set(
			${TARGET_NAME}
			${STATIC_NAME}
			PARENT_SCOPE
		)
	else()
		set(
			${TARGET_NAME}
			${LIBNAME}
			PARENT_SCOPE
		)
	endif()
endfunction()


function(
	fcppt_utils_interface_static_link
	TARGET_NAME
	VARIANT
	LINK_FLAG
)
	if(
		${VARIANT} STREQUAL "STATIC"
	)
		target_compile_definitions(
			${TARGET_NAME}
			PUBLIC
			${LINK_FLAG}
		)
	endif()
endfunction()

function(
	fcppt_utils_set_target_folder
	TARGET_NAME
	PREFIX
	PATH_NAME
)
	string(
		FIND
		${PATH_NAME}
		"/"
		LAST_PART
		REVERSE
	)

	if(
		NOT
		LAST_PART
		EQUAL
		-1
	)
		string(
			SUBSTRING
			${PATH_NAME}
			0
			${LAST_PART}
			FOLDER_NAME
		)

		set(
			FOLDER_NAME
			"/${FOLDER_NAME}"
		)
	endif()

	set_target_properties(
		${TARGET_NAME}
		PROPERTIES
		FOLDER
		${PROJECT_NAME}/${PREFIX}${FOLDER_NAME}
	)
endfunction()

option(
	FCPPT_UTILS_CATCH_LINK_STATIC
	"Link to catch statically"
	OFF
)

function(
	fcppt_utils_setup_tests
)
	find_package(
		Catch2
		CONFIG
		REQUIRED
	)

	set(
		FCPPT_UTILS_CATCH_FILE_TEMP
		${FCPPT_UTILS_PROJECT_BINARY_DIR}/catch_main_temp.cpp
	)

	set(
		FCPPT_UTILS_CATCH_FILE
		${FCPPT_UTILS_PROJECT_BINARY_DIR}/catch_main.cpp
	)

	file(
		WRITE
		${FCPPT_UTILS_CATCH_FILE_TEMP}
		"#define CATCH_CONFIG_MAIN
#include <catch.hpp>"
	)

	configure_file(
		${FCPPT_UTILS_CATCH_FILE_TEMP}
		${FCPPT_UTILS_CATCH_FILE}
	)

	if(
		FCPPT_UTILS_CATCH_LINK_STATIC
	)
		set(
			FCPPT_UTILS_CATCH_LIB_TYPE
			"STATIC"
		)

		message(
			WARNING
			"Linking to Catch statically will drastically increase the size of each test case"
		)
	else()
		set(
			FCPPT_UTILS_CATCH_LIB_TYPE
			"SHARED"
		)
	endif()

	find_package(
		Catch2
		REQUIRED
	)

	if(
		NOT TARGET
		fcppt_utils_catch_main
	)
		add_library(
			fcppt_utils_catch_main
			${FCPPT_UTILS_CATCH_LIB_TYPE}
			${FCPPT_UTILS_CATCH_FILE}
		)

		set_target_properties(
			fcppt_utils_catch_main
			PROPERTIES
			CXX_STANDARD
			11
			CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS
			ON
			FOLDER
			fcppt
		)

		target_link_libraries(
			fcppt_utils_catch_main
			PRIVATE
			Catch2::Catch2
		)
	endif()
endfunction()

function(
	fcppt_utils_add_test
	TEST_DIR
	PATH_NAME
)
	set(
		OPTION_ARGS
		NO_CODE
	)

	set(
		MULTI_ARGS
		LINK_LIBS
		INCLUDE_DIRS
	)

	cmake_parse_arguments(
		""
		"${OPTION_ARGS}"
		""
		"${MULTI_ARGS}"
		${ARGN}
	)

	string(
		REPLACE
		"/"
		"_"
		TEST_NAME
		${PATH_NAME}
	)

	set(
		FULL_TEST_NAME
		${PROJECT_NAME}_test_${TEST_NAME}
	)

	add_executable(
		${FULL_TEST_NAME}
		${TEST_DIR}/${PATH_NAME}.cpp
	)

	fcppt_utils_set_target_folder(
		${FULL_TEST_NAME}
		tests
		${PATH_NAME}
	)

	fcppt_utils_set_target_compiler_flags(
		${FULL_TEST_NAME}
	)

	target_include_directories(
		${FULL_TEST_NAME}
		PRIVATE
		${_INCLUDE_DIRS}
	)

	target_link_libraries(
		${FULL_TEST_NAME}
		PRIVATE
		${_LINK_LIBS}
	)

	if(
		NOT ${_NO_CODE}
	)
		target_link_libraries(
			${FULL_TEST_NAME}
			PRIVATE
			fcppt_utils_catch_main
			Catch2::Catch2
		)

		add_test(
			NAME
			${TEST_NAME}
			COMMAND
			${FULL_TEST_NAME}
		)
	endif()
endfunction()

function(
	fcppt_utils_add_example
	EXAMPLE_DIR
	PATH_NAME
)
	set(
		OPTION_ARGS
		IS_C
	)

	set(
		MULTI_ARGS
		LINK_LIBS
		INCLUDE_DIRS
		COMPILE_DEFINITIONS
		COMPILE_OPTIONS
	)

	cmake_parse_arguments(
		""
		"${OPTION_ARGS}"
		""
		"${MULTI_ARGS}"
		${ARGN}
	)

	string(
		REPLACE
		"/"
		"_"
		EXAMPLE_NAME
		${PATH_NAME}
	)

	set(
		FULL_EXAMPLE_NAME
		${PROJECT_NAME}_example_${EXAMPLE_NAME}
	)

	if(
		${_IS_C}
	)
		set(
			SUFFIX
			"c"
		)
	else()
		set(
			SUFFIX
			"cpp"
		)
	endif()

	add_executable(
		${FULL_EXAMPLE_NAME}
		${EXAMPLE_DIR}/${PATH_NAME}.${SUFFIX}
	)

	fcppt_utils_set_target_folder(
		${FULL_EXAMPLE_NAME}
		examples
		${PATH_NAME}
	)

	target_compile_definitions(
		${FULL_EXAMPLE_NAME}
		PRIVATE
		${_COMPILE_DEFINITIONS}
	)

	target_compile_options(
		${FULL_EXAMPLE_NAME}
		PRIVATE
		${_COMPILE_OPTIONS}
	)

	target_include_directories(
		${FULL_EXAMPLE_NAME}
		PRIVATE
		${_INCLUDE_DIRS}
	)

	if(
		NOT _IS_C
	)
		fcppt_utils_set_target_compiler_flags(
			${FULL_EXAMPLE_NAME}
		)
	endif()

	target_link_libraries(
		${FULL_EXAMPLE_NAME}
		PRIVATE
		${_LINK_LIBS}
	)
endfunction()

function(
	fcppt_utils_link_imported_target_single
	TARGET_NAME
	VISIBILITY
	PKGCONFIG_NAME
)
	get_target_property(
		INCLUDE_DIRS
		${PKGCONFIG_NAME}
		INTERFACE_INCLUDE_DIRECTORIES
	)

	if(
		NOT
		"${INCLUDE_DIRS}"
		STREQUAL
		"INCLUDE_DIRS-NOTFOUND"
	)
		target_include_directories(
			${TARGET_NAME}
			${VISIBILITY}
			${INCLUDE_DIRS}
		)
	endif()

	get_target_property(
		LINK_LIBRARIES
		${PKGCONFIG_NAME}
		INTERFACE_LINK_LIBRARIES
	)

	if(
		NOT
		"${LINK_LIBRARIES}"
		STREQUAL
		"LINK_LIBRARIES-NOTFOUND"
	)
		target_link_libraries(
			${TARGET_NAME}
			${VISIBILITY}
			${LINK_LIBRARIES}
		)
	endif()

	get_target_property(
		COMPILE_OPTIONS
		${PKGCONFIG_NAME}
		INTERFACE_COMPILE_OPTIONS
	)

	if(
		NOT
		"${COMPILE_OPTIONS}"
		STREQUAL
		"COMPILE_OPTIONS-NOTFOUND"
	)
		target_compile_options(
			${TARGET_NAME}
			${VISIBILITY}
			${COMPILE_OPTIONS}
		)
	endif()
endfunction()

function(
	fcppt_utils_link_imported_targets
	TARGET_NAME
	VISIBILITY
)
	foreach(
		CURNAME
		${ARGN}
	)
		fcppt_utils_link_imported_target_single(
			${TARGET_NAME}
			${VISIBILITY}
			${CURNAME}
		)
	endforeach()
endfunction()
