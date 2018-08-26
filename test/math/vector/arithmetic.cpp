//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::vector arithmetic self",
	"[math],[vector]"
)
{
	typedef
	fcppt::math::vector::static_<
		unsigned,
		2
	>
	ui2_vector;

	typedef
	fcppt::math::vector::static_<
		int,
		2
	>
	i2_vector;

	ui2_vector vec(
		0u,
		0u
	);

	vec +=
		ui2_vector(
			1u,
			2u
		);

	REQUIRE(
		vec
		==
		ui2_vector(
			1u,
			2u
		)
	);

	vec *= 2u;

	REQUIRE(
		vec
		==
		ui2_vector(
			2u,
			4u
		)
	);

	i2_vector veci(
		1,
		2
	);

	veci = -veci;

	CHECK(
		veci
		==
		i2_vector(
			-1,
			-2
		)
	);
}

TEST_CASE(
	"math::vector arithmetic free",
	"[math],[vector]"
)
{
	typedef
	fcppt::math::vector::static_<
		int,
		2
	>
	i2_vector;

	CHECK(
		i2_vector(
			1,
			2
		)
		+
		i2_vector(
			3,
			4
		)
		==
		i2_vector(
			4,
			6
		)
	);

	CHECK(
		i2_vector(
			5,
			2
		)
		-
		i2_vector(
			3,
			4
		)
		==
		i2_vector(
			2,
			-2
		)
	);

	CHECK(
		i2_vector(
			2,
			3
		)
		*
		i2_vector(
			3,
			4
		)
		==
		i2_vector(
			6,
			12
		)
	);

	CHECK(
		-i2_vector(
			2,
			3
		)
		==
		i2_vector(
			-2,
			-3
		)
	);

	CHECK(
		2
		*
		i2_vector(
			2,
			3
		)
		==
		i2_vector(
			4,
			6
		)
	);

	CHECK(
		i2_vector(
			2,
			3
		)
		*
		2
		==
		i2_vector(
			4,
			6
		)
	);

	CHECK(
		i2_vector(
			4,
			6
		)
		/
		2
		==
		fcppt::optional::make(
			i2_vector(
				2,
				3
			)
		)
	);

	CHECK(
		i2_vector(
			6,
			6
		)
		/
		i2_vector(
			2,
			3
		)
		==
		fcppt::optional::make(
			i2_vector(
				3,
				2
			)
		)
	);

	CHECK(
		(
			i2_vector(
				6,
				6
			)
			/
			i2_vector(
				2,
				0
			)
		)
		==
		fcppt::optional::object<
			i2_vector
		>{}
	);
}
