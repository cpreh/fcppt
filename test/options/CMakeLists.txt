function(
	add_fcppt_options_test
	TEST_NAME
)
	add_fcppt_test(
		options/${TEST_NAME}
		LINK_LIBS
			"${fcppt_options_TARGET}"
		${ARGN}
	)
endfunction()

add_fcppt_options_test(
	argument
)

add_fcppt_options_test(
	flag
)

add_fcppt_options_test(
	state_from_args
)
