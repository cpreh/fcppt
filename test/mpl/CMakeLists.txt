function(
	add_fcppt_mpl_test
	TEST_NAME
)
	add_fcppt_test(
		mpl/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_mpl_test(
	apply
	NO_CODE
)

add_fcppt_mpl_test(
	arg
	NO_CODE
)

add_fcppt_mpl_test(
	bind
	NO_CODE
)

add_fcppt_mpl_test(
	constant
	NO_CODE
)

add_subdirectory(
	list
)
