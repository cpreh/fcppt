//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/bitfield/comparison.hpp>
#include <fcppt/container/bitfield/object_from_enum.hpp>
#include <fcppt/container/bitfield/object.hpp>
#include <fcppt/container/bitfield/operators.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_bitfield_arithmetic
)
{
FCPPT_PP_POP_WARNING

	enum class test_enum
	{
		test1,
		test2,
		test3,
		fcppt_maximum = test3
	};

	typedef
	fcppt::container::bitfield::object_from_enum<
		test_enum
	>
	bitfield;

	bitfield field1(
		bitfield::null()
	);

	field1[
		test_enum::test1
	] = true;

	bitfield field2(
		bitfield::null()
	);

	BOOST_CHECK(
		(field2 | test_enum::test2)
		& test_enum::test2
	);

	field2[
		test_enum::test3
	] = true;

	{
		bitfield const bf_or(
			field1 | field2
		);

		BOOST_CHECK(
			bf_or[
				test_enum::test1
			]
		);

		BOOST_CHECK(
			!bf_or[
				test_enum::test2
			]
		);

		BOOST_CHECK(
			bf_or[
				test_enum::test3
			]
		);
	}

	BOOST_CHECK(
		(field1 & field2)
		==
		bitfield::null()
	);

	{

		bitfield const bf_xor(
			field1 ^ field2
		);

		BOOST_CHECK(
			bf_xor[
				test_enum::test1
			]
		);

		BOOST_CHECK(
			!bf_xor[
				test_enum::test2
			]
		);

		BOOST_CHECK(
			bf_xor[
				test_enum::test3
			]
		);
	}
}
