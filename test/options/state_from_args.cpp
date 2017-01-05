//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/optional_std_string.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/state_from_args.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	options_state_from_args
)
{
FCPPT_PP_POP_WARNING

	fcppt::options::state result{
		fcppt::options::state_from_args(
			fcppt::args_vector{
				"-bar",
				"-bar",
				"-flag",
				"arg1",
				"-notflag",
				"parameter1",
				"-notflag",
				"parameter2",
				"arg2",
				"--long-flag"
			},
			fcppt::options::has_parameter_set{
				"notflag"
			}
		)
	};

	BOOST_CHECK_EQUAL(
		result.pop_arg(),
		fcppt::optional_std_string{
			"arg1"
		}
	);

	BOOST_CHECK_EQUAL(
		result.pop_arg(),
		fcppt::optional_std_string{
			"arg2"
		}
	);

	BOOST_CHECK_EQUAL(
		result.pop_arg(),
		fcppt::optional_std_string{}
	);

	BOOST_CHECK(
		result.pop_flag(
			"bar",
			fcppt::options::state::is_short{
				true
			}
		)
	);
	BOOST_CHECK(
		!result.pop_flag(
			"bar",
			fcppt::options::state::is_short{
				false
			}
		)
	);

	BOOST_CHECK(
		result.pop_flag(
			"bar",
			fcppt::options::state::is_short{
				true
			}
		)
	);

	BOOST_CHECK(
		!result.pop_flag(
			"bar",
			fcppt::options::state::is_short{
				true
			}
		)
	);

	BOOST_CHECK(
		result.pop_flag(
			"flag",
			fcppt::options::state::is_short{
				true
			}
		)
	);

	BOOST_CHECK(
		!result.pop_flag(
			"flag",
			fcppt::options::state::is_short{
				true
			}
		)
	);

	BOOST_CHECK(
		!result.pop_flag(
			"something",
			fcppt::options::state::is_short{
				true
			}
		)
	);

	BOOST_CHECK_EQUAL(
		result.pop_option(
			"notflag",
			fcppt::options::state::is_short{
				true
			}
		),
		fcppt::optional_std_string{
			"parameter1"
		}
	);

	BOOST_CHECK_EQUAL(
		result.pop_option(
			"notflag",
			fcppt::options::state::is_short{
				true
			}
		),
		fcppt::optional_std_string{
			"parameter2"
		}
	);

	BOOST_CHECK_EQUAL(
		result.pop_option(
			"notflag",
			fcppt::options::state::is_short{
				true
			}
		),
		fcppt::optional_std_string{}
	);

	BOOST_CHECK(
		result.pop_flag(
			"long-flag",
			fcppt::options::state::is_short{
				false
			}
		)
	);
}
