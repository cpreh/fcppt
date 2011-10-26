//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_SCALING_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_SCALING_HPP_INCLUDED

#include <fcppt/math/matrix/basic_impl.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/has_dim.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/// Calculates a scaling matrix from @a x, @a y and @a z
template<
	typename T
>
typename static_<T, 4, 4>::type const
scaling(
	T const _x,
	T const _y,
	T const _z
)
{
	T const
		zero = static_cast<T>(0),
		one = static_cast<T>(1);

	return
		typename static_<T, 4, 4>::type
		(
			   _x, zero, zero, zero,
			zero,     _y,zero, zero,
			zero,  zero,   _z, zero,
			zero,  zero, zero,  one
		);

}

/// Calculates a scaling matrix from a three dimensional vector
template<
	typename Vector
>
typename boost::enable_if<
	vector::has_dim<
		Vector,
		3
	>,
	typename static_<
		typename Vector::value_type,
		4,
		4
	>::type
>::type const
scaling(
	Vector const &_vec
)
{
	return
		matrix::scaling(
			_vec.x(),
			_vec.y(),
			_vec.z()
		);
}

}
}
}

#endif
