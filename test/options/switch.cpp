//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/options/switch.hpp>
#include <fcppt/record/comparison.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/output.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/variant/comparison.hpp>
#include <fcppt/variant/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"options::switch",
	"[options]"
)
{
	FCPPT_RECORD_MAKE_LABEL(
		arg_label
	);

	typedef
	fcppt::options::switch_<
		arg_label
	>
	switch_type;

	switch_type const switch_{
		fcppt::options::optional_short_name{
			fcppt::options::short_name{
				FCPPT_TEXT("f")
			}
		},
		fcppt::options::long_name{
			FCPPT_TEXT("flag")
		},
		fcppt::options::optional_help_text{}
	};

	CHECK(
		fcppt::options::parse(
			switch_,
			fcppt::args_vector{
				FCPPT_TEXT("-f")
			}
		)
		==
		fcppt::options::make_success(
			switch_type::result_type{
				arg_label{}
					= true
			}
		)
	);

	CHECK(
		fcppt::options::parse(
			switch_,
			fcppt::args_vector{
				FCPPT_TEXT("--flag")
			}
		)
		==
		fcppt::options::make_success(
			switch_type::result_type{
				arg_label{}
					= true
			}
		)
	);

	CHECK(
		fcppt::options::parse(
			switch_,
			fcppt::args_vector{}
		)
		==
		fcppt::options::make_success(
			switch_type::result_type{
				arg_label{}
					= false
			}
		)
	);
}
