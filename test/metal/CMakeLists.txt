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
	is_set
	NO_CODE
)

add_subdirectory(
	set
)
