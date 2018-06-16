//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_STRING_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_STRING_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <string>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_traits
{

/**
\brief Tells if a type is a string

\ingroup fcppttypetraits

Tells if \a Type is a string. This trait is used by fcppt::output_to_string and
fcppt::extract_from_string.

\tparam Type Can be any type
*/
template<
	typename Type
>
struct is_string
:
std::false_type
{
};

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
std::true_type
{
};

}
}

#endif
