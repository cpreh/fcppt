function(
	add_fcppt_mpl_test
	TEST_NAME
)
	add_fcppt_test(
		mpl/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_mpl_test(
	add
	NO_CODE
)

add_fcppt_mpl_test(
	apply
	NO_CODE
)

add_fcppt_mpl_test(
	arg
	NO_CODE
)

add_fcppt_mpl_test(
	bind
	NO_CODE
)

add_fcppt_mpl_test(
	constant
	NO_CODE
)

add_fcppt_mpl_test(
	dec
	NO_CODE
)

add_fcppt_mpl_test(
	function_args
	NO_CODE
)

add_fcppt_mpl_test(
	greater
	NO_CODE
)

add_fcppt_mpl_test(
	if
	NO_CODE
)

add_fcppt_mpl_test(
	less
	NO_CODE
)

add_subdirectory(
	list
)

add_subdirectory(
	map
)

add_fcppt_mpl_test(
	mul
	NO_CODE
)

add_subdirectory(
	set
)
