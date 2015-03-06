//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_HAS_ITERATOR_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_HAS_ITERATOR_HPP_INCLUDED

#include <fcppt/type_traits/detail/has_iterator.hpp>


namespace fcppt
{
namespace type_traits
{

/**
\brief Checks if a type has a nested <code>iterator</code> typedef

\ingroup fcppttypetraits

Checks if \a Type has a nested <code>iterator</code> typedef.
*/
template<
	typename Type
>
using has_iterator
=
fcppt::type_traits::detail::has_iterator<
	Type
>;

}
}

#endif
