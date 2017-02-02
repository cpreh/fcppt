function(
	add_fcppt_container_grid_test
	TEST_NAME
)
	add_fcppt_container_test(
		grid/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_container_grid_test(
	apply
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_container_grid_test(
	at_optional
)

add_fcppt_container_grid_test(
	clamped_min
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_container_grid_test(
	clamped_sup
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_container_grid_test(
	clamped_sup_signed
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_container_grid_test(
	comparison
)

add_fcppt_container_grid_test(
	fill
)

add_fcppt_container_grid_test(
	in_range
)

add_fcppt_container_grid_test(
	in_range_dim
)

add_fcppt_container_grid_test(
	map
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_container_grid_test(
	moore_neighbors
)

add_fcppt_container_grid_test(
	neumann_neighbors
)

add_fcppt_container_grid_test(
	object
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_container_grid_test(
	pos_range
)

add_fcppt_container_grid_test(
	pos_ref_range
)

add_fcppt_container_grid_test(
	resize
)

add_fcppt_container_grid_test(
	spiral_range
)
