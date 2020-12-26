//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_ARRAY_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/array/object_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename T, std::size_t Size>
template <typename... Args, typename>
constexpr fcppt::array::object<T, Size>::object(Args &&..._args) noexcept(
    std::conjunction_v<std::is_nothrow_constructible<T, Args>...>)
    : impl_{std::forward<Args>(_args)...}
{
}

template <typename T, std::size_t Size>
constexpr typename fcppt::array::object<T, Size>::impl_type &
fcppt::array::object<T, Size>::impl() noexcept
{
  return this->impl_;
}

template <typename T, std::size_t Size>
constexpr typename fcppt::array::object<T, Size>::impl_type const &
fcppt::array::object<T, Size>::impl() const noexcept
{
  return this->impl_;
}

#endif
