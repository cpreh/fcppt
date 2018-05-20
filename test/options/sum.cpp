//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/text.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_sum.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/unit_switch.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"options::sum",
	"[options]"
)
{
	FCPPT_RECORD_MAKE_LABEL(
		label_left
	);

	FCPPT_RECORD_MAKE_LABEL(
		label_right
	);

	auto const sum(
		fcppt::options::make_sum(
			fcppt::options::unit_switch<
				label_left
			>(
				fcppt::options::optional_short_name{},
				fcppt::options::long_name{
					FCPPT_TEXT("left")
				}
			),
			fcppt::options::unit_switch<
				label_right
			>(
				fcppt::options::optional_short_name{},
				fcppt::options::long_name{
					FCPPT_TEXT("right")
				}
			)
		)
	);

	// TODO: Better test case
	CHECK(
		fcppt::options::parse(
			sum,
			fcppt::args_vector{
				FCPPT_TEXT("--left")
			}
		).has_success()
	);

	CHECK(
		fcppt::options::parse(
			sum,
			fcppt::args_vector{
				FCPPT_TEXT("--right")
			}
		).has_success()
	);

	CHECK(
		fcppt::options::parse(
			sum,
			fcppt::args_vector{}
		).has_failure()
	);
}
