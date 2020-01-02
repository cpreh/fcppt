//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/text.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/unit_comparison.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/catch/record.hpp>
#include <fcppt/catch/strong_typedef.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/unit.hpp>
#include <fcppt/record/comparison.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"options::unit",
	"[options]"
)
{
	FCPPT_RECORD_MAKE_LABEL(
		dummy_label
	);

	typedef
	fcppt::options::unit<
		dummy_label
	>
	unit_type;

	unit_type const unit{};

	CHECK(
		fcppt::options::parse(
			unit,
			fcppt::args_vector{}
		)
		==
		fcppt::options::make_success(
			unit_type::result_type{
				dummy_label{}
					= fcppt::unit{}
			}
		)
	);

	CHECK(
		fcppt::options::parse(
			unit,
			fcppt::args_vector{
				FCPPT_TEXT("")
			}
		).has_failure()
	);
}
