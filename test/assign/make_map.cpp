//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/assign/make_map.hpp>
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
	assign_make_map
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::map<
		int,
		std::string
	>
	map;

	int const i{
		5
	};

	std::string const baz{
		"baz"
	};

	map const m(
		fcppt::assign::make_map<
			map
		>
		(
			3,
			"foo"
		)(
			4,
			"bar"
		)(
			i,
			baz
		)
	);

	BOOST_CHECK_EQUAL(
		m.size(),
		3
	);

	BOOST_REQUIRE(
		m.find(3)
		!=
		m.end()
	);

	BOOST_CHECK_EQUAL(
		m.find(3)->second,
		"foo"
	);

	BOOST_REQUIRE(
		m.find(4)
		!=
		m.end()
	);

	BOOST_CHECK_EQUAL(
		m.find(4)->second,
		"bar"
	);

	BOOST_REQUIRE(
		m.find(5)
		!=
		m.end()
	);

	BOOST_CHECK_EQUAL(
		m.find(5)->second,
		"baz"
	);
}
