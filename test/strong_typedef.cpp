//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/strong_typedef.hpp>
#include <boost/test/unit_test.hpp>
#include <sstream>

namespace
{

FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	strong_int
);

}

BOOST_AUTO_TEST_CASE(
	strong_typedef_io
)
{
	std::stringstream stream;

	strong_int const test(
		42
	);

	stream << test;

	strong_int result;

	BOOST_REQUIRE(
		stream >> result
	);

	BOOST_REQUIRE(
		test == result
	);
}
