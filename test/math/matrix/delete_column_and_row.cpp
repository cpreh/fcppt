//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/delete_row_and_column.hpp>
#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/basic_impl.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(delete_row_and_column)
{
	typedef 
	fcppt::math::matrix::static_<
		float,
		3,
		4
	>::type 
	large_matrix_type;

	typedef 
	fcppt::math::matrix::static_<
		float,
		2,
		3
	>::type 
	small_matrix_type;

	large_matrix_type const t(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9,
		10,11,12);

	BOOST_CHECK(
		(
		fcppt::math::matrix::delete_row_and_column(
			t,
			static_cast<large_matrix_type::size_type>(2),
			static_cast<large_matrix_type::size_type>(1)) == 
		small_matrix_type(
			1,3,
			4,6,
			10,12)));

	BOOST_CHECK(
		(
		fcppt::math::matrix::delete_row_and_column(
			t,
			static_cast<large_matrix_type::size_type>(0),
			static_cast<large_matrix_type::size_type>(0)) == 
		small_matrix_type(
			5, 6,
			8, 9,
			11,12)));
}
