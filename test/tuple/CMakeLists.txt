function(
	add_fcppt_tuple_test
	TEST_NAME
)
	add_fcppt_test(
		tuple/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_tuple_test(
	object
)
