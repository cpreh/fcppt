//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DETAIL_STATIC_STORAGE_IMPL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_STATIC_STORAGE_IMPL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/static_storage_decl.hpp> // IWYU pragma: export
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename T, fcppt::math::size_type N>
template <typename... Args>
constexpr fcppt::math::detail::static_storage<T, N>::static_storage(Args &&..._args) noexcept(
    std::conjunction_v<std::is_nothrow_constructible<T, Args>...>)
  requires(std::conjunction_v<
           std::bool_constant<sizeof...(Args) == N>,
           std::is_constructible<T, Args>...>)
    : impl_{std::forward<Args>(_args)...}
{
}

template <typename T, fcppt::math::size_type N>
fcppt::math::detail::static_storage<T, N>::static_storage(fcppt::no_init const &_no_init)
    : impl_(_no_init)
{
}

template <typename T, fcppt::math::size_type N>
fcppt::math::detail::static_storage<T, N>::static_storage(array_type _array)
    : impl_(std::move(_array))
{
}

template <typename T, fcppt::math::size_type N>
typename fcppt::math::detail::static_storage<T, N>::reference
fcppt::math::detail::static_storage<T, N>::operator[](fcppt::math::size_type const _index)
{
  return impl_.get_unsafe(_index);
}

template <typename T, fcppt::math::size_type N>
typename fcppt::math::detail::static_storage<T, N>::const_reference
fcppt::math::detail::static_storage<T, N>::operator[](fcppt::math::size_type const _index) const
{
  return impl_.get_unsafe(_index);
}

template <typename T, fcppt::math::size_type N>
typename fcppt::math::detail::static_storage<T, N>::pointer
fcppt::math::detail::static_storage<T, N>::data()
{
  return impl_.data();
}

template <typename T, fcppt::math::size_type N>
typename fcppt::math::detail::static_storage<T, N>::const_pointer
fcppt::math::detail::static_storage<T, N>::data() const
{
  return impl_.data();
}

#endif
