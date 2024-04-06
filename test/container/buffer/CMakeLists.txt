function(add_fcppt_container_buffer_test TEST_NAME)
  add_fcppt_container_test(buffer/${TEST_NAME} ${ARGN})
endfunction()

add_fcppt_container_buffer_test(object)

add_fcppt_container_buffer_test(read_from)

add_fcppt_container_buffer_test(read_from_opt)

add_fcppt_container_buffer_test(to_raw_vector)
