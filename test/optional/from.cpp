//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_ref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"optional::from",
	"[optiona]"
)
{
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	typedef
	fcppt::optional::reference<
		int
	>
	optional_int_ref;

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

	optional_int_unique_ptr const ptr(
		fcppt::optional::from(
			optional_int_unique_ptr(
				fcppt::make_unique_ptr<
					int
				>(
					42
				)
			),
			[]{
				return
					fcppt::make_unique_ptr<
						int
					>(
						10
					);
			}
		)
	);

	REQUIRE(
		ptr.has_value()
	);

	CHECK(
		*ptr.get_unsafe()
		==
		42
	);
}
