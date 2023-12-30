//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_POSITION_EQUAL_HPP_INCLUDED
#define FCPPT_PARSE_POSITION_EQUAL_HPP_INCLUDED

#include <fcppt/optional/comparison.hpp> // IWYU pragma: keep
#include <fcppt/parse/location_equal.hpp> // IWYU pragma: keep
#include <fcppt/parse/position_impl.hpp>

namespace fcppt::parse
{
/**
\brief Compares two positions for equality.
\ingroup fcpptparse
*/
template <typename Ch>
bool operator==(fcppt::parse::position<Ch> const &_left, fcppt::parse::position<Ch> const &_right)
{
  return _left.pos() == _right.pos() && _left.location() == _right.location();
}

}

#endif
