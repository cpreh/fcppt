//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_TRANSLATION_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_TRANSLATION_HPP_INCLUDED

#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/vector/has_dim.hpp>
#include <fcppt/math/vector/object_impl.hpp>
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
\brief Calculates a 4x4 translation matrix from three coordinates
\ingroup fcpptmathmatrix
\tparam T The matrix's <code>value_type</code>
\param _x The x translation
\param _y The y translation
\param _z The z translation

The resulting matrix will be static.
*/
template<
	typename T
>
typename static_<T, 4, 4>::type const
translation(
	T const _x,
	T const _y,
	T const _z
)
{
	T const
		zero(
			static_cast<T>(0)
		),
		one(
			static_cast<T>(1)
		);

	return
		typename static_<T, 4, 4>::type
		(
			one, zero, zero, _x,
			zero, one, zero, _y,
			zero, zero, one, _z,
			zero, zero, zero, one
		);
}

/**
\brief Calculates a 4x4 translation matrix from a three-dimensional vector
\ingroup fcpptmathmatrix
\tparam T The matrix's <code>value_type</code>
\param _vec A three-dimensional vector (static or dynamic)

The resulting matrix will be static.
*/
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
translation(
	Vector const &_vec
)
{
	return
		matrix::translation(
			_vec.x(),
			_vec.y(),
			_vec.z()
		);
}

}
}
}

#endif
