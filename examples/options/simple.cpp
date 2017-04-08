//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_char.hpp>
#include <fcppt/args_from_second.hpp>
#include <fcppt/main.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/error_output.hpp>
#include <fcppt/options/help_text.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/make_label.hpp>
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
{
// ![options_label]
	FCPPT_RECORD_MAKE_LABEL(
		age_label
	);
// ![options_label]

// ![options_arg_type]
	typedef
	fcppt::options::argument<
		age_label,
		int
	>
	parser_type;

	typedef
	fcppt::options::result_of<
		parser_type
	>
	result_type;
// ![options_arg_type]

// ![options_arg_object]
	parser_type const parser{
		fcppt::options::long_name{
			FCPPT_TEXT("age")
		},
		fcppt::options::optional_help_text{
			fcppt::options::help_text{
				FCPPT_TEXT("Your age")
			}
		}
	};
// ![options_arg_object]

// ![options_args_from_second]
	fcppt::args_vector const args(
		fcppt::args_from_second(
			argc,
			argv
		)
	);
// ![options_args_from_second]

// ![options_parse]
	fcppt::options::result<
		result_type
	> const result{
		fcppt::options::parse(
			parser,
			args
		)
	};
// ![options_parse]

// ![options_on_success]
	auto const on_success(
		[](
			result_type const &_result
		)
		{
			fcppt::io::cout()
				<<
				FCPPT_TEXT("Your age is ")
				<<
				fcppt::record::get<
					age_label
				>(
					_result
				)
				<<
				FCPPT_TEXT('\n');

			return
				EXIT_SUCCESS;
		}
	);
// ![options_on_success]

// ![options_on_failure]
	auto const on_failure(
		[
			&parser
		](
			fcppt::options::error const &_error
		)
		{
			fcppt::io::cerr()
				<<
				_error
				<<
				FCPPT_TEXT('\n')
				<<
				FCPPT_TEXT("Usage: ")
				<<
				parser.usage()
				<<
				FCPPT_TEXT('\n');

			return
				EXIT_FAILURE;
		}
	);
// ![options_on_failure]

// ![options_match]
	return
		fcppt::either::match(
			result,
			on_failure,
			on_success
		);
// ![options_match]
}

FCPPT_PP_POP_WARNING
