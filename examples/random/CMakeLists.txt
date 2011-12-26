function(
	add_fcppt_random_example
	MAINNAME
	ADDITIONAL_DEPS
)
	make_fcppt_example(
		random
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
	)
endfunction()

add_fcppt_random_example(actor "")
add_fcppt_random_example(uniform "")
