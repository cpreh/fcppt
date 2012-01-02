function(
	add_fcppt_chrono_example
	MAINNAME
	ADDITIONAL_DEPS
	ADDITIONAL_DEFINITIONS
)
	make_fcppt_example(
		chrono
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
		"${ADDITIONAL_DEFINITIONS}"
	)
endfunction()

add_fcppt_chrono_example(asio "${FcpptThreads_LIBRARIES};${Boost_SYSTEM_LIBRARY}" "${FcpptThreads_DEFINITIONS}")
add_fcppt_chrono_example(duration "" "")
add_fcppt_chrono_example(steady_clock "" "")
add_fcppt_chrono_example(system_clock "" "")
add_fcppt_chrono_example(time_point "" "")
