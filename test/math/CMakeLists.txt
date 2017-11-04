function(
	add_fcppt_math_test
	TEST_NAME
)
	add_fcppt_test(
		math/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_subdirectory(
	box
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
	div
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

add_fcppt_math_test(
	is_zero
)

add_subdirectory(
	matrix
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
