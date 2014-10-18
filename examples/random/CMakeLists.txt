function(
	add_fcppt_random_example
	MAINNAME
)
	make_fcppt_example(
		${MAINNAME}
		SUBNAME
			random
		${ARGN}
	)
endfunction()

add_fcppt_random_example(
	complex
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_random_example(
	enum
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_random_example(
	simple
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_random_example(
	strong_typedef
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_random_example(
	transform
	LINK_LIBS
		${fcppt_core_TARGET}
)
