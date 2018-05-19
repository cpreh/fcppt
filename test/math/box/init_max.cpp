//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_homogenous_pair.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/comparison.hpp>
#include <fcppt/math/box/init_max.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/math/box/rect.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::box::init_max",
	"[math],[box]"
)
{
	typedef
	fcppt::math::box::rect<
		fcppt::math::size_type
	>
	box2;

	CHECK(
		fcppt::math::box::init_max<
			box2
		>(
			[](
				auto const _index
			)
			{
				return
					fcppt::make_homogenous_pair(
						_index(),
						_index()
					);
			}
		)
		==
		box2(
			box2::vector(
				0u,
				1u
			),
			box2::vector(
				0u,
				1u
			)
		)
	);
}
