function(
	add_fcppt_type_traits_test
	TEST_NAME
)
	add_fcppt_test(
		type_traits/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_type_traits_test(
	constructible_from
	NO_CODE
)

add_fcppt_type_traits_test(
	function_pointer_to_reference
	NO_CODE
)

add_fcppt_type_traits_test(
	is_base_of
	NO_CODE
)

add_fcppt_type_traits_test(
	is_iterator
	NO_CODE
)

add_fcppt_type_traits_test(
	iterator_category
	NO_CODE
)
