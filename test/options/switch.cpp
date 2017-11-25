//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/make_success.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/options/switch.hpp>
#include <fcppt/record/comparison.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/variant/comparison.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	options_switch
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

	BOOST_CHECK(
		fcppt::options::parse(
			switch_,
			fcppt::args_vector{
				FCPPT_TEXT("-f")
			}
		)
		==
		fcppt::either::make_success<
			fcppt::options::error
		>(
			switch_type::result_type{
				arg_label{}
					= true
			}
		)
	);

	BOOST_CHECK(
		fcppt::options::parse(
			switch_,
			fcppt::args_vector{
				FCPPT_TEXT("--flag")
			}
		)
		==
		fcppt::either::make_success<
			fcppt::options::error
		>(
			switch_type::result_type{
				arg_label{}
					= true
			}
		)
	);

	BOOST_CHECK(
		fcppt::options::parse(
			switch_,
			fcppt::args_vector{}
		)
		==
		fcppt::either::make_success<
			fcppt::options::error
		>(
			switch_type::result_type{
				arg_label{}
					= false
			}
		)
	);
}
