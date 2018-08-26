//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/to_signed.hpp>
#include <fcppt/math/matrix/binary_map.hpp>
#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::matrix::binary_map",
	"[math],[matrix]"
)
{
	typedef
	fcppt::math::matrix::static_<
		unsigned,
		2,
		2
	>
	ui2_matrix;

	typedef
	fcppt::math::matrix::static_<
		int,
		2,
		2
	>
	i2_matrix;

	CHECK(
		fcppt::math::matrix::binary_map(
			ui2_matrix{
				fcppt::math::matrix::row(
					5u,10u
				),
				fcppt::math::matrix::row(
					15u,20u
				)
			},
			i2_matrix{
				fcppt::math::matrix::row(
					1,2
				),
				fcppt::math::matrix::row(
					3,4
				)
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
		i2_matrix(
			fcppt::math::matrix::row(
				6,12
			),
			fcppt::math::matrix::row(
				18,24
			)
		)
	);
}
