function(
	add_fcppt_brigand_test
	TEST_NAME
)
	add_fcppt_test(
		brigand/${TEST_NAME}
		LINK_LIBS
			Brigand
		${ARGN}
	)
endfunction()

add_fcppt_brigand_test(
	ceil_div
	NO_CODE
)

add_fcppt_brigand_test(
	enum_range
	NO_CODE
)

add_fcppt_brigand_test(
	equal_to
	NO_CODE
)

add_fcppt_brigand_test(
	flip_map
	NO_CODE
)

add_fcppt_brigand_test(
	flip_pair
	NO_CODE
)

add_fcppt_brigand_test(
	for_each_break
)

add_fcppt_brigand_test(
	found_t
	NO_CODE
)

add_fcppt_brigand_test(
	list_c
	NO_CODE
)

add_fcppt_brigand_test(
	invoke_on
)

add_fcppt_brigand_test(
	is_set
)

add_fcppt_brigand_test(
	max_value
	NO_CODE
)

add_fcppt_brigand_test(
	numeric_max
	NO_CODE
)

add_fcppt_brigand_test(
	pair_first
	NO_CODE
)

add_fcppt_brigand_test(
	pair_second
	NO_CODE
)

add_fcppt_brigand_test(
	runtime_index
)

add_fcppt_brigand_test(
	set_difference
	NO_CODE
)

add_fcppt_brigand_test(
	set_intersection
	NO_CODE
)

add_fcppt_brigand_test(
	set_symmetric_difference
	NO_CODE
)

add_fcppt_brigand_test(
	unique
	NO_CODE
)
