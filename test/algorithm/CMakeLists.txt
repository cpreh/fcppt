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
)

add_fcppt_algorithm_test(
	array_init
)

add_fcppt_algorithm_test(
	array_init_const
)

add_fcppt_algorithm_test(
	array_init_move
)

add_fcppt_algorithm_test(
	array_push_back
)

add_fcppt_algorithm_test(
	binary_search
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
)

add_fcppt_algorithm_test(
	find_opt
)

add_fcppt_algorithm_test(
	fold
)

add_fcppt_algorithm_test(
	fold_break
)

add_fcppt_algorithm_test(
	index_of
)

add_fcppt_algorithm_test(
	generate_n
)

add_fcppt_algorithm_test(
	join
)

add_fcppt_algorithm_test(
	key_set
)

add_fcppt_algorithm_test(
	loop
)

add_fcppt_algorithm_test(
	loop_break
)

add_fcppt_algorithm_test(
	map
)

add_fcppt_algorithm_test(
	map_concat
)

add_fcppt_algorithm_test(
	map_iteration
)

add_fcppt_algorithm_test(
	map_iteration_second
)

add_fcppt_algorithm_test(
	map_optional
)

add_fcppt_algorithm_test(
	optimize_map
	NO_CODE
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
	set_difference
)

add_fcppt_algorithm_test(
	set_intersection
)

add_fcppt_algorithm_test(
	set_union
)

add_fcppt_algorithm_test(
	unique
)

add_fcppt_algorithm_test(
	vararg_map
)
