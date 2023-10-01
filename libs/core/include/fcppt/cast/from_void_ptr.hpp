//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_FROM_VOID_PTR_HPP_INCLUDED
#define FCPPT_CAST_FROM_VOID_PTR_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::cast
{
/**
\brief Converts a void pointer to a different pointer

\ingroup fcpptcasts

Converts the void pointer \a _ptr to the pointer type specified by \a Dest.
This cast is unsafe.

\tparam Source Must be a pointer type to (cv) void

\tparam Dest Must be a pointer type
*/
template <typename Dest, typename Source>
inline Dest from_void_ptr(Source *const _ptr) noexcept
{
  static_assert(
      std::is_pointer_v<Dest> && std::is_void_v<std::remove_cv_t<Source>>,
      "from_void_ptr can only cast from a pointer to (cv) void to a different pointer type");

  return static_cast<Dest>(_ptr);
}

}

#endif
