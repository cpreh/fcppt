add_definitions(
	${FCPPT_CONFIG_LINK_MACROS}
)

function(
	add_fcppt_test
	PATHNAME
	ADDITIONAL_DEPS
	ADDITIONAL_DEFINES
)
	string(
		REPLACE
		"/"
		"_"
		TESTNAME
		${PATHNAME}
	)

	set(
		FCPPT_TEST_NAME
		test_${TESTNAME}
	)

	add_executable(
		${FCPPT_TEST_NAME}
		${PATHNAME}.cpp
	)

	set_target_properties(
		${FCPPT_TEST_NAME}
		PROPERTIES
		COMPILE_FLAGS
		"${ADDITIONAL_DEFINES}"
	)

	if(
		Boost_USE_STATIC_LIBS
	)
		set_property(
			TARGET
			${FCPPT_TEST_NAME}
			PROPERTY COMPILE_DEFINITIONS
			"BOOST_TEST_NO_LIB;BOOST_TEST_MODULE=${TESTNAME}"
		)
	else()
		set_property(
			TARGET
			${FCPPT_TEST_NAME}
			PROPERTY COMPILE_DEFINITIONS
			"BOOST_TEST_DYN_LINK;BOOST_TEST_MODULE=${TESTNAME}"
		)
	endif()

	fcppt_link_target(
		fcppt_core
	)

	target_link_libraries(
		${FCPPT_TEST_NAME}
		${FCPPT_DEFAULT_LINK_TARGET}
		${fcppt_core_TARGET}
		${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
		${ADDITIONAL_DEPS}
	)

	add_test(
		NAME
		${FCPPT_TEST_NAME}
		COMMAND
		${FCPPT_TEST_NAME}
	)
endfunction()

fcppt_link_target(
	fcppt_filesystem
)

add_fcppt_test(algorithm/contains_set "" "")
add_fcppt_test(algorithm/join "" "")
add_fcppt_test(algorithm/levenshtein "" "")
add_fcppt_test(algorithm/ptr_container_erase "" "")
add_fcppt_test(algorithm/remove "" "")
add_fcppt_test(algorithm/shift_compare "" "")
add_fcppt_test(assert "" "")
add_fcppt_test(assign/make_container "" "")
add_fcppt_test(assign/make_map "" "")
add_fcppt_test(cast_to_enum "" "")
add_fcppt_test(codecvt "" "")
add_fcppt_test(container/bitfield "" "")
add_fcppt_test(container/data "" "")
add_fcppt_test(container/grid "" "")
add_fcppt_test(container/grid/neumann_neighbors "" "")
add_fcppt_test(container/index_map "" "")
add_fcppt_test(container/map "" "")
add_fcppt_test(container/raw_vector "" "")
add_fcppt_test(container/tree/copy "" "")
add_fcppt_test(container/tree/depth "" "")
add_fcppt_test(container/tree/equal "" "")
add_fcppt_test(container/tree/move "" "")
add_fcppt_test(container/tree/pre_order "" "")
add_fcppt_test(container/tree/print "" "")
add_fcppt_test(container/tree/swap "" "")
add_fcppt_test(cyclic_iterator "" "")
add_fcppt_test(endianness "" "")
add_fcppt_test(extract_from_string "" "")
add_fcppt_test(filesystem/remove_extension "${fcppt_filesystem_TARGET}" "")
add_fcppt_test(homogenous_pair "" "")
add_fcppt_test(insert_to_string "" "")
add_fcppt_test(io/read_write "" "")
add_fcppt_test(io/stream_to_string "" "")
add_fcppt_test(io/raw_container_source "" "")
add_fcppt_test(literal "" "")
add_fcppt_test(math/bresenham "" "")
add_fcppt_test(math/ceil_div "" "")
add_fcppt_test(math/circle "" "")
add_fcppt_test(math/dim "" "")
add_fcppt_test(math/binary_vectors "" "")
add_fcppt_test(math/interpolation "" "")
add_fcppt_test(math/is_power_of_2 "" "")
add_fcppt_test(math/vector "" "")
add_fcppt_test(math/units "" "")
add_fcppt_test(math/util "" "")
add_fcppt_test(math/box/center "" "")
add_fcppt_test(math/box/corner_points "" "")
add_fcppt_test(math/box/extend "" "")
add_fcppt_test(math/box/intersection "" "")
add_fcppt_test(math/box/stretch "" "")
add_fcppt_test(math/box/structure_cast "" "")
add_fcppt_test(math/matrix/access "" "")
add_fcppt_test(math/matrix/adjugate "" "")
add_fcppt_test(math/matrix/delete_column_and_row "" "")
add_fcppt_test(math/matrix/determinant "" "")
add_fcppt_test(math/matrix/exponential_pade "" "")
add_fcppt_test(math/matrix/has_dim "" "")
add_fcppt_test(math/matrix/infinity_norm "" "")
add_fcppt_test(math/matrix/inverse "" "")
add_fcppt_test(math/matrix/is_matrix "" "")
add_fcppt_test(math/matrix/logarithm "" "")
add_fcppt_test(math/matrix/multiply "" "")
add_fcppt_test(math/matrix/operators "" "")
add_fcppt_test(math/matrix/rotation_axis "" "")
add_fcppt_test(math/matrix/rotation_x "" "")
add_fcppt_test(math/matrix/scaling "" "")
add_fcppt_test(math/matrix/translation "" "")
add_fcppt_test(math/matrix/view "" "")
add_fcppt_test(math/quaternion/all_quaternion "" "")
add_fcppt_test(math/vector/distance "" "")
add_fcppt_test(math/vector/hash "" "")
add_fcppt_test(math/vector/raw_view "" "")
add_fcppt_test(math/vector/unit "" "")
add_fcppt_test(math/vector/view_storage "" "")
add_fcppt_test(mpl/all_of "" "")
add_fcppt_test(mpl/append "" "")
add_fcppt_test(mpl/ceil_div "" "")
add_fcppt_test(number_multiplexer "" "")
add_fcppt_test(optional "" "")
add_fcppt_test(ptr_container "" "")
add_fcppt_test(reference_wrapper "" "")
add_fcppt_test(scoped_state_machine "" "")
add_fcppt_test(shared_ptr "" "")
add_fcppt_test(signal/simple "" "")
add_fcppt_test(signal/unregister "" "")
add_fcppt_test(strong_typedef "" "")
add_fcppt_test(truncation_check_cast "" "")
add_fcppt_test(type_traits/is_iterator "" "")
add_fcppt_test(type_traits/members "" "")
add_fcppt_test(unique_ptr "" "")
add_fcppt_test(variant/apply_movable "" "")
add_fcppt_test(variant/apply_nonconst "" "")
add_fcppt_test(variant/apply_prvalue "" "")
add_fcppt_test(variant/assign "" "")
add_fcppt_test(variant/equal "" "")
add_fcppt_test(variant/get "" "")
add_fcppt_test(variant/holds_type "" "")
add_fcppt_test(variant/move "" "")
