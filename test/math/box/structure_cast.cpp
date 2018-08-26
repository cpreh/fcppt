//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/float_to_int_fun.hpp>
#include <fcppt/math/box/comparison.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/math/box/structure_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::box::structure_cast",
	"[math],[box]"
)
{
	typedef
	fcppt::math::box::object<
		float,
		2
	>
	box_f2;

	typedef
	fcppt::math::box::object<
		int,
		2
	>
	box_i2;

	CHECK(
		fcppt::math::box::structure_cast<
			box_i2,
			fcppt::cast::float_to_int_fun
		>(
			box_f2{
				box_f2::vector(
					1.5f,
					2.5f
				),
				box_f2::dim(
					3.5f,
					4.5f
				)
			}
		)
		==
		box_i2(
			box_i2::vector(
				1,
				2
			),
			box_i2::dim(
				3,
				4
			)
		)
	);
}
