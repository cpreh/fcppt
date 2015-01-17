//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/container/find_exn.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <map>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_find_exn
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::map<
		int,
		std::string
	>
	int_string_map;

	int_string_map const values{
		std::make_pair(
			42,
			std::string(
				"test"
			)
		),
		std::make_pair(
			100,
			std::string(
				"test2"
			)
		)
	};

	auto const throw_function(
		[]
		{
			return
				fcppt::exception{
					fcppt::string()
				};
		}
	);

	BOOST_CHECK(
		fcppt::container::find_exn(
			values,
			42,
			throw_function
		)
		==
		"test"
	);

	auto const check_exception(
		[](
			fcppt::exception const &
		)
		{
			return
				true;
		}
	);

	BOOST_CHECK_EXCEPTION(
		fcppt::container::find_exn(
			values,
			50,
			throw_function
		),
		fcppt::exception,
		check_exception
	);
}
