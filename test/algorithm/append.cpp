//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/append.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"append with copy",
	"[algorithm]"
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector ints{
		1,2,3
	};

	fcppt::algorithm::append(
		ints,
		int_vector{
			4,5,6
		}
	);

	CHECK(
		ints
		==
		int_vector{
			1,2,3,4,5,6
		}
	);
}

TEST_CASE(
	"append with move",
	"[algorithm]"
)
{
	typedef
	fcppt::catch_::movable<
		int
	>
	movable;

	typedef
	std::vector<
		movable
	>
	movable_vector;

	movable_vector ints(
		fcppt::container::make<
			movable_vector
		>(
			movable{
				1
			},
			movable{
				2
			}
		)
	);

	fcppt::algorithm::append(
		ints,
		[]{
			return
				fcppt::container::make<
					movable_vector
				>(
					movable{
						3
					},
					movable{
						4
					}
				);
		}()
	);

	CHECK(
		ints
		==
		fcppt::container::make<
			movable_vector
		>(
			movable{
				1
			},
			movable{
				2
			},
			movable{
				3
			},
			movable{
				4
			}
		)
	);
}
