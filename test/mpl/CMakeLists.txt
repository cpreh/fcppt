function(
	add_fcppt_mpl_test
	TEST_NAME
)
	add_fcppt_test(
		mpl/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_mpl_test(
	all_of
	NO_CODE
)

add_fcppt_mpl_test(
	append
	NO_CODE
)

add_fcppt_mpl_test(
	ceil_div
	NO_CODE
)

add_fcppt_mpl_test(
	enum_range
	NO_CODE
)

add_fcppt_mpl_test(
	flatten
	NO_CODE
)

add_fcppt_mpl_test(
	numeric_max
	NO_CODE
)

add_fcppt_mpl_test(
	set_difference
	NO_CODE
)

add_fcppt_mpl_test(
	set_intersection
	NO_CODE
)

add_fcppt_mpl_test(
	set_symmetric_difference
	NO_CODE
)

add_fcppt_mpl_test(
	set_union
	NO_CODE
)
