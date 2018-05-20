//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/div.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::div",
	"[math]"
)
{
	CHECK(
		fcppt::math::div(
			2,
			0
		)
		==
		fcppt::optional::object<
			int
		>{}
	);

	CHECK(
		fcppt::math::div(
			6,
			2
		)
		==
		fcppt::optional::make(
			3
		)
	);

	CHECK_FALSE(
		fcppt::math::div(
			2.f,
			0.f
		).has_value()
	);

	CHECK(
		fcppt::math::div<
			long,
			int
		>(
			4l,
			2
		)
		==
		fcppt::optional::make(
			2l
		)
	);
}
