function(
	add_fcppt_io_example
	MAINNAME
)
	make_fcppt_example(
		${MAINNAME}
		SUBNAME
			io
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
