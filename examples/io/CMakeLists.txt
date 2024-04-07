# Create an io example.
function(add_fcppt_io_example example_name)
  add_fcppt_example(io/${example_name} ${ARGN})
endfunction()

add_fcppt_io_example(endianness LINK_LIBS ${fcppt_core_TARGET})

add_fcppt_io_example(scoped_rdbuf LINK_LIBS ${fcppt_core_TARGET})
