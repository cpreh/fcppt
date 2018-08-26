//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/const.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/optional/alternative.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
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
	fcppt::catch_::movable<
		int
	>
	int_movable;

	typedef
	fcppt::optional::object<
		int_movable
	>
	optional_int_movable;

	CHECK(
		fcppt::optional::alternative(
			optional_int_movable{
				int_movable{
					42
				}
			},
			[]{
				return
					optional_int_movable{};
			}
		)
		==
		optional_int_movable{
			int_movable{
				42
			}
		}
	);
}
