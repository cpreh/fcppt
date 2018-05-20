//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/unique_ptr.hpp>
#include <fcppt/unique_ptr_from_std.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"unique_ptr_from_std",
	"[smartptr]"
)
{
	fcppt::optional::maybe(
		fcppt::unique_ptr_from_std(
			std::make_unique<
				int
			>(
				42
			)
		),
		[]{
			CHECK(
				false
			);
		},
		[](
			fcppt::unique_ptr<
				int
			> const &_ptr
		)
		{
			CHECK(
				*_ptr
				==
				42
			);
		}
	);

	CHECK_FALSE(
		fcppt::unique_ptr_from_std(
			std::unique_ptr<
				int
			>{}
		).has_value()
	);
}
