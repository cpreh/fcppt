//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OUTPUT_IMPL_HPP_INCLUDED
#define FCPPT_OUTPUT_IMPL_HPP_INCLUDED

#include <fcppt/output_impl_fwd.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Customization point for #fcppt::output.

\ingroup fcpptvarious

The default implementation uses <code>operator<< </code>.
*/
template <typename Arg, typename Enable>
struct output_impl
{
  template <typename Ch, typename Traits>
  static void execute(std::basic_ostream<Ch, Traits> &_stream, Arg const &_value)
  {
    _stream << _value;
  }
};

}

#endif
