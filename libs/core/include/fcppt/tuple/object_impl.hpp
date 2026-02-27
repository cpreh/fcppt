//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_TUPLE_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/tuple/object_decl.hpp> // IWYU pragma: export
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename... Types>
template <typename... Args>
constexpr fcppt::tuple::object<Types...>::object(Args &&..._args) noexcept(
    std::conjunction_v<std::is_nothrow_constructible<Types, Args>...>)
  requires(
      sizeof...(Types) == sizeof...(Args) &&
      std::conjunction_v<std::is_constructible<Types, Args>...>)
    : impl_{std::forward<Args>(_args)...}
{
}

template <typename... Types>
constexpr fcppt::tuple::object<Types...>::impl_type &
fcppt::tuple::object<Types...>::impl() noexcept
{
  return this->impl_;
}

template <typename... Types>
constexpr fcppt::tuple::object<Types...>::impl_type const &
fcppt::tuple::object<Types...>::impl() const noexcept
{
  return this->impl_;
}

#endif
