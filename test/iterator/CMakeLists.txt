# Create an iterator test.
function(add_fcppt_iterator_test test_name)
  add_fcppt_test(iterator/${test_name} ${ARGN})
endfunction()

add_fcppt_iterator_test(random_access)
