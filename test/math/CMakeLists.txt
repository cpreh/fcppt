# Create a math test.
function(add_fcppt_math_test test_name)
  add_fcppt_test(math/${test_name} ${ARGN})
endfunction()

add_subdirectory(box)

add_fcppt_math_test(ceil_div)

add_fcppt_math_test(ceil_div_static NO_CODE)

add_fcppt_math_test(clamp)

add_fcppt_math_test(deg_to_rad)

add_fcppt_math_test(diff)

add_subdirectory(dim)

add_fcppt_math_test(div)

add_fcppt_math_test(interpolation)

add_fcppt_math_test(interval_distance)

add_fcppt_math_test(is_power_of_2)

add_fcppt_math_test(is_zero)

add_fcppt_math_test(log2)

add_subdirectory(matrix)

add_fcppt_math_test(next_power_of_2)

add_fcppt_math_test(power_of_2)

add_fcppt_math_test(rad_to_deg)

add_fcppt_math_test(sphere)

add_fcppt_math_test(static_storage)

add_subdirectory(vector)

if(ENABLE_BOOST)
  add_fcppt_math_test(units LINK_LIBS fcppt_boost_interface SYSTEM_INCLUDE_DIRS ${Boost_INCLUDE_DIRS})
endif()
