function(
	add_fcppt_preprocessor_example
	EXAMPLE_NAME
)
	add_fcppt_example(
		preprocessor/${EXAMPLE_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_preprocessor_example(
	printing
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_preprocessor_example(
	warning
	LINK_LIBS
		fcppt_core_interface
)
