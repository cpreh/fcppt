# Create a cast example.
function(add_fcppt_cast_example example_name)
  add_fcppt_example(cast/${example_name} ${ARGN})
endfunction()

add_fcppt_cast_example(dynamic LINK_LIBS fcppt_core_interface)

add_fcppt_cast_example(dynamic_cross LINK_LIBS fcppt_core_interface)

add_fcppt_cast_example(safe_numeric LINK_LIBS fcppt_core_interface)

add_fcppt_cast_example(truncation_check LINK_LIBS fcppt_core_interface)
