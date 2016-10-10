function(
	add_fcppt_io_test
	TEST_NAME
)
	add_fcppt_test(
		io/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_io_test(
	get
)

add_fcppt_io_test(
	read_write
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_io_test(
	stream_to_string
)

add_fcppt_io_test(
	widen_string
)
