function(
	add_fcppt_variant_test
	TEST_NAME
)
	add_fcppt_test(
		variant/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_variant_test(
	apply_movable
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_variant_test(
	apply_nonconst
)

add_fcppt_variant_test(
	apply_prvalue
)

add_fcppt_variant_test(
	assign
)

add_fcppt_variant_test(
	compare
)

add_fcppt_variant_test(
	dynamic_cast
)

add_fcppt_variant_test(
	equal
)

add_fcppt_variant_test(
	exception
)

add_fcppt_variant_test(
	get_exn
)

add_fcppt_variant_test(
	holds_type
)

add_fcppt_variant_test(
	less
)

add_fcppt_variant_test(
	match
)

add_fcppt_variant_test(
	move
)

add_fcppt_variant_test(
	output
)

add_fcppt_variant_test(
	to_optional
)

add_fcppt_variant_test(
	to_optional_ref
)

add_fcppt_variant_test(
	variadic
	NO_CODE
)
