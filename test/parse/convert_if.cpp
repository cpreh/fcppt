//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/construct.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/epsilon.hpp>
#include <fcppt/parse/make_convert_if.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <ostream>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace
{

struct my_struct
{
	explicit
	my_struct(
		char const _x
	)
	:
		x_{
			_x
		}
	{
	}

	char x_;
};

bool
operator==(
	my_struct const &_left,
	my_struct const &_right
)
{
	return
		_left.x_
		==
		_right.x_;
}

std::ostream &
operator<<(
	std::ostream &_stream,
	my_struct const &_value
)
{
	return
		_stream
		<<
		_value.x_;
}

}

TEST_CASE(
	"parse::convert_if",
	"[parse]"
)
{
	auto const parser(
		fcppt::parse::make_convert_if(
			fcppt::parse::char_{},
			[](
				char const _value
			)
			{
				return
					fcppt::either::construct(
						_value
						==
						'X',
						[
							_value
						]{
							return
								my_struct{
									_value
								};
						},
						[]{
							return
								fcppt::parse::error<
									char
								>{
									"Invalid value"
								};
						}
					);
			}
		)
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"X"
			},
			fcppt::parse::epsilon{}
		)
		==
		fcppt::parse::make_success<
			char
		>(
			my_struct{
				'X'
			}
		)
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"Y"
			},
			fcppt::parse::epsilon{}
		).has_failure()
	);
}
