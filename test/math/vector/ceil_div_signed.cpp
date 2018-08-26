//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/ceil_div_signed.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::vector::ceil_div_signed",
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
		fcppt::math::vector::ceil_div_signed(
			i2_vector{
				1,
				5
			},
			2
		)
		==
		fcppt::optional::make(
			i2_vector(
				1,
				3
			)
		)
	);
}
