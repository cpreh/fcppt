function(
	add_fcppt_parse_skipper_test
	TEST_NAME
)
	add_fcppt_test(
		parse/skipper/${TEST_NAME}
		LINK_LIBS
			"${fcppt_core_TARGET}"
			fcppt_parse_interface
		INCLUDE_DIRS
			${CMAKE_CURRENT_SOURCE_DIR}/include
		${ARGN}
	)
endfunction()

add_fcppt_parse_skipper_test(
	char_set
)

add_fcppt_parse_skipper_test(
	epsilon
)

add_fcppt_parse_skipper_test(
	is_skipper
	NO_CODE
)

add_fcppt_parse_skipper_test(
	literal
)

add_fcppt_parse_skipper_test(
	repetition
)

add_fcppt_parse_skipper_test(
	sequence
)

add_fcppt_parse_skipper_test(
	space
)

add_fcppt_parse_skipper_test(
	string
)
