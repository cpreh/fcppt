# Create a math box test.
function(add_fcppt_math_box_test test_name)
  add_fcppt_math_test(box/${test_name} ${ARGN})
endfunction()

add_fcppt_math_box_test(center)

add_fcppt_math_box_test(comparison)

add_fcppt_math_box_test(componentwise_equal)

add_fcppt_math_box_test(contains)

add_fcppt_math_box_test(contains_point)

add_fcppt_math_box_test(corner_points)

add_fcppt_math_box_test(distance)

add_fcppt_math_box_test(extend LINK_LIBS "${fcppt_core_TARGET}")

add_fcppt_math_box_test(has_dim NO_CODE)

add_fcppt_math_box_test(init_dim)

add_fcppt_math_box_test(init_max)

add_fcppt_math_box_test(intersection)

add_fcppt_math_box_test(object)

add_fcppt_math_box_test(shrink)

add_fcppt_math_box_test(stretch_absolute)

add_fcppt_math_box_test(stretch_relative)

add_fcppt_math_box_test(structure_cast)
