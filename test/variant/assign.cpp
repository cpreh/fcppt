//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/get_exn.hpp>
#include <fcppt/variant/holds_type.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	variant_assign
)
{
	typedef
	fcppt::variant::variadic<
		int,
		std::string
	>
	variant;

	variant test1(
		0
	);

	variant test2(
		std::string(
			"test"
		)
	);

	test1 = test2;

	BOOST_CHECK(
		fcppt::variant::holds_type<
			std::string
		>(
			test1
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::variant::get_exn<
			std::string
		>(
			test1
		),
		std::string(
			"test"
		)
	);

	test1 = 42;

	BOOST_CHECK(
		fcppt::variant::holds_type<
			int
		>(
			test1
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::variant::get_exn<
			int
		>(
			test1
		),
		42
	);
}
