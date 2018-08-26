//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/grid/clamped_sup_signed.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/to_unsigned.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::grid::clamped_sup_signed",
	"[container],[grid]"
)
{
	typedef
	fcppt::container::grid::dim<
		unsigned,
		2
	>
	dim;

	typedef
	fcppt::container::grid::pos<
		int,
		2
	>
	pos;

	CHECK(
		fcppt::container::grid::clamped_sup_signed(
			pos(
				-1,
				5
			),
			dim(
				3u,
				3u
			)
		).get()
		==
		fcppt::math::vector::to_unsigned(
			pos(
				0,
				3
			)
		)
	);
}
