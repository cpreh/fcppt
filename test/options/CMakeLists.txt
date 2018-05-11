function(
	add_fcppt_options_test
	TEST_NAME
)
	add_fcppt_test(
		options/${TEST_NAME}
		LINK_LIBS
			"${fcppt_core_TARGET}"
			"${fcppt_options_TARGET}"
		${ARGN}
	)
endfunction()

add_fcppt_options_test(
	apply
)

add_fcppt_options_test(
	argument
)

add_fcppt_options_test(
	base
)

add_fcppt_options_test(
	commands
)

add_fcppt_options_test(
	flag
)

add_fcppt_options_test(
	many
)

add_fcppt_options_test(
	multiple_args
)

add_fcppt_options_test(
	option
)

add_fcppt_options_test(
	optional
)

add_fcppt_options_test(
	parse_help
)

add_fcppt_options_test(
	sum
)

add_fcppt_options_test(
	switch
)

add_fcppt_options_test(
	unit
)

add_fcppt_options_test(
	unit_switch
)
