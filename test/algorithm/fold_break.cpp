//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/loop.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/algorithm/fold_break.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <functional>
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
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	CHECK(
		*fcppt::algorithm::fold_break(
			int_vector{
				1,
				2,
				3,
				4
			},
			fcppt::make_unique_ptr<
				int
			>(
				0
			),
			[](
				int const _element,
				int_unique_ptr &&_sum
			)
			{
				*_sum
					+=
					_element;

				fcppt::loop const loop{
					*_sum
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
		)
		==
		6
	);
}
