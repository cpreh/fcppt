//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/key_set.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <map>
#include <set>
#include <string>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	algorithm_key_set
)
{
	typedef
	std::set<
		int
	>
	int_set;

	typedef
	std::map<
		int,
		std::string
	>
	int_string_map;

	int_string_map const map{
		std::make_pair(
			42,
			std::string(
				"test"
			)
		),
		std::make_pair(
			10,
			std::string(
				"test2"
			)
		)
	};

	int_set const keys(
		fcppt::algorithm::key_set<
			int_set
		>(
			map
		)
	);

	BOOST_CHECK((
		keys
		==
		int_set{
			10,
			42
		}
	));
}
