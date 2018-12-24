function(
	add_fcppt_parse_test
	TEST_NAME
)
	add_fcppt_test(
		parse/${TEST_NAME}
		LINK_LIBS
			"${fcppt_core_TARGET}"
			"${fcppt_parse_TARGET}"
		${ARGN}
	)
endfunction()

add_fcppt_parse_test(
	basic_char
)

add_fcppt_parse_test(
	basic_literal
)

add_fcppt_parse_test(
	epsilon
)

add_fcppt_parse_test(
	repetition
)

add_fcppt_parse_test(
	sequence
)
