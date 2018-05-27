function(
	add_fcppt_catch_test
	TEST_NAME
)
	add_fcppt_test(
		catch/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_catch_test(
	movable
	LINK_LIBS
		fcppt_catch_interface
)
