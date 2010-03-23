//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_STRING_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_STRING_HPP_INCLUDED

#include <boost/type_traits/integral_constant.hpp>
#include <string>

namespace fcppt
{
namespace type_traits
{

template<
	typename T
>
struct is_string
:
boost::false_type
{};

template<
	typename Ch,
	typename Traits,
	typename Alloc
>
struct is_string<
	std::basic_string<
		Ch,
		Traits,
		Alloc
	>
>
:
boost::true_type
{};

}
}

#endif
