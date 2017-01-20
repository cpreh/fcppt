//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/make_success.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/nothing.hpp>
#include <fcppt/options/argument.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/make_optional.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/record/comparison.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/variant/comparison.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	options_optional
)
{
FCPPT_PP_POP_WARNING

	FCPPT_RECORD_MAKE_LABEL(
		arg_label
	);

	typedef
	fcppt::options::argument<
		arg_label,
		int
	>
	int_arg_type;

	FCPPT_RECORD_MAKE_LABEL(
		optional_label
	);

	auto const parser{
		fcppt::options::make_optional<
			optional_label
		>(
			int_arg_type{
				fcppt::options::long_name{
					FCPPT_TEXT("arg1")
				}
			}
		)
	};

	typedef
	decltype(
		parser
	)
	parser_type;

	BOOST_CHECK(
		fcppt::options::parse(
			parser,
			fcppt::args_vector{
				FCPPT_TEXT("123")
			}
		)
		==
		fcppt::either::make_success<
			fcppt::options::error
		>(
			parser_type::result_type{
				optional_label{} =
					fcppt::optional::make(
						int_arg_type::result_type{
							arg_label{}
								= 123
						}
					)
			}
		)
	);

	BOOST_CHECK(
		fcppt::options::parse(
			parser,
			fcppt::args_vector{
				FCPPT_TEXT("test")
			}
		).has_failure()
	);

	BOOST_CHECK(
		fcppt::options::parse(
			parser,
			fcppt::args_vector{}
		)
		==
		fcppt::either::make_success<
			fcppt::options::error
		>(
			parser_type::result_type{
				optional_label{} =
					fcppt::optional::nothing{}
			}
		)
	);
}
