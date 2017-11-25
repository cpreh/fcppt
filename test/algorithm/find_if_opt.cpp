//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/find_if_opt.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <iterator>
#include <vector>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	algorithm_find_if_opt
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector const vec{
		1,
		2,
		3
	};

	BOOST_CHECK(
		fcppt::algorithm::find_if_opt(
			vec,
			[](
				int const _i
			)
			{
				return
					_i == 3;
			}
		).get_unsafe()
		==
		std::next(
			vec.begin(),
			2
		)
	);

	BOOST_CHECK(
		!fcppt::algorithm::find_if_opt(
			vec,
			[](
				int const _i
			)
			{
				return
					_i == 4;
			}
		).has_value()
	);
}
