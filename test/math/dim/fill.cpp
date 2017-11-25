//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/fill.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	math_dim_fill
)
{
	typedef
	fcppt::math::dim::static_<
		unsigned,
		2
	>
	ui2_dim;

	ui2_dim const dim(
		fcppt::math::dim::fill<
			ui2_dim
		>(
			42u
		)
	);

	BOOST_CHECK_EQUAL(
		ui2_dim(
			42u,
			42u
		),
		dim
	);
}
