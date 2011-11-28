//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_INVERSE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_INVERSE_HPP_INCLUDED

#include <fcppt/text.hpp>
#include <fcppt/math/exception.hpp>
#include <fcppt/math/inverse.hpp>
#include <fcppt/math/is_static_size.hpp>
#include <fcppt/math/matrix/adjugate.hpp>
#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/matrix/determinant.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{
/**
 * Calculates the inverse matrix, uses fcppt::math::matrix::adjugate and fcppt::math::matrix::determinant.
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
