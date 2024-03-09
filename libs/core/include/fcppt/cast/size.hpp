//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_SIZE_HPP_INCLUDED
#define FCPPT_CAST_SIZE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::cast
{
/**
\brief Converts a type to a similar type of different size

\ingroup fcpptcasts

Converts \a _source to the type specified by \a Dest. Exactly one of
the following cases must hold:

<ul>

<li>Both types are signed integer types.</li>

<li>Both types are unsigned integer types.</li>

<li>Both types are floating point types.</li>

</ul>
*/
template <typename Dest, typename Source>
constexpr Dest size(Source const _source) noexcept
  requires(
      std::is_floating_point_v<Dest> == std::is_floating_point_v<Source> ||
      std::is_signed_v<Dest> == std::is_signed_v<Source> ||
      std::is_unsigned_v<Dest> == std::is_unsigned_v<Source>)

{
  return static_cast<Dest>(_source);
}
}

#endif
