//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_INDENT_START_HPP_INCLUDED
#define FCPPT_INDENT_START_HPP_INCLUDED

#include <fcppt/indent/level.hpp>

namespace fcppt::indent
{
/**
\brief The starting indent level.

\ingroup fcpptvarious
*/
inline fcppt::indent::level start() { return fcppt::indent::level{0U}; }
}

#endif
