//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_ARRAY_IMPL_HPP_INCLUDED
#define FCPPT_ENUM_ARRAY_IMPL_HPP_INCLUDED

#include <fcppt/cast/enum_to_int.hpp>
#include <fcppt/enum/array_decl.hpp> // IWYU pragma: export
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Enum, typename Value>
template <typename... Args>
constexpr fcppt::enum_::array<Enum, Value>::array(Args &&..._args) noexcept(
    std::conjunction_v<std::is_nothrow_constructible<Value, Args>...>)
  requires(
      fcppt::enum_::array<Enum, Value>::static_size::value == sizeof...(Args) &&
      std::conjunction_v<std::is_constructible<Value, Args>...>)
    : impl_{std::forward<Args>(_args)...}
{
}

template <typename Enum, typename Value>
constexpr fcppt::enum_::array<Enum, Value>::array(from_internal, internal &&_impl) noexcept(
    std::is_nothrow_move_constructible_v<internal>)
    : impl_{std::move(_impl)}
{
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::reference
fcppt::enum_::array<Enum, Value>::operator[](Enum const _index) noexcept
{
  return this->impl().get_unsafe(array::to_index(_index));
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::const_reference
fcppt::enum_::array<Enum, Value>::operator[](Enum const _index) const noexcept
{
  return this->impl().get_unsafe(array::to_index(_index));
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::iterator fcppt::enum_::array<Enum, Value>::begin()
{
  return this->impl().begin();
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::iterator fcppt::enum_::array<Enum, Value>::end()
{
  return this->impl().end();
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::const_iterator
fcppt::enum_::array<Enum, Value>::begin() const
{
  return this->impl().begin();
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::const_iterator
fcppt::enum_::array<Enum, Value>::end() const
{
  return this->impl().end();
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::pointer fcppt::enum_::array<Enum, Value>::data()
{
  return this->impl().data();
}
template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::const_pointer
fcppt::enum_::array<Enum, Value>::data() const
{
  return this->impl().data();
}

template <typename Enum, typename Value>
constexpr typename fcppt::enum_::array<Enum, Value>::internal &
fcppt::enum_::array<Enum, Value>::impl() noexcept
{
  return this->impl_;
}

template <typename Enum, typename Value>
constexpr typename fcppt::enum_::array<Enum, Value>::internal const &
fcppt::enum_::array<Enum, Value>::impl() const noexcept
{
  return this->impl_;
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::internal::size_type
fcppt::enum_::array<Enum, Value>::to_index(Enum const _index) noexcept
{
  return fcppt::cast::enum_to_int<typename internal::size_type>(_index);
}

#endif
