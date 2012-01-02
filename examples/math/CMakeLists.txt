function(
	add_fcppt_math_example
	MAINNAME
	ADDITIONAL_DEPS
	ADDITIONAL_DEFINITIONS
)
	make_fcppt_example(
		math
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
		"${ADDITIONAL_DEFINITIONS}"
	)
endfunction()

add_subdirectory(
	vector
)

add_fcppt_math_example(box "" "")
add_fcppt_math_example(matrix "" "")
add_fcppt_math_example(utility "" "")
