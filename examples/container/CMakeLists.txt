function(
	add_fcppt_container_example
	MAINNAME
	ADDITIONAL_DEPS
	ADDITIONAL_DEFINITIONS
)
	make_fcppt_example(
		container
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
		"${ADDITIONAL_DEFINITIONS}"
	)
endfunction()

add_fcppt_container_example(array "" "")
add_fcppt_container_example(bitfield "" "")
add_fcppt_container_example(grid "" "")
add_fcppt_container_example(grid_iteration "" "")
add_fcppt_container_example(ptr "" "")
add_fcppt_container_example(tree_ptr "" "")
add_fcppt_container_example(tree_simple "" "")
add_fcppt_container_example(tree_traversal "" "")
add_fcppt_container_example(raw_vector "" "")
