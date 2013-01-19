//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_RAD_TO_DEG_HPP_INCLUDED
#define FCPPT_MATH_RAD_TO_DEG_HPP_INCLUDED

#include <fcppt/math/pi.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Transforms radians into degrees
\ingroup fcpptmath
\tparam T A floating point type
*/
template<
	typename T
>
inline
typename boost::enable_if<
	std::is_floating_point<
		T
	>,
	T
>::type
rad_to_deg(
	T const rad
)
{
	return rad * static_cast<T>(180) / math::pi<T>();
}

}
}

#endif
