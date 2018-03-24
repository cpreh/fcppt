//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_DISTANCE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_DISTANCE_HPP_INCLUDED

#include <fcppt/cast/int_to_float_fun.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/length.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/structure_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Computes the distance between two floating-point vectors

\ingroup fcpptmathvector
*/
template<
	typename T,
	fcppt::math::size_type N,
	typename S1,
	typename S2
>
std::enable_if_t<
	std::is_floating_point<
		T
	>::value,
	T
>
distance(
	fcppt::math::vector::object<
		T,
		N,
		S1
	> const &_v1,
	fcppt::math::vector::object<
		T,
		N,
		S2
	> const &_v2
)
{
	return
		fcppt::math::vector::length(
			_v1
			-
			_v2
		);
}

/**
\brief Computes the distance between two non floating-point vectors

\ingroup fcpptmathvector
*/
template<
	typename Dest,
	typename T,
	fcppt::math::size_type N,
	typename S1,
	typename S2
>
std::enable_if_t<
	!std::is_floating_point<
		T
	>::value,
	Dest
>
distance(
	fcppt::math::vector::object<
		T,
		N,
		S1
	> const &_v1,
	fcppt::math::vector::object<
		T,
		N,
		S2
	> const &_v2
)
{
	typedef
	fcppt::math::vector::static_<
		Dest,
		N
	>
	result_vector;

	static_assert(
		std::is_floating_point<
			Dest
		>::value,
		"Dest must be a floating point type"
	);

	return
		fcppt::math::vector::distance(
			fcppt::math::vector::structure_cast<
				result_vector,
				fcppt::cast::int_to_float_fun
			>(
				_v1
			),
			fcppt::math::vector::structure_cast<
				result_vector,
				fcppt::cast::int_to_float_fun
			>(
				_v2
			)
		);
}

}
}
}

#endif
