//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"variant::match",
	"[variant]"
)
{
	typedef
	fcppt::variant::object<
		int,
		std::string
	>
	variant;

	std::string const result(
		fcppt::variant::match(
			variant(
				42
			),
			[](
				int const _value
			)
			{
				return
					std::to_string(
						_value
					);
			},
			[](
				std::string const &_value
			)
			{
				return
					_value;
			}
		)
	);

	CHECK(
		result
		==
		"42"
	);
}

TEST_CASE(
	"variant::match move",
	"[variant]"
)
{
	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::variant::object<
		int_unique_ptr,
		std::string
	>
	variant;

	std::string const result(
		fcppt::variant::match(
			variant(
				fcppt::make_unique_ptr<
					int
				>(
					42
				)
			),
			[](
				int_unique_ptr &&_value
			)
			{
				return
					std::to_string(
						*_value
					);
			},
			[](
				std::string const &_value
			)
			{
				return
					_value;
			}
		)
	);

	CHECK(
		result
		==
		"42"
	);
}
