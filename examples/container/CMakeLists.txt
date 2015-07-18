function(
	add_fcppt_container_example
	MAINNAME
)
	make_fcppt_example(
		${MAINNAME}
		SUBNAME
			container
		${ARGN}
	)
endfunction()

add_fcppt_container_example(
	bitfield
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_container_example(
	grid
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_container_example(
	grid_iteration
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_container_example(
	grid_range
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_container_example(
	tree_simple
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_container_example(
	tree_traversal
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_container_example(
	raw_vector
	LINK_LIBS
		${fcppt_core_TARGET}
)
