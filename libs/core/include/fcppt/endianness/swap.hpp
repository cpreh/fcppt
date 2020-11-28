//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENDIANNESS_SWAP_HPP_INCLUDED
#define FCPPT_ENDIANNESS_SWAP_HPP_INCLUDED

#include <fcppt/cast/to_char_ptr.hpp>
#include <fcppt/endianness/raw_pointer.hpp>
#include <fcppt/endianness/reverse_mem.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace endianness
{
/**
\brief Swaps the endianness of an object

\ingroup fcpptendianness

Swaps the endiannness of \a _value.

\tparam Type Must be an arithmetic type

\param _value The value to swap the endianness for

\return The converted value
*/
template <typename Type>
Type swap(Type _value)
{
  static_assert(
      std::is_arithmetic<Type>::value, "endianness::swap can only be used on arithmetic types");

  fcppt::endianness::reverse_mem(
      fcppt::cast::to_char_ptr<fcppt::endianness::raw_pointer>(&_value), sizeof(Type));

  return _value;
}

}
}

#endif
