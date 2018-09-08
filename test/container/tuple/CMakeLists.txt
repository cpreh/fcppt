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
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_container_tuple_test(
	map_result
	NO_CODE
)

add_fcppt_container_tuple_test(
	move_element
	NO_CODE
)

add_fcppt_container_tuple_test(
	push_back
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_container_tuple_test(
	to_varargs
)

add_fcppt_container_tuple_test(
	type_at
	NO_CODE
)

add_fcppt_container_tuple_test(
	vararg_map
	LINK_LIBS
		fcppt_catch_interface
)
