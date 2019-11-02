function(
	add_fcppt_metal_test
	TEST_NAME
)
	add_fcppt_test(
		metal/${TEST_NAME}
		LINK_LIBS
			Metal
		${ARGN}
	)
endfunction()

add_fcppt_metal_test(
	as_tuple
	NO_CODE
)

add_fcppt_metal_test(
	enum_range
	NO_CODE
)

add_fcppt_metal_test(
	flip_map
	NO_CODE
)

add_fcppt_metal_test(
	flip_pair
	NO_CODE
)

add_fcppt_metal_test(
	for_each_break
)

add_fcppt_metal_test(
	from_number
	NO_CODE
)

add_fcppt_metal_test(
	from_number_list
	NO_CODE
)

add_fcppt_metal_test(
	interval
	NO_CODE
)

add_fcppt_metal_test(
	invoke_on
)

add_fcppt_metal_test(
	is_set
	NO_CODE
)

add_fcppt_metal_test(
	maps_equal
	NO_CODE
)

add_fcppt_metal_test(
	max_value
	NO_CODE
)

add_fcppt_metal_test(
	partial_sums
	NO_CODE
)

add_subdirectory(
	set
)

add_fcppt_metal_test(
	unique
	NO_CODE
)

add_fcppt_metal_test(
	to_number
	NO_CODE
)

add_fcppt_metal_test(
	to_number_list
	NO_CODE
)
