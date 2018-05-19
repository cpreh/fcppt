//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/map_values_copy.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::map_values_copy",
	"[container]"
)
{
	typedef
	std::vector<
		std::string
	>
	string_vector;

	typedef
	std::map<
		int,
		std::string
	>
	int_string_map;

	CHECK(
		fcppt::container::map_values_copy<
			string_vector
		>(
			int_string_map{
				std::make_pair(
					1,
					"test1"
				),
				std::make_pair(
					2,
					"test2"
				)
			}
		)
		==
		string_vector{
			std::string{
				"test1"
			},
			std::string{
				"test2"
			}
		}
	);
}
