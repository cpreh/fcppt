//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/iterator/make_range.hpp>
#include <fcppt/range/empty.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	range_empty
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector vec1{
		1,
		2
	};

	BOOST_CHECK(
		fcppt::range::empty(
			fcppt::iterator::make_range(
				vec1.begin(),
				vec1.begin()
			)
		)
	);

	BOOST_CHECK(
		!fcppt::range::empty(
			fcppt::iterator::make_range(
				vec1.begin(),
				vec1.end()
			)
		)
	);
}
