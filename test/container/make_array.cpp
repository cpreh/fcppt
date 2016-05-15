//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/make_array.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <array>
#include <string>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_make_array
)
{
FCPPT_PP_POP_WARNING

	std::string const string_ref{
		"100"
	};

	std::array<
		std::string,
		2
	> const result(
		fcppt::container::make_array(
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
