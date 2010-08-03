FIND_PACKAGE(
	Boost 1.40.0 REQUIRED COMPONENTS
	unit_test_framework
)

ADD_DEFINITIONS(${FCPPT_CONFIG_LINK_MACROS})

MACRO(
	ADD_FCPPT_TEST
	PATHNAME
)
	STRING(REGEX REPLACE "\\/" "_" TESTNAME ${PATHNAME})

	SET(FCPPT_TEST_NAME fcppt${TESTNAME}test)

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
		${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
	)

	ADD_TEST(
		NAME
		${FCPPT_TEST_NAME}
		COMMAND
		${FCPPT_TEST_NAME}
	)
ENDMACRO()

ADD_FCPPT_TEST(alignment)
ADD_FCPPT_TEST(assert)
ADD_FCPPT_TEST(assign/make_container)
ADD_FCPPT_TEST(chrono/duration)
ADD_FCPPT_TEST(chrono/monotonic)
ADD_FCPPT_TEST(container/assign_multi_array)
ADD_FCPPT_TEST(container/bitfield)
ADD_FCPPT_TEST(container/raw_vector)
ADD_FCPPT_TEST(container/tree)
ADD_FCPPT_TEST(endianness)
ADD_FCPPT_TEST(is_iterator)
ADD_FCPPT_TEST(math/circle)
ADD_FCPPT_TEST(math/util)
ADD_FCPPT_TEST(math/vector)
ADD_FCPPT_TEST(math/quaternion/all_quaternion)
ADD_FCPPT_TEST(math/matrix/adjugate)
ADD_FCPPT_TEST(math/matrix/angles_from_matrix)
ADD_FCPPT_TEST(math/matrix/delete_column_and_row)
ADD_FCPPT_TEST(math/matrix/determinant)
ADD_FCPPT_TEST(math/matrix/has_dim)
ADD_FCPPT_TEST(math/matrix/inverse)
ADD_FCPPT_TEST(math/matrix/operators)
ADD_FCPPT_TEST(math/matrix/rotation_axis)
ADD_FCPPT_TEST(math/matrix/rotation_x)
ADD_FCPPT_TEST(math/matrix/scaling)
ADD_FCPPT_TEST(math/matrix/translation)
ADD_FCPPT_TEST(math/matrix/view)
ADD_FCPPT_TEST(math/box/center)
ADD_FCPPT_TEST(math/box/stretch)
ADD_FCPPT_TEST(shared_ptr/dynamic_pointer_cast)
ADD_FCPPT_TEST(ratio/multiply)
ADD_FCPPT_TEST(variant/get)
ADD_FCPPT_TEST(variant/holds_type)
