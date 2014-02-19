function(
	add_fcppt_signal_example
	MAINNAME
	ADDITIONAL_DEPS
	ADDITIONAL_DEFINITIONS
)
	make_fcppt_example(
		signal
		${MAINNAME}
		"${fcppt_core_TARGET};${ADDITIONAL_DEPS}"
		"${ADDITIONAL_DEFINITIONS}"
	)
endfunction()

if(
	${SIGNALS_BENCHMARK_BACKEND} STREQUAL "boostsignals"
)
	add_fcppt_signal_example(
		benchmark
		"${Boost_SIGNALS_LIBRARY}"
		"FCPPT_EXAMPLES_SIGNAL_BENCHMARK_USE_BOOST_SIGNALS1"
	)
elseif(
	${SIGNALS_BENCHMARK_BACKEND} STREQUAL "boostsignals2"
)
	add_fcppt_signal_example(
		benchmark
		""
		"FCPPT_EXAMPLES_SIGNAL_BENCHMARK_USE_BOOST_SIGNALS2"
	)
else()
	add_fcppt_signal_example(
		benchmark
		""
		"FCPPT_EXAMPLES_SIGNAL_BENCHMARK_USE_FCPPT"
	)
endif()

add_fcppt_signal_example(combine "" "")
add_fcppt_signal_example(connection "" "")
add_fcppt_signal_example(simple "" "")
add_fcppt_signal_example(unregister "" "")
