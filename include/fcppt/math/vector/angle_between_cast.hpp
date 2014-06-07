//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_ANGLE_BETWEEN_CAST_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_ANGLE_BETWEEN_CAST_HPP_INCLUDED

#include <fcppt/math/vector/angle_between.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/structure_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Calculates the angle between two arbitrary vector types
\ingroup fcpptmathvector
\tparam Dest The angle type. Must be a floating point type.
\tparam T The vector's <code>value_type</code>
\tparam N The vector's dimension type
\tparam S1 The first vector's storage type
\tparam S2 The first vector's storage type

This function is a generalization of fcppt::math::vector::angle_between in that
it calculates the angle between two arbitrary vectors, instead of two floating
point vectors.

\see fcppt::math::vector::angle_between

\warning
The behaviour is undefined if \p _from or \p _to are very close to zero.
*/
template<
	typename Dest,
	typename T,
	typename N,
	typename S1,
	typename S2
>
typename boost::enable_if<
	std::is_floating_point<
		Dest
	>,
	Dest
>::type
angle_between_cast(
	fcppt::math::vector::object<T, N, S1> const &_from,
	fcppt::math::vector::object<T, N, S2> const &_to
)
{
	typedef fcppt::math::vector::static_<
		Dest,
		N::value
	> intermediate_type;

	return
		fcppt::math::vector::angle_between(
			fcppt::math::vector::structure_cast<
				intermediate_type
			>(
				_from
			),
			fcppt::math::vector::structure_cast<
				intermediate_type
			>(
				_to
			)
		);
}

}
}
}

#endif
