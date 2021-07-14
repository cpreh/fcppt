function(
	add_fcppt_cast_example
	EXAMPLE_NAME
)
	add_fcppt_example(
		cast/${EXAMPLE_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_cast_example(
	dynamic
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_cast_example(
	dynamic_cross
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_cast_example(
	safe_numeric
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_cast_example(
	truncation_check
	LINK_LIBS
		fcppt_core_interface
)
