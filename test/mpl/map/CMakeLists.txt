function(
	add_fcppt_mpl_map_test
	TEST_NAME
)
	add_fcppt_mpl_test(
		map/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_mpl_map_test(
	at
	NO_CODE
)

add_fcppt_mpl_map_test(
	element_key
	NO_CODE
)

add_fcppt_mpl_map_test(
	has_key
	NO_CODE
)

add_fcppt_mpl_map_test(
	insert
	NO_CODE
)
