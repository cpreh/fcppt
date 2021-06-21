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
	all_of
	NO_CODE
)

add_fcppt_mpl_list_test(
	any_of
	NO_CODE
)

add_fcppt_mpl_list_test(
	apply
	NO_CODE
)

add_fcppt_mpl_list_test(
	as
	NO_CODE
)

add_fcppt_mpl_list_test(
	at
	NO_CODE
)

add_fcppt_mpl_list_test(
	contains
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
	index_of
	NO_CODE
)

add_fcppt_mpl_list_test(
	index_of_if
	NO_CODE
)

add_fcppt_mpl_list_test(
	is_set
	NO_CODE
)

add_fcppt_mpl_list_test(
	map
	NO_CODE
)

add_fcppt_mpl_list_test(
	push_back
	NO_CODE
)

add_fcppt_mpl_list_test(
	size
	NO_CODE
)
