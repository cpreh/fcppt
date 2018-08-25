//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_char.hpp>
#include <fcppt/args_from_second.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/main.hpp>
#include <fcppt/make_cref.hpp>
#include <fcppt/string.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/help_text.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_commands.hpp>
#include <fcppt/options/make_optional.hpp>
#include <fcppt/options/make_sub_command.hpp>
#include <fcppt/options/no_default_value.hpp>
#include <fcppt/options/option.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/options_label.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/sub_command_label.hpp>
#include <fcppt/options/unit.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/variant/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wmissing-declarations)

int
FCPPT_MAIN(
	int argc,
	fcppt::args_char **argv
)
try
{
//![common_options]
	FCPPT_RECORD_MAKE_LABEL(
		git_directory
	);

	auto const options_parser{
		fcppt::options::make_optional(
			fcppt::options::option<
				git_directory,
				fcppt::string
			>{
				fcppt::options::optional_short_name{},
				fcppt::options::long_name{
					FCPPT_TEXT("git-dir")
				},
				fcppt::options::no_default_value<
					fcppt::string
				>(),
				fcppt::options::optional_help_text{
					fcppt::options::help_text{
						FCPPT_TEXT("The path to the repository")
					}
				}
			}
		)
	};
//![common_options]

//![sub_parsers]
	FCPPT_RECORD_MAKE_LABEL(
		clone_path
	);

	auto const clone_parser{
		fcppt::options::argument<
			clone_path,
			fcppt::string
		>(
			fcppt::options::long_name{
				FCPPT_TEXT("path")
			},
			fcppt::options::optional_help_text{
				fcppt::options::help_text{
					FCPPT_TEXT("The path to clone from")
				}
			}
		)
	};

	FCPPT_RECORD_MAKE_LABEL(
		pull_unit
	);

	auto const pull_parser{
		fcppt::options::unit<
			pull_unit
		>{}
	};
//![sub_parsers]

//![sub_commands]
	FCPPT_RECORD_MAKE_LABEL(
		clone_label
	);

	auto const clone_command{
		fcppt::options::make_sub_command<clone_label>(
			FCPPT_TEXT("clone"),
			fcppt::make_cref(clone_parser),
			fcppt::options::optional_help_text{
				fcppt::options::help_text{
					FCPPT_TEXT("Clone from another repository")
				}
			}
		)
	};

	FCPPT_RECORD_MAKE_LABEL(
		pull_label
	);

	auto const pull_command{
		fcppt::options::make_sub_command<pull_label>(
			FCPPT_TEXT("pull"),
			fcppt::make_cref(pull_parser),
			fcppt::options::optional_help_text{
				fcppt::options::help_text{
					FCPPT_TEXT("Pull all changes")
				}
			}
		)
	};
//![sub_commands]

//![commands]
	auto const commands{
		fcppt::options::make_commands(
			fcppt::make_cref(options_parser),
			fcppt::make_cref(clone_command),
			fcppt::make_cref(pull_command)
		)
	};
//![commands]

//![usage_git_dir]
	auto const on_success(
		[](fcppt::options::result_of<decltype(commands)> const &_result)
		{
			fcppt::optional::maybe_void(
				fcppt::record::get<git_directory>(
					fcppt::record::get<fcppt::options::options_label>(
						_result
					)
				),
				[](fcppt::string const &_dir)
				{
					fcppt::io::cout()
						<< FCPPT_TEXT("Git directory is ")
						<< _dir
						<< FCPPT_TEXT('\n');
				}
			);
//![usage_git_dir]

//![usage_sub_commands]
			fcppt::variant::match(
				fcppt::record::get<fcppt::options::sub_command_label>(_result),
				[](fcppt::options::result_of<decltype(clone_command)> const &_clone)
				{
					fcppt::io::cout()
						<< FCPPT_TEXT("Clone from ")
						<<
						fcppt::record::get<clone_path>(
							fcppt::record::get<clone_label>(
								_clone
							)
						)
						<< FCPPT_TEXT('\n');
				},
				[](fcppt::options::result_of<decltype(pull_command)> const &)
				{
					fcppt::io::cout()
						<< FCPPT_TEXT("pull\n");
				}
			);
		}
	);
//![usage_sub_commands]

//![main]
	fcppt::either::match(
		fcppt::options::parse(
			commands,
			fcppt::args_from_second(argc,argv)
		),
		[&commands]
		(fcppt::options::error const &_error)
		{
			fcppt::io::cerr()
				<< _error
				<< FCPPT_TEXT("\nUsage:\n")
				<< commands.usage()
				<< FCPPT_TEXT("\n");
		},
		on_success
	);
//![main]

	return
		EXIT_SUCCESS;
}
catch(
	fcppt::exception const &_exception
)
{
	fcppt::io::cerr()
		<<
		_exception.string()
		<<
		FCPPT_TEXT('\n');

	return
		EXIT_FAILURE;
}

FCPPT_PP_POP_WARNING
