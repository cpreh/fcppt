SET (CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)

#Disallow in source builds everywhere
IF(${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
	message(FATAL_ERROR "In-source builds are not permitted. Make a separate folder for building:\nmkdir build; cd build; cmake ..\nBefore that, remove the files that cmake just created:\nrm -rf CMakeCache.txt CMakeFiles")
ENDIF()

#Has to be kept in sync with boost releases
SET(
	Boost_ADDITIONAL_VERSIONS
	"1.41" "1.41.0" "1.42" "1.42.0" "1.43" "1.43.0" "1.44" "1.44.0" "1.45" "1.45.0" "1.46" "1.46.0" "1.46.1"
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
		"-Wfloat-equal -Wredundant-decls -Winit-self"
		"-Woverloaded-virtual -Wnon-virtual-dtor -Wshadow"
		"-Wsign-promo -Wstrict-aliasing=1 -Wold-style-cast"
		"-Wno-long-long"
	)

	IF(FCPPT_UTILS_HAVE_MISSING_DECLARATIONS_FLAG)
		ADD_DEFINITIONS ("-Wmissing-declarations")
	ENDIF()

	IF(FCPPT_UTILS_HAVE_SIGN_CONVERSION_FLAG)
		ADD_DEFINITIONS ("-Wsign-conversion")
	ENDIF()

	IF(FCPPT_UTILS_HAVE_GCC_VISIBILITY)
		ADD_DEFINITIONS ("-fvisibility=hidden")
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
	ADD_DEFINITIONS ("/W4 /wd4996 /EHa /D_BIND_TO_CURRENT_VCLIBS_VERSION=1")
	#4996 - unsafe standard C++ functions
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
