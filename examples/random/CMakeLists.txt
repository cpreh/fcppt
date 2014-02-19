function(
	add_fcppt_random_example
	MAINNAME
	ADDITIONAL_DEPS
)
	make_fcppt_example(
		random
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
		""
	)
endfunction()

add_fcppt_random_example(complex "${fcppt_core_TARGET}")
add_fcppt_random_example(enum "${fcppt_core_TARGET}")
add_fcppt_random_example(simple "${fcppt_core_TARGET}")
add_fcppt_random_example(strong_typedef "${fcppt_core_TARGET}")
add_fcppt_random_example(transform "${fcppt_core_TARGET}")
