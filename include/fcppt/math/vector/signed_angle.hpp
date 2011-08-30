//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_SIGNED_ANGLE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_SIGNED_ANGLE_HPP_INCLUDED

#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/atan2.hpp>
#include <fcppt/math/detail/has_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/mpl/and.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{

/// Calculates the signed angle between two vectors
/**
 * @tparam T must be a floating point type
 * The behaviour is undefined if is_null(_from - _to)
*/
template<
	typename T,
	typename N,
	typename S1,
	typename S2
>
typename boost::enable_if<
	boost::mpl::and_<
		boost::is_floating_point<
			T
		>,
		math::detail::has_size<
			N,
			2
		>
	>,
	T
>::type
signed_angle(
	basic<T, N, S1> const &_from,
	basic<T, N, S2> const &_to
)
{
	return
		vector::atan2(
			_to
			- _from
		);
}

}
}
}

#endif
