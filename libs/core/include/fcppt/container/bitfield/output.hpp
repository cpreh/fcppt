//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_BITFIELD_OUTPUT_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_OUTPUT_HPP_INCLUDED

#include <fcppt/text.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/enum/make_range.hpp>
#include <fcppt/enum/to_string.hpp>
#include <fcppt/io/ostream.hpp>

namespace fcppt
{
namespace container
{
namespace bitfield
{
/**
\brief Outputs a bitfield.

\ingroup fcpptcontainerbitfield
*/
template <typename ElementType, typename NumElements, typename InternalType>
fcppt::io::ostream &operator<<(
    fcppt::io::ostream &_stream,
    fcppt::container::bitfield::object<ElementType, NumElements, InternalType> const &_bitfield)
{
  _stream << FCPPT_TEXT('{');

  for (ElementType const elem : fcppt::enum_::make_range<ElementType>())
  {
    if (_bitfield[elem])
    {
      _stream << fcppt::enum_::to_string(elem) << FCPPT_TEXT(',');
    }
  }

  _stream << FCPPT_TEXT('}');

  return _stream;
}

}
}
}

#endif
