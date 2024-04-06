function(add_fcppt_variant_example EXAMPLE_NAME)
  add_fcppt_example(variant/${EXAMPLE_NAME} ${ARGN})
endfunction()

add_fcppt_variant_example(binary_visitation LINK_LIBS fcppt_core_interface)

add_fcppt_variant_example(motivation LINK_LIBS fcppt_core_interface)

add_fcppt_variant_example(nonconst_visitation LINK_LIBS ${fcppt_core_TARGET})

add_fcppt_variant_example(visitation LINK_LIBS fcppt_core_interface)
