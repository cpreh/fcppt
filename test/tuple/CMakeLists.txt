function(
	add_fcppt_tuple_test
	TEST_NAME
)
	add_fcppt_test(
		tuple/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_tuple_test(
	init
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_tuple_test(
	invoke
)

add_fcppt_tuple_test(
	make
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_tuple_test(
	map
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_tuple_test(
	map_result
	NO_CODE
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_tuple_test(
	object
)

add_fcppt_tuple_test(
	types_of
	NO_CODE
)
