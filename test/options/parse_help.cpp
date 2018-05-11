//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/default_help_switch.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/help_result.hpp>
#include <fcppt/options/help_text.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/parse_help.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/record/comparison.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/variant/comparison.hpp>
#include <fcppt/variant/holds_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	options_parse_help
)
{
	FCPPT_RECORD_MAKE_LABEL(
		arg_label
	);

	typedef
	fcppt::options::argument<
		arg_label,
		int
	>
	int_arg_type;

	int_arg_type const int_arg{
		fcppt::options::long_name{
			FCPPT_TEXT("arg1")
		},
		fcppt::options::optional_help_text{}
	};

	BOOST_CHECK(
		fcppt::variant::holds_type<
			fcppt::options::help_text
		>(
			fcppt::options::parse_help(
				fcppt::options::default_help_switch(),
				int_arg,
				fcppt::args_vector{
					FCPPT_TEXT("--help")
				}
			)
		)
	);

	BOOST_CHECK(
		fcppt::options::parse_help(
			fcppt::options::default_help_switch(),
			int_arg,
			fcppt::args_vector{
				FCPPT_TEXT("1")
			}
		)
		==
		fcppt::options::help_result<
			fcppt::options::result_of<
				int_arg_type
			>
		>{
			fcppt::options::make_success(
				int_arg_type::result_type{
					arg_label{}
						= 1
				}
			)
		}
	);
}
