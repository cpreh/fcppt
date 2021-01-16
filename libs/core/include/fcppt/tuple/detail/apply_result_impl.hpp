//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_DETAIL_APPLY_RESULT_IMPL_HPP_INCLUDED
#define FCPPT_TUPLE_DETAIL_APPLY_RESULT_IMPL_HPP_INCLUDED

#include <fcppt/tuple/object_impl.hpp>
#include <fcppt/tuple/detail/apply_result_at.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple::detail
{
template <typename Function, typename Indices, typename... Tuples>
struct apply_result_impl;

template <typename Function, std::size_t... Indices, typename... Tuples>
struct apply_result_impl<Function, std::index_sequence<Indices...>, Tuples...>
{
  using type =
      fcppt::tuple::object<fcppt::tuple::detail::apply_result_at<Function, Indices, Tuples...>...>;
};

}

#endif
