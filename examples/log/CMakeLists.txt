function(
	add_fcppt_log_example
	MAINNAME
	ADDITIONAL_DEPS
	ADDITIONAL_DEFINITIONS
)
	make_fcppt_example(
		log
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
		"${ADDITIONAL_DEFINITIONS}"
	)
endfunction()

add_fcppt_log_example(complex "" "")
add_fcppt_log_example(context "" "")
add_fcppt_log_example(formatting "" "")
add_fcppt_log_example(helloworld "" "")
