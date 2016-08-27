function(
	add_fcppt_cast_example
	MAINNAME
)
	make_fcppt_example(
		${MAINNAME}
		SUBNAME
			cast
		${ARGN}
	)
endfunction()

add_fcppt_cast_example(
	dynamic
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_cast_example(
	dynamic_cross
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_cast_example(
	dynamic_exn
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_cast_example(
	safe_numeric
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_cast_example(
	truncation_check
	LINK_LIBS
		${fcppt_core_TARGET}
)
