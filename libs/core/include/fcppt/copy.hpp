//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_COPY_HPP_INCLUDED
#define FCPPT_COPY_HPP_INCLUDED

namespace fcppt
{
/**
\brief Copies a value

\ingroup fcpptvarious

This function is useful in case you need to make an explicit copy of a value
but don't want to write down its type.
*/
template <typename Type>
inline Type copy(Type const &_value)
{
  return _value;
}

}

#endif
