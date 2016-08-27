function(
	add_fcppt_math_vector_example
	MAINNAME
)
	make_fcppt_example(
		${MAINNAME}
		SUBNAME
			math_vector
		${ARGN}
	)
endfunction()

add_fcppt_math_vector_example(
	access
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_math_vector_example(
	arithmetic
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_math_vector_example(
	basic
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_math_vector_example(
	convert
	LINK_LIBS
		fcppt_core_interface
)

add_fcppt_math_vector_example(
	various
	LINK_LIBS
		${fcppt_core_TARGET}
)
