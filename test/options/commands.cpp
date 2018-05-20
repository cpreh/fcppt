//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/text.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_commands.hpp>
#include <fcppt/options/make_sub_command.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/no_default_value.hpp>
#include <fcppt/options/option.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/options_label.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/sub_command_label.hpp>
#include <fcppt/record/comparison.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/output.hpp>
#include <fcppt/variant/comparison.hpp>
#include <fcppt/variant/output.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"options::commands",
	"[options]"
)
{
	FCPPT_RECORD_MAKE_LABEL(
		arg_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		option_label
	);

	typedef
	fcppt::options::argument<
		arg_label,
		int
	>
	int_arg;

	typedef
	fcppt::options::option<
		option_label,
		int
	>
	int_option;

	auto const commands{
		fcppt::options::make_commands(
			int_option{
				fcppt::options::optional_short_name{},
				fcppt::options::long_name{
					FCPPT_TEXT("option")
				},
				fcppt::options::no_default_value<
					int
				>(),
				fcppt::options::optional_help_text{}
			},
			fcppt::options::make_sub_command(
				FCPPT_TEXT("foo"),
				int_arg{
					fcppt::options::long_name{
						FCPPT_TEXT("arg1")
					},
					fcppt::options::optional_help_text{}
				},
				fcppt::options::optional_help_text{}
			),
			fcppt::options::make_sub_command(
				FCPPT_TEXT("bar"),
				int_option{
					fcppt::options::optional_short_name{},
					fcppt::options::long_name{
						FCPPT_TEXT("option")
					},
					fcppt::options::no_default_value<
						int
					>(),
					fcppt::options::optional_help_text{}
				},
				fcppt::options::optional_help_text{}
			)

		)
	};

	typedef
	fcppt::options::result_of<
		decltype(
			commands
		)
	>
	result_type;

	typedef
	fcppt::variant::variadic<
		int_arg::result_type,
		int_option::result_type
	>
	command_result_type;

	CHECK(
		fcppt::options::parse(
			commands,
			fcppt::args_vector{
				FCPPT_TEXT("--option"),
				FCPPT_TEXT("10"),
				FCPPT_TEXT("foo"),
				FCPPT_TEXT("0")
			}
		)
		==
		fcppt::options::make_success(
			result_type{
				fcppt::options::options_label{} =
					int_option::result_type{
						option_label{} =
							10
					},
				fcppt::options::sub_command_label{} =
					command_result_type{
						int_arg::result_type{
							arg_label{}
								= 0
						}
					}
			}
		)
	);

	CHECK(
		fcppt::options::parse(
			commands,
			fcppt::args_vector{
				FCPPT_TEXT("--option"),
				FCPPT_TEXT("10"),
				FCPPT_TEXT("bar"),
				FCPPT_TEXT("--option"),
				FCPPT_TEXT("0")
			}
		)
		==
		fcppt::options::make_success(
			result_type{
				fcppt::options::options_label{} =
					int_option::result_type{
						option_label{} =
							10
					},
				fcppt::options::sub_command_label{} =
					command_result_type{
						int_option::result_type{
							option_label{}
								= 0
						}
					}
			}
		)
	);

	CHECK(
		fcppt::options::parse(
			commands,
			fcppt::args_vector{
				FCPPT_TEXT("test"),
			}
		).has_failure()
	);

	CHECK(
		fcppt::options::parse(
			commands,
			fcppt::args_vector{
				FCPPT_TEXT("foo"),
				FCPPT_TEXT("0"),
			}
		).has_failure()
	);

	CHECK(
		fcppt::options::parse(
			commands,
			fcppt::args_vector{
				FCPPT_TEXT("--option"),
				FCPPT_TEXT("10"),
				FCPPT_TEXT("foo"),
			}
		).has_failure()
	);
}
