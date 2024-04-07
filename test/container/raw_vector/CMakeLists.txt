# Create a container raw_vector test.
function(add_fcppt_container_raw_vector_test test_name)
  add_fcppt_container_test(raw_vector/${test_name} ${ARGN})
endfunction()

add_fcppt_container_raw_vector_test(comparison)

add_fcppt_container_raw_vector_test(object)

add_fcppt_container_raw_vector_test(output LINK_LIBS ${fcppt_core_TARGET})
