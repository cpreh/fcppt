//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_VECTOR_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/assert_static_storage.hpp>
#include <fcppt/math/detail/assign.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/detail/copy.hpp>
#include <fcppt/math/detail/index_at.hpp>
#include <fcppt/math/detail/member_operator.hpp>
#include <fcppt/math/detail/multiply_scalar.hpp>
#include <fcppt/math/vector/object_decl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename T, fcppt::math::size_type N, typename S>
fcppt::math::vector::object<T, N, S>::object(fcppt::no_init const &_no_init)
: storage_{_no_init}
{
  FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE(S);
}

template <typename T, fcppt::math::size_type N, typename S>
template <typename... Args, typename>
constexpr fcppt::math::vector::object<T, N, S>::object(Args &&..._args) noexcept(
    std::conjunction_v<std::is_nothrow_constructible<T, Args>...>)
    : storage_(std::forward<Args>(_args)...)
{
}

template <typename T, fcppt::math::size_type N, typename S>
fcppt::math::vector::object<T, N, S>::object(storage_type &&_storage)
    : storage_(std::move(_storage))
{
}

template <typename T, fcppt::math::size_type N, typename S>
template <typename OtherStorage>
fcppt::math::vector::object<T, N, S>::object(
    fcppt::math::vector::object<T, N, OtherStorage> const &_other)
    : storage_(fcppt::math::detail::copy<S>(_other))
{
}

template <typename T, fcppt::math::size_type N, typename S>
template <typename OtherStorage>
fcppt::math::vector::object<T, N, S> &fcppt::math::vector::object<T, N, S>::operator=(
    fcppt::math::vector::object<T, N, OtherStorage> const &_other)
{
  fcppt::math::detail::assign(*this, _other);

  return *this;
}

template <typename T, fcppt::math::size_type N, typename S>
template <typename S2>
fcppt::math::vector::object<T, N, S> &
fcppt::math::vector::object<T, N, S>::operator+=(object<T, N, S2> const &_right)
{
  return fcppt::math::detail::member_operator(
      *this, _right, [](T &_left_elem, T const &_right_elem) { _left_elem += _right_elem; });
}

template <typename T, fcppt::math::size_type N, typename S>
template <typename S2>
fcppt::math::vector::object<T, N, S> &
fcppt::math::vector::object<T, N, S>::operator-=(object<T, N, S2> const &_right)
{
  return fcppt::math::detail::member_operator(
      *this, _right, [](T &_left_elem, T const &_right_elem) { _left_elem -= _right_elem; });
}

template <typename T, fcppt::math::size_type N, typename S>
template <typename S2>
fcppt::math::vector::object<T, N, S> &
fcppt::math::vector::object<T, N, S>::operator*=(object<T, N, S2> const &_right)
{
  return fcppt::math::detail::member_operator(
      *this, _right, [](T &_left_elem, T const &_right_elem) { _left_elem *= _right_elem; });
}

template <typename T, fcppt::math::size_type N, typename S>
fcppt::math::vector::object<T, N, S> &
fcppt::math::vector::object<T, N, S>::operator*=(value_type const &_value)
{
  fcppt::math::detail::multiply_scalar(storage_, _value);

  return *this;
}

template <typename T, fcppt::math::size_type N, typename S>
typename fcppt::math::vector::object<T, N, S>::const_reference
fcppt::math::vector::object<T, N, S>::get_unsafe(size_type const _index) const
{
  return fcppt::math::detail::index_at(storage_, _index);
}

template <typename T, fcppt::math::size_type N, typename S>
typename fcppt::math::vector::object<T, N, S>::reference
fcppt::math::vector::object<T, N, S>::get_unsafe(size_type const _index)
{
  return fcppt::math::detail::index_at(storage_, _index);
}

template <typename T, fcppt::math::size_type N, typename S>
typename fcppt::math::vector::object<T, N, S>::reference fcppt::math::vector::object<T, N, S>::x()
{
  return fcppt::math::detail::checked_access<0>(*this);
}

template <typename T, fcppt::math::size_type N, typename S>
typename fcppt::math::vector::object<T, N, S>::const_reference
fcppt::math::vector::object<T, N, S>::x() const
{
  return fcppt::math::detail::checked_access<0>(*this);
}

template <typename T, fcppt::math::size_type N, typename S>
typename fcppt::math::vector::object<T, N, S>::reference fcppt::math::vector::object<T, N, S>::y()
{
  return fcppt::math::detail::checked_access<1>(*this);
}

template <typename T, fcppt::math::size_type N, typename S>
typename fcppt::math::vector::object<T, N, S>::const_reference
fcppt::math::vector::object<T, N, S>::y() const
{
  return fcppt::math::detail::checked_access<1>(*this);
}

template <typename T, fcppt::math::size_type N, typename S>
typename fcppt::math::vector::object<T, N, S>::reference fcppt::math::vector::object<T, N, S>::z()
{
  return fcppt::math::detail::checked_access<2>(*this);
}

template <typename T, fcppt::math::size_type N, typename S>
typename fcppt::math::vector::object<T, N, S>::const_reference
fcppt::math::vector::object<T, N, S>::z() const
{
  return fcppt::math::detail::checked_access<2>(*this);
}

template <typename T, fcppt::math::size_type N, typename S>
typename fcppt::math::vector::object<T, N, S>::reference fcppt::math::vector::object<T, N, S>::w()
{
  return fcppt::math::detail::checked_access<3>(*this);
}

template <typename T, fcppt::math::size_type N, typename S>
typename fcppt::math::vector::object<T, N, S>::const_reference
fcppt::math::vector::object<T, N, S>::w() const
{
  return fcppt::math::detail::checked_access<3>(*this);
}

template <typename T, fcppt::math::size_type N, typename S>
S &fcppt::math::vector::object<T, N, S>::storage()
{
  return storage_;
}

template <typename T, fcppt::math::size_type N, typename S>
S const &fcppt::math::vector::object<T, N, S>::storage() const
{
  return storage_;
}

#endif
