fcppt_utils_link_target(
	fcppt_core
)

fcppt_utils_link_target(
	fcppt_log
)

function(
	make_fcppt_example
	MAINNAME
)
	set(
		SINGLE_ARGS
		SUBNAME
		IS_C
	)

	set(
		MULTI_ARGS
		LINK_LIBS
		COMPILE_DEFINITIONS
	)

	cmake_parse_arguments(
		""
		""
		"${SINGLE_ARGS}"
		"${MULTI_ARGS}"
		${ARGN}
	)

	if(
		"${_SUBNAME}"
		STREQUAL
		""
	)
		set(
			FCPPT_EXAMPLE_NAME_SUFFIX
			${MAINNAME}
		)
	else()
		set(
			FCPPT_EXAMPLE_NAME_SUFFIX
			${_SUBNAME}_${MAINNAME}
		)
	endif()

	set(
		FCPPT_EXAMPLE_NAME
		fcppt_example_${FCPPT_EXAMPLE_NAME_SUFFIX}
	)

	if(
		_IS_C
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
		${FCPPT_EXAMPLE_NAME}
		${MAINNAME}.${SUFFIX}
	)

	target_compile_definitions(
		${FCPPT_EXAMPLE_NAME}
		PRIVATE
		"${_COMPILE_DEFINITIONS}"
	)

	if(
		NOT _IS_C
	)
		fcppt_utils_set_target_compiler_flags(
			${FCPPT_EXAMPLE_NAME}
		)
	endif()

	target_link_libraries(
		${FCPPT_EXAMPLE_NAME}
		PRIVATE
		${_LINK_LIBS}
	)
endfunction()

function(
	add_fcppt_example
)
	make_fcppt_example(
		${ARGN}
	)
endfunction()

add_fcppt_example(
	algorithm
)

add_fcppt_example(
	assert
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	assert_complete
)

add_fcppt_example(
	assign
)

add_fcppt_example(
	backtrace
	LINK_LIBS
		${fcppt_core_TARGET}
		${Boost_SYSTEM_LIBRARY}
)

add_fcppt_example(
	cast
)

add_fcppt_example(
	codecvt
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	config
)

add_fcppt_example(
	coding_style
)

add_fcppt_example(
	coding_style_asthetic
)

add_fcppt_example(
	cyclic_iterator
)

add_fcppt_example(
	endianness
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	enum
)

add_fcppt_example(
	either
)

add_fcppt_example(
	homogenous_pair
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	literal
)

add_fcppt_example(
	log
	LINK_LIBS
		${fcppt_core_TARGET}
		${fcppt_log_TARGET}
)

add_fcppt_example(
	no_cpp
	IS_C
		TRUE
)

add_fcppt_example(
	noncopyable
)

add_fcppt_example(
	optional
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	output_tm
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	smart_ptr_deleter
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	shared_ptr
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	string
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	string_conversion
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	strong_typedef
)

add_fcppt_example(
	type_iso
)

add_fcppt_example(
	type_traits
)

add_fcppt_example(
	unique_ptr
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	version
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	visibility
)

add_fcppt_example(
	weak_ptr
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_subdirectory(
	cast
)

add_subdirectory(
	container
)

add_subdirectory(
	io
)

add_subdirectory(
	log
)

add_subdirectory(
	math
)

add_subdirectory(
	mpl
)

add_subdirectory(
	preprocessor
)

add_subdirectory(
	random
)

add_subdirectory(
	signal
)

add_subdirectory(
	variant
)
