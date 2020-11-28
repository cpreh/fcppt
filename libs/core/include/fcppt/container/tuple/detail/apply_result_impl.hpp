//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_TUPLE_DETAIL_APPLY_RESULT_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_TUPLE_DETAIL_APPLY_RESULT_IMPL_HPP_INCLUDED

#include <fcppt/container/tuple/detail/apply_result_at.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <tuple>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
namespace tuple
{
namespace detail
{
template <typename Function, typename Indices, typename... Tuples>
struct apply_result_impl;

template <typename Function, std::size_t... Indices, typename... Tuples>
struct apply_result_impl<Function, std::index_sequence<Indices...>, Tuples...>
{
  using type =
      std::tuple<fcppt::container::tuple::detail::apply_result_at<Function, Indices, Tuples...>...>;
};

}
}
}
}

#endif
