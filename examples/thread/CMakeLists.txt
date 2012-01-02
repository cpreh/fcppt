function(
	add_fcppt_thread_example
	MAINNAME
	ADDITIONAL_DEPS
	ADDITIONAL_DEFINITIONS
)
	make_fcppt_example(
		thread
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
		"${ADDITIONAL_DEFINITIONS}"
	)
endfunction()

fcppt_link_target(
	fcppt_thread
)

add_fcppt_thread_example(
	thread
	"${FcpptThreads_LIBRARIES};${fcppt_thread_TARGET}"
	"${FcpptThreads_DEFINITIONS}"
)
