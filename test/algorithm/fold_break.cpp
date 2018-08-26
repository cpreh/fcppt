//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/loop.hpp>
#include <fcppt/algorithm/fold_break.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"algorithm fold_break"
	"[algorithm_fold_break]"
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	CHECK(
		fcppt::algorithm::fold_break(
			int_vector{
				1,
				2,
				3,
				4
			},
			0,
			[](
				int const _element,
				int const _sum
			)
			{
				int const result{
					_element
					+
					_sum
				};

				return
					std::make_pair(
						result
						<=
						5
						?
							fcppt::loop::continue_
						:
							fcppt::loop::break_
						,
						result
					);
			}
		)
		==
		6
	);
}

TEST_CASE(
	"algorithm fold_break move"
	"[algorithm_fold_break]"
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	typedef
	fcppt::catch_::movable<
		int
	>
	int_movable;

	CHECK(
		fcppt::algorithm::fold_break(
			int_vector{
				1,
				2,
				3,
				4
			},
			int_movable{
				0
			},
			[](
				int const _element,
				int_movable &&_sum
			)
			{
				_sum.value()
					+=
					_element;

				fcppt::loop const loop{
					_sum.value()
					<=
					5
					?
						fcppt::loop::continue_
					:
						fcppt::loop::break_
				};

				return
					std::make_pair(
						loop,
						std::move(
							_sum
						)
					);
			}
		).value()
		==
		6
	);
}
