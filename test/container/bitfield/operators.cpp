//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/bitfield/comparison.hpp>
#include <fcppt/container/bitfield/enum_object.hpp>
#include <fcppt/container/bitfield/operators.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	container_bitfield_arithmetic
)
{
	enum class test_enum
	{
		test1,
		test2,
		test3,
		fcppt_maximum = test3
	};

	typedef
	fcppt::container::bitfield::enum_object<
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
