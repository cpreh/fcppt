# Create a variant test.
function(add_fcppt_variant_test test_name)
  add_fcppt_test(variant/${test_name} ${ARGN})
endfunction()

add_fcppt_variant_test(apply_movable LINK_LIBS ${fcppt_core_TARGET})

add_fcppt_variant_test(apply_nonconst LINK_LIBS ${fcppt_core_TARGET})

add_fcppt_variant_test(apply_prvalue LINK_LIBS ${fcppt_core_TARGET})

add_fcppt_variant_test(assign LINK_LIBS ${fcppt_core_TARGET})

add_fcppt_variant_test(compare)

add_fcppt_variant_test(comparison)

add_fcppt_variant_test(dynamic_cast)

add_fcppt_variant_test(dynamic_cast_types NO_CODE)

add_fcppt_variant_test(from_list NO_CODE)

add_fcppt_variant_test(hash)

add_fcppt_variant_test(holds_type)

add_fcppt_variant_test(match)

add_fcppt_variant_test(move LINK_LIBS ${fcppt_core_TARGET})

add_fcppt_variant_test(output)

add_fcppt_variant_test(partition LINK_LIBS fcppt_catch_interface)

add_fcppt_variant_test(partition_result NO_CODE)

add_fcppt_variant_test(to_optional LINK_LIBS fcppt_catch_interface)

add_fcppt_variant_test(to_optional_ref)
