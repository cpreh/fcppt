//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_UNIQUE_PTR_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_UNIQUE_PTR_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_traits
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Tells if a type is a unique ptr

\ingroup fcppttypetraits

Tells if \a Type is a unique ptr. It is used by the functions in \ref
fcpptcontainerptr

\tparam Type Can be any type
*/
template<
	typename Type
>
struct is_unique_ptr
:
std::false_type
{
};

template<
	typename Type,
	typename Deleter
>
struct is_unique_ptr<
	std::unique_ptr<
		Type,
		Deleter
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
