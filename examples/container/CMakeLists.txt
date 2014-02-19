function(
	add_fcppt_container_example
	MAINNAME
	ADDITIONAL_DEPS
)
	make_fcppt_example(
		container
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
		""
	)
endfunction()

add_fcppt_container_example(bitfield "${fcppt_core_TARGET}")
add_fcppt_container_example(grid "${fcppt_core_TARGET}")
add_fcppt_container_example(grid_iteration "${fcppt_core_TARGET}")
add_fcppt_container_example(ptr "${fcppt_core_TARGET}")
add_fcppt_container_example(tree_simple "${fcppt_core_TARGET}")
add_fcppt_container_example(tree_traversal "${fcppt_core_TARGET}")
add_fcppt_container_example(raw_vector "${fcppt_core_TARGET}")
