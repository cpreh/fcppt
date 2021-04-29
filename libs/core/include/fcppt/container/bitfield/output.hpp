//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_BITFIELD_OUTPUT_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_OUTPUT_HPP_INCLUDED

#include <fcppt/char_literal.hpp>
#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/enum/make_range.hpp>
#include <fcppt/enum/to_string.hpp>
#include <fcppt/io/widen_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <string>
#include <fcppt/config/external_end.hpp>

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
template <
    typename Ch,
    typename Traits,
    typename ElementType,
    typename InternalType>
std::basic_ostream<Ch, Traits> &operator<<(
    std::basic_ostream<Ch, Traits> &_stream,
    fcppt::container::bitfield::object<ElementType, InternalType> const &_bitfield)
{
  _stream << FCPPT_CHAR_LITERAL(Ch, '{');

  bool is_first{true};

  for (ElementType const elem : fcppt::enum_::make_range<ElementType>())
  {
    if (_bitfield[elem])
    {
      if(!is_first)
      {
        _stream << FCPPT_CHAR_LITERAL(Ch, ',');
      }
      _stream << fcppt::io::widen_string(std::string{fcppt::enum_::to_string(elem)});
      is_first = false;
    }
  }

  _stream << FCPPT_CHAR_LITERAL(Ch, '}');

  return _stream;
}
}
}
}

#endif
