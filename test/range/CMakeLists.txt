# Create a range test.
function(add_fcppt_range_test test_name)
  add_fcppt_test(range/${test_name} ${ARGN})
endfunction()

add_fcppt_range_test(begin)

add_fcppt_range_test(empty)

add_fcppt_range_test(end)

add_fcppt_range_test(from_pair)

add_fcppt_range_test(singular)

add_fcppt_range_test(size)
