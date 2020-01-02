//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_STD_ARRAY_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_STD_ARRAY_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_traits
{

/**
\brief Checks if a type is a std::array

\ingroup fcppttypetraits

Checks if \a Type is a std::array

\tparam Type Can be any type
*/
template<
	typename Type
>
struct is_std_array
:
std::false_type
{
};

template<
	typename T,
	std::size_t N
>
struct is_std_array<
	std::array<
		T,
		N
	>
>
:
std::true_type
{
};

}
}

#endif
