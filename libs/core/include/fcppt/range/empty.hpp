//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RANGE_EMPTY_HPP_INCLUDED
#define FCPPT_RANGE_EMPTY_HPP_INCLUDED

namespace fcppt::range
{
/**
\brief Tests if a range is empty.

\ingroup fcpptrange
*/
template <typename Range>
inline bool empty(Range const &_range)
{
  return _range.begin() == _range.end();
}

}

#endif
