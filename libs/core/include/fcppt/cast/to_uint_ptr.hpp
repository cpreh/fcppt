//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_TO_UINT_PTR_HPP_INCLUDED
#define FCPPT_CAST_TO_UINT_PTR_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace cast
{
/**
\brief Converts a pointer to a <code>std::uintptr_t</code>.

\ingroup fcpptcasts
*/
template <typename Source>
inline std::uintptr_t to_uint_ptr(Source *const _ptr) noexcept
{
  return
      // NOLINTNEXTLINE(cppcoreguidelines-pro-type-reinterpret-cast)
      reinterpret_cast<std::uintptr_t>(_ptr);
}

}
}

#endif
