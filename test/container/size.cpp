//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <list>
#include <vector>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	container_size
)
{
	std::list<
		int
	> const test{
		1,
		2,
		3,
		4
	};

	std::vector<
		int
	> test2{
		1,
		2
	};

	BOOST_CHECK_EQUAL(
		fcppt::container::size(
			test
		),
		4u
	);

	BOOST_CHECK_EQUAL(
		fcppt::container::size(
			test2
		),
		2u
	);

}
