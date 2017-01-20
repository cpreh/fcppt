//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_from_second.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/default_help_switch.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/error_output.hpp>
#include <fcppt/options/flag.hpp>
#include <fcppt/options/help_text.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/multiply.hpp>
#include <fcppt/options/option.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/parse_help.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/output.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


int
main(
	int argc,
	char **argv
)
{
	FCPPT_RECORD_MAKE_LABEL(
		arg_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		flag_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		option_label
	);

	typedef
	fcppt::options::argument<
		arg_label,
		fcppt::string
	>
	arg_type;

	typedef
	fcppt::options::flag<
		flag_label,
		int
	>
	flag_type;

	typedef
	fcppt::options::option<
		option_label,
		fcppt::string
	>
	option_type;

	auto const parser(
		fcppt::options::multiply(
			arg_type{
				fcppt::options::long_name{
					FCPPT_TEXT("arg")
				},
				fcppt::options::optional_help_text{
					fcppt::options::help_text{
						FCPPT_TEXT("The main argument")
					}
				}
			},
			flag_type{
				fcppt::options::optional_short_name{},
				fcppt::options::long_name{
					FCPPT_TEXT("flag")
				},
				flag_type::active_value{
					42
				},
				flag_type::inactive_value{
					0
				},
				fcppt::options::optional_help_text{
					fcppt::options::help_text{
						FCPPT_TEXT("Some flag")
					}
				}
			},
			option_type{
				fcppt::options::optional_short_name{
					fcppt::options::short_name{
						FCPPT_TEXT("o")
					}
				},
				fcppt::options::long_name{
					FCPPT_TEXT("option")
				},
				option_type::optional_default_value{
					fcppt::optional::make(
						fcppt::string{
							FCPPT_TEXT("default")
						}
					)
				},
				fcppt::options::optional_help_text{
					fcppt::options::help_text{
						FCPPT_TEXT("Some option")
					}
				}
			}
		)
	);

	typedef
	decltype(
		parser
	)::result_type
	result_type;

	return
		fcppt::variant::match(
			fcppt::options::parse_help(
				fcppt::options::default_help_switch(),
				parser,
				fcppt::args_from_second(
					argc,
					argv
				)
			),
			[](
				fcppt::options::result<
					result_type
				> const &_result
			)
			{
				return
					fcppt::either::match(
						_result,
						[](
							fcppt::options::error const &_error
						)
						{
							fcppt::io::cerr()
								<<
								_error
								<<
								FCPPT_TEXT('\n');

							return
								EXIT_FAILURE;
						},
						[](
							result_type const &_options
						)
						{
							fcppt::io::cout()
								<<
								FCPPT_TEXT("The result is ")
								<<
								_options
								<<
								FCPPT_TEXT('\n');

							return
								EXIT_SUCCESS;
						}
					);
			},
			[](
				fcppt::options::help_text const &_help_text
			)
			{
				fcppt::io::cout()
					<<
					_help_text
					<<
					FCPPT_TEXT('\n');

				return
					EXIT_SUCCESS;
			}
		);
}
