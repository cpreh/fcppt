function(
	add_fcppt_container_test
	TEST_NAME
)
	add_fcppt_test(
		container/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_subdirectory(
	array
)

add_fcppt_container_test(
	at_optional
)

add_subdirectory(
	bitfield
)

add_subdirectory(
	buffer
)

add_fcppt_container_test(
	data
)

add_fcppt_container_test(
	dynamic_array
)

add_fcppt_container_test(
	find_opt
)

add_fcppt_container_test(
	find_opt_mapped
)

add_fcppt_container_test(
	get_or_insert
)

add_subdirectory(
	grid
)

add_fcppt_container_test(
	index_map
)

add_fcppt_container_test(
	insert
)

add_fcppt_container_test(
	join
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_container_test(
	key_set
)

add_fcppt_container_test(
	make
)

add_fcppt_container_test(
	maybe_back
)

add_fcppt_container_test(
	maybe_front
)

add_fcppt_container_test(
	map_values_copy
)

add_fcppt_container_test(
	map_values_ref
)

add_fcppt_container_test(
	move_range
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_container_test(
	output
)

add_fcppt_container_test(
	pop_back
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_container_test(
	pop_front
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_container_test(
	size
)

add_subdirectory(
	raw_vector
)

add_fcppt_container_test(
	set_difference
)

add_fcppt_container_test(
	set_intersection
)

add_fcppt_container_test(
	set_union
)

add_subdirectory(
	tree
)

add_subdirectory(
	tuple
)
