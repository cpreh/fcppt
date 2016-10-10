function(
	add_fcppt_io_example
	EXAMPLE_NAME
)
	add_fcppt_example(
		io/${EXAMPLE_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_io_example(
	endianness
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_io_example(
	scoped_rdbuf
	LINK_LIBS
		${fcppt_core_TARGET}
)
