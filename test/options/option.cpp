//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/text.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/catch/record.hpp>
#include <fcppt/catch/strong_typedef.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_default_value.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/no_default_value.hpp>
#include <fcppt/options/option.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/record/comparison.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"options::option",
	"[options]"
)
{
	FCPPT_RECORD_MAKE_LABEL(
		arg_label
	);

	using
	int_option_type
	=
	fcppt::options::option<
		arg_label,
		int
	>;

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

	CHECK(
		fcppt::options::parse(
			int_option,
			fcppt::args_vector{
				FCPPT_TEXT("-f"),
				FCPPT_TEXT("42")
			}
		)
		==
		fcppt::options::make_success(
			int_option_type::result_type{
				arg_label{}
					= 42
			}
		)
	);

	CHECK(
		fcppt::options::parse(
			int_option,
			fcppt::args_vector{
				FCPPT_TEXT("--option"),
				FCPPT_TEXT("42")
			}
		)
		==
		fcppt::options::make_success(
			int_option_type::result_type{
				arg_label{}
					= 42
			}
		)
	);

	CHECK(
		fcppt::options::parse(
			int_option,
			fcppt::args_vector{
				FCPPT_TEXT("-something"),
				FCPPT_TEXT("42")
			}
		).has_failure()
	);

	CHECK(
		fcppt::options::parse(
			int_option,
			fcppt::args_vector{
				FCPPT_TEXT("--option")
			}
		).has_failure()
	);

	CHECK(
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

	CHECK(
		fcppt::options::parse(
			int_option_with_default,
			fcppt::args_vector{
				FCPPT_TEXT("-f"),
				FCPPT_TEXT("42")
			}
		)
		==
		fcppt::options::make_success(
			int_option_type::result_type{
				arg_label{}
					= 42
			}
		)
	);

	CHECK(
		fcppt::options::parse(
			int_option_with_default,
			fcppt::args_vector{
				FCPPT_TEXT("--option")
			}
		).has_failure()
	);

	CHECK(
		fcppt::options::parse(
			int_option_with_default,
			fcppt::args_vector{}
		)
		==
		fcppt::options::make_success(
			int_option_type::result_type{
				arg_label{}
					= 100
			}
		)
	);
}
