//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/matrix/componentwise_equal.hpp>
#include <fcppt/math/matrix/inverse.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <limits>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(delete_row_and_column_test)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::matrix::static_<
		double,
		3,
		3
	>
	large_matrix_type;

	BOOST_CHECK((
		fcppt::math::matrix::componentwise_equal(
			fcppt::math::matrix::inverse(
				large_matrix_type(
					0.,1.,2.,
					1.,0.,3.,
					4.,-3.,8.
				)
			),
			large_matrix_type(
				-9./2.,7.,-3./2.,
				-2.,4.,-1.,
				3./2.,-2.,1./2.
			),
			std::numeric_limits<
				double
			>::epsilon()
		)
	));
}
