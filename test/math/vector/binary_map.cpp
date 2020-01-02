//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/to_signed.hpp>
#include <fcppt/math/vector/binary_map.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::vector::binary_map",
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
		fcppt::math::vector::binary_map(
			ui2_vector{
				10u,
				20u
			},
			i2_vector{
				3,
				5
			},
			[](
				unsigned const _val1,
				int const _val2
			)
			{
				return
					fcppt::cast::to_signed(
						_val1
					)
					+
					_val2;
			}
		)
		==
		i2_vector(
			13,
			25
		)
	);
}
