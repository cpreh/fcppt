//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/ptr/push_back_unique_ptr.hpp>
#include <fcppt/container/ptr/insert_unique_ptr.hpp>
#include <fcppt/container/ptr/insert_unique_ptr_set.hpp>
#include <fcppt/container/ptr/insert_unique_ptr_map.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/ptr_container/ptr_set.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(
	ptr_container
)
{
	typedef fcppt::unique_ptr<
		std::string
	> string_unique_ptr;

	typedef boost::ptr_vector<
		std::string
	> string_ptr_vector;

	string_ptr_vector vector;

	fcppt::container::ptr::push_back_unique_ptr(
		vector,
		fcppt::make_unique_ptr<
			std::string
		>(
			"test1"
		)
	);

	string_ptr_vector::iterator const insert_pos(
		fcppt::container::ptr::insert_unique_ptr(
			vector,
			vector.begin(),
			fcppt::make_unique_ptr<
				std::string
			>(
				"test2"
			)
		)
	);

	BOOST_REQUIRE(
		insert_pos
		== vector.begin()
	);

	BOOST_REQUIRE(
		vector.size() == 2
	);

	BOOST_REQUIRE(
		vector[0] == "test2"
	);

	BOOST_REQUIRE(
		vector[1] == "test1"
	);
}

BOOST_AUTO_TEST_CASE(
	ptr_container_multi_set
)
{
	typedef boost::ptr_multiset<
		std::string
	> string_ptr_multiset;

	string_ptr_multiset set;

	fcppt::container::ptr::insert_unique_ptr_set(
		set,
		fcppt::make_unique_ptr<
			std::string
		>(
			"test"
		)
	);

	BOOST_REQUIRE(
		!set.empty()
	);

	BOOST_REQUIRE(
		*set.begin() == "test"
	);
}

BOOST_AUTO_TEST_CASE(
	ptr_container_map
)
{
	typedef boost::ptr_map<
		int,
		std::string
	> int_string_ptr_map;

	int_string_ptr_map map;

	fcppt::container::ptr::insert_unique_ptr_map(
		map,
		42,
		fcppt::make_unique_ptr<
			std::string
		>(
			"test"
		)
	);

	BOOST_REQUIRE(
		!map.empty()
	);

	BOOST_REQUIRE(
		map.begin()->first == 42
		&& *map.begin()->second == "test"
	);
}
