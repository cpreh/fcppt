function(
	add_fcppt_io_example
	MAINNAME
	ADDITIONAL_DEPS
)
	make_fcppt_example(
		io
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
		""
	)
endfunction()

add_fcppt_io_example(endianness "${fcppt_core_TARGET}")
add_fcppt_io_example(scoped_rdbuf "${fcppt_core_TARGET}")
