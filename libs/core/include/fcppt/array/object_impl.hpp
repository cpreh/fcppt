//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ARRAY_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_ARRAY_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/array/object_decl.hpp> // IWYU pragma: export
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename T, std::size_t Size>
template <typename... Args>
constexpr fcppt::array::object<T, Size>::object(Args &&..._args) noexcept(
    std::conjunction_v<std::is_nothrow_constructible<T, Args>...>)
  requires(Size == sizeof...(Args) && std::conjunction_v<std::is_constructible<T, Args>...>)
    : impl_{{std::forward<Args>(_args)...}}
{
}

template <typename T, std::size_t Size>
fcppt::array::object<T, Size>::object(fcppt::no_init const &)
{
}

template <typename T, std::size_t Size>
fcppt::array::object<T, Size>::reference
fcppt::array::object<T, Size>::get_unsafe(size_type const _index) noexcept
{
  // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-constant-array-index,cppcoreguidelines-pro-bounds-avoid-unchecked-container-access)
  return this->impl()[_index];
}

template <typename T, std::size_t Size>
fcppt::array::object<T, Size>::const_reference
fcppt::array::object<T, Size>::get_unsafe(size_type const _index) const noexcept
{
  // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-constant-array-index,cppcoreguidelines-pro-bounds-avoid-unchecked-container-access)
  return this->impl()[_index];
}

template <typename T, std::size_t Size>
fcppt::array::object<T, Size>::iterator fcppt::array::object<T, Size>::begin()
{
  return this->impl().begin();
}

template <typename T, std::size_t Size>
fcppt::array::object<T, Size>::iterator fcppt::array::object<T, Size>::end()
{
  return this->impl().end();
}

template <typename T, std::size_t Size>
fcppt::array::object<T, Size>::const_iterator fcppt::array::object<T, Size>::begin() const
{
  return this->impl().begin();
}

template <typename T, std::size_t Size>
fcppt::array::object<T, Size>::const_iterator fcppt::array::object<T, Size>::end() const
{
  return this->impl().end();
}

template <typename T, std::size_t Size>
fcppt::array::object<T, Size>::pointer fcppt::array::object<T, Size>::data()
{
  return this->impl().data();
}

template <typename T, std::size_t Size>
fcppt::array::object<T, Size>::const_pointer fcppt::array::object<T, Size>::data() const
{
  return this->impl().data();
}

template <typename T, std::size_t Size>
constexpr fcppt::array::object<T, Size>::size_type
fcppt::array::object<T, Size>::size() const
{
  return this->impl().size();
}

template <typename T, std::size_t Size>
constexpr fcppt::array::object<T, Size>::impl_type &
fcppt::array::object<T, Size>::impl() noexcept
{
  return this->impl_;
}

template <typename T, std::size_t Size>
constexpr fcppt::array::object<T, Size>::impl_type const &
fcppt::array::object<T, Size>::impl() const noexcept
{
  return this->impl_;
}

#endif
