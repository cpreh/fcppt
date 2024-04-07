# Create an mpl example.
function(add_fcppt_mpl_example example_name)
  add_fcppt_example(mpl/${example_name} ${ARGN} LINK_LIBS fcppt_core_interface)
endfunction()

add_fcppt_mpl_example(lambda)

add_subdirectory(list)

add_fcppt_mpl_example(variant)
