//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_DETAIL_HAS_RANDOM_ACCESS_ITERATOR_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_HAS_RANDOM_ACCESS_ITERATOR_HPP_INCLUDED

#include <fcppt/detail/void.hpp>
#include <fcppt/type_traits/is_iterator_of_category.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm::detail
{
template <typename Type, typename Test = void>
struct has_random_access_iterator : std::false_type
{
};

template <typename Type>
struct has_random_access_iterator<
    Type,
    decltype(fcppt::detail::void_(std::declval<Type>().begin()))>
    : fcppt::type_traits::is_iterator_of_category<
          decltype(std::declval<Type>().begin()),
          std::random_access_iterator_tag>
{
};

}

#endif
