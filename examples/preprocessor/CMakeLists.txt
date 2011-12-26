function(
	add_fcppt_preprocessor_example
	MAINNAME
	ADDITIONAL_DEPS
)
	make_fcppt_example(
		preprocessor
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
	)
endfunction()

add_fcppt_preprocessor_example(message "")
add_fcppt_preprocessor_example(printing "")
add_fcppt_preprocessor_example(warning "")
