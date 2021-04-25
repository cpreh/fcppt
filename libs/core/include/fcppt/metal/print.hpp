//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_METAL_PRINT_HPP_INCLUDED
#define FCPPT_METAL_PRINT_HPP_INCLUDED

#include <fcppt/char_literal.hpp>
#include <fcppt/metal/detail/print.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace metal
{
/**
\brief Pretty prints a metal list.

\ingroup fcpptmetal

Pretty prints \a Sequence to \a _stream. Every type in \a Sequence will be
converted to a string using fcppt::type_name. The resulting format of the
printed sequence will be <code>(name_1, ..., name_n)</code>.

\tparam Sequence Must be a metal::list.

\param _stream The stream to print to.

\return \a _stream
*/
template <typename Sequence, typename Ch, typename Traits>
std::basic_ostream<Ch, Traits> &print(std::basic_ostream<Ch, Traits> &_stream)
{
  _stream << FCPPT_CHAR_LITERAL(Ch, '(');

  fcppt::metal::detail::print<Sequence>(_stream);

  _stream << FCPPT_CHAR_LITERAL(Ch, ')');

  return _stream;
}
}
}

#endif
