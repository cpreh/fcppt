//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference.hpp>
#include <fcppt/reference_output.hpp>
#include <fcppt/container/map_values_ref.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	container_map_values_ref
)
{
	typedef
	std::vector<
		fcppt::reference<
			std::string
		>
	>
	string_vector_ref;

	typedef
	std::vector<
		fcppt::reference<
			std::string const
		>
	>
	string_vector_cref;

	typedef
	std::map<
		int,
		std::string
	>
	int_string_map;

	int_string_map map{
		std::make_pair(
			1,
			"test1"
		),
		std::make_pair(
			2,
			"test2"
		)
	};

	{
		string_vector_ref const strings_ref(
			fcppt::container::map_values_ref<
				string_vector_ref
			>(
				map
			)
		);

		BOOST_REQUIRE_EQUAL(
			strings_ref.size(),
			2u
		);

		BOOST_CHECK_EQUAL(
			strings_ref[0],
			fcppt::make_ref(
				map[1]
			)
		);

		BOOST_CHECK_EQUAL(
			strings_ref[1],
			fcppt::make_ref(
				map[2]
			)
		);
	}

	{
		string_vector_cref const strings_cref(
			fcppt::container::map_values_ref<
				string_vector_cref
			>(
				map
			)
		);

		BOOST_REQUIRE_EQUAL(
			strings_cref.size(),
			2u
		);

		BOOST_CHECK_EQUAL(
			strings_cref[0],
			fcppt::make_cref(
				map[1]
			)
		);

		BOOST_CHECK_EQUAL(
			strings_cref[1],
			fcppt::make_cref(
				map[2]
			)
		);
	}
}
