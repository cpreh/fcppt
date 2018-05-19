//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"algorithm::all_of",
	"[algorithm]"
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	CHECK(
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

	CHECK_FALSE(
		fcppt::algorithm::all_of(
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
					==
					0;
			}
		)
	);
}
