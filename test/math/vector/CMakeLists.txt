function(
	add_fcppt_math_vector_test
	TEST_NAME
)
	add_fcppt_math_test(
		vector/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_math_vector_test(
	angle_between
)

add_fcppt_math_vector_test(
	arithmetic
)

add_fcppt_math_vector_test(
	at
)

add_fcppt_math_vector_test(
	atan2
)

add_fcppt_math_vector_test(
	binary_map
)

add_fcppt_math_vector_test(
	bit_strings
)

add_fcppt_math_vector_test(
	ceil_div_signed
)

add_fcppt_math_vector_test(
	comparison
)

add_fcppt_math_vector_test(
	dim
)

add_fcppt_math_vector_test(
	distance
)

add_fcppt_math_vector_test(
	fill
)

add_fcppt_math_vector_test(
	hash
)

add_fcppt_math_vector_test(
	hypersphere_to_cartesian
)

add_fcppt_math_vector_test(
	input
)

add_fcppt_math_vector_test(
	map
)

add_fcppt_math_vector_test(
	mod
)

add_fcppt_math_vector_test(
	normalize
)

add_fcppt_math_vector_test(
	null
)

add_fcppt_math_vector_test(
	push_back
)

add_fcppt_math_vector_test(
	raw_view
)

add_fcppt_math_vector_test(
	sequence
)

add_fcppt_math_vector_test(
	static
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_math_vector_test(
	structure_cast
)

add_fcppt_math_vector_test(
	to_signed
)

add_fcppt_math_vector_test(
	to_unsigned
)

add_fcppt_math_vector_test(
	unit
)

add_fcppt_math_vector_test(
	view_storage
)
