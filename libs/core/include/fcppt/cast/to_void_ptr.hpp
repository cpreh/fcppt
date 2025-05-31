//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_TO_VOID_PTR_HPP_INCLUDED
#define FCPPT_CAST_TO_VOID_PTR_HPP_INCLUDED

namespace fcppt::cast
{
/**
\brief Converts a pointer to const to a pointer to const void.

\ingroup fcpptcasts
*/
template <typename Source>
// NOLINTNEXTLINE(readability-avoid-const-params-in-decls)
[[nodiscard]] inline void const *to_void_ptr(Source const *const _ptr) noexcept
{
  return _ptr; // NOLINT(bugprone-multi-level-implicit-pointer-conversion)
}

/**
\brief Converts a pointer to a pointer to void.

\ingroup fcpptcasts
*/
template <typename Source>
// NOLINTNEXTLINE(readability-avoid-const-params-in-decls)
[[nodiscard]] inline void *to_void_ptr(Source *const _ptr) noexcept
{
  return _ptr; // NOLINT(bugprone-multi-level-implicit-pointer-conversion)
}

}

#endif
