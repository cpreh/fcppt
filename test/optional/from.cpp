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
					42;
			}
		)
		==
		42
	);

	CHECK(
		fcppt::optional::from(
			optional_int(
				100
			),
			[]
			{
				return
					42;
			}
		)
		==
		100
	);

	int x{
		42
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
		100;

	CHECK(
		x
		==
		100
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
					42
				}
			),
			[]{
				return
					int_movable{
						10
					};
			}
		)
		==
		int_movable{
			42
		}
	);
}
