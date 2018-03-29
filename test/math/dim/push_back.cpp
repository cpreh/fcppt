//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/dim/push_back.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	math_dim_push_back
)
{
	typedef
	fcppt::math::dim::static_<
		int,
		2
	>
	i2_dim;

	typedef
	fcppt::math::dim::static_<
		int,
		3
	>
	i3_dim;

	i3_dim const dim(
		fcppt::math::dim::push_back(
			i2_dim(
				1,
				2
			),
			3
		)
	);

	BOOST_CHECK_EQUAL(
		i3_dim(
			1,
			2,
			3
		),
		dim
	);
}
