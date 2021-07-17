function(
	add_fcppt_parse_example
	EXAMPLE_NAME
)
	add_fcppt_example(
		parse/${EXAMPLE_NAME}
		LINK_LIBS
			fcppt_parse_interface
		${ARGN}
	)
endfunction()

add_fcppt_parse_example(
	fatal
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_parse_example(
	grammar
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_parse_example(
	main
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_parse_example(
	skip
	LINK_LIBS
		${fcppt_core_TARGET}
)
