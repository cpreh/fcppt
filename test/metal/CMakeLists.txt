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

add_subdirectory(
	set
)
