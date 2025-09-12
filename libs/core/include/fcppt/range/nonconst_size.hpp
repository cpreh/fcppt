//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RANGE_NONCONST_SIZE_HPP_INCLUDED
#define FCPPT_RANGE_NONCONST_SIZE_HPP_INCLUDED

#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>

namespace fcppt::range
{
/**
\brief Returns the size of a range using std::distance.

\ingroup fcpptrange

Depending on the range used, this might not run in constant time.
*/
template <typename Range>
inline auto nonconst_size(Range const &_range)
{
  return fcppt::cast::to_unsigned(std::distance(_range.begin(), _range.end()));
}

}

#endif
