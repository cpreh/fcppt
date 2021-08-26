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

add_fcppt_concepts_test(
	invocable_move
	NO_CODE
)

add_fcppt_concepts_test(
	move_constructible
	NO_CODE
)

add_fcppt_concepts_test(
	range
	NO_CODE
)
