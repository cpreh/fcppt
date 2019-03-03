//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/not.hpp>
#include <fcppt/recursive.hpp>
#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/catch/convert.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/catch/recursive.hpp>
#include <fcppt/catch/strong_typedef.hpp>
#include <fcppt/catch/variant.hpp>
#include <fcppt/container/insert.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/container/make_move_range.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/parse/base_unique_ptr.hpp>
#include <fcppt/parse/char_set.hpp>
#include <fcppt/parse/construct.hpp>
#include <fcppt/parse/convert_const.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/int.hpp>
#include <fcppt/parse/literal.hpp>
#include <fcppt/parse/make_base.hpp>
#include <fcppt/parse/make_convert.hpp>
#include <fcppt/parse/make_lexeme.hpp>
#include <fcppt/parse/make_recursive.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/parse_string.hpp>
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
	typedef
	fcppt::variant::variadic<
		json::null,
		bool,
		int,
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
	>
	type;

	explicit
	value(
		type &&_impl
	)
	:
	impl{
		std::move(
			_impl
		)
	}
	{
	}

	type impl;
};

template<
	typename Type
>
fcppt::recursive<
	json::value
>
make_value(
	Type &&_value
)
{
	return
		fcppt::recursive<
			json::value
		>{
			json::value{
				json::value::type{
					std::forward<
						Type
					>(
						_value
					)
				}
			}
		};
}

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
			parse::literal('"')
			>> parse::make_lexeme(*~parse::char_set{'"'})
			>> parse::literal('"')
		)
	},
	value_{
		parse::make_base<char_type,skipper>(
			parse::construct<json::value>(
				parse::convert_const(parse::string("null"), json::null{})
				| (parse::convert_const(parse::string("true"), true)
					| parse::convert_const(parse::string("false"), false))
				| parse::int_<int>{}
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
					>> parse::make_recursive(fcppt::make_cref(value_)),
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
				parse::make_recursive(fcppt::make_cref(value_)),
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

namespace json
{

fcppt::either::object<
	fcppt::parse::error<
		char
	>,
	json::start
>
parse_string(
	parser const &,
	std::string &&
);

fcppt::either::object<
	fcppt::parse::error<
		char
	>,
	json::start
>
parse_string(
	parser const &_parser,
	std::string &&_input
)
{
	return
		fcppt::parse::parse_string(
			fcppt::parse::deref(
				_parser.get()
			),
			std::move(
				_input
			),
			fcppt::parse::space_skipper()
		);
}

fcppt::either::object<
	fcppt::parse::error<
		char
	>,
	json::start
>
make_success(
	json::start &&
);

fcppt::either::object<
	fcppt::parse::error<
		char
	>,
	json::start
>
make_success(
	json::start &&_value
)
{
	return
		fcppt::parse::make_success<
			char
		>(
			std::move(
				_value
			)
		);
}

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
	"parse::json base",
	"[parse]"
)
{
	parser const parser_{};

	CHECK(
		json::parse_string(
			parser_,
			std::string{}
		).has_failure()
	);

	CHECK(
		json::parse_string(
			parser_,
			std::string{"[]"}
		)
		==
		json::make_success(
			json::start{
				json::array{}
			}
		)
	);

	CHECK(
		json::parse_string(
			parser_,
			std::string{"[1]"}
		)
		==
		json::make_success(
			json::start{
				fcppt::container::make<
					json::array
				>(
					json::make_value(
						1
					)
				)
			}
		)
	);

	CHECK(
		json::parse_string(
			parser_,
			std::string{"[null]"}
		)
		==
		json::make_success(
			json::start{
				fcppt::container::make<
					json::array
				>(
					json::make_value(
						json::null{}
					)
				)
			}
		)
	);

	CHECK(
		json::parse_string(
			parser_,
			std::string{"[true]"}
		)
		==
		json::make_success(
			json::start{
				fcppt::container::make<
					json::array
				>(
					json::make_value(
						true
					)
				)
			}
		)
	);

	CHECK(
		json::parse_string(
			parser_,
			std::string{"[false]"}
		)
		==
		json::make_success(
			json::start{
				fcppt::container::make<
					json::array
				>(
					json::make_value(
						false
					)
				)
			}
		)
	);

	CHECK(
		json::parse_string(
			parser_,
			std::string{"[ \"test\" ]"}
		)
		==
		json::make_success(
			json::start{
				fcppt::container::make<
					json::array
				>(
					json::make_value(
						std::string{"test"}
					)
				)
			}
		)
	);

	CHECK(
		json::parse_string(
			parser_,
			std::string{"[1, true]"}
		)
		==
		json::make_success(
			json::start{
				fcppt::container::make<
					json::array
				>(
					json::make_value(
						1
					),
					json::make_value(
						true
					)
				)
			}
		)
	);
}

TEST_CASE(
	"parse::json object",
	"[parse]"
)
{
	parser const parser_{};

	CHECK(
		json::parse_string(
			parser_,
			std::string{"{}"}
		)
		==
		json::make_success(
			json::start{
				json::object{}
			}
		)
	);

	CHECK(
		json::parse_string(
			parser_,
			std::string{"{\"XY\":42}"}
		)
		==
		json::make_success(
			json::start{
				fcppt::container::make<
					json::object
				>(
					json::object::value_type{
						std::string{"XY"},
						json::make_value(
							42
						)
					}
				)
			}
		)
	);

	CHECK(
		json::parse_string(
			parser_,
			std::string{" { \"XY\" : 42 }"}
		)
		==
		json::make_success(
			json::start{
				fcppt::container::make<
					json::object
				>(
					json::object::value_type{
						std::string{"XY"},
						json::make_value(
							42
						)
					}
				)
			}
		)
	);

	CHECK(
		json::parse_string(
			parser_,
			std::string{"{"
				"\"X\" : true,"
				"\"Y\" : [ 10, false, null ],"
				"\"Z\" : { \"A\" : \"test\", \"B\" : 20 }"
			"}"}
		)
		==
		json::make_success(
			json::start{
				fcppt::container::make<
					json::object
				>(
					json::object::value_type{
						std::string{"X"},
						json::make_value(
							true
						)
					},
					json::object::value_type{
						std::string{"Y"},
						json::make_value(
							fcppt::container::make<
								json::array
							>(
								json::make_value(
									10
								),
								json::make_value(
									false
								),
								json::make_value(
									json::null{}
								)
							)
						)
					},
					json::object::value_type{
						std::string{"Z"},
						json::make_value(
							fcppt::container::make<
								json::object
							>(
								json::object::value_type{
									std::string{"A"},
									json::make_value(
										std::string{"test"}
									)
								},
								json::object::value_type{
									std::string{"B"},
									json::make_value(
										20
									)
								}
							)
						)
					}
				)
			}
		)
	);
}
