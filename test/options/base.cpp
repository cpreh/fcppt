//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/text.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/base_unique_ptr.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_base.hpp>
#include <fcppt/options/make_success.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/record/comparison.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/output.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/variant/comparison.hpp>
#include <fcppt/variant/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"options::base"
	"[options]"
)
{
	FCPPT_RECORD_MAKE_LABEL(
		arg_label
	);

	typedef
	fcppt::record::variadic<
		fcppt::record::element<
			arg_label,
			int
		>
	>
	result_type;

	fcppt::options::base_unique_ptr<
		result_type
	> const base{
		fcppt::options::make_base<
			result_type
		>(
			fcppt::options::argument<
				arg_label,
				int
			>{
				fcppt::options::long_name{
					FCPPT_TEXT("arg")
				},
				fcppt::options::optional_help_text{}
			}
		)
	};

	CHECK(
		fcppt::options::parse(
			*base,
			fcppt::args_vector{
				FCPPT_TEXT("123")
			}
		)
		==
		fcppt::options::make_success(
			result_type{
				arg_label{}
					= 123
			}
		)
	);

	CHECK(
		fcppt::options::parse(
			*base,
			fcppt::args_vector{
				FCPPT_TEXT("test")
			}
		).has_failure()
	);

	CHECK(
		fcppt::options::parse(
			*base,
			fcppt::args_vector{}
		).has_failure()
	);
}
