//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RANGE_SINGULAR_HPP_INCLUDED
#define FCPPT_RANGE_SINGULAR_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <ranges>
#include <fcppt/config/external_end.hpp>

namespace fcppt::range
{
/**
\brief Tests if a range consists of a single element.

\ingroup fcpptrange
*/
template <typename Range>
bool singular(Range const &_range)
{
  return !std::ranges::empty(_range) && std::next(_range.begin()) == _range.end();
}
}

#endif
