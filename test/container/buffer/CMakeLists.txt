# Create a container buffer test.
function(add_fcppt_container_buffer_test test_name)
  add_fcppt_container_test(buffer/${test_name} ${ARGN})
endfunction()

add_fcppt_container_buffer_test(object)

add_fcppt_container_buffer_test(read_from)

add_fcppt_container_buffer_test(read_from_opt)

add_fcppt_container_buffer_test(to_raw_vector)
