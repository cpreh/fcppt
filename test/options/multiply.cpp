//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/make_success.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/flag.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/multiply.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/record/comparison.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/variant/comparison.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	options_multiply
)
{
FCPPT_PP_POP_WARNING

	FCPPT_RECORD_MAKE_LABEL(
		arg_label
	);

	typedef
	fcppt::options::argument<
		arg_label,
		int
	>
	int_arg_type;

	FCPPT_RECORD_MAKE_LABEL(
		flag_label
	);

	typedef
	fcppt::options::flag<
		flag_label,
		int
	>
	int_flag_type;

	auto const mult_parser(
		fcppt::options::multiply(
			int_arg_type{
				fcppt::options::long_name{
					FCPPT_TEXT("arg1")
				},
				fcppt::options::optional_help_text{}
			},
			int_flag_type{
				fcppt::options::optional_short_name{
					fcppt::options::short_name{
						FCPPT_TEXT("f")
					}
				},
				fcppt::options::long_name{
					FCPPT_TEXT("flag")
				},
				int_flag_type::active_value{
					42
				},
				int_flag_type::inactive_value{
					10
				},
				fcppt::options::optional_help_text{}
			}
		)
	);

	auto const result(
		fcppt::options::parse(
			mult_parser,
			fcppt::args_vector{
				FCPPT_TEXT("--flag"),
				FCPPT_TEXT("123")
			}
		)
	);

	BOOST_CHECK(
		result
		==
		fcppt::either::make_success<
			fcppt::options::error
		>(
			decltype(
				mult_parser
			)::result_type{
				arg_label{}
					= 123,
				flag_label{}
					= 42
			}
		)
	);
}
