include(
	CMakeParseArguments
)

function(
	add_fcppt_test
	PATH_NAME
)
	set(
		OPTION_ARGS
		NO_CODE
	)

	set(
		MULTI_ARGS
		LINK_LIBS
	)

	cmake_parse_arguments(
		""
		"${OPTION_ARGS}"
		""
		"${MULTI_ARGS}"
		${ARGN}
	)

	if(
		_NO_CODE
	)
		set(
			NO_CODE
			NO_CODE
		)
	endif()

	fcppt_utils_add_test(
		${FCPPT_UTILS_PROJECT_SOURCE_DIR}/test
		"${PATH_NAME}"
		${NO_CODE}
		LINK_LIBS
			${_LINK_LIBS}
			fcppt_core_interface
	)
endfunction()


fcppt_utils_link_target(
	fcppt_core
)

if(
	ENABLE_FILESYSTEM
)
	fcppt_utils_link_target(
		fcppt_filesystem
	)
endif()

fcppt_utils_link_target(
	fcppt_log
)

fcppt_utils_link_target(
	fcppt_options
)

add_fcppt_test(
	absurd
	NO_CODE
)

add_subdirectory(
	algorithm
)

add_subdirectory(
	assert
)

add_subdirectory(
	assign
)

add_fcppt_test(
	bit
)

add_fcppt_test(
	boost_units_value
)

add_subdirectory(
	cast
)

add_fcppt_test(
	cast_to_enum
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	codecvt
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	const
)

add_subdirectory(
	container
)

add_fcppt_test(
	cyclic_iterator
)

add_subdirectory(
	either
)

add_fcppt_test(
	endianness
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	enum_range
)

add_fcppt_test(
	extract_from_string
)

if(
	ENABLE_FILESYSTEM
)
	add_subdirectory(
		filesystem
	)
endif()

add_fcppt_test(
	function
)

add_fcppt_test(
	homogenous_pair
)

add_fcppt_test(
	insert_to_string
)

add_fcppt_test(
	int_range
)

add_subdirectory(
	io
)

add_fcppt_test(
	literal
)

add_subdirectory(
	math
)

add_subdirectory(
	mpl
)

add_fcppt_test(
	move_if_rvalue
)

add_subdirectory(
	optional
)

add_subdirectory(
	options
)

add_subdirectory(
	random
)

add_subdirectory(
	record
)

add_fcppt_test(
	reference
)

add_fcppt_test(
	reference_to_base
)

add_fcppt_test(
	reference_to_const
)

add_fcppt_test(
	runtime_enum
)

add_fcppt_test(
	scoped_state_machine
)

add_fcppt_test(
	shared_ptr
)

add_subdirectory(
	signal
)

add_fcppt_test(
	strong_typedef
)

add_subdirectory(
	type_traits
)

add_fcppt_test(
	unique_ptr
)

add_fcppt_test(
	unit
)

add_subdirectory(
	variant
)
