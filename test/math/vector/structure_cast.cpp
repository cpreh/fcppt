//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/to_signed_fun.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/structure_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::vector::structure_cast",
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

	CHECK(
		fcppt::math::vector::structure_cast<
			i2_vector,
			fcppt::cast::to_signed_fun
		>(
			ui2_vector(
				1u,
				2u
			)
		)
		==
		i2_vector{
			1,
			2
		}
	);
}
