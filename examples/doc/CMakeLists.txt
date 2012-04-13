function(
	add_fcppt_doc_example
	MAINNAME
	ADDITIONAL_DEPS
	ADDITIONAL_DEFINITIONS
)
	make_fcppt_example(
		doc
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
		"${ADDITIONAL_DEFINITIONS}"
	)
endfunction()

add_fcppt_doc_example(algorithm "" "")
add_fcppt_doc_example(assign "" "")
add_fcppt_doc_example(container "" "")
add_fcppt_doc_example(container_bitfield "" "")
add_fcppt_doc_example(strong_typedef "" "")
