function(
	add_fcppt_mpl_example
	MAINNAME
)
	make_fcppt_example(
		${MAINNAME}
		SUBNAME
			mpl
		${ARGN}
	)
endfunction()

add_fcppt_mpl_example(
	for_each
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_mpl_example(
	invoke_on
)

add_fcppt_mpl_example(
	various
	LINK_LIBS
		${fcppt_core_TARGET}
)
