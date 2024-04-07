# Create a container bitfield test.
function(add_fcppt_container_bitfield_test test_name)
  add_fcppt_container_test(bitfield/${test_name} ${ARGN})
endfunction()

add_fcppt_container_bitfield_test(comparison LINK_LIBS "${fcppt_core_TARGET}")

add_fcppt_container_bitfield_test(hash)

add_fcppt_container_bitfield_test(init LINK_LIBS "${fcppt_core_TARGET}")

add_fcppt_container_bitfield_test(is_subset_eq)

add_fcppt_container_bitfield_test(large)

add_fcppt_container_bitfield_test(object)

add_fcppt_container_bitfield_test(operators LINK_LIBS "${fcppt_core_TARGET}")

add_fcppt_container_bitfield_test(output LINK_LIBS "${fcppt_core_TARGET}")

add_fcppt_container_bitfield_test(underlying_value)
