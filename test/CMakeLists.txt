ADD_DEFINITIONS(${FCPPT_CONFIG_LINK_MACROS})

MACRO(
	ADD_FCPPT_TEST
	PATHNAME
)
	STRING(REGEX REPLACE "\\/" "_" TESTNAME ${PATHNAME})

	SET(FCPPT_TEST_NAME test_${TESTNAME})

	ADD_EXECUTABLE (${FCPPT_TEST_NAME} ${PATHNAME}.cpp)

	IF(MSVC)
		SET_PROPERTY(
			TARGET ${FCPPT_TEST_NAME}
			PROPERTY COMPILE_FLAGS
			"-DBOOST_TEST_NO_LIB -DBOOST_TEST_MODULE=${TESTNAME}"
		)
	ELSE()
		SET_PROPERTY(
			TARGET ${FCPPT_TEST_NAME}
			PROPERTY COMPILE_FLAGS
			"-DBOOST_TEST_DYN_LINK -DBOOST_TEST_MODULE=${TESTNAME}"
		)
	ENDIF()

	TARGET_LINK_LIBRARIES (
		${FCPPT_TEST_NAME}
		${FCPPT_DEFAULT_LINK_TARGET}
		${FcpptThreads_LIBRARIES}
		${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
	)

	ADD_TEST(
		NAME
		${FCPPT_TEST_NAME}
		COMMAND
		${FCPPT_TEST_NAME}
	)
ENDMACRO()

ADD_FCPPT_TEST(alignment/array)
ADD_FCPPT_TEST(alignment/char)
ADD_FCPPT_TEST(algorithm/levenshtein)
ADD_FCPPT_TEST(algorithm/ptr_container_erase)
ADD_FCPPT_TEST(algorithm/remove)
ADD_FCPPT_TEST(algorithm/shift_compare)
ADD_FCPPT_TEST(assert)
ADD_FCPPT_TEST(assign/make_array)
ADD_FCPPT_TEST(assign/make_container)
ADD_FCPPT_TEST(chrono/duration/arithmetic)
ADD_FCPPT_TEST(chrono/duration/convert)
ADD_FCPPT_TEST(chrono/steady)
ADD_FCPPT_TEST(chrono/asio/deadline_timer)
ADD_FCPPT_TEST(codecvt)
ADD_FCPPT_TEST(container/array)
ADD_FCPPT_TEST(container/array_fusion)
ADD_FCPPT_TEST(container/bitfield)
ADD_FCPPT_TEST(container/grid)
ADD_FCPPT_TEST(container/index_map)
ADD_FCPPT_TEST(container/map)
ADD_FCPPT_TEST(container/raw_vector)
ADD_FCPPT_TEST(container/tree/copy)
ADD_FCPPT_TEST(container/tree/equal)
ADD_FCPPT_TEST(container/tree/pre_order)
ADD_FCPPT_TEST(container/tree/print)
ADD_FCPPT_TEST(container/tree/ptr_copy)
ADD_FCPPT_TEST(container/tree/ptr_release)
ADD_FCPPT_TEST(container/tree/swap)
ADD_FCPPT_TEST(cyclic_iterator)
ADD_FCPPT_TEST(endianness)
ADD_FCPPT_TEST(extract_from_string)
ADD_FCPPT_TEST(filesystem/remove_extension)
ADD_FCPPT_TEST(function/has_addressof_overload)
ADD_FCPPT_TEST(insert_to_string)
ADD_FCPPT_TEST(io/stream_to_string)
ADD_FCPPT_TEST(io/raw_container_source)
ADD_FCPPT_TEST(math/ceil_div)
ADD_FCPPT_TEST(math/circle)
ADD_FCPPT_TEST(math/dim)
ADD_FCPPT_TEST(math/binary_vectors)
ADD_FCPPT_TEST(math/interpolation)
ADD_FCPPT_TEST(math/is_power_of_2)
ADD_FCPPT_TEST(math/vector)
ADD_FCPPT_TEST(math/util)
ADD_FCPPT_TEST(math/box/center)
ADD_FCPPT_TEST(math/box/corner_points)
ADD_FCPPT_TEST(math/box/extend)
ADD_FCPPT_TEST(math/box/intersection)
ADD_FCPPT_TEST(math/box/stretch)
ADD_FCPPT_TEST(math/box/structure_cast)
ADD_FCPPT_TEST(math/matrix/adjugate)
ADD_FCPPT_TEST(math/matrix/delete_column_and_row)
ADD_FCPPT_TEST(math/matrix/determinant)
ADD_FCPPT_TEST(math/matrix/has_dim)
ADD_FCPPT_TEST(math/matrix/inverse)
ADD_FCPPT_TEST(math/matrix/is_matrix)
ADD_FCPPT_TEST(math/matrix/multiply)
ADD_FCPPT_TEST(math/matrix/operators)
ADD_FCPPT_TEST(math/matrix/rotation_axis)
ADD_FCPPT_TEST(math/matrix/rotation_x)
ADD_FCPPT_TEST(math/matrix/scaling)
ADD_FCPPT_TEST(math/matrix/translation)
ADD_FCPPT_TEST(math/matrix/view)
ADD_FCPPT_TEST(math/quaternion/all_quaternion)
ADD_FCPPT_TEST(math/vector/unit)
ADD_FCPPT_TEST(mpl/append)
ADD_FCPPT_TEST(mpl/ceil_div)
ADD_FCPPT_TEST(null_ptr)
ADD_FCPPT_TEST(optional)
ADD_FCPPT_TEST(ptr_container)
ADD_FCPPT_TEST(ratio/multiply)
ADD_FCPPT_TEST(ref)
ADD_FCPPT_TEST(scoped_state_machine)
ADD_FCPPT_TEST(shared_ptr/dynamic_pointer_cast)
ADD_FCPPT_TEST(signal/simple)
ADD_FCPPT_TEST(signal/unregister)
ADD_FCPPT_TEST(strong_typedef)
ADD_FCPPT_TEST(type_traits/is_iterator)
ADD_FCPPT_TEST(type_traits/members)
ADD_FCPPT_TEST(unique_ptr)
ADD_FCPPT_TEST(variant/apply_ternary)
ADD_FCPPT_TEST(variant/equal)
ADD_FCPPT_TEST(variant/get)
ADD_FCPPT_TEST(variant/holds_type)
