//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/options/apply.hpp>
#include <fcppt/options/duplicate_names.hpp>
#include <fcppt/options/flag.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_active_value.hpp>
#include <fcppt/options/make_inactive_value.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"options multiple args",
	"[options]"
)
{
	FCPPT_RECORD_MAKE_LABEL(
		flag_label1
	);

	FCPPT_RECORD_MAKE_LABEL(
		flag_label2
	);

	typedef
	fcppt::options::flag<
		flag_label1,
		int
	>
	flag1_type;

	typedef
	fcppt::options::flag<
		flag_label2,
		int
	>
	flag2_type;

	CHECK_THROWS_AS(
		flag1_type(
			fcppt::options::optional_short_name{
				fcppt::options::short_name{
					FCPPT_TEXT("flag")
				}
			},
			fcppt::options::long_name{
				FCPPT_TEXT("flag")
			},
			fcppt::options::make_active_value(
				0
			),
			fcppt::options::make_inactive_value(
				1
			),
			fcppt::options::optional_help_text{}
		),
		fcppt::options::duplicate_names
	);

	CHECK_THROWS_AS(
		fcppt::options::apply(
			flag1_type{
				fcppt::options::optional_short_name{},
				fcppt::options::long_name{
					FCPPT_TEXT("flag")
				},
				fcppt::options::make_active_value(
					0
				),
				fcppt::options::make_inactive_value(
					1
				),
				fcppt::options::optional_help_text{}
			},
			flag2_type{
				fcppt::options::optional_short_name{},
				fcppt::options::long_name{
					FCPPT_TEXT("flag")
				},
				fcppt::options::make_active_value(
					0
				),
				fcppt::options::make_inactive_value(
					1
				),
				fcppt::options::optional_help_text{}
			}
		),
		fcppt::options::duplicate_names
	);
}
