//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_ERROR_EQUAL_HPP_INCLUDED
#define FCPPT_PARSE_ERROR_EQUAL_HPP_INCLUDED

#include <fcppt/parse/error_impl.hpp>

namespace fcppt
{
namespace parse
{
template <typename Ch>
bool operator==(fcppt::parse::error<Ch> const &_left, fcppt::parse::error<Ch> const &_right)
{
  return _left.get() == _right.get();
}

}
}

#endif
