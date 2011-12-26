function(
	add_fcppt_math_vector_example
	MAINNAME
	ADDITIONAL_DEPS
)
	make_fcppt_example(
		mathvector
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
	)
endfunction()

add_fcppt_math_vector_example(access "")
add_fcppt_math_vector_example(arithmetic "")
add_fcppt_math_vector_example(basic "")
add_fcppt_math_vector_example(convert "")
