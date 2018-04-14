function(
	add_fcppt_strong_typedef_test
	TEST_NAME
)
	add_fcppt_test(
		strong_typedef/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_strong_typedef_test(
	apply
)

add_fcppt_strong_typedef_test(
	map
)
