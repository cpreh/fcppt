//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OUTPUT_PAIR_HPP_INCLUDED
#define FCPPT_OUTPUT_PAIR_HPP_INCLUDED

#include <fcppt/output.hpp>
#include <fcppt/output_impl_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
template <typename T1, typename T2>
struct output_impl<std::pair<T1, T2>, void>
{
  template <typename Ch, typename Traits>
  static void
  execute(std::basic_ostream<Ch, Traits> &_stream, std::pair<T1, T2> const &_value)
  {
    _stream << _stream.widen('(');
    fcppt::output(_stream, _value.first);
    _stream << _stream.widen(',');
    fcppt::output(_stream, _value.second);
    _stream << _stream.widen(')');
  }
};
}

#endif
