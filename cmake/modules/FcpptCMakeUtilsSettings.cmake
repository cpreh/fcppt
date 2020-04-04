include(
	CMakeDetermineCXXCompiler
)

include(
	CheckCXXCompilerFlag
)

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
	CMAKE_COMPILER_IS_GNUCXX OR FCPPT_UTILS_COMPILER_IS_CLANGPP
)
	set(
		CMAKE_CXX_FLAGS_RELEASE
		"-O3 -fomit-frame-pointer -DNDEBUG"
	)

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
	)

	if(
		FCPPT_UTILS_COMPILER_IS_CLANGPP
	)
		list(
			APPEND
			FCPPT_UTILS_COMPILE_OPTIONS
			"-Weverything"
			"-Wno-c++98-compat"
			"-Wno-c++98-compat-pedantic"
			"-Wno-padded"
			"-fcomment-block-commands=snippet"
		)
	else()
		list(
			APPEND
			FCPPT_UTILS_COMPILE_OPTIONS
			"-Wall"
			"-Wextra"
			"-Wcast-align"
			"-Wcast-qual"
			"-Wconversion"
			"-Wconversion-null"
			"-Wdelete-non-virtual-dtor"
			"-Wduplicated-cond"
			"-Wfloat-equal"
			"-Winit-self"
			"-Wmissing-declarations"
			"-Wnon-virtual-dtor"
			"-Wnull-dereference"
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
			"-Wdouble-promotion"
			"-Wlogical-op"
			"-Wmaybe-uninitialized"
			"-Wmissing-include-dirs"
			"-Wsuggest-override"
			"-Wunused-local-typedefs"
		)

		#"-Wzero-as-null-pointer-constant" - too many warnings from boost that cannot be disabled
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
		/wd4464
		/wd4503
		/wd4514
		/wd4710
		/wd4711
		/wd4714
		/wd4738
		/wd4820
		/wd4866
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
	#4464 - relative include path contains ..
	#4503 - decorated name length exceeded
	#4514 - unreferenced inline function removed
	#4710 - function not inlined
	#4711 - function selected for automatic inline expansion
	#4714 - function marked as __forceinline not inlined
	#4738 - storing 32-bit float result in memory
	#4820 - byte padding after data members
	#4866 - compiler may not enforce left-to-right evaluation of a C++17 operator (e.g. operator<< used in ostreams)
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
