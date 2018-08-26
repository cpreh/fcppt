//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/output_to_fcppt_string.hpp>
#include <fcppt/output_to_std_string.hpp>
#include <fcppt/output_to_std_string_convert.hpp>
#include <fcppt/output_to_std_wstring.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"output_to_string",
	"[string]"
)
{
	CHECK(
		fcppt::output_to_fcppt_string(
			42
		)
		==
		fcppt::string{
			FCPPT_TEXT("42")
		}
	);

	CHECK(
		fcppt::output_to_std_string(
			42
		)
		==
		std::string{
			"42"
		}
	);

	CHECK(
		fcppt::output_to_std_wstring(
			42
		)
		==
		std::wstring{
			L"42"
		}
	);

	CHECK(
		fcppt::output_to_std_string_convert(
			42
		)
		==
		std::string{
			"42"
		}
	);
}
