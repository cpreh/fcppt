//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/less.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	variant_less
)
{
	typedef
	fcppt::variant::variadic<
		int,
		std::string
	>
	variant;

	variant const v1(
		10
	);

	variant const v2(
		20
	);

	BOOST_CHECK(
		v1 < v2
	);

	BOOST_CHECK(
		!(v2 < v1)
	);

	variant const v3(
		std::string(
			"hello world"
		)
	);

	BOOST_CHECK(
		v1 < v3
	);

	BOOST_CHECK(
		!(v3 < v1)
	);
}
