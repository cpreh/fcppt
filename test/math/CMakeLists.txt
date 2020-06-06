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
	ceil_div_static
	NO_CODE
)

add_fcppt_math_test(
	diff
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

add_fcppt_math_test(
	next_power_of_2
)

add_fcppt_math_test(
	sphere
)

add_fcppt_math_test(
	static_storage
)

add_subdirectory(
	vector
)

if(
	ENABLE_BOOST
)
	add_fcppt_math_test(
		units
		LINK_LIBS
			fcppt_boost_interface
	)
endif()
