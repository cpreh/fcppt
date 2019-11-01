function(
	add_fcppt_metal_example
	EXAMPLE_NAME
)
	add_fcppt_example(
		metal/${EXAMPLE_NAME}
		LINK_LIBS
			Metal
		${ARGN}
	)
endfunction()

add_fcppt_metal_example(
	invoke_on
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_metal_example(
	various
	LINK_LIBS
		${fcppt_core_TARGET}
)
