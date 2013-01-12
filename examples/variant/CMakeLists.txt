function(
	add_fcppt_variant_example
	MAINNAME
	ADDITIONAL_DEPS
	ADDITIONAL_DEFINITIONS
)
	make_fcppt_example(
		variant
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
		"${ADDITIONAL_DEFINITIONS}"
	)
endfunction()

add_fcppt_variant_example(binary_visitation "" "")
add_fcppt_variant_example(nonconst_visitation "" "")
