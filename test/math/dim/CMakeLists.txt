# Create a math dim test.
function(add_fcppt_math_dim_test test_name)
  add_fcppt_math_test(dim/${test_name} ${ARGN})
endfunction()

add_fcppt_math_dim_test(arithmetic)

add_fcppt_math_dim_test(at)

add_fcppt_math_dim_test(binary_map)

add_fcppt_math_dim_test(comparison)

add_fcppt_math_dim_test(componentwise_equal)

add_fcppt_math_dim_test(fill)

add_fcppt_math_dim_test(has_dim NO_CODE)

add_fcppt_math_dim_test(hash)

add_fcppt_math_dim_test(input)

add_fcppt_math_dim_test(is_quadratic)

add_fcppt_math_dim_test(map)

add_fcppt_math_dim_test(narrow_cast)

add_fcppt_math_dim_test(push_back)

add_fcppt_math_dim_test(sequence)

add_fcppt_math_dim_test(static LINK_LIBS fcppt_catch_interface)

add_fcppt_math_dim_test(to_signed)

add_fcppt_math_dim_test(to_unsigned)
