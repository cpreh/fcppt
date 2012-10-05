set(
	CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS
	ON
)

#Disallow in source builds everywhere
if(
	${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR}
)
	message(
		FATAL_ERROR
		"In-source builds are not permitted. Make a separate folder for building:\nmkdir build; cd build; cmake ..\nBefore that, remove the files that cmake just created:\nrm -rf CMakeCache.txt CMakeFiles"
	)
endif()

include(
	CMakeDetermineCXXCompiler
)

include(
	CheckCXXCompilerFlag
)

# Define locations for installations
# These don't have an FCPPT_ prefix because they have to be set by the user

set(
	INSTALL_BINARY_DIR
	"${CMAKE_INSTALL_PREFIX}/bin"
	CACHE
	STRING
	"Custom binary installation directory"
)

# Some distributions set CMAKE_INSTALL_LIBDIR to handle multilib. Also, some of
# them use an absolute path, some use a relative path. We have chosen an
# absolute path here, so please change it in the build if your distribution is
# using relative paths.
if(
	"${CMAKE_INSTALL_LIBDIR}"
	STREQUAL
	""
)
	set(
		FCPPT_UTILS_DEFAULT_INSTALL_LIB_DIR
		"${CMAKE_INSTALL_PREFIX}/lib"
	)
else()
	set(
		FCPPT_UTILS_DEFAULT_INSTALL_LIB_DIR
		"${CMAKE_INSTALL_LIBDIR}"
	)
endif()

set(
	INSTALL_LIBRARY_DIR
	"${FCPPT_UTILS_DEFAULT_INSTALL_LIB_DIR}"
	CACHE
	STRING
	"Custom library installation directory"
)

set(
	INSTALL_INCLUDE_DIR
	"${CMAKE_INSTALL_PREFIX}/include"
	CACHE
	STRING
	"Custom include installation directory"
)

set(
	INSTALL_DATA_DIR_BASE
	"${CMAKE_INSTALL_PREFIX}/share"
	CACHE
	STRING
	"Custom data installation directory without suffixes"
)

set(
	INSTALL_DATA_DIR
	"${INSTALL_DATA_DIR_BASE}/${CMAKE_PROJECT_NAME}"
	CACHE
	STRING
	"Custom data installation directory"
)

set(
	INSTALL_DOC_DIR_BASE
	"${INSTALL_DATA_DIR_BASE}/doc"
	CACHE
	STRING
	"Custom doc installation directory without suffixes"
)

set(
	INSTALL_DOC_DIR
	"${INSTALL_DOC_DIR_BASE}/${CMAKE_PROJECT_NAME}"
	CACHE
	STRING
	"Custom doc installation directory"
)

set(
	INSTALL_PKGCONFIG_DIR
	"${INSTALL_LIBRARY_DIR}/pkgconfig"
	CACHE
	STRING
	"Custom pkgconfig installation directory"
)

set(
	FCPPT_UTILS_CURRENT_DIRECTORY
	"${CMAKE_ROOT}"
)

set(
	FCPPT_UTILS_INSTALL_PREFIX_IS_PREFIX_OF_CMAKE_ROOT
	FALSE
)

set(
	FCPPT_UTILS_LOOP_VAR
	TRUE
)

while(
	FCPPT_UTILS_LOOP_VAR
)
	if(
		"${CMAKE_INSTALL_PREFIX}"
		STREQUAL "${FCPPT_UTILS_CURRENT_DIRECTORY}"
	)
		set(
			FCPPT_UTILS_INSTALL_PREFIX_IS_PREFIX_OF_CMAKE_ROOT
			TRUE
		)

		break()
	endif()

	get_filename_component(
		FCPPT_UTILS_NEW_CURRENT_DIRECTORY
		"${FCPPT_UTILS_CURRENT_DIRECTORY}"
		PATH
	)

	if(
		"${FCPPT_UTILS_NEW_CURRENT_DIRECTORY}"
		STREQUAL
		"${FCPPT_UTILS_CURRENT_DIRECTORY}"
	)
		break()
	endif()

	set(
		FCPPT_UTILS_CURRENT_DIRECTORY
		"${FCPPT_UTILS_NEW_CURRENT_DIRECTORY}"
	)
endwhile()

unset(
	FCPPT_UTILS_CURRENT_DIRECTORY
)

unset(
	FCPPT_UTILS_NEW_CURRENT_DIRECTORY
)

unset(
	FCPPT_UTILS_LOOP_VAR
)

if(
	FCPPT_UTILS_INSTALL_PREFIX_IS_PREFIX_OF_CMAKE_ROOT
)
	set(
		FCPPT_UTILS_CMAKE_MODULE_DIR
		"${CMAKE_ROOT}/Modules"
	)
