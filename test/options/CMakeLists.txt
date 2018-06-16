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
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_options_test(
	argument
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_options_test(
	base
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_options_test(
	commands
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_options_test(
	flag
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_options_test(
	many
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_options_test(
	option
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_options_test(
	optional
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_options_test(
	parse_help
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_options_test(
	sum
)

add_fcppt_options_test(
	switch
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_options_test(
	unit
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_options_test(
	unit_switch
	LINK_LIBS
		fcppt_catch_interface
)
