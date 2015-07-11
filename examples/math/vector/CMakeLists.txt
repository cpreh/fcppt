function(
	add_fcppt_math_vector_example
	MAINNAME
)
	make_fcppt_example(
		${MAINNAME}
		SUBNAME
			mathvector
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
)

add_fcppt_math_vector_example(
	basic
)

add_fcppt_math_vector_example(
	convert
)

add_fcppt_math_vector_example(
	various
	LINK_LIBS
		${fcppt_core_TARGET}
)
