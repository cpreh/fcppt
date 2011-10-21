//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_LOOK_AT_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_LOOK_AT_HPP_INCLUDED

#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/translation.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/basic_fwd.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/cross.hpp>
#include <fcppt/math/vector/has_dim.hpp>
#include <fcppt/math/vector/normalize.hpp>
#include <fcppt/math/vector/static.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/// Calculates a perspective matrix from three vectors
/**
 * @param eye The direction the viewer looks at
 * @param location The location of the viewer
 * @param up A vector orthogonal to the @a eye vector
*/
template<
	typename T,
	typename N,
	typename S
>
typename boost::enable_if<
	math::vector::has_dim<
		vector::basic<
			T,
			N,
			S
		>,
		3
	>,
	typename static_<
		T,
		4,
		4
	>::type const
>::type
look_at(
	vector::basic<
		T,
		N,
		S
	> const &eye,
	vector::basic<
		T,
		N,
		S
	> const &location,
	vector::basic<
		T,
		N,
		S
	> const &up
)
{
	typedef typename vector::static_<
		T,
		3
	>::type vec3;

	vec3 const
		f(
			normalize(
				location - eye
			)
		),
		s(
			cross(
				f,
				normalize(
					up
				)
			)
		),
		u(
			cross(
				s,
				f
			)
		);

	return
		typename static_<
			T,
			4,
			4
		>::type(
			s.x(),  s.y(),  s.z(),  0,
			u.x(),  u.y(),  u.z(),  0,
			-f.x(), -f.y(), -f.z(), 0,
			0, 0, 0, 1
		)
		* translation(
			-eye.x(),
			-eye.y(),
			-eye.z()
		);
}

}
}
}

#endif
