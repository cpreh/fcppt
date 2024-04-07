# Create a random test.
function(add_fcppt_random_test test_name)
  add_fcppt_test(random/${test_name} ${ARGN})
endfunction()

add_fcppt_random_test(wrapper/uniform_container LINK_LIBS
                      "${fcppt_core_TARGET}")
