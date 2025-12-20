//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_INDENT_EXTRA_HPP_INCLUDED
#define FCPPT_INDENT_EXTRA_HPP_INCLUDED

#include <fcppt/strong_typedef_arithmetic.hpp>
#include <fcppt/indent/level.hpp>

namespace fcppt::indent
{
/**
\brief Increases the indent level.

\ingroup fcpptvarious
*/
[[nodiscard]] inline fcppt::indent::level
extra(fcppt::indent::level const _level)
{
  return _level + fcppt::indent::level{2U};
}
}

#endif
