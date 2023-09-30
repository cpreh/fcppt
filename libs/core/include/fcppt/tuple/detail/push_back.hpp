//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_DETAIL_PUSH_BACK_HPP_INCLUDED
#define FCPPT_TUPLE_DETAIL_PUSH_BACK_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple::detail
{
template <typename Result, typename Source, typename NewElement, std::size_t... Indices>
inline Result
// NOLINTNEXTLINE(cppcoreguidelines-missing-std-forward)
push_back(std::index_sequence<Indices...>, Source &&_source, NewElement &&_new_element)
{
  return Result{
      fcppt::move_if_rvalue<Source>(
          fcppt::tuple::get<Indices>(_source))...,
      std::forward<NewElement>(_new_element)};
}

}

#endif
