function(
	add_fcppt_math_vector_example
	MAINNAME
	ADDITIONAL_DEPS
	ADDITIONAL_DEFINITIONS
)
	make_fcppt_example(
		mathvector
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
		"${ADDITIONAL_DEFINITIONS}"
	)
endfunction()

add_fcppt_math_vector_example(access "" "")
add_fcppt_math_vector_example(arithmetic "" "")
add_fcppt_math_vector_example(basic "" "")
add_fcppt_math_vector_example(convert "" "")
