function(
	add_fcppt_mpl_list_test
	TEST_NAME
)
	add_fcppt_mpl_test(
		list/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_mpl_list_test(
	apply
	NO_CODE
)

add_fcppt_mpl_list_test(
	at
	NO_CODE
)

add_fcppt_mpl_list_test(
	distinct
	NO_CODE
)

add_fcppt_mpl_list_test(
	fold
	NO_CODE
)

add_fcppt_mpl_list_test(
	push_back
	NO_CODE
)

add_fcppt_mpl_list_test(
	transform
	NO_CODE
)
