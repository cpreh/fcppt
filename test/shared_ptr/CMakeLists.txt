# Create a shared_ptr test.
function(add_fcppt_shared_ptr_test test_name)
  add_fcppt_test(shared_ptr/${test_name} ${ARGN})
endfunction()

add_fcppt_shared_ptr_test(cast)

add_fcppt_shared_ptr_test(enable_shared_from_this)

add_fcppt_shared_ptr_test(hash)
