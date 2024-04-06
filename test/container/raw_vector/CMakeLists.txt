function(add_fcppt_container_raw_vector_test TEST_NAME)
  add_fcppt_container_test(raw_vector/${TEST_NAME} ${ARGN})
endfunction()

add_fcppt_container_raw_vector_test(comparison)

add_fcppt_container_raw_vector_test(object)

add_fcppt_container_raw_vector_test(output LINK_LIBS ${fcppt_core_TARGET})
