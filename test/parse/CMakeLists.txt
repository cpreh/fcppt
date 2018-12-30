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
	alternative_result
	NO_CODE
)

add_fcppt_parse_test(
	as_struct
)

add_fcppt_parse_test(
	base
)

add_fcppt_parse_test(
	char
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_parse_test(
	char_set
)

add_fcppt_parse_test(
	complement
)

add_fcppt_parse_test(
	construct
)

add_fcppt_parse_test(
	convert
)

add_fcppt_parse_test(
	convert_const
)

add_fcppt_parse_test(
	deref
)

add_fcppt_parse_test(
	epsilon
)

add_fcppt_parse_test(
	fail
)

add_fcppt_parse_test(
	float
)

add_fcppt_parse_test(
	ignore
)

add_fcppt_parse_test(
	int
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_parse_test(
	lexeme
)

add_fcppt_parse_test(
	literal
)

add_fcppt_parse_test(
	json
)

add_fcppt_parse_test(
	not
)

add_fcppt_parse_test(
	optional
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_parse_test(
	repetition
)

add_fcppt_parse_test(
	repetition_plus
)

add_fcppt_parse_test(
	repetition_result
	NO_CODE
)

add_fcppt_parse_test(
	separator
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_parse_test(
	sequence
)

add_fcppt_parse_test(
	sequence_result
)

add_fcppt_parse_test(
	space
)

add_fcppt_parse_test(
	space_skipper
)

add_fcppt_parse_test(
	string
)
