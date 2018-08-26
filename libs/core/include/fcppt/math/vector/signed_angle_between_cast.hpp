//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_SIGNED_ANGLE_BETWEEN_CAST_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_SIGNED_ANGLE_BETWEEN_CAST_HPP_INCLUDED

#include <fcppt/cast/int_to_float_fun.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/signed_angle_between.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/structure_cast.hpp>
#include <fcppt/optional/object_impl.hpp>
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
\brief Calculates the signed angle between two arbitrary 2D vector types.

\ingroup fcpptmathvector

This function is a generalization of \link
fcppt::math::vector::signed_angle_between \endlink since it calculates the
angle between two arbitrary vectors, instead of two floating-point vectors.
In case of an error, nothing is returned.

\see fcppt::math::vector::signed_angle_between

\tparam Dest The angle type. Must be a floating-point type.
*/
template<
	typename Dest,
	typename T,
	typename S1,
	typename S2
>
fcppt::optional::object<
	Dest
>
signed_angle_between_cast(
	fcppt::math::vector::object<
		T,
		2,
		S1
	> const &_from,
	fcppt::math::vector::object<
		T,
		2,
		S2
	> const &_to
)
{
	static_assert(
		std::is_floating_point<
			Dest
		>::value,
		"signed_angle_between_cast can only be used on vectors of floating-point type"
	);

	typedef
	fcppt::math::vector::static_<
		Dest,
		2
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
