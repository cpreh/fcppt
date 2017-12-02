function(
	add_fcppt_iterator_test
	TEST_NAME
)
	add_fcppt_test(
		iterator/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_iterator_test(
	random_access
)
