//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_STD_TUPLE_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_STD_TUPLE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_traits
{

/**
\brief Checks if an type is a std::tuple

\ingroup fcppttypetraits

Checks if \a Type is a std::tuple

\tparam Type Can be any type
*/
template<
	typename Type
>
struct is_std_tuple
:
std::false_type
{
};

template<
	typename... Types
>
struct is_std_tuple<
	std::tuple<
		Types...
	>
>
:
std::true_type
{
};

}
}

#endif
