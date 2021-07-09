function(
	add_fcppt_mpl_list_test
	TEST_NAME
)
	add_fcppt_mpl_test(
		list/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_mpl_list_test(
	all_of
	NO_CODE
)

add_fcppt_mpl_list_test(
	any_of
	NO_CODE
)

add_fcppt_mpl_list_test(
	append
	NO_CODE
)

add_fcppt_mpl_list_test(
	apply
	NO_CODE
)

add_fcppt_mpl_list_test(
	as
	NO_CODE
)

add_fcppt_mpl_list_test(
	as_tuple
	NO_CODE
)

add_fcppt_mpl_list_test(
	at
	NO_CODE
)

add_fcppt_mpl_list_test(
	back
	NO_CODE
)

add_fcppt_mpl_list_test(
	contains
	NO_CODE
)

add_fcppt_mpl_list_test(
	distinct
	NO_CODE
)

add_fcppt_mpl_list_test(
	drop
	NO_CODE
)

add_fcppt_mpl_list_test(
	empty
	NO_CODE
)

add_fcppt_mpl_list_test(
	enum_range
	NO_CODE
)

add_fcppt_mpl_list_test(
	enum_range_start_end
	NO_CODE
)

add_fcppt_mpl_list_test(
	fold
	NO_CODE
)

add_fcppt_mpl_list_test(
	for_each_break
)

add_fcppt_mpl_list_test(
	from
	NO_CODE
)

add_fcppt_mpl_list_test(
	front
	NO_CODE
)

add_fcppt_mpl_list_test(
	index_of
	NO_CODE
)

add_fcppt_mpl_list_test(
	index_of_if
	NO_CODE
)

add_fcppt_mpl_list_test(
	indices
	NO_CODE
)

add_fcppt_mpl_list_test(
	interval
	NO_CODE
)

add_fcppt_mpl_list_test(
	invoke_on
)

add_fcppt_mpl_list_test(
	join
	NO_CODE
)

add_fcppt_mpl_list_test(
	keep_if
	NO_CODE
)

add_fcppt_mpl_list_test(
	map
	NO_CODE
)

add_fcppt_mpl_list_test(
	map_multi
	NO_CODE
)

add_fcppt_mpl_list_test(
	maximum
	NO_CODE
)

add_fcppt_mpl_list_test(
	pop_back
	NO_CODE
)

add_fcppt_mpl_list_test(
	push_back
	NO_CODE
)

add_fcppt_mpl_list_test(
	push_front
	NO_CODE
)

add_fcppt_mpl_list_test(
	print
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_mpl_list_test(
	repeat
	NO_CODE
)

add_fcppt_mpl_list_test(
	remove
	NO_CODE
)

add_fcppt_mpl_list_test(
	remove_if
	NO_CODE
)

add_fcppt_mpl_list_test(
	take
	NO_CODE
)

add_fcppt_mpl_list_test(
	tail
	NO_CODE
)

add_fcppt_mpl_list_test(
	size
	NO_CODE
)

add_fcppt_mpl_list_test(
	transpose
	NO_CODE
)

add_fcppt_mpl_list_test(
	to_string
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_mpl_list_test(
	unique
	NO_CODE
)
