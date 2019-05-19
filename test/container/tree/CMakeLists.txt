function(
	add_fcppt_container_tree_test
	TEST_NAME
)
	add_fcppt_container_test(
		tree/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_container_tree_test(
	child_position
)

add_fcppt_container_tree_test(
	copy
)

add_fcppt_container_tree_test(
	depth
)

add_fcppt_container_tree_test(
	equal
)

add_fcppt_container_tree_test(
	level
)

add_fcppt_container_tree_test(
	make_pre_order
	NO_CODE
)

add_fcppt_container_tree_test(
	make_to_root
	NO_CODE
)

add_fcppt_container_tree_test(
	map
)

add_fcppt_container_tree_test(
	move
)

add_fcppt_container_tree_test(
	output
)

add_fcppt_container_tree_test(
	pre_order
)

add_fcppt_container_tree_test(
	swap
)

add_fcppt_container_tree_test(
	to_root
)
