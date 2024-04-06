function(add_fcppt_mpl_map_test TEST_NAME)
  add_fcppt_mpl_test(map/${TEST_NAME} ${ARGN})
endfunction()

add_fcppt_mpl_map_test(at NO_CODE)

add_fcppt_mpl_map_test(element_key NO_CODE)

add_fcppt_mpl_map_test(element_value NO_CODE)

add_fcppt_mpl_map_test(equal NO_CODE)

add_fcppt_mpl_map_test(flip NO_CODE)

add_fcppt_mpl_map_test(has_key NO_CODE)

add_fcppt_mpl_map_test(insert NO_CODE)

add_fcppt_mpl_map_test(keys NO_CODE)
