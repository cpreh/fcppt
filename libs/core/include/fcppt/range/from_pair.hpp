//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RANGE_FROM_PAIR_HPP_INCLUDED
#define FCPPT_RANGE_FROM_PAIR_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <ranges>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::range
{
/**
\brief Creates a range from a std::pair.

\ingroup fcpptrange
*/
template <typename Iterator>
[[nodiscard]] inline std::ranges::subrange<Iterator>
from_pair(std::pair<Iterator, Iterator> const &_range)
{
  return std::ranges::subrange<Iterator>{_range.first, _range.second};
}
}

#endif
