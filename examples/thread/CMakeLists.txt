function(
	add_fcppt_thread_example
	MAINNAME
	ADDITIONAL_DEPS
)
	make_fcppt_example(
		thread
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
	)
endfunction()

add_definitions(
	"${FcpptThreads_DEFINITIONS}"
)

fcppt_link_target(
	fcppt_thread
)

add_fcppt_thread_example(
	thread
	"${FcpptThreads_LIBRARIES};${fcppt_thread_TARGET}"
)
