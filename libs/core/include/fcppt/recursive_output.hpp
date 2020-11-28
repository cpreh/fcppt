//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECURSIVE_OUTPUT_HPP_INCLUDED
#define FCPPT_RECURSIVE_OUTPUT_HPP_INCLUDED

#include <fcppt/recursive_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
template <typename Ch, typename Traits, typename Type>
std::basic_ostream<Ch, Traits> &
operator<<(std::basic_ostream<Ch, Traits> &_stream, fcppt::recursive<Type> const &_value)
{
  return _stream << _value.get();
}

}

#endif
