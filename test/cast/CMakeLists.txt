# Create a cast test.
function(add_fcppt_cast_test test_name)
  add_fcppt_test(cast/${test_name} ${ARGN})
endfunction()

add_fcppt_cast_test(dynamic LINK_LIBS "${fcppt_core_TARGET}")

add_fcppt_cast_test(dynamic_any)

add_fcppt_cast_test(dynamic_cross LINK_LIBS "${fcppt_core_TARGET}")

add_fcppt_cast_test(from_void_ptr)

add_fcppt_cast_test(promote_int)

add_fcppt_cast_test(to_uint_ptr)

add_fcppt_cast_test(truncation_check LINK_LIBS "${fcppt_core_TARGET}")
