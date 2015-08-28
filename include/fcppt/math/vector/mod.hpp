//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_MOD_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_MOD_HPP_INCLUDED

#include <fcppt/math/mod.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/init.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Calculate vector modulo a scalar

\ingroup fcpptmathvector
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S
>
fcppt::math::vector::static_<
	T,
	N
>
mod(
	fcppt::math::vector::object<
		T,
		N,
		S
	> const &_arg,
	T const _div
)
{
	typedef
	fcppt::math::vector::static_<
		T,
		N
	>
	result_type;

	return
		fcppt::math::vector::init<
			result_type
		>(
			[
				&_arg,
				_div
			](
				typename
				result_type::size_type const _index
			)
			{
				return
					fcppt::math::mod(
						_arg[
							_index
						],
						_div
					);
			}
		);
}

/**
\brief Calculate vector modulo a vector

\ingroup fcpptmathvector
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S1,
	typename S2
>
fcppt::math::vector::static_<
	T,
	N
>
mod(
	fcppt::math::vector::object<
		T,
		N,
		S1
	> const &_v0,
	fcppt::math::vector::object<
		T,
		N,
		S2
	> const &_v1
)
{
	typedef
	fcppt::math::vector::static_<
		T,
		N
	>
	result_type;

	return
		fcppt::math::vector::init<
			result_type
		>(
			[
				&_v0,
				&_v1
			](
				typename
				result_type::size_type const _index
			)
			{
				return
					fcppt::math::mod(
						_v0[
							_index
						],
						_v1[
							_index
						]
					);
			}
		);
}

}
}
}

#endif
