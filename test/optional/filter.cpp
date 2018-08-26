//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/catch/movable.hpp>
#include <fcppt/optional/filter.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"optional::filter",
	"[optional]"
)
{
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	auto const function(
		[](
			int const _value
		)
		{
			return
				_value
				==
				42;
		}
	);

	CHECK(
		fcppt::optional::filter(
			optional_int(
				42
			),
			function
		)
		==
		optional_int{
			42
		}
	);

	CHECK(
		fcppt::optional::filter(
			optional_int(
				10
			),
			function
		)
		==
		optional_int{}
	);

	CHECK(
		fcppt::optional::filter(
			optional_int(),
			function
		)
		==
		optional_int{}
	);
}

TEST_CASE(
	"optional::filter move",
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
		fcppt::optional::filter(
			optional_int_movable(
				int_movable{
					42
				}
			),
			[](
				int_movable const &_value
			)
			{
				return
					_value.value()
					==
					42;
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
