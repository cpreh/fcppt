//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/equal.hpp>
#include <fcppt/variant/not_equal.hpp>
#include <fcppt/variant/object.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(variant_equal)
{
	typedef fcppt::variant::object<
		boost::mpl::vector3<
			bool,
			int,
			std::string
		>
	> variant;

	std::string const string(
		"hello world"
	);

	variant const v1(
		string
	);

	variant const v2(
		string
	);

	variant const empty1;

	variant const empty2;

	BOOST_REQUIRE(
		v1 == v2
	);

	BOOST_REQUIRE(
		empty1 == empty2
	);

	BOOST_REQUIRE(
		empty1 != v1
	);

	BOOST_REQUIRE(
		v1 != empty1
	);

	variant const v3(
		42
	);

	BOOST_REQUIRE(
		v1 != v3
	);
}
