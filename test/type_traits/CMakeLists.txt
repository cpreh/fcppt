# Create a type_traits test.
function(add_fcppt_type_traits_test test_name)
  add_fcppt_test(type_traits/${test_name} ${ARGN})
endfunction()

add_fcppt_type_traits_test(enum_constant_concept NO_CODE)

add_fcppt_type_traits_test(implication NO_CODE)

add_fcppt_type_traits_test(integral_cast NO_CODE)

add_fcppt_type_traits_test(is_base_of NO_CODE)

add_fcppt_type_traits_test(is_integral_constant NO_CODE)

add_fcppt_type_traits_test(is_raw_pointer NO_CODE)

add_fcppt_type_traits_test(is_string NO_CODE)

add_fcppt_type_traits_test(is_value NO_CODE)

add_fcppt_type_traits_test(iterator_category NO_CODE)

add_fcppt_type_traits_test(numeric_max NO_CODE)

add_fcppt_type_traits_test(remove_cv_ref NO_CODE)

add_fcppt_type_traits_test(safe_integral_cast NO_CODE)

add_fcppt_type_traits_test(to_bool NO_CODE)

add_fcppt_type_traits_test(value_type NO_CODE)
