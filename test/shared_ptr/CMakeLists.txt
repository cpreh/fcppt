function(add_fcppt_shared_ptr_test TEST_NAME)
  add_fcppt_test(shared_ptr/${TEST_NAME} ${ARGN})
endfunction()

add_fcppt_shared_ptr_test(cast)

add_fcppt_shared_ptr_test(enable_shared_from_this)

add_fcppt_shared_ptr_test(hash)
