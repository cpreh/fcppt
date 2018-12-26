function(
	add_fcppt_parse_test
	TEST_NAME
)
	add_fcppt_test(
		parse/${TEST_NAME}
		LINK_LIBS
			"${fcppt_core_TARGET}"
			fcppt_parse_interface
		${ARGN}
	)
endfunction()

add_fcppt_parse_test(
	alternative
)

add_fcppt_parse_test(
	char
)

add_fcppt_parse_test(
	char_set
)

add_fcppt_parse_test(
	epsilon
)

add_fcppt_parse_test(
	ignore
)

add_fcppt_parse_test(
	lexeme
)

add_fcppt_parse_test(
	literal
)

add_fcppt_parse_test(
	repetition
)

add_fcppt_parse_test(
	repetition_result
	NO_CODE
)

add_fcppt_parse_test(
	sequence
)

add_fcppt_parse_test(
	space
)

add_fcppt_parse_test(
	space_skipper
)

add_fcppt_parse_test(
	sequence_result
)
