//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/insert.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <set>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	container_insert
)
{
	typedef
	std::set<
		int
	>
	int_set;

	int_set set{};

	BOOST_CHECK(
		fcppt::container::insert(
			set,
			1
		)
	);

	BOOST_CHECK(
		!fcppt::container::insert(
			set,
			1
		)
	);
}