else()
	set(
		FCPPT_UTILS_CMAKE_MODULE_DIR
		"${INSTALL_DATA_DIR_BASE}/cmake/Modules"
	)
endif()

set(
	INSTALL_CMAKEMODULES_DIR
	"${FCPPT_UTILS_CMAKE_MODULE_DIR}"
	CACHE
	STRING
	"Custom cmake module installation directory"
)

set(
	INSTALL_CMAKECONFIG_DIR_BASE
	"${INSTALL_LIBRARY_DIR}/cmake"
	CACHE
	STRING
	"Custom cmake config installation directory without suffixes"
)

set(
	INSTALL_CMAKECONFIG_DIR
	"${INSTALL_CMAKECONFIG_DIR_BASE}/${CMAKE_PROJECT_NAME}"
	CACHE
	STRING
	"Custom cmake module installation directory"
)

set(
	INSTALL_SYSCONFIG_DIR_BASE
	"${CMAKE_INSTALL_PREFIX}/etc"
	CACHE
	STRING
	"Custom config installation directory"
)

option(
	FCPPT_ENABLE_CPP11
	"Enable C++11 support."
	FALSE
)

# cmake-2.8.3 is required for this to work
if(
	"${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang"
)
	set(
		FCPPT_UTILS_COMPILER_IS_CLANGPP ON
	)
endif()

if(
	"${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel"
)
	set(
		FCPPT_UTILS_COMPILER_IS_INTELCPP ON
	)
endif()

