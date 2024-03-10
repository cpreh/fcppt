//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_DETAIL_TUPLE_LOOP_BREAK_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_TUPLE_LOOP_BREAK_HPP_INCLUDED

#include <fcppt/loop.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/tuple/size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm::detail
{
template <std::size_t Index, typename Tuple, typename Body>
inline void
tuple_loop_break(Tuple &&, Body const &) // NOLINT(cppcoreguidelines-missing-std-forward)
  requires(Index == fcppt::tuple::size<std::remove_cvref_t<Tuple>>::value)
{
}

template <std::size_t Index, typename Tuple, typename Body>
inline void tuple_loop_break(Tuple &&_tuple, Body const &_body)
  requires(Index != fcppt::tuple::size<std::remove_cvref_t<Tuple>>::value)
{
  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GCC_WARNING(-Wswitch-default)
  switch (_body(fcppt::tuple::get<Index>(_tuple)))
  {
  case fcppt::loop::continue_:
    fcppt::algorithm::detail::tuple_loop_break<Index + 1U>(std::forward<Tuple>(_tuple), _body);
    break;
  case fcppt::loop::break_:
    break;
  }
  FCPPT_PP_POP_WARNING
}
}

#endif
