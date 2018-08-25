function(
	add_fcppt_algorithm_test
	TEST_NAME
)
	add_fcppt_test(
		algorithm/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_algorithm_test(
	all_of
)

add_fcppt_algorithm_test(
	append
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_algorithm_test(
	binary_search
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_algorithm_test(
	equal
)

add_fcppt_algorithm_test(
	equal_range
)

add_fcppt_algorithm_test(
	find_by_opt
)

add_fcppt_algorithm_test(
	find_if_opt
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_algorithm_test(
	find_opt
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_algorithm_test(
	fold
)

add_fcppt_algorithm_test(
	fold_break
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_algorithm_test(
	index_of
)

add_fcppt_algorithm_test(
	generate_n
)

add_fcppt_algorithm_test(
	loop
	LINK_LIBS
		Brigand
)

add_fcppt_algorithm_test(
	loop_break
)

add_fcppt_algorithm_test(
	map
	LINK_LIBS
		fcppt_catch_interface
		Brigand
)

add_fcppt_algorithm_test(
	map_concat
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_algorithm_test(
	map_iteration
)

add_fcppt_algorithm_test(
	map_iteration_second
)

add_fcppt_algorithm_test(
	map_optional
	LINK_LIBS
		fcppt_catch_interface
)

add_fcppt_algorithm_test(
	optimize_map
	NO_CODE
	LINK_LIBS
		Brigand
)

add_fcppt_algorithm_test(
	remove
)

add_fcppt_algorithm_test(
	repeat
)

add_fcppt_algorithm_test(
	reverse
)

add_fcppt_algorithm_test(
	sequence_iteration
)

add_fcppt_algorithm_test(
	split_string
)

add_fcppt_algorithm_test(
	unique
)
