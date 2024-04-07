# Create a tuple test.
function(add_fcppt_tuple_test test_name)
  add_fcppt_test(tuple/${test_name} ${ARGN})
endfunction()

add_fcppt_tuple_test(apply LINK_LIBS fcppt_catch_interface)

add_fcppt_tuple_test(as_struct LINK_LIBS fcppt_catch_interface)

add_fcppt_tuple_test(concat LINK_LIBS fcppt_catch_interface)

add_fcppt_tuple_test(from_array LINK_LIBS fcppt_catch_interface)

add_fcppt_tuple_test(init LINK_LIBS fcppt_catch_interface)

add_fcppt_tuple_test(invoke)

add_fcppt_tuple_test(make LINK_LIBS fcppt_catch_interface)

add_fcppt_tuple_test(map LINK_LIBS fcppt_catch_interface)

add_fcppt_tuple_test(map_result NO_CODE LINK_LIBS fcppt_catch_interface)

add_fcppt_tuple_test(object)

add_fcppt_tuple_test(output LINK_LIBS ${fcppt_core_TARGET})

add_fcppt_tuple_test(push_back LINK_LIBS fcppt_catch_interface)

add_fcppt_tuple_test(size NO_CODE)

add_fcppt_tuple_test(types_of NO_CODE)
