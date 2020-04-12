function(
	add_fcppt_monad_test
	TEST_NAME
)
	add_fcppt_test(
		monad/${TEST_NAME}
		LINK_LIBS
			Metal
		${ARGN}
	)
endfunction()

add_fcppt_monad_test(
	do
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_monad_test(
	inner_type
	NO_CODE
)
