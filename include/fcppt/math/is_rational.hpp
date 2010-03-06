//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_IS_RATIONAL_HPP_INCLUDED
#define FCPPT_MATH_IS_RATIONAL_HPP_INCLUDED

#include <boost/type_traits/integral_constant.hpp>
#include <boost/rational.hpp>

namespace fcppt
{
namespace math
{
template<
	typename T
>
struct is_rational
:
boost::false_type
{};

template<
	typename T
>
struct is_rational
<
	boost::rational<T>
>
:
boost::true_type
{};

}
}

#endif
