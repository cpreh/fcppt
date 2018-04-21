//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/unit_comparison.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/make_success.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/options/unit_switch.hpp>
#include <fcppt/record/comparison.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/variant/comparison.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	options_unit_switch
)
{
	FCPPT_RECORD_MAKE_LABEL(
		dummy_label
	);

	typedef
	fcppt::options::unit_switch<
		dummy_label
	>
	switch_type;

	typedef
	fcppt::options::result_of<
		switch_type
	>
	result_type;

	switch_type const switch_{
		fcppt::options::optional_short_name{
			fcppt::options::short_name{
				FCPPT_TEXT("f")
			}
		},
		fcppt::options::long_name{
			FCPPT_TEXT("flag")
		}
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
			result_type{
				dummy_label{}
					= fcppt::unit{}
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
			result_type{
				dummy_label{}
					= fcppt::unit{}
			}
		)
	);

	BOOST_CHECK(
		fcppt::options::parse(
			switch_,
			fcppt::args_vector{}
		).has_failure()
	);
}
