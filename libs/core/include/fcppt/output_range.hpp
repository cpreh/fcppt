//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OUTPUT_RANGE_HPP_INCLUDED
#define FCPPT_OUTPUT_RANGE_HPP_INCLUDED

#include <fcppt/output_impl_fwd.hpp>
#include <fcppt/concepts/range.hpp> // IWYU pragma: keep
#include <fcppt/container/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
template <typename Arg>
requires fcppt::concepts::range<Arg>
struct output_impl<Arg, void>
{
  template <typename Ch, typename Traits>
  static void execute(std::basic_ostream<Ch, Traits> &_stream, Arg const &_value)
  {
    _stream << fcppt::container::output(_value);
  }
};
}

#endif
