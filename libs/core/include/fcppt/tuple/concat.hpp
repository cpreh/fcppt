//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_CONCAT_HPP_INCLUDED
#define FCPPT_TUPLE_CONCAT_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/tuple/is_object.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt::tuple
{
/**
\brief Concatenates multiple tuples
\ingroup fcppttuple
*/
template <
    typename... Tuples,
    typename = std::enable_if_t<std::conjunction_v<fcppt::tuple::is_object<Tuples>...>>>
decltype(auto) concat(Tuples &&..._tuples)
{
  return std::apply(
      [](auto &&..._results) {
        return fcppt::tuple::make(std::forward<decltype(_results)>(_results)...);
      },
      std::tuple_cat(fcppt::move_if_rvalue<Tuples>(_tuples.impl())...));
}
}

#endif
