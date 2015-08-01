//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/literal.hpp>
#include <fcppt/make_literal_boost_units.hpp>
#include <fcppt/make_literal_strong_typedef.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si/length.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	literal_fundamental
)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK_EQUAL(
		fcppt::literal<
			unsigned
		>(
			2
		),
		2u
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	literal_boost_units
)
{
FCPPT_PP_POP_WARNING

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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	literal_strong_typedef
)
{
FCPPT_PP_POP_WARNING
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
