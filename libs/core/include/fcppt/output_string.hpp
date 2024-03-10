//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OUTPUT_STRING_HPP_INCLUDED
#define FCPPT_OUTPUT_STRING_HPP_INCLUDED

#include <fcppt/output_impl_fwd.hpp>
#include <fcppt/widen.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
template<>
struct output_impl<std::string, void>
{
  static void
  execute(std::ostream &_stream, std::string const &_value)
  {
    _stream << _value;
  }

  static void
  execute(std::wostream &_stream, std::string const &_value)
  {
    _stream << fcppt::widen(_value);
  }

};
}

#endif
