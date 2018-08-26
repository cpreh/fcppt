//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"optional::bind",
	"[optional]"
)
{
	typedef
	fcppt::optional::object<
		std::string
	>
	optional_string;

	CHECK(
		fcppt::optional::bind(
			optional_string{
				"test2"
			},
			[](
				std::string const &_value
			)
			{
				return
					optional_string{
						"test1"
						+
						_value
					};
			}
		)
		==
		optional_string{
			"test1test2"
		}
	);

	CHECK(
		fcppt::optional::bind(
			optional_string{
				"test2"
			},
			[](
				std::string const &
			)
			{
				return
					optional_string{};
			}
		)
		==
		optional_string{}
	);
}
