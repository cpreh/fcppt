//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/text.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/catch/record.hpp>
#include <fcppt/catch/strong_typedef.hpp>
#include <fcppt/catch/variant.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/duplicate_names.hpp>
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
#include <fcppt/options/unit.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object.hpp>
#include <fcppt/variant/comparison.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
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

	FCPPT_RECORD_MAKE_LABEL(
		command_foo_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		command_bar_label
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
			fcppt::options::make_sub_command<
				command_foo_label
			>(
				FCPPT_TEXT("foo"),
				int_arg{
					fcppt::options::long_name{
						FCPPT_TEXT("arg1")
					},
					fcppt::options::optional_help_text{}
				},
				fcppt::options::optional_help_text{}
			),
			fcppt::options::make_sub_command<
				command_bar_label
			>(
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
	fcppt::record::object<
		fcppt::record::element<
			command_foo_label,
			int_arg::result_type
		>
	>
	command_foo_result_type;

	typedef
	fcppt::record::object<
		fcppt::record::element<
			command_bar_label,
			int_option::result_type
		>
	>
	command_bar_result_type;

	typedef
	fcppt::variant::variadic<
		command_foo_result_type,
		command_bar_result_type
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
						command_foo_result_type{
							command_foo_label{} =
								int_arg::result_type{
									arg_label{}
										= 0
								}
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
						command_bar_result_type{
							command_bar_label{} =
								int_option::result_type{
									option_label{}
										= 0
								}
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

TEST_CASE(
	"options::commands duplicate names",
	"[options]"
)
{
	FCPPT_RECORD_MAKE_LABEL(
		unit_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		command_1_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		command_2_label
	);

	CHECK_THROWS_AS(
		fcppt::options::make_commands(
			fcppt::options::unit<
				unit_label
			>{},
			fcppt::options::make_sub_command<
				command_1_label
			>(
				FCPPT_TEXT("foo"),
				fcppt::options::unit<
					unit_label
				>{},
				fcppt::options::optional_help_text{}
			),
			fcppt::options::make_sub_command<
				command_2_label
			>(
				FCPPT_TEXT("foo"),
				fcppt::options::unit<
					unit_label
				>{},
				fcppt::options::optional_help_text{}
			)

		),
		fcppt::options::duplicate_names
	);
}
