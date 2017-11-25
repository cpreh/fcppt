//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/dim/arithmetic.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/math/dim/static.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	dim_arithmetic_self
)
{
	typedef
	fcppt::math::dim::static_<
		unsigned,
		2
	>
	ui2_dim;

	typedef
	fcppt::math::dim::static_<
		int,
		2
	>
	i2_dim;

	ui2_dim dim(
		0u,
		0u
	);

	dim +=
		ui2_dim(
			1u,
			2u
		);

	BOOST_CHECK_EQUAL(
		dim,
		ui2_dim(
			1u,
			2u
		)
	);

	dim *= 2u;

	BOOST_CHECK_EQUAL(
		dim,
		ui2_dim(
			2u,
			4u
		)
	);

	i2_dim dimi(
		1,
		2
	);

	dimi = -dimi;

	BOOST_CHECK_EQUAL(
		dimi,
		i2_dim(
			-1,
			-2
		)
	);
}

BOOST_AUTO_TEST_CASE(
	dim_arithmetic_free
)
{
	typedef
	fcppt::math::dim::static_<
		int,
		2
	>
	i2_dim;

	BOOST_CHECK_EQUAL(
		i2_dim(
			1,
			2
		)
		+
		i2_dim(
			3,
			4
		),
		i2_dim(
			4,
			6
		)
	);

	BOOST_CHECK_EQUAL(
		i2_dim(
			5,
			2
		)
		-
		i2_dim(
			3,
			4
		),
		i2_dim(
			2,
			-2
		)
	);

	BOOST_CHECK_EQUAL(
		i2_dim(
			2,
			3
		)
		*
		i2_dim(
			3,
			4
		),
		i2_dim(
			6,
			12
		)
	);

	BOOST_CHECK_EQUAL(
		-i2_dim(
			2,
			3
		),
		i2_dim(
			-2,
			-3
		)
	);

	BOOST_CHECK_EQUAL(
		i2_dim(
			2,
			3
		)
		*
		2,
		i2_dim(
			4,
			6
		)
	);

	BOOST_CHECK_EQUAL(
		2
		*
		i2_dim(
			2,
			3
		),
		i2_dim(
			4,
			6
		)
	);

	BOOST_CHECK_EQUAL(
		i2_dim(
			4,
			6
		)
		/
		2,
		fcppt::optional::make(
			i2_dim(
				2,
				3
			)
		)
	);

	BOOST_CHECK_EQUAL(
		i2_dim(
			6,
			6
		)
		/
		i2_dim(
			2,
			3
		),
		fcppt::optional::make(
			i2_dim(
				3,
				2
			)
		)
	);

	BOOST_CHECK(
		!(
			i2_dim(
				6,
				6
			)
			/
			i2_dim(
				2,
				0
			)
		).has_value()
	);
}
