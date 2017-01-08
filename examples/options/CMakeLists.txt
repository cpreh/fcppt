function(
	add_fcppt_options_example
	EXAMPLE_NAME
)
	add_fcppt_example(
		options/${EXAMPLE_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_options_example(
	complex
	LINK_LIBS
		${fcppt_core_TARGET}
		${fcppt_options_TARGET}
)

add_fcppt_options_example(
	simple
	LINK_LIBS
		${fcppt_core_TARGET}
		${fcppt_options_TARGET}
)
