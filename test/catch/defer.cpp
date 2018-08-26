//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/string.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/text.hpp>
#include <fcppt/catch/defer.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

FCPPT_MAKE_STRONG_TYPEDEF(
	fcppt::string,
	test_string
);

}

TEST_CASE(
	"catch::defer",
	"[catch]"
)
{
	CHECK(
		fcppt::catch_::defer(
			test_string{
				fcppt::string{
					FCPPT_TEXT("test")
				}
			}
			==
			test_string{
				fcppt::string{
					FCPPT_TEXT("test")
				}
			}
		)
	);
}
