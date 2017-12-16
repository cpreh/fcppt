function(
	add_fcppt_intrusive_test
	TEST_NAME
)
	add_fcppt_test(
		intrusive/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_intrusive_test(
	list
)
