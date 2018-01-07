//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/public_config.hpp>
#include <fcppt/literal.hpp>
#if defined(FCPPT_BOOST_SUPPORT)
#include <fcppt/make_literal_boost_units.hpp>
#endif
#include <fcppt/make_literal_strong_typedef.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si/length.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	literal_fundamental
)
{
	BOOST_CHECK_EQUAL(
		fcppt::literal<
			unsigned
		>(
			2
		),
		2u
	);
}

#if defined(FCPPT_BOOST_SUPPORT)
BOOST_AUTO_TEST_CASE(
	literal_boost_units
)
{
	typedef
	boost::units::quantity<
		boost::units::si::length,
		int
	>
	length;

	BOOST_CHECK_EQUAL(
		fcppt::literal<
			length
		>(
			2
		).value(),
		2
	);
}
#endif

BOOST_AUTO_TEST_CASE(
	literal_strong_typedef
)
{
	FCPPT_MAKE_STRONG_TYPEDEF(
		int,
		my_type
	);

	BOOST_CHECK_EQUAL(
		fcppt::literal<
			my_type
		>(
			1
		).get(),
		1
	);
}
