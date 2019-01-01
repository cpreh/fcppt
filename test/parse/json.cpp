//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/not.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/recursive.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/catch/convert.hpp>
#include <fcppt/catch/recursive.hpp>
#include <fcppt/catch/variant.hpp>
#include <fcppt/container/insert.hpp>
#include <fcppt/container/make_move_range.hpp>
#include <fcppt/parse/base_unique_ptr.hpp>
#include <fcppt/parse/char_set.hpp>
#include <fcppt/parse/construct.hpp>
#include <fcppt/parse/convert_const.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/float.hpp>
#include <fcppt/parse/int.hpp>
#include <fcppt/parse/literal.hpp>
#include <fcppt/parse/make_base.hpp>
#include <fcppt/parse/make_convert.hpp>
#include <fcppt/parse/lexeme.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/recursive.hpp>
#include <fcppt/parse/separator.hpp>
#include <fcppt/parse/space_skipper.hpp>
#include <fcppt/parse/string.hpp>
#include <fcppt/parse/operators/alternative.hpp>
#include <fcppt/parse/operators/complement.hpp>
#include <fcppt/parse/operators/repetition.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/variant/comparison.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <unordered_map>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace
{

namespace json
{

struct null
{
};

bool
operator==(
	json::null const &,
	json::null const &
);

bool
operator==(
	json::null const &,
	json::null const &
)
{
	return
		true;
}

struct value
{
	fcppt::variant::variadic<
		json::null,
		bool,
		int,
		float,
		std::string,
		std::vector<
			fcppt::recursive<
				json::value
			>
		>,
		std::unordered_map<
			std::string,
			fcppt::recursive<
				json::value
			>
		>
	> impl;
};

bool
operator==(
	json::value const &,
	json::value const &
);

bool
operator==(
	json::value const &_left,
	json::value const &_right
)
{
	return
		_left.impl
		==
		_right.impl;
}

typedef
std::vector<
	fcppt::recursive<
		json::value
	>
>
array;

typedef
std::unordered_map<
	std::string,
	fcppt::recursive<
		json::value
	>
>
object;

class double_insert
{
};

typedef
std::vector<
	std::tuple<
		std::string,
		fcppt::recursive<
			json::value
		>
	>
>
entries;

object
make_object(
	entries &&
);

object
make_object(
	entries &&_args
)
{
	return
		fcppt::algorithm::fold(
			fcppt::container::make_move_range(
				std::move(
					_args
				)
			),
			object{},
			[](
				std::tuple<
					std::string,
					fcppt::recursive<
						json::value
					>
				> &&_element,
				object &&_state
			)
			{
				if(
					fcppt::not_(
						fcppt::container::insert(
							_state,
							object::value_type{
								std::move(
									std::get<0>(_element)
								),
								std::move(
									std::get<1>(_element)
								)
							}
						)
					)
				)
					throw
						double_insert{};

			return
				std::move(
					_state
				);
			}
		);
}

typedef
fcppt::variant::variadic<
	json::array,
	json::object
>
start;

}

typedef
char
char_type;

typedef
decltype(
	fcppt::parse::space_skipper()
)
skipper;

template<
	typename Type
>
using
base
=
fcppt::parse::base_unique_ptr<
	Type,
	char_type,
	skipper
>;

class parser
{
	FCPPT_NONCOPYABLE(
		parser
	);
public:
	parser();

	~parser()
	{
	}

	base<json::start> const &
	get() const
	{
		return start_;
	}
private:
	base<std::string> string_;

	base<json::value> value_;

	base<json::object> object_;

	base<json::array> array_;

	base<json::start> start_;
};

namespace parse = fcppt::parse;

parser::parser()
:
	string_{
		parse::make_base<char_type,skipper>(
			parse::lexeme(parse::literal('"') >> *~parse::char_set{'"'} >> parse::literal('"'))
		)
	},
	value_{
		parse::make_base<char_type,skipper>(
			parse::construct<json::value>(
				parse::convert_const(parse::string("null"), json::null{})
				| (parse::convert_const(parse::string("true"), true)
					| parse::convert_const(parse::string("false"), false))
				| parse::int_<int>{}
				| parse::float_<float>{}

				| fcppt::make_cref(string_)
				| fcppt::make_cref(array_)
				| fcppt::make_cref(object_)
			)
		)
	},
	object_{
		parse::make_base<char_type,skipper>(
			parse::make_convert(
				parse::literal('{')
				>> parse::separator(
					fcppt::make_cref(string_)
					>> parse::literal(':')
					>> parse::recursive{fcppt::make_cref(value_)},
					',')
				>> parse::literal('}'),
				[](json::entries &&_entries) { return json::make_object(std::move(_entries)); }
			)
		)
	},
	array_{
		parse::make_base<char_type,skipper>(
			parse::literal('[')
			>> parse::separator(
				parse::recursive{fcppt::make_cref(value_)},
				',')
			>> parse::literal(']')
		)
	},
	start_{
		parse::make_base<char_type,skipper>(
			fcppt::make_cref(array_) | fcppt::make_cref(object_)
		)
	}
{
}

}

namespace Catch
{

template<>
struct StringMaker<
	json::null
>
{
	static
	std::string
	convert(
		json::null const &
	)
	{
		return
			std::string{"null"};
	}
};

template<>
struct StringMaker<
	json::value
>
{
	static
	std::string
	convert(
		json::value const &_value
	)
	{
		return
			fcppt::catch_::convert(
				_value.impl
			);
	}
};

}

TEST_CASE(
	"parse::json",
	"[parse]"
)
{
	parser const parser_{};

	CHECK(
		fcppt::parse::parse_string(
			fcppt::parse::deref(
				parser_.get()
			),
			std::string{},
			fcppt::parse::space_skipper()
		).has_failure()
	);
}
