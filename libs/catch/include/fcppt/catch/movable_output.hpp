//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CATCH_MOVABLE_OUTPUT_HPP_INCLUDED
#define FCPPT_CATCH_MOVABLE_OUTPUT_HPP_INCLUDED

#include <fcppt/catch/convert.hpp>
#include <fcppt/catch/movable_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_tostring.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt::catch_
{
template <typename Type, typename Ch, typename Traits>
std::basic_ostream<Ch, Traits> &
operator<<(std::basic_ostream<Ch, Traits> &_stream, fcppt::catch_::movable<Type> const &_movable)
{
  return _stream << _movable.value();
}

}

namespace Catch
{
/**
\brief Output specialization for #fcppt::catch_::movable.

\ingroup fcpptcatch
*/
template <typename Type>
struct StringMaker<fcppt::catch_::movable<Type>>
{
  static std::string convert(fcppt::catch_::movable<Type> const &_value)
  {
    return fcppt::catch_::convert(_value.value());
  }
};
}

#endif
