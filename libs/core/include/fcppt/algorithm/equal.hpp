//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_EQUAL_HPP_INCLUDED
#define FCPPT_ALGORITHM_EQUAL_HPP_INCLUDED

#include <fcppt/range/begin.hpp>
#include <fcppt/range/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm
{
/**
\brief Compares two ranges for equality.

\ingroup fcpptalgorithm
*/
template <typename Range1, typename Range2>
inline bool equal(Range1 const &_range1, Range2 const &_range2)
{
  return std::equal(
      fcppt::range::begin(_range1),
      fcppt::range::end(_range1),
      fcppt::range::begin(_range2),
      fcppt::range::end(_range2));
}

}

#endif
