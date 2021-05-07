//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_DETAIL_MAP_RESULT_HPP_INCLUDED
#define FCPPT_TUPLE_DETAIL_MAP_RESULT_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/tuple/element.hpp>
#include <fcppt/tuple/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple::detail
{
template <typename Indices, typename Tuple, typename Function>
struct map_result;

template <std::size_t... Indices, typename Tuple, typename Function>
struct map_result<std::index_sequence<Indices...>, Tuple, Function>
{
  using tuple_type = std::remove_cvref_t<Tuple>;
  using type = fcppt::tuple::object<decltype(std::declval<Function>()(
      fcppt::move_if_rvalue<Tuple>(std::declval<fcppt::tuple::element<Indices,tuple_type>>())))...>;
};

}

#endif
