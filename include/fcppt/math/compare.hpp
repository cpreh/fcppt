//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_COMPARE_HPP_INCLUDED
#define FCPPT_MATH_COMPARE_HPP_INCLUDED

#include <fcppt/math/nearly_equals.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_floating_point.hpp>

namespace fcppt
{
namespace math
{

template<
	typename T
>
inline
typename boost::disable_if<
	boost::is_floating_point<
		T
	>,
	bool
>::type
compare(
	T const &a,
	T const &b)
{
	return a == b;
}

template<
	typename T
>
inline
typename boost::enable_if<
	boost::is_floating_point<
		T
	>,
	bool
>::type
compare(
	T const &a,
	T const &b)
{
	return nearly_equals(a, b);
}

}
}

#endif
