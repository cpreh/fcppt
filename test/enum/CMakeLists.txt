# Create an enum test.
function(add_fcppt_enum_test test_name)
  add_fcppt_test(enum/${test_name} ${ARGN})
endfunction()

add_fcppt_enum_test(array LINK_LIBS "${fcppt_core_TARGET}")

add_fcppt_enum_test(array_init)

add_fcppt_enum_test(array_map LINK_LIBS "${fcppt_core_TARGET}")

add_fcppt_enum_test(array_output LINK_LIBS "${fcppt_core_TARGET}")

add_fcppt_enum_test(from_int LINK_LIBS fcppt_catch_interface
                    "${fcppt_core_TARGET}")

add_fcppt_enum_test(has_maximum NO_CODE)

add_fcppt_enum_test(index_of_array LINK_LIBS fcppt_catch_interface)

add_fcppt_enum_test(range)

add_fcppt_enum_test(string LINK_LIBS fcppt_catch_interface
                    "${fcppt_core_TARGET}")

add_fcppt_enum_test(to_static)
