//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_COND_HPP_INCLUDED
#define FCPPT_COND_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Functional if-then-else.

\ingroup fcpptvarious

Unlike the <code>? :</code> operator, this function does no implicit conversions.

The functions \a If and \a Then must return the same type <code>R</code>.

\tparam If A function callable as <code>R ()</code>.

\tparam Then A function callable as <code>R ()</code>.
*/
template <typename If, typename Then>
inline std::invoke_result_t<If> cond(bool const _conditional, If const &_if, Then const &_then)
{
  static_assert(std::is_same_v<std::invoke_result_t<If>, std::invoke_result_t<Then>>);

  if (_conditional)
  {
    return _if();
  }

  return _then();
}

}

#endif
