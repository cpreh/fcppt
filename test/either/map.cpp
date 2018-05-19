//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"either::map",
	"[either]"
)
{
	typedef
	fcppt::either::object<
		std::string,
		int
	>
	either_int;

	typedef
	fcppt::either::object<
		std::string,
		bool
	>
	either_bool;

	auto const map_function(
		[](
			int const _value
		)
		{
			return
				_value
				>
				10;
		}
	);

	CHECK(
		fcppt::either::map(
			either_int(
				std::string(
					"test"
				)
			),
			map_function
		)
		==
		either_bool(
			std::string(
				"test"
			)
		)
	);

	CHECK(
		fcppt::either::map(
			either_int(
				20
			),
			map_function
		)
		==
		either_bool(
			true
		)
	);
}

TEST_CASE(
	"either::map move",
	"[either]"
)
{
	typedef
	fcppt::either::object<
		std::string,
		fcppt::unique_ptr<
			int
		>
	>
	either_int;

	FCPPT_MAKE_STRONG_TYPEDEF(
		fcppt::unique_ptr<
			int
		>,
		strong_int
	);

	auto const map_function(
		[](
			fcppt::unique_ptr<
				int
			> &&_ptr
		)
		{
			return
				strong_int{
					std::move(
						_ptr
					)
				};
		}
	);

	fcppt::either::match(
		fcppt::either::map(
			either_int(
				fcppt::make_unique_ptr<
					int
				>(
					20
				)
			),
			map_function
		),
		[](
			std::string const &
		)
		{
			CHECK(
				false
			);
		},
		[](
			strong_int const &_value
		)
		{
			CHECK(
				*_value.get()
				==
				20
			);
		}
	);
}
