//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_LOOP_BREAK_IMPL_HPP_INCLUDED
#define FCPPT_ALGORITHM_LOOP_BREAK_IMPL_HPP_INCLUDED

#include <fcppt/loop.hpp>
#include <fcppt/algorithm/loop_break_impl_fwd.hpp> // IWYU pragma: keep
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm
{
template <typename Range, typename Enable>
struct loop_break_impl
{
  template <typename Arg, typename Body>
  // NOLINTNEXTLINE(cppcoreguidelines-missing-std-forward)
  static void execute(Arg &&_range, Body const &_body)
  {
    for (auto &&element : _range)
    {
      FCPPT_PP_PUSH_WARNING
      FCPPT_PP_DISABLE_GCC_WARNING(-Wswitch-default)
      // NOLINTNEXTLINE(clang-diagnostic-switch-default)
      switch (_body(std::forward<decltype(element)>(element)))
      {
      case fcppt::loop::break_:
        return;
      case fcppt::loop::continue_:
        break;
      }
      FCPPT_PP_POP_WARNING
    }
  }
};

}

#endif
