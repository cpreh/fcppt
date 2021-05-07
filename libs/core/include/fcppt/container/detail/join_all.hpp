//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_DETAIL_JOIN_ALL_HPP_INCLUDED
#define FCPPT_CONTAINER_DETAIL_JOIN_ALL_HPP_INCLUDED

#include <fcppt/move_iterator_if_rvalue.hpp>
#include <fcppt/container/detail/join_insert.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
namespace detail
{
template <typename Result, typename... Args>
inline std::remove_cvref_t<Result> join_all(Result &&_first)
{
  return std::forward<Result>(_first);
}

template <typename Result, typename Container, typename... Args>
inline std::remove_cvref_t<Result>
join_all(Result &&_result, Container &&_container, Args &&..._args)
{
  fcppt::container::detail::join_insert(
      _result,
      fcppt::move_iterator_if_rvalue<Container>(_container.begin()),
      fcppt::move_iterator_if_rvalue<Container>(_container.end()));

  return fcppt::container::detail::join_all(
      std::forward<Result>(_result), std::forward<Args>(_args)...);
}

}
}
}

#endif
