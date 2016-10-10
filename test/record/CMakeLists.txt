function(
	add_fcppt_record_test
	TEST_NAME
)
	add_fcppt_test(
		record/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_record_test(
	init
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_record_test(
	object
)
