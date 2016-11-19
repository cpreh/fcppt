function(
	add_fcppt_cast_test
	TEST_NAME
)
	add_fcppt_test(
		cast/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_cast_test(
	dynamic
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_cast_test(
	dynamic_any
)

add_fcppt_cast_test(
	dynamic_cross
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_cast_test(
	promote
)

add_fcppt_cast_test(
	truncation_check
	LINK_LIBS
		"${fcppt_core_TARGET}"
)
