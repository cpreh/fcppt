//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/bad_truncation_check_cast.hpp>
#include <fcppt/truncation_check_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <climits>
#include <limits>
#include <fcppt/config/external_end.hpp>


namespace
{

bool
check_exception(
	fcppt::bad_truncation_check_cast const &
)
{
	return true;
}

}

BOOST_AUTO_TEST_CASE(
	truncation_check_cast
)
{
#if SHORT_MAX < LONG_MAX
	BOOST_CHECK_EXCEPTION(
		fcppt::truncation_check_cast<
			short
		>(
			std::numeric_limits<
				long
			>::max()
		),
		fcppt::bad_truncation_check_cast,
		check_exception
	);

	BOOST_CHECK_EXCEPTION(
		fcppt::truncation_check_cast<
			short
		>(
			std::numeric_limits<
				long
			>::min()
		),
		fcppt::bad_truncation_check_cast,
		check_exception
	);
#endif
	BOOST_CHECK_EXCEPTION(
		fcppt::truncation_check_cast<
			long
		>(
			std::numeric_limits<
				unsigned long
			>::max()
		),
		fcppt::bad_truncation_check_cast,
		check_exception
	);

	BOOST_CHECK_EXCEPTION(
		fcppt::truncation_check_cast<
			unsigned long
		>(
			-1
		),
		fcppt::bad_truncation_check_cast,
		check_exception
	);

#if USHORT_MAX < ULONG_MAX
	BOOST_CHECK_EXCEPTION(
		fcppt::truncation_check_cast<
			unsigned short
		>(
			std::numeric_limits<
				unsigned long
			>::max()
		),
		fcppt::bad_truncation_check_cast,
		check_exception
	);
#endif
	BOOST_CHECK(
		fcppt::truncation_check_cast<
			unsigned
		>(
			10u
		)
		==
		10u
	);

	BOOST_CHECK(
		fcppt::truncation_check_cast<
			unsigned long
		>(
			42u
		)
		==
		42ul
	);

	BOOST_CHECK(
		fcppt::truncation_check_cast<
			long
		>(
			-1
		)
		==
		-1l
	);
}
