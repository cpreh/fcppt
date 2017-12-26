function(
	add_fcppt_brigand_example
	EXAMPLE_NAME
)
	add_fcppt_example(
		brigand/${EXAMPLE_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_brigand_example(
	for_each
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_brigand_example(
	invoke_on
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_brigand_example(
	various
	LINK_LIBS
		${fcppt_core_TARGET}
)
