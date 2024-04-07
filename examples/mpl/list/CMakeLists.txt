# Create an mpl list example.
function(add_fcppt_mpl_list_example example_name)
  add_fcppt_mpl_example(list/${example_name} ${ARGN})
endfunction()

add_fcppt_mpl_list_example(invoke_on LINK_LIBS ${fcppt_core_TARGET})

add_fcppt_mpl_list_example(output LINK_LIBS ${fcppt_core_TARGET})
