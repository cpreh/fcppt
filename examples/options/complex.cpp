//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

// TODO: Output openmode properly
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wsign-promo)

#include <fcppt/args_from_second.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/filesystem/ifstream.hpp>
#include <fcppt/filesystem/ofstream.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_input.hpp>
#include <fcppt/log/level_output.hpp>
#include <fcppt/log/name.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/parameters.hpp>
#include <fcppt/log/optional_level.hpp>
#include <fcppt/log/format/optional_function.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/default_help_switch.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/error_output.hpp>
#include <fcppt/options/flag.hpp>
#include <fcppt/options/help_text.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_optional.hpp>
#include <fcppt/options/apply.hpp>
#include <fcppt/options/option.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/parse_help.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/options/switch.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/output.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <ios>
#include <fcppt/config/external_end.hpp>


int
main(
	int argc,
	char **argv
)
{
// ![options_labels]
	FCPPT_RECORD_MAKE_LABEL(
		input_file_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		output_file_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		execute_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		openmode_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		log_level_label
	);
// ![options_labels]

// ![options_input_file_option]
	typedef
	fcppt::options::argument<
		input_file_label,
		fcppt::string
	>
	input_file_option;

	input_file_option const input_file{
		fcppt::options::long_name{
			FCPPT_TEXT("Input filename")
		},
		fcppt::options::optional_help_text{
			fcppt::options::help_text{
				FCPPT_TEXT("The name of the input file to copy")
			}
		}
	};
// ![options_input_file_option]

// ![options_output_file_option]
	typedef
	fcppt::options::argument<
		output_file_label,
		fcppt::string
	>
	output_file_option;

	typedef
	fcppt::options::optional<
		output_file_option
	>
	optional_output_file_option;

	optional_output_file_option const output_file{
		fcppt::options::make_optional(
			output_file_option{
				fcppt::options::long_name{
					FCPPT_TEXT("Output filename")
				},
				fcppt::options::optional_help_text{
					fcppt::options::help_text{
						FCPPT_TEXT("The name of the output file. Defaults to input_file.bak")
					}
				}
			}
		)
	};
// ![options_output_file_option]

// ![options_execute_switch]
	typedef
	fcppt::options::switch_<
		execute_label
	>
	execute_switch;

	execute_switch const execute{
		fcppt::options::optional_short_name{
			fcppt::options::short_name{
				FCPPT_TEXT("e")
			}
		},
		fcppt::options::long_name{
			FCPPT_TEXT("execute")
		},
		fcppt::options::optional_help_text{
			fcppt::options::help_text{
				FCPPT_TEXT("Whether to actually execute the actions")
			}
		}
	};
// ![options_execute_switch]

// ![options_openmode_option]
	typedef
	fcppt::options::flag<
		openmode_label,
		std::ios_base::openmode
	>
	openmode_option;

	openmode_option const openmode{
		fcppt::options::optional_short_name{},
		fcppt::options::long_name{
			FCPPT_TEXT("trunc")
		},
		openmode_option::active_value{
			std::ios_base::trunc
		},
		openmode_option::inactive_value{
			std::ios_base::openmode{}
		},
		fcppt::options::optional_help_text{
			fcppt::options::help_text{
				FCPPT_TEXT("Whether to truncate the output file")
			}
		}
	};
// ![options_openmode_option]

// ![options_log_level_option]
	typedef
	fcppt::options::option<
		log_level_label,
		fcppt::log::level
	>
	log_level_option;

	log_level_option const log_level{
		fcppt::options::optional_short_name{
			fcppt::options::short_name{
				FCPPT_TEXT("l")
			}
		},
		fcppt::options::long_name{
			FCPPT_TEXT("loglevel")
		},
		log_level_option::optional_default_value{
			fcppt::optional::make(
				fcppt::log::level::warning
			)
		},
		fcppt::options::optional_help_text{
			fcppt::options::help_text{
				FCPPT_TEXT("The log level to use")
			}
		}
	};
// ![options_log_level_option]

// ![options_parser]
	auto const parser(
		fcppt::options::apply(
			input_file,
			output_file,
			execute,
			openmode,
			log_level
		)
	);

	typedef
	fcppt::options::result_of<
		decltype(
			parser
		)
	>
	result_type;
// ![options_parser]

// ![options_main_program]
	auto const main_program(
		[](
			result_type const &_result
		)
		-> bool
		{
// ![options_main_program]

// ![options_read_execute]
			if(
				!fcppt::record::get<
					execute_label
				>(
					_result
				)
			)
				return
					false;
// ![options_read_execute]

// ![options_log_context]
			fcppt::log::context log_context{
				fcppt::log::optional_level{
					fcppt::record::get<
						log_level_label
					>(
						_result
					)
				},
				fcppt::log::default_level_streams()
			};
// ![options_log_context]

			fcppt::log::object logger{
				log_context,
				fcppt::log::parameters{
					fcppt::log::name{
						FCPPT_TEXT("options")
					},
					fcppt::log::format::optional_function{}
				}
			};

// ![options_open_input]
			fcppt::filesystem::ifstream input{
				fcppt::record::get<
					input_file_label
				>(
					_result
				)
			};
// ![options_open_input]

// ![options_output_filename]
			fcppt::string const output_filename{
				fcppt::optional::from(
					fcppt::record::get<
						output_file_label
					>(
						_result
					),
					[
						&_result
					]{
						return
							fcppt::record::get<
								input_file_label
							>(
								_result
							)
							+
							FCPPT_TEXT(".bak");
					}
				)
			};
// ![options_output_filename]

// ![options_open_output]
			fcppt::filesystem::ofstream output{
				output_filename,
				fcppt::record::get<
					openmode_label
				>(
					_result
				)
			};
// ![options_open_output]

			// ...

			return
				true;
		}
	);

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
			[
				main_program
			](
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
						[
							main_program
						](
							result_type const &_options
						)
						{
							if(
								!main_program(
									_options
								)
							)
								fcppt::io::cout()
									<<
									FCPPT_TEXT("The result is:\n")
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
				// TODO: Make it possible to use boolalpha
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

FCPPT_PP_POP_WARNING
