//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_DIM_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_MATH_DIM_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/assert_static_storage.hpp>
#include <fcppt/math/detail/assign.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/detail/copy.hpp>
#include <fcppt/math/detail/index_at.hpp>
#include <fcppt/math/detail/member_operator.hpp>
#include <fcppt/math/detail/multiply_scalar.hpp>
#include <fcppt/math/dim/object_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename T, fcppt::math::size_type N, typename S>
fcppt::math::dim::object<T, N, S>::object(fcppt::no_init const &_no_init)
: storage_{_no_init}
{
  FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE(S);
}

template <typename T, fcppt::math::size_type N, typename S>
template <typename... Args>
fcppt::math::dim::object<T, N, S>::object(Args const &..._args) : storage_(_args...)
{
  FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE(S);

  static_assert(sizeof...(Args) == N, "Wrong number of parameters");
}

template <typename T, fcppt::math::size_type N, typename S>
fcppt::math::dim::object<T, N, S>::object(storage_type &&_storage) : storage_(std::move(_storage))
{
}

template <typename T, fcppt::math::size_type N, typename S>
fcppt::math::dim::object<T, N, S>::object(object const &) = default;

template <typename T, fcppt::math::size_type N, typename S>
fcppt::math::dim::object<T, N, S>::object(object &&_other) noexcept(
    std::is_nothrow_move_constructible_v<storage_type>)
    : storage_{std::move(_other.storage_)}
{
}

template <typename T, fcppt::math::size_type N, typename S>
template <typename OtherStorage>
fcppt::math::dim::object<T, N, S>::object(
    fcppt::math::dim::object<T, N, OtherStorage> const &_other)
    : storage_(fcppt::math::detail::copy<S>(_other))
{
}

template <typename T, fcppt::math::size_type N, typename S>
fcppt::math::dim::object<T, N, S> &
fcppt::math::dim::object<T, N, S>::operator=(object const &) = default;

template <typename T, fcppt::math::size_type N, typename S>
fcppt::math::dim::object<T, N, S> &fcppt::math::dim::object<T, N, S>::operator=(
    object &&_other) noexcept(std::is_nothrow_move_assignable_v<storage_type>)
{
  if (this == &_other)
  {
    return *this;
  }

  storage_ = std::move(_other.storage_);

  return *this;
}

template <typename T, fcppt::math::size_type N, typename S>
template <typename OtherStorage>
fcppt::math::dim::object<T, N, S> &fcppt::math::dim::object<T, N, S>::operator=(
    fcppt::math::dim::object<T, N, OtherStorage> const &_other)
{
  fcppt::math::detail::assign(*this, _other);

  return *this;
}

template <typename T, fcppt::math::size_type N, typename S>
fcppt::math::dim::object<T, N, S>::~object<T, N, S>() = default;

template <typename T, fcppt::math::size_type N, typename S>
template <typename S2>
fcppt::math::dim::object<T, N, S> &
fcppt::math::dim::object<T, N, S>::operator+=(object<T, N, S2> const &_right)
{
  return fcppt::math::detail::member_operator(
      *this, _right, [](T &_left_elem, T const &_right_elem) { _left_elem += _right_elem; });
}

template <typename T, fcppt::math::size_type N, typename S>
template <typename S2>
fcppt::math::dim::object<T, N, S> &
fcppt::math::dim::object<T, N, S>::operator-=(object<T, N, S2> const &_right)
{
  return fcppt::math::detail::member_operator(
      *this, _right, [](T &_left_elem, T const &_right_elem) { _left_elem -= _right_elem; });
}

template <typename T, fcppt::math::size_type N, typename S>
template <typename S2>
fcppt::math::dim::object<T, N, S> &
fcppt::math::dim::object<T, N, S>::operator*=(object<T, N, S2> const &_right)
{
  return fcppt::math::detail::member_operator(
      *this, _right, [](T &_left_elem, T const &_right_elem) { _left_elem *= _right_elem; });
}

template <typename T, fcppt::math::size_type N, typename S>
fcppt::math::dim::object<T, N, S> &
fcppt::math::dim::object<T, N, S>::operator*=(value_type const &_value)
{
  fcppt::math::detail::multiply_scalar(storage_, _value);

  return *this;
}

template <typename T, fcppt::math::size_type N, typename S>
typename fcppt::math::dim::object<T, N, S>::reference
fcppt::math::dim::object<T, N, S>::get_unsafe(size_type const _index)
{
  return fcppt::math::detail::index_at(storage_, _index);
}

template <typename T, fcppt::math::size_type N, typename S>
typename fcppt::math::dim::object<T, N, S>::const_reference
fcppt::math::dim::object<T, N, S>::get_unsafe(size_type const _index) const
{
  return fcppt::math::detail::index_at(storage_, _index);
}

template <typename T, fcppt::math::size_type N, typename S>
typename fcppt::math::dim::object<T, N, S>::reference fcppt::math::dim::object<T, N, S>::w()
{
  return fcppt::math::detail::checked_access<0>(*this);
}

template <typename T, fcppt::math::size_type N, typename S>
typename fcppt::math::dim::object<T, N, S>::const_reference
fcppt::math::dim::object<T, N, S>::w() const
{
  return fcppt::math::detail::checked_access<0>(*this);
}

template <typename T, fcppt::math::size_type N, typename S>
typename fcppt::math::dim::object<T, N, S>::reference fcppt::math::dim::object<T, N, S>::h()
{
  return fcppt::math::detail::checked_access<1>(*this);
}

template <typename T, fcppt::math::size_type N, typename S>
typename fcppt::math::dim::object<T, N, S>::const_reference
fcppt::math::dim::object<T, N, S>::h() const
{
  return fcppt::math::detail::checked_access<1>(*this);
}

template <typename T, fcppt::math::size_type N, typename S>
typename fcppt::math::dim::object<T, N, S>::reference fcppt::math::dim::object<T, N, S>::d()
{
  return fcppt::math::detail::checked_access<2>(*this);
}

template <typename T, fcppt::math::size_type N, typename S>
typename fcppt::math::dim::object<T, N, S>::const_reference
fcppt::math::dim::object<T, N, S>::d() const
{
  return fcppt::math::detail::checked_access<2>(*this);
}

template <typename T, fcppt::math::size_type N, typename S>
S &fcppt::math::dim::object<T, N, S>::storage()
{
  return storage_;
}

template <typename T, fcppt::math::size_type N, typename S>
S const &fcppt::math::dim::object<T, N, S>::storage() const
{
  return storage_;
}

#endif
