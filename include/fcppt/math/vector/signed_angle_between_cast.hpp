//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_SIGNED_ANGLE_BETWEEN_CAST_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_SIGNED_ANGLE_BETWEEN_CAST_HPP_INCLUDED

#include <fcppt/cast/int_to_float_fun.hpp>
#include <fcppt/math/detail/has_size.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/signed_angle_between.hpp>
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
\brief Calculates the signed angle between two arbitrary 2D vector types
\ingroup fcpptmathvector
\tparam Dest The angle type. Must be a floating point type.
\tparam T The vector's <code>value_type</code>
\tparam N The vector's dimension type
\tparam S1 The first vector's storage type
\tparam S2 The first vector's storage type

This function is a generalization of fcppt::math::vector::signed_angle_between in that
it calculates the angle between two arbitrary vectors, instead of two floating
point vectors.

\see fcppt::math::vector::signed_angle_between

\warning
The behaviour is undefined if \p _from or \p _to are nearly identical.
*/
template<
	typename Dest,
	typename T,
	typename N,
	typename S1,
	typename S2
>
Dest
signed_angle_between_cast(
	fcppt::math::vector::object<
		T,
		N,
		S1
	> const &_from,
	fcppt::math::vector::object<
		T,
		N,
		S2
	> const &_to
)
{
	static_assert(
		std::is_floating_point<
			Dest
		>::value,
		"signed_angle_between_cast can only be used on vectors of floating point type"
	);

	static_assert(
		fcppt::math::detail::has_size<
			N,
			2
		>::value,
		"signed_angle_between_cast can only be used on two-dimensional vectors"
	);

	typedef
	fcppt::math::vector::static_<
		Dest,
		N::value
	>
	intermediate_type;

	return
		fcppt::math::vector::signed_angle_between(
			fcppt::math::vector::structure_cast<
				intermediate_type,
				fcppt::cast::int_to_float_fun
			>(
				_from
			),
			fcppt::math::vector::structure_cast<
				intermediate_type,
				fcppt::cast::int_to_float_fun
			>(
				_to
			)
		);
}

}
}
}

#endif
