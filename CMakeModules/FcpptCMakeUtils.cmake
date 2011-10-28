SET (CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)

#Disallow in source builds everywhere
IF(${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
	message(FATAL_ERROR "In-source builds are not permitted. Make a separate folder for building:\nmkdir build; cd build; cmake ..\nBefore that, remove the files that cmake just created:\nrm -rf CMakeCache.txt CMakeFiles")
ENDIF()

#Has to be kept in sync with boost releases
SET(
	Boost_ADDITIONAL_VERSIONS
	"1.41" "1.41.0" "1.42" "1.42.0" "1.43" "1.43.0" "1.44" "1.44.0" "1.45" "1.45.0" "1.46" "1.46.0" "1.46.1" "1.47" "1.47.0" "1.48" "1.48.0"
)

# Setup default compiler flags
INCLUDE(CMakeDetermineCXXCompiler)
INCLUDE(CheckCXXCompilerFlag)

# Define locations for installations
# These don't have an FCPPT_ prefix because they have to be set by the user

SET(
	INSTALL_BINARY_DIR
	"${CMAKE_INSTALL_PREFIX}/bin"
	CACHE
	STRING
	"Custom binary installation directory"
)

SET(
	INSTALL_LIBRARY_DIR
	"${CMAKE_INSTALL_PREFIX}/lib"
	CACHE
	STRING
	"Custom library installation directory"
)

SET(
	INSTALL_INCLUDE_DIR
	"${CMAKE_INSTALL_PREFIX}/include"
	CACHE
	STRING
	"Custom include installation directory"
)

SET(
	INSTALL_DATA_DIR_BASE
	"${CMAKE_INSTALL_PREFIX}/share"
	CACHE
	STRING
	"Custom data installation directory without suffixes"
)

SET(
	INSTALL_DATA_DIR
	"${INSTALL_DATA_DIR_BASE}/${CMAKE_PROJECT_NAME}"
	CACHE
	STRING
	"Custom data installation directory"
)

SET(
	INSTALL_DOC_DIR_BASE
	"${INSTALL_DATA_DIR_BASE}/doc"
	CACHE
	STRING
	"Custom doc installation directory without suffixes"
)

SET(
	INSTALL_DOC_DIR
	"${INSTALL_DOC_DIR_BASE}/${CMAKE_PROJECT_NAME}"
	CACHE
	STRING
	"Custom doc installation directory"
)

SET(
	INSTALL_PKGCONFIG_DIR
	"${INSTALL_LIBRARY_DIR}/pkgconfig"
	CACHE
	STRING
	"Custom pkgconfig installation directory"
)

SET(
	FCPPT_UTILS_CURRENT_DIRECTORY
	"${CMAKE_ROOT}"
)

SET(
	FCPPT_UTILS_INSTALL_PREFIX_IS_PREFIX_OF_CMAKE_ROOT
	FALSE
)

SET(
	FCPPT_UTILS_LOOP_VAR
	TRUE
)

WHILE(
	FCPPT_UTILS_LOOP_VAR
)
	IF(
		"${CMAKE_INSTALL_PREFIX}"
		STREQUAL "${FCPPT_UTILS_CURRENT_DIRECTORY}"
	)
		SET(
			FCPPT_UTILS_INSTALL_PREFIX_IS_PREFIX_OF_CMAKE_ROOT
			TRUE
		)

		BREAK()
	ENDIF()

	GET_FILENAME_COMPONENT(
		FCPPT_UTILS_NEW_CURRENT_DIRECTORY
		"${FCPPT_UTILS_CURRENT_DIRECTORY}"
		PATH
	)

	IF(
		"${FCPPT_UTILS_NEW_CURRENT_DIRECTORY}"
		STREQUAL
		"${FCPPT_UTILS_CURRENT_DIRECTORY}"
	)
		BREAK()
	ENDIF()

	SET(
		FCPPT_UTILS_CURRENT_DIRECTORY
		"${FCPPT_UTILS_NEW_CURRENT_DIRECTORY}"
	)
ENDWHILE()

UNSET(
	FCPPT_UTILS_CURRENT_DIRECTORY
)

UNSET(
	FCPPT_UTILS_NEW_CURRENT_DIRECTORY
)

UNSET(
	FCPPT_UTILS_LOOP_VAR
)

IF(
	FCPPT_UTILS_INSTALL_PREFIX_IS_PREFIX_OF_CMAKE_ROOT
)
	SET(
		FCPPT_UTILS_CMAKE_MODULE_DIR
		"${CMAKE_ROOT}/Modules"
	)
ELSE()
	SET(
		FCPPT_UTILS_CMAKE_MODULE_DIR
		"${INSTALL_DATA_DIR_BASE}/cmake/Modules"
	)
ENDIF()

SET(
	INSTALL_CMAKEMODULES_DIR
	"${FCPPT_UTILS_CMAKE_MODULE_DIR}"
	CACHE
	STRING
	"Custom cmake module installation directory"
)

SET(
	INSTALL_CMAKECONFIG_DIR_BASE
	"${INSTALL_LIBRARY_DIR}/cmake"
	CACHE
	STRING
	"Custom cmake config installation directory without suffixes"
)

SET(
	INSTALL_CMAKECONFIG_DIR
	"${INSTALL_CMAKECONFIG_DIR_BASE}/${CMAKE_PROJECT_NAME}"
	CACHE
	STRING
	"Custom cmake module installation directory"
)

SET(
	INSTALL_SYSCONFIG_DIR_BASE
	"${CMAKE_INSTALL_PREFIX}/etc"
	CACHE
	STRING
	"Custom config installation directory"
)

# cmake-2.8.3 is required for this to work
IF(
	"${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang"
)
	SET(
		FCPPT_UTILS_COMPILER_IS_CLANGPP ON
	)
ENDIF()

IF(
	CMAKE_COMPILER_IS_GNUCXX OR FCPPT_UTILS_COMPILER_IS_CLANGPP
)
	SET(
		CMAKE_CXX_FLAGS_RELEASE
		"-O3 -fomit-frame-pointer -DNDEBUG"
	)

	# we need -fPIC for libraries on AMD64
	IF("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86_64")
		ADD_DEFINITIONS(
			"-fPIC"
		)
	ENDIF()

	# cmake tries to grep for warning messages which will fail in a lot of cases
	SET(
		CMAKE_REQUIRED_FLAGS_BASE "-Wall -Werror -pedantic"
	)

	SET(
		CMAKE_REQUIRED_FLAGS ${CMAKE_REQUIRED_FLAGS_BASE}
	)

	CHECK_CXX_COMPILER_FLAG(
		"-fvisibility=hidden"
		FCPPT_UTILS_HAVE_GCC_VISIBILITY
	)

	CHECK_CXX_COMPILER_FLAG(
		"-Wdouble-promotion"
		FCPPT_UTILS_HAVE_DOUBLE_PROMOTION_FLAG
	)

	CHECK_CXX_COMPILER_FLAG(
		"-Wlogical-op"
		FCPPT_UTILS_HAVE_LOGICAL_OP_FLAG
	)

	CHECK_CXX_COMPILER_FLAG(
		"-Wmissing-declarations"
		FCPPT_UTILS_HAVE_MISSING_DECLARATIONS_FLAG
	)

	CHECK_CXX_COMPILER_FLAG(
		"-Wsign-conversion"
		FCPPT_UTILS_HAVE_SIGN_CONVERSION_FLAG
	)

	# To check for linker flags, CMAKE_REQUIRED_FLAGS has to be expanded
	FUNCTION(
		FCPPT_CHECK_GCC_LINKER_FLAG
		FLAG
		VARIABLE
	)
		SET(
			CMAKE_REQUIRED_FLAGS
			"${CMAKE_REQUIRED_FLAGS_BASE} ${FLAG}"
		)

		CHECK_CXX_COMPILER_FLAG(
			""
			${VARIABLE}
		)
	ENDFUNCTION()

	FCPPT_CHECK_GCC_LINKER_FLAG(
		"-Wl,--as-needed"
		FCPPT_UTILS_HAVE_AS_NEEDED_LINKER_FLAG
	)

	FCPPT_CHECK_GCC_LINKER_FLAG(
		"-Wl,--no-undefined"
		FCPPT_UTILS_HAVE_NO_UNDEFINED_LINKER_FLAG
	)

	FCPPT_CHECK_GCC_LINKER_FLAG(
		"-Wl,--no-copy-dt-needed-entries"
		FCPPT_UTILS_HAVE_NO_COPY_DT_NEEDED_ENTRIES_LINKER_FLAG
	)

	UNSET(CMAKE_REQUIRED_FLAGS)

	# activate common warning options
	# use -Wno-long-long because too much stuff uses it
	ADD_DEFINITIONS (
		"-ansi -pedantic-errors -Wall -Wextra -Wconversion"
		"-Wfloat-equal -Wredundant-decls -Wuninitialized -Winit-self"
		"-Woverloaded-virtual -Wnon-virtual-dtor -Wshadow"
		"-Wsign-promo -Wstrict-aliasing=1 -Wold-style-cast"
		"-Wcast-qual -Wcast-align -Wno-long-long"
		#currently, -Wundef cannot be disabled via a pragma
	)

	IF(FCPPT_UTILS_HAVE_DOUBLE_PROMOTION_FLAG)
		ADD_DEFINITIONS ("-Wdouble-promotion")
	ENDIF()

	IF(FCPPT_UTILS_HAVE_LOGICAL_OP_FLAG)
		ADD_DEFINITIONS ("-Wlogical-op")
	ENDIF()

	IF(FCPPT_UTILS_HAVE_MISSING_DECLARATIONS_FLAG)
		ADD_DEFINITIONS ("-Wmissing-declarations")
	ENDIF()

	IF(FCPPT_UTILS_HAVE_SIGN_CONVERSION_FLAG)
		ADD_DEFINITIONS ("-Wsign-conversion")
	ENDIF()

	IF(FCPPT_UTILS_HAVE_GCC_VISIBILITY)
		OPTION(
			FCPPT_ENABLE_VISIBILITY_HIDDEN
			"Enable -fvisbility=hidden"
			TRUE
		)

		IF(FCPPT_ENABLE_VISIBILITY_HIDDEN)
			ADD_DEFINITIONS ("-fvisibility=hidden")
		ENDIF()
	ENDIF()

	IF(FCPPT_UTILS_HAVE_AS_NEEDED_LINKER_FLAG)
		SET(
			CMAKE_SHARED_LINKER_FLAGS
			"-Wl,--as-needed ${CMAKE_SHARED_LINKER_FLAGS}"
		)
	ENDIF()

	IF(FCPPT_UTILS_HAVE_NO_UNDEFINED_LINKER_FLAG)
		SET(
			CMAKE_SHARED_LINKER_FLAGS
			"-Wl,--no-undefined ${CMAKE_SHARED_LINKER_FLAGS}"
		)
	ENDIF()

	IF(FCPPT_UTILS_HAVE_NO_COPY_DT_NEEDED_ENTRIES_LINKER_FLAG)
		SET(
			CMAKE_SHARED_LINKER_FLAGS
			"-Wl,--no-copy-dt-needed-entries ${CMAKE_SHARED_LINKER_FLAGS}"
		)
		SET(
			CMAKE_EXE_LINKER_FLAGS
			"-Wl,--no-copy-dt-needed-entries ${CMAKE_EXE_LINKER_FLAGS}"
		)
	ENDIF()
ELSEIF(
	MSVC
)
	ADD_DEFINITIONS(
		"/W4 /Wall /EHa /D_BIND_TO_CURRENT_VCLIBS_VERSION=1"
		" /wd4996 /wd4061 /wd4350 /wd4371 /wd4503 /wd4514 /wd4710 /wd4711 /wd4738 /wd4820"
	)

	# /W4 warnings
	#4996 - unsafe standard C++ functions

	# /Wall warnings
	#4061 - warning for not handled cases in switchs even with default
	#4350 - behaviour change due to implicit conversions (needed for unique_ptr)
	#4371 - layout of class may have changed from previous compiler version
	#4503 - decorated name length exceeded
	#4514 - unreferenced inline function removed
	#4710 - function not inlined
	#4711 - function selected for automatic inline expansion
	#4738 - storing 32-bit float result in memory
	#4820 - byte padding after data members
ENDIF()

# configure standard CMake build paths
SET(
	EXECUTABLE_OUTPUT_PATH
	${CMAKE_BINARY_DIR}/bin
)

SET(
	LIBRARY_OUTPUT_PATH
	${CMAKE_BINARY_DIR}/lib
)

#macro for adding source groups
MACRO(
	FCPPT_UTILS_ADD_SOURCE_GROUPS
	ALL_FILES
)
	FOREACH(
		CURFILE
		${ALL_FILES}
	)
		GET_FILENAME_COMPONENT(
			REL_PATH
			"${CURFILE}"
			PATH
		)

		STRING(REPLACE "/" "\\" GROUPFOLDER ${REL_PATH})

		SOURCE_GROUP(
			${GROUPFOLDER}
			FILES
			${CURFILE}
		)
	ENDFOREACH()
ENDMACRO()

MACRO(
	FCPPT_UTILS_APPEND_SOURCE_DIR_AND_MAKE_GROUPS
	FILES
	RESULT
)
	UNSET(
		TEMP_RESULT
	)

	FOREACH(
		CUR_FILE
		${FILES}
	)
		SET(
			WHOLE_FILE
			${CMAKE_SOURCE_DIR}/${CUR_FILE}
		)

		GET_FILENAME_COMPONENT(
			REL_PATH
			${CUR_FILE}
			PATH
		)

		STRING(REPLACE "/" "\\" GROUPFOLDER ${REL_PATH})

		SOURCE_GROUP(
			${GROUPFOLDER}
			FILES
			${WHOLE_FILE}
		)

		SET(
			TEMP_RESULT
			${TEMP_RESULT}
			${WHOLE_FILE}
		)
	ENDFOREACH()

	SET(
		${RESULT}
		"${${RESULT}};${TEMP_RESULT}"
	)
ENDMACRO()
