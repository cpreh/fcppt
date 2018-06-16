//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/text.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/unit_comparison.hpp>
#include <fcppt/unit_output.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/make_sum.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/unit_switch.hpp>
#include <fcppt/record/comparison.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/output.hpp>
#include <fcppt/variant/comparison.hpp>
#include <fcppt/variant/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"options::sum",
	"[options]"
)
{
	FCPPT_RECORD_MAKE_LABEL(
		left_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		right_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		unit_label
	);

	typedef
	fcppt::options::unit_switch<
		unit_label
	>
	unit_parser;

	auto const sum(
		fcppt::options::make_sum<
			left_label,
			right_label
		>(
			unit_parser{
				fcppt::options::optional_short_name{},
				fcppt::options::long_name{
					FCPPT_TEXT("left")
				}
			},
			unit_parser{
				fcppt::options::optional_short_name{},
				fcppt::options::long_name{
					FCPPT_TEXT("right")
				}
			}
		)
	);

	typedef
	decltype(
		sum
	)
	parser_type;

	CHECK(
		fcppt::options::parse(
			sum,
			fcppt::args_vector{
				FCPPT_TEXT("--left")
			}
		)
		==
		fcppt::options::make_success(
			fcppt::options::result_of<
				parser_type
			>{
				fcppt::options::result_of<
					parser_type::left
				>(
					left_label{} =
						fcppt::options::result_of<
							unit_parser
						>{
							unit_label{} =
								fcppt::unit{}
						}
				)
			}
		)
	);

	CHECK(
		fcppt::options::parse(
			sum,
			fcppt::args_vector{
				FCPPT_TEXT("--right")
			}
		)
		==
		fcppt::options::make_success(
			fcppt::options::result_of<
				parser_type
			>{
				fcppt::options::result_of<
					parser_type::right
				>(
					right_label{} =
						fcppt::options::result_of<
							unit_parser
						>{
							unit_label{} =
								fcppt::unit{}
						}
				)
			}
		)
	);

	CHECK(
		fcppt::options::parse(
			sum,
			fcppt::args_vector{}
		).has_failure()
	);
}
