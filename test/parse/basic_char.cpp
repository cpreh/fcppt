//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/parse/basic_char.hpp>
#include <fcppt/parse/parse_noskip.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <sstream>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"prase::basic_char",
	"[parse]"
)
{
	fcppt::parse::basic_char<
		char
	> const parser{};

	{
		std::istringstream stream{
			""
		};

		CHECK(
			fcppt::parse::parse_noskip(
				parser,
				stream
			)
			==
			fcppt::optional::object<
				char
			>{}
		);
	}

	{
		std::istringstream stream{
			"X"
		};

		CHECK(
			fcppt::parse::parse_noskip(
				parser,
				stream
			)
			==
			fcppt::optional::make(
				'X'
			)
		);
	}
}
