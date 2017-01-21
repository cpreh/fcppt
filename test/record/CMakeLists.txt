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
	are_disjoint
	NO_CODE
)

add_fcppt_record_test(
	are_equivalent
	NO_CODE
)

add_fcppt_record_test(
	comparison
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_record_test(
	disjoint_product
	NO_CODE
)

add_fcppt_record_test(
	element_map
	NO_CODE
)

add_fcppt_record_test(
	init
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_record_test(
	map
)

add_fcppt_record_test(
	map_elements
	NO_CODE
)

add_fcppt_record_test(
	multiply_disjoint
)

add_fcppt_record_test(
	label_set
	NO_CODE
)

add_fcppt_record_test(
	object
)

add_fcppt_record_test(
	permute
)
