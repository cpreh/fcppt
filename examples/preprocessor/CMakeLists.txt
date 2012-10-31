function(
	add_fcppt_preprocessor_example
	MAINNAME
	ADDITIONAL_DEPS
	ADDITIONAL_DEFINITIONS
)
	make_fcppt_example(
		preprocessor
		${MAINNAME}
		"${ADDITIONAL_DEPS}"
		"${ADDITIONAL_DEFINITIONS}"
	)
endfunction()

add_fcppt_preprocessor_example(printing "" "")
add_fcppt_preprocessor_example(warning "" "")
