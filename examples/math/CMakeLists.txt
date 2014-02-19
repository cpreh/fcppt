function(
	add_fcppt_math_example
	MAINNAME
	ADDITIONAL_DEPS
)
	make_fcppt_example(
		math
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
		""
	)
endfunction()

add_subdirectory(
	vector
)

add_fcppt_math_example(box "")
add_fcppt_math_example(matrix "")
add_fcppt_math_example(utility "")
