//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/either/match.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"either::match",
	"[either]"
)
{
	using
	either_int
	=
	fcppt::either::object<
		std::string,
		int
	>;

	auto const success_function(
		[](
			int const _value
		)
		{
			return
				std::string(
					"success: "
				)
				+
				std::to_string(
					_value
				);
		}
	);

	auto const failure_function(
		[](
			std::string const &_value
		)
		{
			return
				std::string(
					"failure: "
				)
				+
				_value;
		}
	);

	CHECK(
		fcppt::either::match(
			either_int(
				std::string(
					"test"
				)
			),
			failure_function,
			success_function
		)
		==
		std::string(
			"failure: test"
		)
	);

	CHECK(
		fcppt::either::match(
			either_int(
				42
			),
			failure_function,
			success_function
		)
		==
		std::string(
			"success: 42"
		)
	);
}
