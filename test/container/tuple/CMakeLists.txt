function(
	add_fcppt_container_tuple_test
	TEST_NAME
)
	add_fcppt_container_test(
		tuple/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_container_tuple_test(
	map
)

add_fcppt_container_tuple_test(
	push_back
)

add_fcppt_container_tuple_test(
	to_varargs
)

add_fcppt_container_tuple_test(
	vararg_map
)
