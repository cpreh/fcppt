function(
	add_fcppt_preprocessor_example
	MAINNAME
)
	make_fcppt_example(
		${MAINNAME}
		SUBNAME
			preprocessor
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
