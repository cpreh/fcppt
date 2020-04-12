function(
	add_fcppt_optional_test
	TEST_NAME
)
	add_fcppt_test(
		optional/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_optional_test(
	alternative
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_optional_test(
	apply
)

add_fcppt_optional_test(
	assign
)

add_fcppt_optional_test(
	bind
)

add_fcppt_optional_test(
	casts
)

add_fcppt_optional_test(
	cat
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_optional_test(
	combine
)

add_fcppt_optional_test(
	compare
)

add_fcppt_optional_test(
	copy_value
)

add_fcppt_optional_test(
	deref
)

add_fcppt_optional_test(
	filter
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_optional_test(
	from
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_optional_test(
	from_pointer
)

add_fcppt_optional_test(
	join
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_optional_test(
	make
)

add_fcppt_optional_test(
	make_if
)

add_fcppt_optional_test(
	map
)

add_fcppt_optional_test(
	maybe
)

add_fcppt_optional_test(
	maybe_multi
)

add_fcppt_optional_test(
	maybe_void
)

add_fcppt_optional_test(
	maybe_void_multi
)

add_fcppt_optional_test(
	monad
)

add_fcppt_optional_test(
	move
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_optional_test(
	nothing
)

add_fcppt_optional_test(
	object
)

add_fcppt_optional_test(
	reference
)

add_fcppt_optional_test(
	sequence
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_optional_test(
	to_container
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_optional_test(
	to_exception
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_optional_test(
	to_pointer
)

add_fcppt_optional_test(
	value_type
	NO_CODE
)
