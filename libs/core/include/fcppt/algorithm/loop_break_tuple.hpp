//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_LOOP_BREAK_TUPLE_HPP_INCLUDED
#define FCPPT_ALGORITHM_LOOP_BREAK_TUPLE_HPP_INCLUDED

#include <fcppt/algorithm/loop_break_impl_fwd.hpp>
#include <fcppt/algorithm/detail/tuple_loop_break.hpp>
#include <fcppt/tuple/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm
{
template <typename Range>
struct loop_break_impl<Range, std::enable_if_t<fcppt::tuple::is_object<Range>::value>>
{
  template <typename Tuple, typename Body>
  static void execute(Tuple &&_range, Body const &_body)
  {
    fcppt::algorithm::detail::tuple_loop_break<0U>(std::forward<Tuple>(_range), _body);
  }
};

}

#endif
