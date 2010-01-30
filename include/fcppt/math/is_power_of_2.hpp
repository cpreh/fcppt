//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_IS_POWER_OF_2_HPP_INCLUDED
#define FCPPT_MATH_IS_POWER_OF_2_HPP_INCLUDED

#include <boost/type_traits/is_unsigned.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{
namespace math
{

template<
	typename T
>
inline typename boost::enable_if<
	boost::is_unsigned<T>,
	bool
>::type
is_power_of_2(
	T const t)
{
	return t && !(t & (t - 1));
}

}
}

#endif
