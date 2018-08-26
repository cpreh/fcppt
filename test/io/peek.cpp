//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/peek.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <sstream>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"io::peek",
	"[io]"
)
{
	typedef
	fcppt::optional::object<
		char
	>
	optional_char;

	{
		std::istringstream stream{
			"x"
		};

		CHECK(
			fcppt::io::peek(
				stream
			)
			==
			optional_char{
				'x'
			}
		);
	}

	{
		std::istringstream stream{};

		CHECK(
			fcppt::io::peek(
				stream
			)
			==
			optional_char{}
		);
	}
}
