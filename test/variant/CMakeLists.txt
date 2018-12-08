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
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_variant_test(
	apply_prvalue
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_variant_test(
	assign
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_variant_test(
	compare
)

add_fcppt_variant_test(
	comparison
)

add_fcppt_variant_test(
	dynamic_cast
	LINK_LIBS
		Brigand
)

add_fcppt_variant_test(
	dynamic_cast_types
        NO_CODE
)

add_fcppt_variant_test(
	get_exn
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_variant_test(
	holds_type
	LINK_LIBS
		Brigand
)

add_fcppt_variant_test(
	match
)

add_fcppt_variant_test(
	move
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_variant_test(
	output
)

add_fcppt_variant_test(
	to_optional
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_variant_test(
	to_optional_ref
)

add_fcppt_variant_test(
	variadic
	NO_CODE
	LINK_LIBS
		Brigand
)