set(
	FCPPT_UTILS_GCC_ICC_CLANG_COMMON_OPTIONS
	"-Wall -Wextra -Wconversion"
	"-Wuninitialized "
	"-Woverloaded-virtual -Wnon-virtual-dtor -Wshadow"
	"-Wstrict-aliasing=1"
	"-Wcast-qual"
	#currently, -Wundef cannot be disabled via a pragma
)

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
		CMAKE_REQUIRED_FLAGS_BASE "-Wall -Werror -pedantic"
	)

	set(
		CMAKE_REQUIRED_FLAGS ${CMAKE_REQUIRED_FLAGS_BASE}
	)

	CHECK_CXX_COMPILER_FLAG(
		"-fvisibility=hidden"
		FCPPT_UTILS_HAVE_GCC_VISIBILITY
	)

	CHECK_CXX_COMPILER_FLAG(
		"-Wconditional-uninitialized"
		FCPPT_UTILS_HAVE_CONDITIONAL_UNINITIALIZED_FLAG
	)

	CHECK_CXX_COMPILER_FLAG(
		"-Wconversion-null"
		FCPPT_UTILS_HAVE_CONVERSION_NULL_FLAG
	)

	CHECK_CXX_COMPILER_FLAG(
		"-Wdelete-non-virtual-dtor"
		FCPPT_UTILS_HAVE_DELETE_NON_VIRTUAL_DTOR_FLAG
	)

	CHECK_CXX_COMPILER_FLAG(
		"-Wdouble-promotion"
		FCPPT_UTILS_HAVE_DOUBLE_PROMOTION_FLAG
	)

	CHECK_CXX_COMPILER_FLAG(
		"-Wextra-semi"
		FCPPT_UTILS_HAVE_EXTRA_SEMI_FLAG
	)

	CHECK_CXX_COMPILER_FLAG(
		"-Wimplicit-fallthrough"
		FCPPT_UTILS_HAVE_IMPLICIT_FALLTHROUGH_FLAG
	)

	CHECK_CXX_COMPILER_FLAG(
		"-Wlogical-op"
		FCPPT_UTILS_HAVE_LOGICAL_OP_FLAG
	)

	CHECK_CXX_COMPILER_FLAG(
		"-Wmaybe-uninitialized"
		FCPPT_UTILS_HAVE_MAYBE_UNINITIALIZED_FLAG
	)

	CHECK_CXX_COMPILER_FLAG(
		"-Wmissing-declarations"
		FCPPT_UTILS_HAVE_MISSING_DECLARATIONS_FLAG
	)

	CHECK_CXX_COMPILER_FLAG(
		"-Wsign-conversion"
		FCPPT_UTILS_HAVE_SIGN_CONVERSION_FLAG
	)

	CHECK_CXX_COMPILER_FLAG(
		"-Wunneeded-member-function"
		FCPPT_UTILS_HAVE_UNNEEDED_MEMBER_FUNCTION_FLAG
	)

	CHECK_CXX_COMPILER_FLAG(
		"-Wunused-local-typedefs"
		FCPPT_UTILS_HAVE_UNUSED_LOCAL_TYPEDEFS_FLAG
	)

	CHECK_CXX_COMPILER_FLAG(
		"-Wunused-member-function"
		FCPPT_UTILS_HAVE_UNUSED_MEMBER_FUNCTION_FLAG
	)

	CHECK_CXX_COMPILER_FLAG(
		"-Wunreachable-code"
		FCPPT_UTILS_HAVE_UNREACHABLE_CODE_FLAG
	)

	CHECK_CXX_COMPILER_FLAG(
		"-Wzero-as-null-pointer-constant"
		FCPPT_UTILS_HAVE_ZERO_AS_NULL_POINTER_CONSTANT_FLAG
	)

	if(
		FCPPT_ENABLE_CPP11
	)
		add_definitions("-std=c++0x")
	else()
		add_definitions("-ansi")
	endif()

	add_definitions(
		${FCPPT_UTILS_GCC_ICC_CLANG_COMMON_OPTIONS}
	)

	set(
		CMAKE_REQUIRED_FLAGS
		"-Wall -Werror -pedantic"
	)

	check_cxx_source_compiles(
		"#pragma GCC diagnostic push
		int main() {}"
		FCPPT_UTILS_HAVE_GCC_DIAGNOSTIC
	)

	unset(
		CMAKE_REQUIRED_FLAGS
	)

	if(
		NOT FCPPT_UTILS_HAVE_GCC_DIAGNOSTIC
	)
		set(
			FCPPT_UTILS_INCLUDE_SYSTEM
			"SYSTEM"
		)
	endif()

	add_definitions(
		"-pedantic-errors -Wfloat-equal -Wredundant-decls"
		"-Winit-self -Wsign-promo -Wcast-align -Wold-style-cast"
	)

	if(
		FCPPT_UTILS_HAVE_GCC_DIAGNOSTIC
	)
		add_definitions(
			"-Weffc++"
		)
	endif()

	# Disable warnings about long long because too much stuff uses it
	if(
		NOT FCPPT_ENABLE_CPP11
	)
		add_definitions("-Wno-long-long")
	endif()

	if(FCPPT_UTILS_HAVE_CONDITIONAL_UNINITIALIZED_FLAG)
		add_definitions("-Wconditional-uninitialized")
	endif()

	if(FCPPT_UTILS_HAVE_DELETE_NON_VIRTUAL_DTOR_FLAG)
		add_definitions("-Wdelete-non-virtual-dtor")
	endif()

	if(FCPPT_UTILS_HAVE_DOUBLE_PROMOTION_FLAG)
		add_definitions("-Wdouble-promotion")
	endif()

	if(FCPPT_UTILS_HAVE_IMPLICIT_FALLTHROUGH_FLAG)
		add_definitions("-Wimplicit-fallthrough")
	endif()

	if(FCPPT_UTILS_HAVE_LOGICAL_OP_FLAG)
		add_definitions("-Wlogical-op")
	endif()

	if(FCPPT_UTILS_HAVE_MAYBE_UNINITIALIZED_FLAG)
		add_definitions("-Wmaybe-uninitialized")
	endif()

	if(FCPPT_UTILS_HAVE_MISSING_DECLARATIONS_FLAG)
		add_definitions("-Wmissing-declarations")
	endif()

	if(FCPPT_UTILS_HAVE_SIGN_CONVERSION_FLAG)
		add_definitions("-Wsign-conversion")
	endif()

	if(FCPPT_UTILS_HAVE_UNNEEDED_MEMBER_FUNCTION_FLAG)
		add_definitions("-Wunneeded-member-function")
	endif()

	if(FCPPT_UTILS_HAVE_UNUSED_LOCAL_TYPEDEFS_FLAG)
		add_definitions("-Wunused-local-typedefs")
	endif()

	if(FCPPT_UTILS_HAVE_UNUSED_MEMBER_FUNCTION_FLAG)
		add_definitions("-Wunused-member-function")
	endif()

	if(FCPPT_UTILS_HAVE_UNREACHABLE_CODE_FLAG)
		add_definitions("-Wunreachable-code")
	endif()

#	if(FCPPT_UTILS_HAVE_ZERO_AS_NULL_POINTER_CONSTANT_FLAG)
#		add_definitions("-Wzero-as-null-pointer-constant")
#	endif()

	# Only enable this for clang for now, because in gcc its not possible
	# to ignore this warning with a pragma
	if(FCPPT_UTILS_COMPILER_IS_CLANGPP)
		add_definitions("-Wundef")
	endif()

	if(FCPPT_UTILS_HAVE_GCC_VISIBILITY)
		option(
			FCPPT_ENABLE_VISIBILITY_HIDDEN
			"Enable -fvisbility=hidden"
			TRUE
		)

		if(FCPPT_ENABLE_VISIBILITY_HIDDEN)
			add_definitions("-fvisibility=hidden")
		endif()
	endif()
