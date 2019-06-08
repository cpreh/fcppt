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
	append
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_container_array_test(
	apply
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_container_array_test(
	init
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_container_array_test(
	init_const
)

add_fcppt_container_array_test(
	init_move
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_container_array_test(
	make
)

add_fcppt_container_array_test(
	map
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_container_array_test(
	push_back
	LINK_LIBS
		fcppt_catch_interface
)
