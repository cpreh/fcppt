//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/bad_truncation_check.hpp>
#include <fcppt/cast/truncation_check.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <climits>
#include <limits>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	truncation_check_cast
)
{
#if SHRT_MAX < LONG_MAX
	BOOST_CHECK_THROW(
		fcppt::cast::truncation_check<
			short
		>(
			std::numeric_limits<
				long
			>::max()
		),
		fcppt::cast::bad_truncation_check
	);

	BOOST_CHECK_THROW(
		fcppt::cast::truncation_check<
			short
		>(
			std::numeric_limits<
				long
			>::min()
		),
		fcppt::cast::bad_truncation_check
	);
#endif
	BOOST_CHECK_THROW(
		fcppt::cast::truncation_check<
			long
		>(
			std::numeric_limits<
				unsigned long
			>::max()
		),
		fcppt::cast::bad_truncation_check
	);

	BOOST_CHECK_THROW(
		fcppt::cast::truncation_check<
			unsigned long
		>(
			-1
		),
		fcppt::cast::bad_truncation_check
	);

#if USHRT_MAX < ULONG_MAX
	BOOST_CHECK_THROW(
		fcppt::cast::truncation_check<
			unsigned short
		>(
			std::numeric_limits<
				unsigned long
			>::max()
		),
		fcppt::cast::bad_truncation_check
	);
#endif
	BOOST_CHECK_EQUAL(
		fcppt::cast::truncation_check<
			unsigned
		>(
			10u
		),
		10u
	);

	BOOST_CHECK_EQUAL(
		fcppt::cast::truncation_check<
			unsigned long
		>(
			42u
		),
		42ul
	);

	BOOST_CHECK_EQUAL(
		fcppt::cast::truncation_check<
			long
		>(
			-1
		),
		-1l
	);
}
