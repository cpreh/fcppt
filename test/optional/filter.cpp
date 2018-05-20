//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/optional/filter.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
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
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::optional::object<
		int_unique_ptr
	>
	optional_int_unique_ptr;

	optional_int_unique_ptr const result(
		fcppt::optional::filter(
			optional_int_unique_ptr(
				fcppt::make_unique_ptr<
					int
				>(
					42
				)
			),
			[](
				int_unique_ptr const &_value
			)
			{
				return
					*_value
					==
					42;
			}
		)
	);

	REQUIRE(
		result.has_value()
	);

	CHECK(
		*result.get_unsafe()
		==
		42
	);
}
