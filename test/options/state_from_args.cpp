//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args_vector.hpp>
#include <fcppt/optional_string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/state_from_args.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	options_state_from_args
)
{
	fcppt::options::state result{
		fcppt::options::detail::state_from_args(
			fcppt::args_vector{
				FCPPT_TEXT("-bar"),
				FCPPT_TEXT("-bar"),
				FCPPT_TEXT("-flag"),
				FCPPT_TEXT("arg1"),
				FCPPT_TEXT("-notflag"),
				FCPPT_TEXT("parameter1"),
				FCPPT_TEXT("-notflag"),
				FCPPT_TEXT("parameter2"),
				FCPPT_TEXT("arg2"),
				FCPPT_TEXT("--long-flag")
			},
			fcppt::options::has_parameter_set{
				FCPPT_TEXT("notflag")
			}
		)
	};

	BOOST_CHECK(
		result.pop_arg()
		==
		fcppt::optional_string{
			FCPPT_TEXT("arg1")
		}
	);

	BOOST_CHECK(
		result.pop_arg()
		==
		fcppt::optional_string{
			FCPPT_TEXT("arg2")
		}
	);

	BOOST_CHECK(
		result.pop_arg()
		==
		fcppt::optional_string{}
	);

	BOOST_CHECK(
		result.pop_flag(
			FCPPT_TEXT("bar"),
			fcppt::options::state::is_short{
				true
			}
		)
	);
	BOOST_CHECK(
		!result.pop_flag(
			FCPPT_TEXT("bar"),
			fcppt::options::state::is_short{
				false
			}
		)
	);

	BOOST_CHECK(
		result.pop_flag(
			FCPPT_TEXT("bar"),
			fcppt::options::state::is_short{
				true
			}
		)
	);

	BOOST_CHECK(
		!result.pop_flag(
			FCPPT_TEXT("bar"),
			fcppt::options::state::is_short{
				true
			}
		)
	);

	BOOST_CHECK(
		result.pop_flag(
			FCPPT_TEXT("flag"),
			fcppt::options::state::is_short{
				true
			}
		)
	);

	BOOST_CHECK(
		!result.pop_flag(
			FCPPT_TEXT("flag"),
			fcppt::options::state::is_short{
				true
			}
		)
	);

	BOOST_CHECK(
		!result.pop_flag(
			FCPPT_TEXT("something"),
			fcppt::options::state::is_short{
				true
			}
		)
	);

	BOOST_CHECK(
		result.pop_option(
			FCPPT_TEXT("notflag"),
			fcppt::options::state::is_short{
				true
			}
		)
		==
		fcppt::optional_string{
			FCPPT_TEXT("parameter1")
		}
	);

	BOOST_CHECK(
		result.pop_option(
			FCPPT_TEXT("notflag"),
			fcppt::options::state::is_short{
				true
			}
		)
		==
		fcppt::optional_string{
			FCPPT_TEXT("parameter2")
		}
	);

	BOOST_CHECK(
		result.pop_option(
			FCPPT_TEXT("notflag"),
			fcppt::options::state::is_short{
				true
			}
		)
		==
		fcppt::optional_string{}
	);

	BOOST_CHECK(
		result.pop_flag(
			FCPPT_TEXT("long-flag"),
			fcppt::options::state::is_short{
				false
			}
		)
	);
}
