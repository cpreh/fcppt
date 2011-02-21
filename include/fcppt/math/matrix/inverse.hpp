//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_INVERSE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_INVERSE_HPP_INCLUDED

#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/matrix/determinant.hpp>
#include <fcppt/math/matrix/adjugate.hpp>
#include <fcppt/math/is_static_size.hpp>
#include <fcppt/math/inverse.hpp>
#include <fcppt/math/almost_zero.hpp>
#include <fcppt/math/exception.hpp>
#include <fcppt/text.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
/**
 * Calculates the inverse matrix, uses fcppt::math::matrix::adjugate and fcppt::math::matrix::determinant. Throws fcppt::math::exception if fcppt::math::matrix::determinant(t) == 0
 *
 * @exception fcppt::math::exception If fcppt::math::matrix::determinant(t) == 0
 */
template
<
	typename T,
	typename N,
	typename S
>
typename 
boost::enable_if<
	math::is_static_size<
		N
	>,
	typename matrix::static_<
		T,
		N::value,
		N::value
	>::type const
>::type
inverse(
	basic<T,N,N,S> const &t
)
{
	T const det = 
		fcppt::math::matrix::determinant(
			t);
	if (fcppt::math::almost_zero(det))
		throw fcppt::math::exception(FCPPT_TEXT("tried to invert a matrix with determinant 0"));
	return 
		fcppt::math::inverse(
			det) * 
		matrix::adjugate(
			t);
}
}
}
}

#endif
