//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_PI_HPP_INCLUDED
#define FCPPT_MATH_PI_HPP_INCLUDED

#include <fcppt/math/detail/pi.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

/// Returns pi for type T
/**
 * @tparam T must be a floating point type
*/
template<
	typename T
>
inline
typename boost::enable_if<
	boost::is_floating_point<
		T
	>,
	T
>::type
pi()
{
	return detail::pi<
		T
	>::get();
}

}
}

#endif
