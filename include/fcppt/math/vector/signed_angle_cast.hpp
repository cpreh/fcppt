//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_SIGNED_ANGLE_CAST_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_SIGNED_ANGLE_CAST_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/signed_angle.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/structure_cast.hpp>
#include <fcppt/math/detail/has_size.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/mpl/and.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{

/// Calculates the signed angle between two vectors
/// and structure_casts the parameters to the destination type
/**
 * @tparam Dest must be a floating point type
 * The behaviour is undefined if is_null(_from - _to)
*/
template<
	typename Dest,
	typename T,
	typename N,
	typename S1,
	typename S2
>
typename boost::enable_if<
	boost::mpl::and_<
		boost::is_floating_point<
			Dest
		>,
		math::detail::has_size<
			N,
			2
		>
	>,
	Dest
>::type
signed_angle_cast(
	basic<T, N, S1> const &_from,
	basic<T, N, S2> const &_to
)
{
	typedef typename fcppt::math::vector::static_<
		Dest,
		N::value
	>::type intermediate_type;

	return
		vector::signed_angle(
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
