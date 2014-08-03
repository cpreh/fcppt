function(
	add_fcppt_doc_example
	MAINNAME
	ADDITIONAL_DEPS
)
	make_fcppt_example(
		doc
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
		""
	)
endfunction()

add_fcppt_doc_example(algorithm "")
add_fcppt_doc_example(container "")
add_fcppt_doc_example(container_bitfield "${fcppt_core_TARGET}")
add_fcppt_doc_example(strong_typedef "")
