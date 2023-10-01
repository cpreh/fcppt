//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TYPE_TRAITS_IS_ITERATOR_OF_CATEGORY_V_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_ITERATOR_OF_CATEGORY_V_HPP_INCLUDED

#include <fcppt/type_traits/is_iterator_of_category.hpp>

namespace fcppt::type_traits
{
/**
\brief Checks if an iterator models a given category.
\ingroup fcppttypetraits
\see fcppt::type_traits::is_iterator_of_category
*/
template <typename Iterator, typename Category>
constexpr inline bool is_iterator_of_category_v =
    // NOLINTNEXTLINE(modernize-type-traits)
    fcppt::type_traits::is_iterator_of_category<Iterator, Category>::value;
}

#endif
