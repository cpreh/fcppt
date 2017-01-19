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
	multiply
)

add_fcppt_options_test(
	option
)

add_fcppt_options_test(
	optional
)

add_fcppt_options_test(
	state_from_args
)

add_fcppt_options_test(
	switch
)
