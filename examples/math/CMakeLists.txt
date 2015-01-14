function(
	add_fcppt_math_example
	MAINNAME
)
	make_fcppt_example(
		${MAINNAME}
		SUBNAME
			math
	)
endfunction()

add_subdirectory(
	vector
)

add_fcppt_math_example(
	box
)

add_fcppt_math_example(
	casts
)

add_fcppt_math_example(
	dim
)

add_fcppt_math_example(
	matrix
)

add_fcppt_math_example(
	utility
)

add_fcppt_math_example(
	vector
)
