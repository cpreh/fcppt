# Create a preprocessor example.
function(add_fcppt_preprocessor_example example_name)
  add_fcppt_example(preprocessor/${example_name} ${ARGN})
endfunction()

add_fcppt_preprocessor_example(printing LINK_LIBS ${fcppt_core_TARGET})

add_fcppt_preprocessor_example(warning LINK_LIBS fcppt_core_interface)
