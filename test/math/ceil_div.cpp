//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/ceil_div.hpp>
#include <fcppt/math/ceil_div_signed.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::ceil_div",
	"[math]"
)
{
	CHECK(
		fcppt::math::ceil_div(
			0u,
			1u
		)
		==
		fcppt::optional::make(
			0u
		)
	);

	CHECK(
		fcppt::math::ceil_div(
			1u,
			1u
		)
		==
		fcppt::optional::make(
			1u
		)
	);

	CHECK(
		fcppt::math::ceil_div(
			5u,
			3u
		)
		==
		fcppt::optional::make(
			2u
		)
	);

	CHECK(
		fcppt::math::ceil_div(
			6u,
			3u
		)
		==
		fcppt::optional::make(
			2u
		)
	);

	CHECK(
		fcppt::math::ceil_div(
			2u,
			0u
		)
		==
		fcppt::optional::object<
			unsigned
		>{}
	);
}

TEST_CASE(
	"math::ceil_div_signed",
	"[math]"
)
{
	CHECK(
		fcppt::math::ceil_div_signed(
			-3,
			2
		)
		==
		fcppt::optional::make(
			-1
		)
	);

	CHECK(
		fcppt::math::ceil_div_signed(
			5,
			3
		)
		==
		fcppt::optional::make(
			2
		)
	);

	CHECK(
		fcppt::math::ceil_div_signed(
			5,
			0
		)
		==
		fcppt::optional::object<
			int
		>{}
	);
}
