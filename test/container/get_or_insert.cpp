//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/get_or_insert.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <map>
#include <string>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_get_or_insert
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::map<
		int,
		std::string
	>
	int_string_map;

	int_string_map map;

	auto const inserter(
		[](
			int const _value
		)
		{
			return
				std::to_string(
					_value
				);
		}
	);

	std::string &inserted(
		fcppt::container::get_or_insert(
			map,
			42,
			inserter
		)
	);

	BOOST_REQUIRE(
		map.find(
			42
		)
		!=
		map.end()
	);

	BOOST_CHECK_EQUAL(
		&inserted,
		&map.find(
			42
		)->second
	);

	BOOST_CHECK_EQUAL(
		map.find(
			42
		)->second,
		"42"
	);

	BOOST_CHECK_EQUAL(
		fcppt::container::get_or_insert(
			map,
			42,
			inserter
		),
		map.find(
			42
		)->second
	);
}
