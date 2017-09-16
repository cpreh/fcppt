//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/map_values_copy.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_map_values_copy
)
{
FCPPT_PP_POP_WARNING

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

	string_vector const strings(
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
	);

	BOOST_REQUIRE_EQUAL(
		strings.size(),
		2u
	);

	BOOST_CHECK_EQUAL(
		strings[0],
		"test1"
	);

	BOOST_CHECK_EQUAL(
		strings[1],
		"test2"
	);
}
