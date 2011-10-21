//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_POINT_ROTATE_HPP_INCLUDED
#define FCPPT_MATH_POINT_ROTATE_HPP_INCLUDED

#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/matrix/rotation_2d.hpp>
#include <fcppt/math/matrix/vector.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/basic_decl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>


namespace fcppt
{
namespace math
{

/// Rotates a two dimensional point around another point
/**
 * Rotates @a point around @a around by the rotation @a rot
*/
template<
	typename T,
	typename N,
	typename S
>
vector::basic<T, N, S> const
point_rotate(
	vector::basic<T, N, S> const &point,
	vector::basic<T, N, S> const &around,
	T const rot
)
{
	return
		(
			matrix::rotation_2d(rot)
			* (point - around)
		)
		+ around;
}

}
}

#endif
