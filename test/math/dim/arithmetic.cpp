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
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::dim arithmetic_self",
	"[math],[dim]"
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

	CHECK(
		dim
		==
		ui2_dim(
			1u,
			2u
		)
	);

	dim *= 2u;

	CHECK(
		dim
		==
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

	CHECK(
		dimi
		==
		i2_dim(
			-1,
			-2
		)
	);
}

TEST_CASE(
	"math::dim arithmetic free",
	"[math],[dim]"
)
{
	typedef
	fcppt::math::dim::static_<
		int,
		2
	>
	i2_dim;

	CHECK(
		i2_dim(
			1,
			2
		)
		+
		i2_dim(
			3,
			4
		)
		==
		i2_dim(
			4,
			6
		)
	);

	CHECK(
		i2_dim(
			5,
			2
		)
		-
		i2_dim(
			3,
			4
		)
		==
		i2_dim(
			2,
			-2
		)
	);

	CHECK(
		i2_dim(
			2,
			3
		)
		*
		i2_dim(
			3,
			4
		)
		==
		i2_dim(
			6,
			12
		)
	);

	CHECK(
		-i2_dim(
			2,
			3
		)
		==
		i2_dim(
			-2,
			-3
		)
	);

	CHECK(
		i2_dim(
			2,
			3
		)
		*
		2
		==
		i2_dim(
			4,
			6
		)
	);

	CHECK(
		2
		*
		i2_dim(
			2,
			3
		)
		==
		i2_dim(
			4,
			6
		)
	);

	CHECK(
		i2_dim(
			4,
			6
		)
		/
		2
		==
		fcppt::optional::make(
			i2_dim(
				2,
				3
			)
		)
	);

	CHECK(
		i2_dim(
			6,
			6
		)
		/
		i2_dim(
			2,
			3
		)
		==
		fcppt::optional::make(
			i2_dim(
				3,
				2
			)
		)
	);

	CHECK_FALSE(
		(
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
