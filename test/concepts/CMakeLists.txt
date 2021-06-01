function(
	add_fcppt_concepts_test
	TEST_NAME
)
	add_fcppt_test(
		concepts/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_concepts_test(
	invocable
	NO_CODE
)
