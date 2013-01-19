//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MOD_ASSIGN_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MOD_ASSIGN_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <cmath>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T
>
typename boost::enable_if<
	std::is_floating_point<
		T
	>,
	void
>::type
mod_assign(
	T& l,
	T const &r
)
{
	l = std::fmod(l, r);
}

template<
	typename T
>
typename boost::enable_if<
	std::is_unsigned<
		T
	>,
	void
>::type
mod_assign(
	T& l,
	T const &r
)
{
	l %= r;
}

}
}
}

#endif
