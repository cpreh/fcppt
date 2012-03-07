function(
	add_fcppt_mpl_example
	MAINNAME
	ADDITIONAL_DEPS
	ADDITIONAL_DEFINITIONS
)
	make_fcppt_example(
		mpl
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
		"${ADDITIONAL_DEFINITIONS}"
	)
endfunction()

add_fcppt_mpl_example(
	for_each "" ""
)

add_fcppt_mpl_example(
	invoke_on "" ""
)

add_fcppt_mpl_example(
	various "" ""
)
