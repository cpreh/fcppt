//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_TO_SIGNED_FUN_HPP_INCLUDED
#define FCPPT_CAST_TO_SIGNED_FUN_HPP_INCLUDED

#include <fcppt/cast/to_signed.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::cast
{
/**
\brief Function object of fcppt::cast::to_signed

\ingroup fcpptcasts
*/
struct to_signed_fun
{
  template <typename Dest, typename Source>
  static constexpr Dest execute(Source const &_source) noexcept
  {
    static_assert(
        std::is_same_v<decltype(fcppt::cast::to_signed(std::declval<Source>())), Dest>,
        "Mismatched types in to_signed_fun");

    return fcppt::cast::to_signed(_source);
  }
};

}

#endif
