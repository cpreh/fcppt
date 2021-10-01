//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_INT_TO_ENUM_FUN_HPP_INCLUDED
#define FCPPT_CAST_INT_TO_ENUM_FUN_HPP_INCLUDED

#include <fcppt/cast/int_to_enum.hpp>

namespace fcppt::cast
{
/**
\brief Function object of fcppt::cast::int_to_enum

\ingroup fcpptcasts
*/
struct int_to_enum_fun
{
  template <typename Dest, typename Source>
  static constexpr Dest execute(Source const &_source) noexcept
  {
    return fcppt::cast::int_to_enum<Dest>(_source);
  }
};

}

#endif
