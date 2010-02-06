//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/bitfield/bitfield.hpp>
#include <boost/test/unit_test.hpp>

namespace
{

namespace test_enum
{

enum type
{
	test1,
	test2,
	test3,
	size
};

}

typedef fcppt::container::bitfield::basic<
	test_enum::type,
	test_enum::size
> bitfield;

}

BOOST_AUTO_TEST_CASE(container_bitfield)
{
	bitfield field1(
		bitfield::null()
	);
	
	BOOST_REQUIRE(
		!field1
	);

	field1[test_enum::test1] = true;

	BOOST_REQUIRE(
		field1
	);

	bitfield field2(
		bitfield::null()
	);

	field2[test_enum::test3] = true;

	{
		bitfield const bf_or(
			field1 | field2
		);

		BOOST_REQUIRE(
			bf_or[test_enum::test1]
			&& !bf_or[test_enum::test2]
			&& bf_or[test_enum::test3]
		);
	}

	BOOST_REQUIRE(
		!(field1 & field2)
	);

	{

		bitfield const bf_xor(
			field1 ^ field2
		);
		
		BOOST_REQUIRE(
			bf_xor[test_enum::test1]
			&& !bf_xor[test_enum::test2]
			&& bf_xor[test_enum::test3]
		);
	}

	bitfield::iterator it(
		field1.begin()
	);

	bitfield::iterator it2;

	it = it2;

	BOOST_REQUIRE(
		it == it2
	);
}
