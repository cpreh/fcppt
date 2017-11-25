//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/assign/make_container.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <map>
#include <set>
#include <vector>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	assign_make_container_vector
)
{
	typedef
	std::vector<
		int
	>
	sequence;

	sequence const c(
		fcppt::assign::make_container<
			sequence
		>(
			3,
			4,
			5
		)
	);

	BOOST_REQUIRE_EQUAL(
		c.size(),
		3u
	);

	BOOST_CHECK_EQUAL(
		c[0],
		3
	);

	BOOST_CHECK_EQUAL(
		c[1],
		4
	);

	BOOST_CHECK_EQUAL(
		c[2],
		5
	);
}

BOOST_AUTO_TEST_CASE(
	assign_make_container_set
)
{
	typedef
	std::set<
		int
	>
	set;

	set const c(
		fcppt::assign::make_container<
			set
		>(
			3,
			4,
			5
		)
	);

	BOOST_CHECK_EQUAL(
		c.size(),
		3u
	);

	BOOST_CHECK_EQUAL(
		c.count(3),
		1u
	);

	BOOST_CHECK_EQUAL(
		c.count(4),
		1u
	);

	BOOST_CHECK_EQUAL(
		c.count(5),
		1u
	);
}

BOOST_AUTO_TEST_CASE(
	assign_make_container_map
)
{
	typedef
	std::map<
		int,
		int
	>
	map;

	map const m(
		fcppt::assign::make_container<
			map
		>(
			map::value_type(
				3,
				2
			),
			map::value_type(
				4,
				5
			)
		)
	);

	BOOST_CHECK_EQUAL(
		m.size(),
		2u
	);

	BOOST_REQUIRE(
		m.find(3)
		!=
		m.end()
	);

	BOOST_CHECK_EQUAL(
		m.find(3)->second,
		2
	);

	BOOST_REQUIRE(
		m.find(4)
		!=
		m.end()
	);

	BOOST_CHECK_EQUAL(
		m.find(4)->second,
		5
	);
}
