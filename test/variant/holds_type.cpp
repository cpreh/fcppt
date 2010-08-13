//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/object.hpp>
#include <fcppt/variant/holds_type.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <string>

BOOST_AUTO_TEST_CASE(
	variant_holds_type
)
{
	typedef fcppt::variant::object<
		boost::mpl::vector2<
			int,
			std::string
		>
	> variant;

	std::string const string(
		"hello world"
	);

	variant test(
		string
	);

	BOOST_REQUIRE(
		fcppt::variant::holds_type<
			std::string
		>(
			test
		)
	);

	BOOST_REQUIRE(
		!fcppt::variant::holds_type<
			int
		>(
			test
		)
	);

	variant const test2;

	BOOST_REQUIRE(
		!fcppt::variant::holds_type<
			std::string
		>(
			test2
		)
	);

	BOOST_REQUIRE(
		!fcppt::variant::holds_type<
			int
		>(
			test2
		)
	);

	test.reset();

	BOOST_REQUIRE(
		!fcppt::variant::holds_type<
			std::string
		>(
			test
		)
	);
}
