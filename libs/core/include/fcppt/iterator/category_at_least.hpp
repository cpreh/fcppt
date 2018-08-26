//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ITERATOR_CATEGORY_AT_LEAST_HPP_INCLUDED
#define FCPPT_ITERATOR_CATEGORY_AT_LEAST_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace iterator
{

/**
\brief Checks if an iterator category includes another.

\ingroup fcpptiterator

Checks if \a Category models \a CategoryRef. For example,
if \a Category is <code>std::bidirectional_iterator_category</code>
and \a CategoryRef is <code>std::forward_iterator_category</code>, then
the value is true.

\tparam Category Must be one of the <code>std::</code> iterator category classes.

\tparam CategoryRef Must be one of the <code>std::</code> iterator category classes.
*/
template<
	typename Category,
	typename CategoryRef
>
using category_at_least
=
std::is_base_of<
	CategoryRef,
	Category
>;

}
}

#endif
