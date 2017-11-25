//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/ceil_div.hpp>
#include <fcppt/math/ceil_div_signed.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	ceil_div
)
{
	BOOST_CHECK_EQUAL(
		fcppt::math::ceil_div(
			0u,
			1u
		),
		fcppt::optional::make(
			0u
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::ceil_div(
			1u,
			1u
		),
		fcppt::optional::make(
			1u
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::ceil_div(
			5u,
			3u
		),
		fcppt::optional::make(
			2u
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::ceil_div(
			6u,
			3u
		),
		fcppt::optional::make(
			2u
		)
	);

	BOOST_CHECK(
		!fcppt::math::ceil_div(
			2u,
			0u
		).has_value()
	);
}

BOOST_AUTO_TEST_CASE(
	ceil_div_signed
)
{
	BOOST_CHECK_EQUAL(
		fcppt::math::ceil_div_signed(
			-3,
			2
		),
		fcppt::optional::make(
			-1
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::ceil_div_signed(
			5,
			3
		),
		fcppt::optional::make(
			2
		)
	);

	BOOST_CHECK(
		!fcppt::math::ceil_div_signed(
			5,
			0
		).has_value()
	);
}
