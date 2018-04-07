//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/array/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <array>
#include <string>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	array_make
)
{
	std::string const string_ref{
		"100"
	};

	std::array<
		std::string,
		2
	> const result(
		fcppt::container::array::make(
			std::string{"42"},
			string_ref
		)
	);

	BOOST_CHECK_EQUAL(
		std::get<
			0
		>(
			result
		),
		std::string{
			"42"
		}
	);

	BOOST_CHECK_EQUAL(
		std::get<
			1
		>(
			result
		),
		std::string{
			"100"
		}
	);
}
