//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/make_success.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_default_value.hpp>
#include <fcppt/options/no_default_value.hpp>
#include <fcppt/options/option.hpp>
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


BOOST_AUTO_TEST_CASE(
	options_option
)
{
	FCPPT_RECORD_MAKE_LABEL(
		arg_label
	);

	typedef
	fcppt::options::option<
		arg_label,
		int
	>
	int_option_type;

	int_option_type const int_option{
		fcppt::options::optional_short_name{
			fcppt::options::short_name{
				FCPPT_TEXT("f")
			}
		},
		fcppt::options::long_name{
			FCPPT_TEXT("option")
		},
		fcppt::options::no_default_value<
			int
		>(),
		fcppt::options::optional_help_text{}
	};

	BOOST_CHECK(
		fcppt::options::parse(
			int_option,
			fcppt::args_vector{
				FCPPT_TEXT("-f"),
				FCPPT_TEXT("42")
			}
		)
		==
		fcppt::either::make_success<
			fcppt::options::error
		>(
			int_option_type::result_type{
				arg_label{}
					= 42
			}
		)
	);

	BOOST_CHECK(
		fcppt::options::parse(
			int_option,
			fcppt::args_vector{
				FCPPT_TEXT("--option"),
				FCPPT_TEXT("42")
			}
		)
		==
		fcppt::either::make_success<
			fcppt::options::error
		>(
			int_option_type::result_type{
				arg_label{}
					= 42
			}
		)
	);

	BOOST_CHECK(
		fcppt::options::parse(
			int_option,
			fcppt::args_vector{
				FCPPT_TEXT("-something"),
				FCPPT_TEXT("42")
			}
		).has_failure()
	);

	BOOST_CHECK(
		fcppt::options::parse(
			int_option,
			fcppt::args_vector{
				FCPPT_TEXT("--option")
			}
		).has_failure()
	);

	BOOST_CHECK(
		fcppt::options::parse(
			int_option,
			fcppt::args_vector{
				FCPPT_TEXT("--flag")
			}
		).has_failure()
	);

	int_option_type const int_option_with_default{
		fcppt::options::optional_short_name{
			fcppt::options::short_name{
				FCPPT_TEXT("f")
			}
		},
		fcppt::options::long_name{
			FCPPT_TEXT("option")
		},
		fcppt::options::make_default_value(
			fcppt::optional::make(
				100
			)
		),
		fcppt::options::optional_help_text{}
	};

	BOOST_CHECK(
		fcppt::options::parse(
			int_option_with_default,
			fcppt::args_vector{
				FCPPT_TEXT("-f"),
				FCPPT_TEXT("42")
			}
		)
		==
		fcppt::either::make_success<
			fcppt::options::error
		>(
			int_option_type::result_type{
				arg_label{}
					= 42
			}
		)
	);

	BOOST_CHECK(
		fcppt::options::parse(
			int_option_with_default,
			fcppt::args_vector{
				FCPPT_TEXT("--option")
			}
		).has_failure()
	);

	BOOST_CHECK(
		fcppt::options::parse(
			int_option_with_default,
			fcppt::args_vector{}
		)
		==
		fcppt::either::make_success<
			fcppt::options::error
		>(
			int_option_type::result_type{
				arg_label{}
					= 100
			}
		)
	);
}
