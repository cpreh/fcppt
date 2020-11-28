//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MOVE_CLEAR_HPP_INCLUDED
#define FCPPT_MOVE_CLEAR_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Moves out of a value and clears it.

\ingroup fcpptvarious

Certain types can be moved out of but are then left in an unspecific state
that only allows them to be destroyed or assigned. This function first
moves out of the value and then assigns a default constructed value.
For example, this function can be used to move out of a container
and leave an empty container behind.

\tparam Type Must be movable and have a default constructor.
*/
template <typename Type>
Type move_clear(Type &_value)
{
  Type result(std::move(_value));

  _value = Type();

  return result;
}

}

#endif
