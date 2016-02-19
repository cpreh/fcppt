//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/at_c.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	math_at_c
)
{
	typedef
	fcppt::math::dim::static_<
		int,
		2
	>
	dim2;

	dim2 const dim_c(
		1,
		2
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::at_c<
			0
		>(
			dim_c
		),
		1
	);

	BOOST_CHECK_EQUAL(
		fcppt::math::at_c<
			1
		>(
			dim_c
		),
		2
	);


	dim2 dim_m(
		1,
		2
	);

	fcppt::math::at_c<
		1
	>(
		dim_m
	) =
		42;

	BOOST_CHECK_EQUAL(
		fcppt::math::at_c<
			1
		>(
			dim_m
		),
		42
	);
}
