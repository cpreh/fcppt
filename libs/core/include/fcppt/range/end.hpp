//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RANGE_END_HPP_INCLUDED
#define FCPPT_RANGE_END_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace range
{
/**
\brief Calls end via ADL.

\ingroup fcpptrange
*/
template <typename Range>
auto end(Range &_range)
{
  using std::end;

  return end(_range);
}

}
}

#endif
