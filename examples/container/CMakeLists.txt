# Create a container example.
function(add_fcppt_container_example example_name)
  add_fcppt_example(container/${example_name} ${ARGN})
endfunction()

add_fcppt_container_example(bitfield LINK_LIBS fcppt_core_interface)

add_fcppt_container_example(buffer LINK_LIBS fcppt_core_interface)

add_fcppt_container_example(grid LINK_LIBS fcppt_core_interface)

add_fcppt_container_example(grid_iteration LINK_LIBS fcppt_core_interface)

add_fcppt_container_example(grid_range LINK_LIBS fcppt_core_interface)

add_fcppt_container_example(tree_simple LINK_LIBS fcppt_core_interface)

add_fcppt_container_example(tree_traversal LINK_LIBS fcppt_core_interface)
