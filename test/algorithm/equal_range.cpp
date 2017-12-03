//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/equal_range.hpp>
#include <fcppt/iterator/range_empty.hpp>
#include <fcppt/iterator/singular_range.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <iterator>
#include <vector>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	algorithm_equal_range
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector const vec{
		2,
		5,
		7
	};

	{
		auto const result(
			fcppt::algorithm::equal_range(
				vec,
				3
			)
		);

		BOOST_CHECK(
			fcppt::iterator::range_empty(
				result
			)
		);
	}

	{
		auto const result(
			fcppt::algorithm::equal_range(
				vec,
				5
			)
		);

		BOOST_REQUIRE(
			fcppt::iterator::singular_range(
				result
			)
		);

		BOOST_CHECK(
			result.begin()
			==
			std::next(
				vec.begin(),
				1
			)
		);

		BOOST_CHECK(
			result.end()
			==
			std::next(
				vec.begin(),
				2
			)
		);
	}
}
