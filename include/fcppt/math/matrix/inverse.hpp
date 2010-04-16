#ifndef FCPPT_MATH_MATRIX_INVERSE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_INVERSE_HPP_INCLUDED

#include <fcppt/math/matrix/determinant.hpp>
#include <fcppt/math/matrix/adjugate.hpp>
#include <fcppt/math/inverse.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
/// Calculates the adjugate matrix
template
<
	typename T,
	typename N,
	typename S
>
typename 
static_<T,N::value,N::value>::type const
inverse(
	basic<T,N,N,S> const &t)
{
	return 
		fcppt::math::inverse(
			determinant(
				t)) * 
		adjugate(
			t);
}
}
}
}

#endif
