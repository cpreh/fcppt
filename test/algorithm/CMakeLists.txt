# Create an algorithm test.
function(add_fcppt_algorithm_test test_name)
  add_fcppt_test(algorithm/${test_name} ${ARGN})
endfunction()

add_fcppt_algorithm_test(all_of)

add_fcppt_algorithm_test(binary_search LINK_LIBS fcppt_catch_interface)

add_fcppt_algorithm_test(contains_if)

add_fcppt_algorithm_test(equal)

add_fcppt_algorithm_test(equal_range)

add_fcppt_algorithm_test(find_by_opt LINK_LIBS fcppt_catch_interface)

add_fcppt_algorithm_test(find_if_opt LINK_LIBS fcppt_catch_interface)

add_fcppt_algorithm_test(find_opt LINK_LIBS fcppt_catch_interface)

add_fcppt_algorithm_test(fold LINK_LIBS fcppt_catch_interface)

add_fcppt_algorithm_test(fold_break LINK_LIBS fcppt_catch_interface)

add_fcppt_algorithm_test(index_of)

add_fcppt_algorithm_test(generate_n)

add_fcppt_algorithm_test(loop)

add_fcppt_algorithm_test(loop_break)

add_fcppt_algorithm_test(map LINK_LIBS ${fcppt_core_TARGET}
                         fcppt_catch_interface)

add_fcppt_algorithm_test(map_concat LINK_LIBS fcppt_catch_interface)

add_fcppt_algorithm_test(map_iteration)

add_fcppt_algorithm_test(map_iteration_second)

add_fcppt_algorithm_test(map_optional LINK_LIBS fcppt_catch_interface)

add_fcppt_algorithm_test(optimize_map NO_CODE)

add_fcppt_algorithm_test(range_element_type NO_CODE)

add_fcppt_algorithm_test(remove)

add_fcppt_algorithm_test(repeat)

add_fcppt_algorithm_test(reverse)

add_fcppt_algorithm_test(sequence_iteration)

add_fcppt_algorithm_test(split_string)

add_fcppt_algorithm_test(unique)
