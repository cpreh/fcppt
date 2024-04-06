function(add_fcppt_random_test TEST_NAME)
  add_fcppt_test(random/${TEST_NAME} ${ARGN})
endfunction()

add_fcppt_random_test(wrapper/uniform_container LINK_LIBS
                      "${fcppt_core_TARGET}")
