//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/push_back.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::vector::push_back",
	"[math],[vector]"
)
{
	CHECK(
		fcppt::math::vector::push_back(
			fcppt::math::vector::static_<
				int,
				2
			>{
				1,
				2
			},
			3
		)
		==
		fcppt::math::vector::static_<
			int,
			3
		>{
			1,
			2,
			3
		}
	);
}
