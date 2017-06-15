function(
	add_fcppt_container_test
	TEST_NAME
)
	add_fcppt_test(
		container/${TEST_NAME}
		${ARGN}
	)
endfunction()

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
	make_array
)

add_fcppt_container_test(
	maybe_back
)

add_fcppt_container_test(
	maybe_front
)

add_fcppt_container_test(
	move_range
)

add_fcppt_container_test(
	output
)

add_fcppt_container_test(
	pop_back
)

add_subdirectory(
	raw_vector
)

add_subdirectory(
	tree
)

add_fcppt_container_test(
	untuple
)
