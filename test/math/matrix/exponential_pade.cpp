//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/componentwise_equal.hpp>
#include <fcppt/math/matrix/exponential_pade.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(exponential_pade)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::matrix::static_<
		double,
		3,
		3
	>
	matrix_type;

	matrix_type const t(
		2.0, -1.0, 1.0,
		0.0, 3.0, -1.0,
		2.0, 1.0, 3.0);

	double const epsilon =
		0.01;

	BOOST_CHECK((
        fcppt::math::matrix::componentwise_equal(
	        fcppt::math::matrix::exponential_pade(
		        t),
	        matrix_type(
		        23.6045,-7.38906,23.6045,
		        -16.2155,14.7781,-23.6045,
		        30.9936,7.38906,30.9936),
	        epsilon)));
}
