function(
	add_fcppt_record_test
	TEST_NAME
)
	add_fcppt_test(
		record/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_record_test(
	all_initializers
	NO_CODE
	LINK_LIBS
		Brigand
)

add_fcppt_record_test(
	are_disjoint
	NO_CODE
)

add_fcppt_record_test(
	are_equivalent
	NO_CODE
)

add_fcppt_record_test(
	contains_initializer
	NO_CODE
	LINK_LIBS
		Brigand
)

add_fcppt_record_test(
	comparison
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_record_test(
	disjoint_product
	NO_CODE
	LINK_LIBS
		Brigand
)

add_fcppt_record_test(
	element_map
	NO_CODE
	LINK_LIBS
		Brigand
)

add_fcppt_record_test(
	element_tag_tuple
	NO_CODE
)

add_fcppt_record_test(
	init
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_record_test(
	label_arg
)

add_fcppt_record_test(
	label_set
	NO_CODE
	LINK_LIBS
		Brigand
)

add_fcppt_record_test(
	label_value_type
	NO_CODE
)

add_fcppt_record_test(
	map
	LINK_LIBS
		"${fcppt_core_TARGET}"
		fcppt_catch_interface
)

add_fcppt_record_test(
	map_elements
	NO_CODE
	LINK_LIBS
		Brigand
)

add_fcppt_record_test(
	multiply_disjoint
)

add_fcppt_record_test(
	object
)

add_fcppt_record_test(
	permute
)
