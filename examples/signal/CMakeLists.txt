function(
	add_fcppt_signal_example
	MAINNAME
	ADDITIONAL_DEPS
)
	make_fcppt_example(
		signal
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
	)
endfunction()

add_fcppt_signal_example(combine "")
add_fcppt_signal_example(connection "")
add_fcppt_signal_example(simple "")
add_fcppt_signal_example(unregister "")
