//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/inverse.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/matrix/comparison.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(delete_row_and_column_test)
{
	typedef 
	fcppt::math::matrix::static_<
		double,
		3,
		3
	>::type 
	large_matrix_type;

	BOOST_CHECK((
		fcppt::math::matrix::inverse(
			large_matrix_type(
				0.,1.,2.,
				1.,0.,3.,
				4.,-3.,8.)) == 
		large_matrix_type(
			-9./2.,7.,-3./2.,
			-2.,4.,-1.,
			3./2.,-2.,1./2.)));
}
