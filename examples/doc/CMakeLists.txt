function(
	add_fcppt_doc_example
	MAINNAME
)
	make_fcppt_example(
		${MAINNAME}
		SUBNAME
			doc
		${ARGN}
	)
endfunction()

add_fcppt_doc_example(
	algorithm
)

add_fcppt_doc_example(
	container
)

add_fcppt_doc_example(
	container_bitfield
	LINK_LIBS
		${fcppt_core_TARGET}
)

add_fcppt_doc_example(
	strong_typedef
)
