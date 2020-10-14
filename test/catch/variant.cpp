//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/catch/variant.hpp>
#include <fcppt/variant/comparison.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/variant/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"catch::variant",
	"[catch]"
)
{
	using
	variant
	=
	fcppt::variant::object<
		fcppt::string
	>;

	CHECK(
		variant{
			fcppt::string{
				FCPPT_TEXT("test")
			}
		}
		==
		variant{
			fcppt::string{
				FCPPT_TEXT("test")
			}
		}
	);
}
