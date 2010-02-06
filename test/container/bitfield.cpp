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
	bitfield field(
		bitfield::null()
	);
	
	BOOST_REQUIRE(
		!field
	);
}
