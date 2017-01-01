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
)

add_fcppt_optional_test(
	from
)

add_fcppt_optional_test(
	from_pointer
)

add_fcppt_optional_test(
	general
)

add_fcppt_optional_test(
	join
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
	move
)

add_fcppt_optional_test(
	nothing
)

add_fcppt_optional_test(
	reference
)

add_fcppt_optional_test(
	to_exception
)

add_fcppt_optional_test(
	to_pointer
)
