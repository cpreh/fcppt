//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_DETAIL_HAS_RESERVE_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_HAS_RESERVE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace algorithm
{
namespace detail
{
template <typename Type, typename Test = void>
struct has_reserve : std::false_type
{
};

template <typename Type>
struct has_reserve<Type, decltype(std::declval<Type>().reserve(0U))> : std::true_type
{
};

}
}
}

#endif
