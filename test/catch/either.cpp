//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"catch::either",
	"[catch]"
)
{
	typedef
	fcppt::either::object<
		fcppt::string,
		int
	>
	either;

	CHECK(
		either{
			fcppt::string{
				FCPPT_TEXT("test")
			}
		}
		==
		either{
			fcppt::string{
				FCPPT_TEXT("test")
			}
		}
	);
}
