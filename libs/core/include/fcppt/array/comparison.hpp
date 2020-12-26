//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_COMPARISON_HPP_INCLUDED
#define FCPPT_ARRAY_COMPARISON_HPP_INCLUDED

#include <fcppt/array/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

namespace fcppt::array
{
/**
\brief Compares two arrays for equality.
\ingroup fcpptarray
*/
template <typename T, std::size_t Size>
[[nodiscard]] bool inline
operator==(fcppt::array::object<T, Size> const &a, fcppt::array::object<T, Size> const &b)
{
  return a.impl() == b.impl();
}
}

#endif
