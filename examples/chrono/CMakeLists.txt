function(
	add_fcppt_chrono_example
	MAINNAME
	ADDITIONAL_DEPS
)
	make_fcppt_example(
		chrono
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
	)
endfunction()

add_fcppt_chrono_example(asio "${Boost_SYSTEM_LIBRARY}")
add_fcppt_chrono_example(duration "")
add_fcppt_chrono_example(steady_clock "")
add_fcppt_chrono_example(system_clock "")
add_fcppt_chrono_example(time_point "")
