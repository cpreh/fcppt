//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_commands.hpp>
#include <fcppt/options/make_sub_command.hpp>
#include <fcppt/options/no_default_value.hpp>
#include <fcppt/options/option.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/output.hpp>
#include <fcppt/variant/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	options_commands
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
				FCPPT_TEXT("test"),
				int_arg{
					fcppt::options::long_name{
						FCPPT_TEXT("arg1")
					},
					fcppt::options::optional_help_text{}
				}
			)
		)
	};

	fcppt::io::cout()
		<<
		fcppt::options::parse(
			commands,
			fcppt::args_vector{
				FCPPT_TEXT("--option"),
				FCPPT_TEXT("10"),
				FCPPT_TEXT("test"),
				FCPPT_TEXT("0")
			}
		)
		<<
		FCPPT_TEXT('\n');
}
