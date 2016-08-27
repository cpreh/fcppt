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
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_variant_example(
	motivation
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_variant_example(
	nonconst_visitation
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_variant_example(
	visitation
	LINK_LIBS
		fcppt_core_interface
)
