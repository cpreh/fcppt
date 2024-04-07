# Create an intrusive test.
function(add_fcppt_intrusive_test test_name)
  add_fcppt_test(intrusive/${test_name} ${ARGN})
endfunction()

add_fcppt_intrusive_test(list)
