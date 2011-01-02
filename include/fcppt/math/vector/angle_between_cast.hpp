//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_ANGLE_BETWEEN_CAST_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_ANGLE_BETWEEN_CAST_HPP_INCLUDED

#include <fcppt/math/vector/angle_between.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/structure_cast.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_floating_point.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{

/// Calculates the relative angle between two vectors
/// and structure_casts the parameters to the destination type
/**
 * @tparam Dest must be a floating point type
 * The behaviour is undefined if length(_from - _to) == 0
*/
template<
	typename Dest,
	typename T,
	typename N,
	typename S1,
	typename S2
>
typename boost::enable_if<
	boost::is_floating_point<
		Dest
	>,
	Dest
>::type
angle_between_cast(
	basic<T, N, S1> const &_from,
	basic<T, N, S2> const &_to
)
{
	typedef typename fcppt::math::vector::static_<
		Dest,
		N::value
	>::type intermediate_type;

	return
		vector::angle_between(
			vector::structure_cast<
				intermediate_type
			>(
				_from
			),
			vector::structure_cast<
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
