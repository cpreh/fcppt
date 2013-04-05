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

add_fcppt_random_example(complex "${Boost_CHRONO_LIBRARIES};${Boost_SYSTEM_LIBRARY}" "")
add_fcppt_random_example(simple "${Boost_CHRONO_LIBRARIES};${Boost_SYSTEM_LIBRARY}" "")
add_fcppt_random_example(strong_typedef "${Boost_CHRONO_LIBRARIES};${Boost_SYSTEM_LIBRARY}" "")
add_fcppt_random_example(transform "${Boost_CHRONO_LIBRARIES};${Boost_SYSTEM_LIBRARY}" "")
