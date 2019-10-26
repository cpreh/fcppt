function(
	add_fcppt_metal_set_test
	TEST_NAME
)
	add_fcppt_metal_test(
		set/${TEST_NAME}
		LINK_LIBS
			Metal
		${ARGN}
	)
endfunction()

add_fcppt_metal_set_test(
	from_list_relaxed
	NO_CODE
)

add_fcppt_metal_set_test(
	insert_relaxed
	NO_CODE
)

add_fcppt_metal_set_test(
	intersection
	NO_CODE
)

add_fcppt_metal_set_test(
	make
	NO_CODE
)

add_fcppt_metal_set_test(
	make_relaxed
	NO_CODE
)

add_fcppt_metal_set_test(
	to_list
	NO_CODE
)

add_fcppt_metal_set_test(
	union
	NO_CODE
)
