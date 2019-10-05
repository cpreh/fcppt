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
	set_insert_key_relaxed
	NO_CODE
)

add_fcppt_metal_test(
	set_union
	NO_CODE
)
