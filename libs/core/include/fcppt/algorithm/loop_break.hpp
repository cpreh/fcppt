//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_LOOP_BREAK_HPP_INCLUDED
#define FCPPT_ALGORITHM_LOOP_BREAK_HPP_INCLUDED

#include <fcppt/algorithm/loop_break_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm
{
/**
\brief Iterates through a range with the ability to break out of the loop.

\ingroup fcpptalgorithm

Iterates through \a _range, calling \a _body for every element of the range as
long as \a _function returns fcppt::loop::continue_. The
implementation for a specific range type is handled by #fcppt::algorithm::loop_break_impl.

\tparam Body A function callable as <code>fcppt::loop (T)</code> for every type
<code>T</code> in \a Range
*/
template <typename Range, typename Body>
inline void loop_break(Range &&_range, Body const &_body)
{
  fcppt::algorithm::loop_break_impl<std::remove_cvref_t<Range>>::execute(
      std::forward<Range>(_range), _body);
}

}

#endif
