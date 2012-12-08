//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_PI_HPP_INCLUDED
#define FCPPT_MATH_PI_HPP_INCLUDED

#include <fcppt/math/detail/pi.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

/**
\brief Returns Pi for type T
\ingroup fcpptmath
\tparam T Must be a floating point type
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
pi()
{
	return
		fcppt::math::detail::pi<
			T
		>::get();
}

}
}

#endif
