//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_REFERENCE_OUTPUT_HPP_INCLUDED
#define FCPPT_REFERENCE_OUTPUT_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Outputs a reference wrapper to a stream

\ingroup fcpptref
*/
template <typename T, typename Ch, typename Traits>
std::basic_ostream<Ch, Traits> &
operator<<(std::basic_ostream<Ch, Traits> &_stream, fcppt::reference<T> const &_ref)
{
  return _stream << &_ref.get();
}

}

#endif
