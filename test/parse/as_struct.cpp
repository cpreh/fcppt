//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/parse/as_struct.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/error_equal.hpp>
#include <fcppt/parse/error_output.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/parse/skipper/epsilon.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <ostream>
#include <string>
#include <tuple>
#include <fcppt/config/external_end.hpp>


namespace
{

class my_struct
{
public:
	my_struct(
		char const _x,
		char const _y
	)
	:
		x_{
			_x
		},
		y_{
			_y
		}
	{
	}

	[[nodiscard]]
	char const &
	x() const
	{
		return
			x_;
	}

	[[nodiscard]]
	char const &
	y() const
	{
		return
			y_;
	}
private:
	char x_;

	char y_;
};

bool
operator==(
	my_struct const &_left,
	my_struct const &_right
)
{
	return
		std::tie(
			_left.x(),
			_left.y()
		)
		==
		std::tie(
			_right.x(),
			_right.y()
		);
}

std::ostream &
operator<<(
	std::ostream &_stream,
	my_struct const &_value
)
{
	return
		_stream
		<< '('
		<< _value.x()
		<< ','
		<< _value.y()
		<< ')';
}

}

TEST_CASE(
	"parse::as_struct",
	"[parse]"
)
{
	auto const parser(
		fcppt::parse::as_struct<
			my_struct
		>(
			fcppt::parse::char_{}
			>>
			fcppt::parse::char_{}
		)
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"XY"
			},
			fcppt::parse::skipper::epsilon{}
		)
		==
		fcppt::parse::make_success<
			char
		>(
			my_struct{
				'X',
				'Y'
			}
		)
	);
}
