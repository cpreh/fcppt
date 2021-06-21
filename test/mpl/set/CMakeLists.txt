function(
	add_fcppt_mpl_set_test
	TEST_NAME
)
	add_fcppt_mpl_test(
		set/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_mpl_set_test(
	contains
	NO_CODE
)

add_fcppt_mpl_set_test(
	from_list
	NO_CODE
)

add_fcppt_mpl_set_test(
	from_list_relaxed
	NO_CODE
)

add_fcppt_mpl_set_test(
	insert
	NO_CODE
)

add_fcppt_mpl_set_test(
	insert_relaxed
	NO_CODE
)

add_fcppt_mpl_set_test(
	size
	NO_CODE
)

add_fcppt_mpl_set_test(
	to_list
	NO_CODE
)
