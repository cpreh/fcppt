//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_ARITHMETIC_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_ARITHMETIC_HPP_INCLUDED

#include <fcppt/math/div.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/binary_type.hpp>
#include <fcppt/math/detail/unary_type.hpp>
#include <fcppt/math/vector/binary_map.hpp>
#include <fcppt/math/vector/map.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/sequence.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/optional/object_impl.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Negates a vector.

\ingroup fcpptmathvector
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
inline
fcppt::math::vector::static_<
	FCPPT_MATH_DETAIL_UNARY_TYPE(T, -),
	N
>
operator -(
	fcppt::math::vector::object<
		T,
		N,
		S
	> const &_left
)
{
	return
		fcppt::math::vector::map(
			_left,
			[](
				T const &_elem
			){
				return
					-
					_elem;
			}
		);
}

/**
\brief Adds a vector to a vector.

\ingroup fcpptmathvector
*/
template<
	typename L,
	typename R,
	fcppt::math::size_type N,
	typename S1,
	typename S2
>
inline
fcppt::math::vector::static_<
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, +, R),
	N
>
operator +(
	fcppt::math::vector::object<
		L,
		N,
		S1
	> const &_left,
	fcppt::math::vector::object<
		R,
		N,
		S2
	> const &_right
)
{
	return
		fcppt::math::vector::binary_map(
			_left,
			_right,
			[](
				L const &_left_elem,
				R const &_right_elem
			){
				return
					_left_elem
					+
					_right_elem;
			}
		);
}

/**
\brief Subtracts a vector from a vector.

\ingroup fcpptmathvector
*/
template<
	typename L,
	typename R,
	fcppt::math::size_type N,
	typename S1,
	typename S2
>
inline
fcppt::math::vector::static_<
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, -, R),
	N
>
operator -(
	fcppt::math::vector::object<
		L,
		N,
		S1
	> const &_left,
	fcppt::math::vector::object<
		R,
		N,
		S2
	> const &_right
)
{
	return
		fcppt::math::vector::binary_map(
			_left,
			_right,
			[](
				L const &_left_elem,
				R const &_right_elem
			){
				return
					_left_elem
					-
					_right_elem;
			}
		);
}

/**
\brief Multiplies a vector by a vector.

\ingroup fcpptmathvector
*/
template<
	typename L,
	typename R,
	fcppt::math::size_type N,
	typename S1,
	typename S2
>
inline
fcppt::math::vector::static_<
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
	N
>
operator *(
	fcppt::math::vector::object<
		L,
		N,
		S1
	> const &_left,
	fcppt::math::vector::object<
		R,
		N,
		S2
	> const &_right
)
{
	return
		fcppt::math::vector::binary_map(
			_left,
			_right,
			[](
				L const &_left_elem,
				R const &_right_elem
			){
				return
					_left_elem
					*
					_right_elem;
			}
		);
}

/**
\brief Divides a vector by a vector.

\ingroup fcpptmathvector
*/
template<
	typename L,
	typename R,
	fcppt::math::size_type N,
	typename S1,
	typename S2
>
inline
fcppt::optional::object<
	fcppt::math::vector::static_<
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, /, R),
		N
	>
>
operator /(
	fcppt::math::vector::object<
		L,
		N,
		S1
	> const &_left,
	fcppt::math::vector::object<
		R,
		N,
		S2
	> const &_right
)
{
	return
		fcppt::math::vector::sequence(
			fcppt::math::vector::binary_map(
				_left,
				_right,
				[](
					L const &_left_elem,
					R const &_right_elem
				){
					return
						fcppt::math::div(
							_left_elem,
							_right_elem
						);
				}
			)
		);
}

/**
\brief Multiplies a vector by a scalar on the right.

\ingroup fcpptmathvector
*/
template<
	typename L,
	typename R,
	fcppt::math::size_type N,
	typename S
>
inline
fcppt::math::vector::static_<
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
	N
>
operator *(
	fcppt::math::vector::object<
		L,
		N,
		S
	> const &_left,
	R const &_right
)
{
	return
		fcppt::math::vector::map(
			_left,
			[
				&_right
			](
				L const &_left_elem
			)
			{
				return
					_left_elem
					*
					_right;
			}
		);
}

/**
\brief Multiplies a vector by a scalar on the left.

\ingroup fcpptmathvector
*/
template<
	typename L,
	typename R,
	fcppt::math::size_type N,
	typename S
>
inline
fcppt::math::vector::static_<
	FCPPT_MATH_DETAIL_BINARY_TYPE(L, *, R),
	N
>
operator *(
	L const &_left,
	fcppt::math::vector::object<
		R,
		N,
		S
	> const &_right
)
{
	return
		fcppt::math::vector::map(
			_right,
			[
				&_left
			](
				R const &_right_elem
			)
			{
				return
					_left
					*
					_right_elem;
			}
		);
}

/**
\brief Divides a vector by a scalar.

\ingroup fcpptmathvector
*/
template<
	typename L,
	typename R,
	fcppt::math::size_type N,
	typename S
>
inline
fcppt::optional::object<
	fcppt::math::vector::static_<
		FCPPT_MATH_DETAIL_BINARY_TYPE(L, /, R),
		N
	>
>
operator /(
	fcppt::math::vector::object<
		L,
		N,
		S
	> const &_left,
	R const &_right
)
{
	return
		fcppt::math::vector::sequence(
			fcppt::math::vector::map(
				_left,
				[
					&_right
				](
					L const &_left_elem
				)
				{
					return
						fcppt::math::div(
							_left_elem,
							_right
						);
				}
			)
		);
}

}
}
}

#endif
