function(
	add_fcppt_log_example
	MAINNAME
)
	make_fcppt_example(
		${MAINNAME}
		SUBNAME
			log
		LINK_LIBS
			${fcppt_core_TARGET}
			${fcppt_log_TARGET}
	)
endfunction()

add_fcppt_log_example(
	context
)

add_fcppt_log_example(
	formatting
)

add_fcppt_log_example(
	helloworld
)
