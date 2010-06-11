//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETERMINANT_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETERMINANT_HPP_INCLUDED

#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/delete_column_and_row.hpp>
#include <fcppt/math/matrix/has_dim.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/null.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
template
<
	typename T,
	typename N,
	typename S
>
typename
boost::enable_if
<
	has_dim
	<
		basic<T,N,N,S>,
		1,
		1
	>,
	T
>::type
determinant(
	basic<T,N,N,S> const &t
)
{
	return t[0][0];
}

/// Calculates the matrix determinant via the Laplace extension and delete_column_and_row
template
<
	typename T,
	typename N,
	typename S
>
typename
boost::disable_if
<
	has_dim
	<
		basic<T,N,N,S>,
		1,
		1
	>,
	T
>::type
determinant(
	basic<T,N,N,S> const &t
)
{
	T sum = fcppt::math::null<T>();

	for (size_type i = 0; i < t.columns(); ++i)
	{
		T const coeff = 
			i % static_cast<size_type>(2) == static_cast<size_type>(0)
			?
				static_cast<T>(
					1)
			:
				static_cast<T>(
					-1);

		sum += 
			coeff * 
			t[i][0] * 
			determinant(
				delete_column_and_row(
					t,
					i,
					0));
	}

	return sum;
}
}
}
}

#endif
