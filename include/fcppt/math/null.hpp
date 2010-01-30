//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_NULL_HPP_INCLUDED
#define FCPPT_MATH_NULL_HPP_INCLUDED

#include <fcppt/math/is_rational.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{
namespace math
{
template<typename T>
typename
boost::disable_if
<
	fcppt::math::is_rational<T>,
	T
>::type
null()
{
	return static_cast<T>(0);
}

template<typename T>
typename
boost::enable_if
<
	fcppt::math::is_rational<T>,
	T
>::type
null()
{
	return T();
}
}
}

#endif
