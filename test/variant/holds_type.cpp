//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/holds_type.hpp>
#include <fcppt/variant/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <brigand/sequences/list.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	variant_holds_type
)
{
	typedef
	fcppt::variant::object<
		brigand::list<
			int,
			std::string
		>
	>
	variant;

	std::string const string(
		"hello world"
	);

	variant test(
		string
	);

	BOOST_CHECK(
		fcppt::variant::holds_type<
			std::string
		>(
			test
		)
	);

	BOOST_CHECK(
		!fcppt::variant::holds_type<
			int
		>(
			test
		)
	);

	variant const test2(
		42
	);

	BOOST_CHECK(
		!fcppt::variant::holds_type<
			std::string
		>(
			test2
		)
	);

	BOOST_CHECK(
		fcppt::variant::holds_type<
			int
		>(
			test2
		)
	);
}
