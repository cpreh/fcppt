function(
	add_fcppt_enum_test
	TEST_NAME
)
	add_fcppt_test(
		enum/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_enum_test(
	array
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_enum_test(
	array_init
)

add_fcppt_enum_test(
	from_int
	LINK_LIBS
		fcppt_catch_interface
		"${fcppt_core_TARGET}"
)

add_fcppt_enum_test(
	index_of_array
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_enum_test(
	range
)

add_fcppt_enum_test(
	string
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_enum_test(
	to_static
)
