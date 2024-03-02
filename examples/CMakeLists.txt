fcppt_utils_link_target(
	fcppt_core
)

fcppt_utils_link_target(
	fcppt_filesystem
)

fcppt_utils_link_target(
	fcppt_log
)

fcppt_utils_link_target(
	fcppt_options
)

function(
	add_fcppt_example
	PATH_NAME
)
	set(
		OPTION_ARGS
		IS_C
	)

	set(
		MULTI_ARGS
		LINK_LIBS
		COMPILE_DEFINITIONS
	)

	cmake_parse_arguments(
		""
		"${OPTION_ARGS}"
		""
		"${MULTI_ARGS}"
		${ARGN}
	)

	if(
		_IS_C
	)
		set(
			IS_C
			IS_C
		)
	endif()

	fcppt_utils_add_example(
		${FCPPT_UTILS_PROJECT_SOURCE_DIR}/examples
		${PATH_NAME}
		${IS_C}
		LINK_LIBS
			${_LINK_LIBS}
		COMPILE_DEFINITIONS
			${_COMPILE_DEFINITIONS}
		INCLUDE_DIRS
			${FCPPT_UTILS_PROJECT_BINARY_DIR}/include
	)
endfunction()

add_fcppt_example(
	algorithm
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	array
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	assert_complete
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	assign
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	cast
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	config
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	coding_style
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	cyclic_iterator
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	endianness
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	enum
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	either
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	iterator
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
        intrusive
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	literal
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
        main
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	no_cpp
	IS_C
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	noncopyable
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	nonmovable
	LINK_LIBS
		fcppt_core_interface
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
	record
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
		fcppt_core_interface
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
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	type_iso
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	unique_ptr
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	version
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_example(
	visibility
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_example(
	weak_ptr
	LINK_LIBS
		fcppt_core_interface
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
	options
)

add_subdirectory(
	parse
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
