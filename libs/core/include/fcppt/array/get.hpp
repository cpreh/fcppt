//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_GET_HPP_INCLUDED
#define FCPPT_ARRAY_GET_HPP_INCLUDED

#include <fcppt/array/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array> // IWYU pragma: keep
#include <cstddef>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace fcppt::array
{
/**
\brief Returns the I'th element of a nonconst array.
\ingroup fcpptarray
*/
template <std::size_t I, typename T, std::size_t Size>
[[nodiscard]] constexpr T &get(fcppt::array::object<T, Size> &_value) noexcept
  requires(std::less<>{}(I, Size))
{
  return std::get<I>(_value.impl());
}

/**
\brief Returns the I'th element of a const array.
\ingroup fcpptarray
*/
template <std::size_t I, typename T, std::size_t Size>
[[nodiscard]] constexpr T const &get(fcppt::array::object<T, Size> const &_value) noexcept
  requires(std::less<>{}(I, Size))
{
  return std::get<I>(_value.impl());
}
}

#endif
