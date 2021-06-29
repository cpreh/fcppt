function(
	add_fcppt_mpl_list_example
	EXAMPLE_NAME
)
	add_fcppt_mpl_example(
		list/${EXAMPLE_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_mpl_list_example(
	invoke_on
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_mpl_list_example(
	print
	LINK_LIBS
		${fcppt_core_TARGET}
)
