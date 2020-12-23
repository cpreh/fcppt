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
	make
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_tuple_test(
	object
)
