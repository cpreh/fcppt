function(
	add_fcppt_container_bitfield_test
	TEST_NAME
)
	add_fcppt_container_test(
		bitfield/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_container_bitfield_test(
	comparison
)

add_fcppt_container_bitfield_test(
	empty
)

add_fcppt_container_bitfield_test(
	hash
)

add_fcppt_container_bitfield_test(
	init
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_container_bitfield_test(
	is_subset_eq
)

add_fcppt_container_bitfield_test(
	object
)

add_fcppt_container_bitfield_test(
	operators
)

add_fcppt_container_bitfield_test(
	underlying_value
)
