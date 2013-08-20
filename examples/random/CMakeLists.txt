function(
	add_fcppt_random_example
	MAINNAME
	ADDITIONAL_DEPS
	ADDITIONAL_DEFINITIONS
)
	make_fcppt_example(
		random
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
		"${ADDITIONAL_DEFINITIONS}"
	)
endfunction()

add_fcppt_random_example(complex "${Boost_SYSTEM_LIBRARY}" "")
add_fcppt_random_example(enum "${Boost_SYSTEM_LIBRARY}" "")
add_fcppt_random_example(simple "${Boost_SYSTEM_LIBRARY}" "")
add_fcppt_random_example(strong_typedef "${Boost_SYSTEM_LIBRARY}" "")
add_fcppt_random_example(transform "${Boost_SYSTEM_LIBRARY}" "")
