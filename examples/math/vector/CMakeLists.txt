# Create a math vector example.
function(add_fcppt_math_vector_example example_name)
  add_fcppt_math_example(vector/${example_name} ${ARGN})
endfunction()

add_fcppt_math_vector_example(access LINK_LIBS fcppt_core_interface)

add_fcppt_math_vector_example(arithmetic LINK_LIBS fcppt_core_interface)

add_fcppt_math_vector_example(basic LINK_LIBS fcppt_core_interface)

add_fcppt_math_vector_example(bit_strings LINK_LIBS fcppt_core_interface)

add_fcppt_math_vector_example(convert LINK_LIBS fcppt_core_interface)

add_fcppt_math_vector_example(various LINK_LIBS fcppt_core_interface)
