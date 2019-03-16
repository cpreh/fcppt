//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/parse/grammar.hpp>
#include <fcppt/parse/int.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/space_skipper.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
decltype(
	fcppt::parse::space_skipper()
)
skipper;

typedef
fcppt::parse::grammar<
	int,
	char,
	skipper
>
grammar_base;

class grammar
:
	public grammar_base
{
	FCPPT_NONCOPYABLE(
		grammar
	);
public:
	grammar();

	~grammar();
private:
	grammar_base::base_type<
		int
	> start_;
};

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4355)

grammar::grammar()
:
	grammar_base{
		fcppt::make_cref(
			this->start_
		),
		fcppt::parse::space_skipper()
	},
	start_{
		this->make_base(
			fcppt::parse::int_<int>{}
		)
	}
{
}

FCPPT_PP_POP_WARNING

grammar::~grammar()
{
}

}

TEST_CASE(
	"parse::grammar",
	"[parse]"
)
{
	grammar const parser{};

	CHECK(
		fcppt::parse::parse_string(
			*parser.start(),
			std::string{
				" 42"
			},
			parser.skipper()
		)
		==
		fcppt::parse::make_success<
			char
		>(
			42
		)
	);
}
