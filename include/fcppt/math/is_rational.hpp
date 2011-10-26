//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_IS_RATIONAL_HPP_INCLUDED
#define FCPPT_MATH_IS_RATIONAL_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/rational.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{

/// derives from boost::true_type if T is a boost::rational<U>
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
