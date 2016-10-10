function(
	add_fcppt_assign_test
	TEST_NAME
)
	add_fcppt_test(
		assign/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_assign_test(
	make_container
)
