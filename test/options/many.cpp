//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/text.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/catch/record.hpp>
#include <fcppt/catch/strong_typedef.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_many.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/record/comparison.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"options::many",
	"[options]"
)
{
	FCPPT_RECORD_MAKE_LABEL(
		arg_label
	);

	auto const parser{
		fcppt::options::make_many(
			fcppt::options::argument<
				arg_label,
				int
			>{
				fcppt::options::long_name{
					FCPPT_TEXT("arg1")
				},
				fcppt::options::optional_help_text{}
			}
		)
	};

	typedef
	decltype(
		parser
	)
	parser_type;

	CHECK(
		fcppt::options::parse(
			parser,
			fcppt::args_vector{
				FCPPT_TEXT("123"),
				FCPPT_TEXT("456")
			}
		)
		==
		fcppt::options::make_success(
			parser_type::result_type{
				arg_label{} =
					std::vector<
						int
					>{
						123,
						456
					}
			}
		)
	);

	CHECK(
		fcppt::options::parse(
			parser,
			fcppt::args_vector{
				FCPPT_TEXT("123"),
				FCPPT_TEXT("test")
			}
		).has_failure()
	);

	CHECK(
		fcppt::options::parse(
			parser,
			fcppt::args_vector{}
		)
		==
		fcppt::options::make_success(
			parser_type::result_type{
				arg_label{} =
					std::vector<
						int
					>{}
			}
		)
	);
}
