//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MOD_HPP_INCLUDED
#define FCPPT_MATH_MOD_HPP_INCLUDED

#include <cmath>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_unsigned.hpp>
#include <boost/type_traits/is_floating_point.hpp>

namespace fcppt
{
namespace math
{
template<typename T>
typename boost::enable_if<boost::is_floating_point<T>, void>::type mod_assign(T& l, const T& r)
{
	l = std::fmod(l, r);
}

template<typename T>
typename boost::enable_if<boost::is_unsigned<T>, void>::type mod_assign(T& l, const T& r)
{
	l %= r;
}

template<typename T>
typename boost::enable_if<boost::is_floating_point<T>, T>::type mod(const T& a, const T& b)
{
	return std::fmod(a, b);
}

template<typename T>
typename boost::enable_if<boost::is_unsigned<T>, T>::type mod(const T& a, const T& b)
{
	return a % b;
}
}
}

#endif
