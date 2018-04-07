function(
	add_fcppt_container_array_test
	TEST_NAME
)
	add_fcppt_container_test(
		array/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_container_array_test(
	binary_map
)

add_fcppt_container_array_test(
	init
)

add_fcppt_container_array_test(
	init_const
)

add_fcppt_container_array_test(
	init_move
)

add_fcppt_container_array_test(
	make
)

add_fcppt_container_array_test(
	map
)

add_fcppt_container_array_test(
	push_back
)
