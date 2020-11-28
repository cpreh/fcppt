//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_METAL_PRINT_HPP_INCLUDED
#define FCPPT_METAL_PRINT_HPP_INCLUDED

#include <fcppt/text.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/metal/detail/print.hpp>

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
template <typename Sequence>
fcppt::io::ostream &print(fcppt::io::ostream &_stream)
{
  _stream << FCPPT_TEXT('(');

  fcppt::metal::detail::print<Sequence>(_stream);

  _stream << FCPPT_TEXT(')');

  return _stream;
}

}
}

#endif
