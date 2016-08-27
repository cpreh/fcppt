//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_STRING_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_STRING_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_traits
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Tells if a type is a string

\ingroup fcppttypetraits

Tells if \a Type is a string. This trait is used by fcppt::insert_to_string and
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

FCPPT_PP_POP_WARNING

}
}

#endif
