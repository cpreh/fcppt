function(
	add_fcppt_array_test
	TEST_NAME
)
	add_fcppt_test(
		array/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_array_test(
	append
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_array_test(
	apply
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_array_test(
	from_range
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_array_test(
	init
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_array_test(
	is_object
	NO_CODE
)

add_fcppt_array_test(
	join
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_array_test(
	make
)

add_fcppt_array_test(
	map
	LINK_LIBS
		${fcppt_core_TARGET}
		fcppt_catch_interface
)

add_fcppt_array_test(
	object
)

add_fcppt_array_test(
	push_back
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_array_test(
	size
	NO_CODE
)

add_fcppt_array_test(
	value_type
	NO_CODE
)
