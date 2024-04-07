# Create a math example.
function(add_fcppt_math_example example_name)
  add_fcppt_example(math/${example_name} ${ARGN})
endfunction()

add_subdirectory(vector)

add_fcppt_math_example(box LINK_LIBS fcppt_core_interface)

add_fcppt_math_example(casts LINK_LIBS fcppt_core_interface)

add_fcppt_math_example(dim LINK_LIBS fcppt_core_interface)

add_fcppt_math_example(matrix LINK_LIBS fcppt_core_interface)

add_fcppt_math_example(utility LINK_LIBS fcppt_core_interface)

add_fcppt_math_example(vector LINK_LIBS fcppt_core_interface)
