//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_HAS_CONST_ITERATOR_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_HAS_CONST_ITERATOR_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/detail/has_const_iterator.hpp>


namespace fcppt
{
namespace type_traits
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)
/**
\brief Checks if a type has a nested <code>const_iterator</code> typedef

\ingroup fcppttypetraits

Checks if \a Type has a nested <code>const_iterator</code> typedef.
*/
template<
	typename Type
>
struct has_const_iterator
:
fcppt::type_traits::detail::has_const_iterator<
	Type
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
