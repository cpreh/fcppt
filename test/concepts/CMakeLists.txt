# Create a concepts test.
function(add_fcppt_concepts_test test_name)
  add_fcppt_test(concepts/${test_name} ${ARGN})
endfunction()

add_fcppt_concepts_test(invocable_move NO_CODE)

add_fcppt_concepts_test(move_constructible NO_CODE)
