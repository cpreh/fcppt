//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/const.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/optional/alternative.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"optional::alternative",
	"[optional]"
)
{
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	CHECK(
		fcppt::optional::alternative(
			optional_int(
				42
			),
			fcppt::const_(
				optional_int(
					10
				)
			)
		)
		==
		optional_int(
			42
		)
	);

	CHECK(
		fcppt::optional::alternative(
			optional_int(),
			fcppt::const_(
				optional_int(
					10
				)
			)
		)
		==
		optional_int(
			10
		)
	);

	CHECK(
		fcppt::optional::alternative(
			optional_int(),
			fcppt::const_(
				optional_int()
			)
		)
		==
		optional_int()
	);

	optional_int const value{};

	CHECK(
		fcppt::optional::alternative(
			value,
			fcppt::const_(
				optional_int{
					42
				}
			)
		)
		==
		optional_int{
			42
		}
	);
}

TEST_CASE(
	"optional::alternative move",
	"[optional]"
)
{
	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::optional::object<
		int_unique_ptr
	>
	optional_int_unique_ptr;

	fcppt::optional::maybe(
		fcppt::optional::alternative(
			optional_int_unique_ptr(
				fcppt::make_unique_ptr<
					int
				>(
					42
				)
			),
			[]{
				return
					optional_int_unique_ptr();
			}
		),
		[]{
			CHECK(
				false
			);
		},
		[](
			int_unique_ptr const &_ptr
		)
		{
			CHECK(
				*_ptr
				==
				42
			);
		}
	);
}
