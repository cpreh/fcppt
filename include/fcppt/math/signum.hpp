//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_SIGNUM_HPP_INCLUDED
#define FCPPT_MATH_SIGNUM_HPP_INCLUDED

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_unsigned.hpp>

namespace fcppt
{
namespace math
{

template<
	typename T
>
inline typename boost::disable_if<boost::is_unsigned<T>,T>::type
signum(
	T const t)
{
	if (t > static_cast<T>(0))
		return static_cast<T>(1);
	if (t < static_cast<T>(0))
		return static_cast<T>(-1);
	return static_cast<T>(0);
}

template<
	typename T
>
inline typename boost::enable_if<boost::is_unsigned<T>, T>::type
signum(
	T const t)
{
	return t != static_cast<T>(0)
		? static_cast<T>(1)
		: static_cast<T>(0);
}

}
}

#endif
