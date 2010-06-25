//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_INVERSE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_INVERSE_HPP_INCLUDED

#include <fcppt/math/matrix/determinant.hpp>
#include <fcppt/math/matrix/adjugate.hpp>
#include <fcppt/math/detail/is_static_size.hpp>
#include <fcppt/math/inverse.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
/// Calculates the inverse matrix
template
<
	typename T,
	typename N,
	typename S
>
typename 
boost::enable_if<
	math::detail::is_static_size<
		N
	>,
	typename static_<
		T,
		N::value,
		N::value
	>::type const
>::type
inverse(
	basic<T,N,N,S> const &t
)
{
	return 
		fcppt::math::inverse(
			matrix::determinant(
				t)) * 
		matrix::adjugate(
			t);
}
}
}
}

#endif
