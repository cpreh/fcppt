//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_homogenous_pair.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/comparison.hpp>
#include <fcppt/math/box/init_dim.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/math/box/rect.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::box::init_dim",
	"[math],[box]"
)
{
	typedef
	fcppt::math::box::rect<
		fcppt::math::size_type
	>
	box2;

	CHECK(
		fcppt::math::box::init_dim<
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
			box2::dim(
				0u,
				1u
			)
		)
	);
}
