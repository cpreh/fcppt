//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/make_success.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/flag.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/parse.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/record/comparison.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	options_flag
)
{
FCPPT_PP_POP_WARNING

	FCPPT_RECORD_MAKE_LABEL(
		arg_label
	);

	typedef
	fcppt::options::flag<
		arg_label,
		int
	>
	int_flag_type;

	int_flag_type const int_flag{
		fcppt::options::optional_short_name{
			fcppt::options::short_name{
				FCPPT_TEXT("f")
			}
		},
		fcppt::options::long_name{
			FCPPT_TEXT("flag")
		},
		int_flag_type::active_value{
			42
		},
		int_flag_type::inactive_value{
			10
		}
	};

	BOOST_CHECK(
		fcppt::options::parse(
			int_flag,
			fcppt::args_vector{
				"-f"
			}
		)
		==
		fcppt::either::make_success<
			fcppt::options::error
		>(
			int_flag_type::result_type{
				arg_label{}
					= 42
			}
		)
	);

	BOOST_CHECK(
		fcppt::options::parse(
			int_flag,
			fcppt::args_vector{
				"--flag"
			}
		)
		==
		fcppt::either::make_success<
			fcppt::options::error
		>(
			int_flag_type::result_type{
				arg_label{}
					= 42
			}
		)
	);

	BOOST_CHECK(
		fcppt::options::parse(
			int_flag,
			fcppt::args_vector{
				"-something"
			}
		)
		==
		fcppt::either::make_success<
			fcppt::options::error
		>(
			int_flag_type::result_type{
				arg_label{}
					= 10
			}
		)
	);
}