elseif(
	MSVC
)
	macro(
		FCPPT_CMAKE_UTILS_CHECK_VC_WARNING
		WARNING_NUMBER
	)
		set(
			CMAKE_REQUIRED_FLAGS "/WX /W4 /Wall"
		)

		check_cxx_source_compiles(
			"
			#pragma warning(push)
			#pragma warning(disable:${WARNING_NUMBER})
			#pragma warning(pop)
			int main() {}"
			"FCPPT_UTILS_HAVE_${WARNING_NUMBER}_FLAG"
		)

		unset(
			CMAKE_REQUIRED_FLAGS
		)
	endmacro()

	FCPPT_CMAKE_UTILS_CHECK_VC_WARNING(
		"4347"
	)

	FCPPT_CMAKE_UTILS_CHECK_VC_WARNING(
		"4435"
	)

	add_definitions(
		"/W4 /Wall /EHa /D_BIND_TO_CURRENT_VCLIBS_VERSION=1"
		" /wd4996 /wd4061 /wd4350 /wd4371 /wd4503 /wd4514 /wd4710 /wd4711 /wd4714 /wd4738 /wd4820"
	)

	if(
		FCPPT_UTILS_HAVE_4435_FLAG
	)
		add_definitions("/wd4435")
	endif()

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
elseif(
	FCPPT_UTILS_COMPILER_IS_INTELCPP
)
	add_definitions(
		${FCPPT_UTILS_GCC_ICC_CLANG_COMMON_OPTIONS}
	)

	# 304: No explicit public/private used for inheritance
	# 383: rvalue bound to const reference
	# 444: destructor of base class not virtual
	# 981: Arguments are evaluated in unspecified order
	# 1418: Function definition without declaration (even emitted for inline functions and templates)
	add_definitions(
		"-wd304 -wd383 -wd444 -wd981 -wd1418"
	)
endif()

# setup platform specific flags
if(
	UNIX
)
	# we need -fPIC for libraries on AMD64
	if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86_64")
		add_definitions(
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

	if(FCPPT_UTILS_HAVE_AS_NEEDED_LINKER_FLAG)
		set(
			CMAKE_SHARED_LINKER_FLAGS
			"-Wl,--as-needed ${CMAKE_SHARED_LINKER_FLAGS}"
		)
	endif()

	if(FCPPT_UTILS_HAVE_NO_UNDEFINED_LINKER_FLAG)
		set(
			CMAKE_SHARED_LINKER_FLAGS
			"-Wl,--no-undefined ${CMAKE_SHARED_LINKER_FLAGS}"
		)
	endif()

	if(FCPPT_UTILS_HAVE_NO_COPY_DT_NEEDED_ENTRIES_LINKER_FLAG)
		set(
			CMAKE_SHARED_LINKER_FLAGS
			"-Wl,--no-copy-dt-needed-entries ${CMAKE_SHARED_LINKER_FLAGS}"
		)
		set(
			CMAKE_EXE_LINKER_FLAGS
			"-Wl,--no-copy-dt-needed-entries ${CMAKE_EXE_LINKER_FLAGS}"
		)
	endif()
endif()

# Ignore Boost's deprecated features

add_definitions(
	"-D BOOST_FILESYSTEM_NO_DEPRECATED"
	"-D BOOST_SYSTEM_NO_DEPRECATED"
)

# configure standard CMake build paths
set(
	EXECUTABLE_OUTPUT_PATH
	${CMAKE_BINARY_DIR}/bin
)

set(
	LIBRARY_OUTPUT_PATH
	${CMAKE_BINARY_DIR}/lib
)

#macro for adding source groups
macro(
	FCPPT_UTILS_ADD_SOURCE_GROUPS
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
			${REL_PATH}
		)

		source_group(
			${GROUPFOLDER}
			FILES
			${CURFILE}
		)
	endforeach()
endmacro()

macro(
	FCPPT_UTILS_APPEND_SOURCE_DIR_AND_MAKE_GROUPS
	FILES
	RESULT
)
	unset(
		TEMP_RESULT
	)

	foreach(
		CUR_FILE
		${FILES}
	)
		set(
			WHOLE_FILE
			${CMAKE_SOURCE_DIR}/${CUR_FILE}
		)

		get_filename_component(
			REL_PATH
			${CUR_FILE}
			PATH
		)

		string(
			REPLACE
			"/"
			"\\"
			GROUPFOLDER
			${REL_PATH}
		)

		source_group(
			${GROUPFOLDER}
			FILES
			${WHOLE_FILE}
		)

		set(
			TEMP_RESULT
			${TEMP_RESULT}
			${WHOLE_FILE}
		)
	endforeach()

	set(
		${RESULT}
		"${${RESULT}};${TEMP_RESULT}"
	)
endmacro()
