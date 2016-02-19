//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/time.hpp>
#include <boost/units/systems/si/velocity.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_units
)
{
FCPPT_PP_POP_WARNING
	typedef int unit_type;

	typedef boost::units::quantity<
		boost::units::si::length,
		unit_type
	> length;

	typedef boost::units::quantity<
		boost::units::si::time,
		unit_type
	> time;

	typedef boost::units::quantity<
		boost::units::si::velocity,
		unit_type
	> velocity;

	typedef fcppt::math::vector::static_<
		length,
		2
	> length2;

	typedef fcppt::math::vector::static_<
		time,
		2
	> time2;

	typedef fcppt::math::vector::static_<
		velocity,
		2
	> velocity2;

	length2 const l1(
		length(
			-100
			*
			boost::units::si::meter
		),
		length(
			200
			*
			boost::units::si::meter
		)
	);

	time2 const t1(
		time(
			4
			*
			boost::units::si::second
		),
		time(
			2
			*
			boost::units::si::second
		)
	);

	velocity2 const v1(
		l1
		/
		t1
	);

	BOOST_CHECK_EQUAL(
		v1.x().value(),
		-25
	);

	BOOST_CHECK_EQUAL(
		v1.y().value(),
		100
	);
}
