//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_TRANSFORM_DIRECTION_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_TRANSFORM_DIRECTION_HPP_INCLUDED

#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/vector.hpp>
#include <fcppt/math/vector/construct.hpp>
#include <fcppt/math/vector/narrow_cast.hpp>
#include <fcppt/math/vector/object_impl.hpp>

namespace fcppt
{
namespace math
{
namespace matrix
{
/**
\brief Multiplies a 4x4 matrix by a 3D vector, adding 0 for w, returns a 3D vector
\ingroup fcpptmathmatrix
\tparam T The matrix's <code>value_type</code>
\tparam N The matrix's row (and column!) dimension type
\tparam M The vector's dimension type
\tparam S1 The vector's storage type
\tparam S2 The matrix's storage type
\param _matrix A 4x4 matrix
\param _vector A 3D vector
\see fcppt::math::matrix::transform_point
*/
template<typename T,typename M,typename N,typename S1,typename S2>
fcppt::math::vector::object<T,M,S1> const
transform_direction(
	fcppt::math::matrix::object<T,N,N,S2> const &_matrix,
	fcppt::math::vector::object<T,M,S1> const &_vector)
{
	return
		fcppt::math::vector::narrow_cast
		<
			fcppt::math::vector::object<T,M,S1>
		>(
			_matrix *
			fcppt::math::vector::construct(
				_vector,
				static_cast<T>(
					0)));
}
}
}
}

#endif
