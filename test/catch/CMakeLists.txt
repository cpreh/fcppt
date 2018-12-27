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
	defer
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_catch_test(
	either
	LINK_LIBS
		fcppt_catch_interface
		${fcppt_core_TARGET}
)

add_fcppt_catch_test(
	movable
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_catch_test(
	optional
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_catch_test(
	record
	LINK_LIBS
		fcppt_catch_interface
		${fcppt_core_TARGET}
)

add_fcppt_catch_test(
	strong_typedef
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_catch_test(
	variant
	LINK_LIBS
		fcppt_catch_interface
		${fcppt_core_TARGET}
)
