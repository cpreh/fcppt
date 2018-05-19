//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/box/corner_points.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::box::corner_points",
	"[math],[box]"
)
{
	typedef
	fcppt::math::box::object<
		int,
		2
	>
	box_type;

	CHECK(
		fcppt::math::box::corner_points(
			box_type{
				box_type::vector{
					10,
					12
				},
				box_type::dim{
					24,
					26
				}
			}
		)
		==
		std::array<
			box_type::vector,
			4
		>{
			box_type::vector(
				10,
				12
			),
			box_type::vector(
				34,
				12
			),
			box_type::vector(
				10,
				38
			),
			box_type::vector(
				34,
				38
			)
		}
	);
}
