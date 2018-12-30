//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/not.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/algorithm/fold.hpp>
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
#include <fcppt/parse/lexeme.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/separator.hpp>
#include <fcppt/parse/space_skipper.hpp>
#include <fcppt/parse/string.hpp>
#include <fcppt/parse/operators/alternative.hpp>
#include <fcppt/parse/operators/complement.hpp>
#include <fcppt/parse/operators/repetition.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <tuple>
#include <unordered_map>
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

struct array;

struct object;

typedef
fcppt::variant::variadic<
	json::null,
	bool,
	int,
	float,
	std::string,
	json::array,
	json::object
>
value;

struct array
{
	std::vector<
		json::value
	> impl_;
};

struct object
{
	explicit
	object(
		std::vector<
			std::tuple<
				std::string,
				json::value
			>
		> &&
	);

	std::unordered_map<
		std::string,
		json::value
	> impl_;
};

class double_insert
{
};

object::object(
	std::vector<
		std::tuple<
			std::string,
			json::value
		>
	> &&_args
)
:
	impl_{
		fcppt::algorithm::fold(
			fcppt::container::make_move_range(
				std::move(
					_args
				)
			),
			std::unordered_map<
				std::string,
				json::value
			>{},
			[](
				std::tuple<
					std::string,
					json::value
				> const &_element,
				std::unordered_map<
					std::string,
					json::value
				> &&_state
			)
			{
				if(
					fcppt::not_(
						fcppt::container::insert(
							_state,
							//std::move(
								_element
							//)
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
		)
	}
{
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
			parse::convert_const(parse::string("null"), json::null{})
			| (parse::convert_const(parse::string("true"), true)
				| parse::convert_const(parse::string("false"), false))
			| parse::int_<int>{}
			| parse::float_<float>{}

			| fcppt::make_cref(string_)
			| fcppt::make_cref(array_)
			| fcppt::make_cref(object_)
		)
	},
	object_{
		parse::make_base<char_type,skipper>(
			fcppt::parse::construct<json::object>(
				parse::literal('{')
				>> parse::separator(
					fcppt::make_cref(string_) >> parse::literal(':') >> fcppt::make_cref(value_), ',')
				>> parse::literal('}')
			)
		)
	},
	array_{
		parse::make_base<char_type,skipper>(
			fcppt::parse::construct<json::array>(
				parse::literal('[')
				>> parse::separator(
					fcppt::make_cref(value_), ',')
				>> parse::literal(']')
			)
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

TEST_CASE(
	"parse::json",
	"[parse]"
)
{
	parser const parser_{};

	fcppt::parse::parse_string(
		fcppt::parse::deref(
			parser_.get()
		),
		std::string{},
		fcppt::parse::space_skipper()
	);
}
