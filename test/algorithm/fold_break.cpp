//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/loop.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/algorithm/fold_break.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <functional>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	algorithm_fold_break
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector const vector{
		1,
		2,
		3,
		4
	};

	int const sum(
		fcppt::algorithm::fold_break(
			vector,
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
	);

	BOOST_CHECK_EQUAL(
		sum,
		6
	);
}

BOOST_AUTO_TEST_CASE(
	algorithm_fold_break_move
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector const vector{
		1,
		2,
		3,
		4
	};

	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	int_unique_ptr const sum_ptr(
		fcppt::algorithm::fold_break(
			vector,
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
	);

	BOOST_CHECK_EQUAL(
		*sum_ptr,
		6
	);
}
