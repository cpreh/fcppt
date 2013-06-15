//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_POINT_ROTATE_HPP_INCLUDED
#define FCPPT_MATH_POINT_ROTATE_HPP_INCLUDED

#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/rotation_2d.hpp>
#include <fcppt/math/matrix/vector.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/object_decl.hpp>
#include <fcppt/math/vector/object_impl.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Rotates a two dimensional point around another point
\ingroup fcpptmath
\tparam T The vector's <code>value_type</code>
\tparam N The vector's dimension type. The vector must be two-dimensional.
\tparam S The vector's storage type
\param point The point to rotate
\param around The point to rotate around
\param rot The rotation angle
*/
template<
	typename T,
	typename N,
	typename S
>
fcppt::math::vector::object<T, N, S> const
point_rotate(
	fcppt::math::vector::object<T, N, S> const &point,
	fcppt::math::vector::object<T, N, S> const &around,
	T const rot
)
{
	return
		(
			fcppt::math::matrix::rotation_2d(rot)
			* (point - around)
		)
		+ around;
}

}
}

#endif
