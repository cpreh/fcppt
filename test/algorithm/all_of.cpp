//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	algorithm_all_of
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	BOOST_CHECK(
		fcppt::algorithm::all_of(
			int_vector{
				2,
				4,
				6
			},
			[](
				int const _val
			)
			{
				return
					_val % 2
					== 0;
			}
		)
	);

	BOOST_CHECK(
		!fcppt::algorithm::all_of(
			int_vector{
				2,
				3,
				4,
				6
			},
			[](
				int const _val
			)
			{
				return
					_val % 2
					== 0;
			}
		)
	);
}
