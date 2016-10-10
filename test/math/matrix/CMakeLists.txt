function(
	add_fcppt_math_matrix_test
	TEST_NAME
)
	add_fcppt_math_test(
		matrix/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_math_matrix_test(
	access
)

add_fcppt_math_matrix_test(
	adjugate
)

add_fcppt_math_matrix_test(
	at_c
)

add_fcppt_math_matrix_test(
	delete_row_and_column
)

add_fcppt_math_matrix_test(
	determinant
)

add_fcppt_math_matrix_test(
	exponential_pade
)

add_fcppt_math_matrix_test(
	has_dim
	NO_CODE
)

add_fcppt_math_matrix_test(
	hash
)

add_fcppt_math_matrix_test(
	infinity_norm
)

add_fcppt_math_matrix_test(
	inverse
)

add_fcppt_math_matrix_test(
	is_matrix
	NO_CODE
)

add_fcppt_math_matrix_test(
	logarithm
)

add_fcppt_math_matrix_test(
	multiply
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_math_matrix_test(
	operators
)

add_fcppt_math_matrix_test(
	rotation_axis
)

add_fcppt_math_matrix_test(
	rotation_x
)

add_fcppt_math_matrix_test(
	scaling
)

add_fcppt_math_matrix_test(
	structure_cast
)

add_fcppt_math_matrix_test(
	transform_direction
)

add_fcppt_math_matrix_test(
	transform_point
)

add_fcppt_math_matrix_test(
	translation
)

add_fcppt_math_matrix_test(
	transpose
)

add_fcppt_math_matrix_test(
	view
)
