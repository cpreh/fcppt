//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_ref.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"optional::from",
	"[optiona]"
)
{
	using
	optional_int
	=
	fcppt::optional::object<
		int
	>;

	using
	optional_int_ref
	=
	fcppt::optional::reference<
		int
	>;

	CHECK(
		fcppt::optional::from(
			optional_int(),
			[]
			{
				return
					42; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			}
		)
		==
		42 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	CHECK(
		fcppt::optional::from(
			optional_int(
				100 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			),
			[]
			{
				return
					42; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			}
		)
		==
		100 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	int x{
		42 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	};

	int y{
		0
	};

	fcppt::optional::from(
		optional_int_ref{
			fcppt::make_ref(
				x
			)
		},
		[
			&y
		]()
		{
			return
				fcppt::make_ref(
					y
				);
		}
	).get() =
		100; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)

	CHECK(
		x
		==
		100 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);
}

TEST_CASE(
	"optional::from move",
	"[optiona;]"
)
{
	using
	int_movable
	=
	fcppt::catch_::movable<
		int
	>;

	CHECK(
		fcppt::optional::from(
			fcppt::optional::make(
				int_movable{
					42 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
				}
			),
			[]{
				return
					int_movable{
						10 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
					};
			}
		)
		==
		int_movable{
			42 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		}
	);
}
