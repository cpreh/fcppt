function(
	add_fcppt_math_test
	TEST_NAME
)
	add_fcppt_test(
		math/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_math_test(
	at_c
)

add_fcppt_math_test(
	binary_vectors
)

add_subdirectory(
	box
)

add_fcppt_math_test(
	bresenham
)

add_fcppt_math_test(
	ceil_div
)

add_fcppt_math_test(
	circle
)

add_subdirectory(
	dim
)

add_fcppt_math_test(
	interpolation
)

add_fcppt_math_test(
	interval_distance
)

add_fcppt_math_test(
	is_power_of_2
)

add_subdirectory(
	matrix
)

add_fcppt_math_test(
	vector
)

add_subdirectory(
	vector
)

add_fcppt_math_test(
	units
)

add_fcppt_math_test(
	util
)
