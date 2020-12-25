//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_DETAIL_TUPLE_LOOP_BREAK_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_TUPLE_LOOP_BREAK_HPP_INCLUDED

#include <fcppt/loop.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/tuple/size.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace algorithm
{
namespace detail
{
template <std::size_t Index, typename Tuple, typename Body>
inline std::enable_if_t<Index == fcppt::tuple::size<fcppt::type_traits::remove_cv_ref_t<Tuple>>::value>
tuple_loop_break(Tuple &&, Body const &)
{
}

template <std::size_t Index, typename Tuple, typename Body>
inline std::enable_if_t<Index != fcppt::tuple::size<fcppt::type_traits::remove_cv_ref_t<Tuple>>::value>
tuple_loop_break(Tuple &&_tuple, Body const &_body)
{
  switch (_body(fcppt::tuple::get<Index>(_tuple)))
  {
  case fcppt::loop::continue_:
    fcppt::algorithm::detail::tuple_loop_break<Index + 1U>(std::forward<Tuple>(_tuple), _body);
    break;
  case fcppt::loop::break_:
    break;
  }
}
}
}
}

#endif
