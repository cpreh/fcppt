function(
	add_fcppt_assert_test
	TEST_NAME
)
	add_fcppt_test(
		assert/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_assert_test(
	optional_error
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_assert_test(
	throw_message
	LINK_LIBS
		"${fcppt_core_TARGET}"
)
