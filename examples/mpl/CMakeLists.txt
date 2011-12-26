function(
	add_fcppt_mpl_example
	MAINNAME
	ADDITIONAL_DEPS
)
	make_fcppt_example(
		mpl
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
	)
endfunction()

add_fcppt_mpl_example(for_each "")
