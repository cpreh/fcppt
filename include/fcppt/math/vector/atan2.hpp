//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_ATAN2_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_ATAN2_HPP_INCLUDED

#include <fcppt/math/detail/has_size.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/// Calculates atan2(@a v.y(), @a v.x())
/**
 * @tparam T must be a floating point type
 * @tparam N must be two (only two dimensional vectors are allowed)
*/
template<
	typename T,
	typename N,
	typename S
>
inline
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
atan2(
	basic<T, N, S> const &_vector
)
{
	return
		std::atan2(
			_vector.y(),
			_vector.x()
		);
}

}
}
}

#endif
