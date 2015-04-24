function(
	add_fcppt_variant_example
	MAINNAME
)
	make_fcppt_example(
		${MAINNAME}
		SUBNAME
			variant
		${ARGN}
	)
endfunction()

add_fcppt_variant_example(
	binary_visitation
)

add_fcppt_variant_example(
	motivation
)

add_fcppt_variant_example(
	nonconst_visitation
)

add_fcppt_variant_example(
	visitation
)
