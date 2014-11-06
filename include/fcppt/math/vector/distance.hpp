//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_DISTANCE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_DISTANCE_HPP_INCLUDED

#include <fcppt/math/static_storage.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/length.hpp>
#include <fcppt/math/vector/object_impl.hpp>
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

template<
	typename T,
	typename N,
	typename S1,
	typename S2
>
typename
std::enable_if<
	std::is_floating_point<
		T
	>::value,
	T
>::type
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

template<
	typename Dest,
	typename T,
	typename N,
	typename S1,
	typename S2
>
typename
std::enable_if<
	!std::is_floating_point<
		T
	>::value,
	Dest
>::type
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
	fcppt::math::vector::object<
		Dest,
		N,
		fcppt::math::static_storage<
			Dest,
			N
		>
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
				result_vector
			>(
				_v1
			),
			fcppt::math::vector::structure_cast<
				result_vector
			>(
				_v2
			)
		);
}

}
}
}

#endif
