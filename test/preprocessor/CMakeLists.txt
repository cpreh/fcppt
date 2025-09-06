# Create a preprocessor test.
function(add_fcppt_preprocessor_test test_name)
  add_fcppt_test(preprocessor/${test_name} ${ARGN})
endfunction()

add_fcppt_preprocessor_test(stringize)
