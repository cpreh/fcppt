//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_MATRIX_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/assert_static_storage.hpp>
#include <fcppt/math/detail/assign.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/detail/copy.hpp>
#include <fcppt/math/detail/member_operator.hpp>
#include <fcppt/math/detail/multiply_scalar.hpp>
#include <fcppt/math/matrix/object_decl.hpp> // IWYU pragma: export
#include <fcppt/math/matrix/row_type.hpp> // IWYU pragma: keep
#include <fcppt/math/matrix/detail/init_storage.hpp>
#include <fcppt/math/matrix/detail/row_view_impl.hpp> // IWYU pragma: keep
#include <fcppt/math/vector/object_impl.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
fcppt::math::matrix::object<T, R, C, S>::object(fcppt::no_init const &_no_init)
: storage_{_no_init}
{
  FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE(S);
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
fcppt::math::matrix::object<T, R, C, S>::object(storage_type &&_storage)
    : storage_(std::move(_storage))
{
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
template <typename... Args>
fcppt::math::matrix::object<T, R, C, S>::object(Args &&..._args)
  requires(std::conjunction_v<
           std::bool_constant<sizeof...(Args) == R>,
           std::is_same<fcppt::math::matrix::row_type<T, C>, std::remove_cvref_t<Args>>...>)
    : storage_(fcppt::math::matrix::detail::init_storage<storage_type, C>(
          std::forward_as_tuple(std::forward<Args>(_args)...)))
{
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
template <typename OtherStorage>
fcppt::math::matrix::object<T, R, C, S>::object(
    fcppt::math::matrix::object<T, R, C, OtherStorage> const &_other)
    : storage_(fcppt::math::detail::copy<S>(_other))
{
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
template <typename OtherStorage>
fcppt::math::matrix::object<T, R, C, S> &fcppt::math::matrix::object<T, R, C, S>::operator=(
    fcppt::math::matrix::object<T, R, C, OtherStorage> const &_other)
{
  fcppt::math::detail::assign(*this, _other);

  return *this;
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
template <typename S2>
fcppt::math::matrix::object<T, R, C, S> &
fcppt::math::matrix::object<T, R, C, S>::operator+=(object<T, R, C, S2> const &_right)
{
  return fcppt::math::detail::member_operator(
      *this, _right, [](T &_left_elem, T const &_right_elem) { _left_elem += _right_elem; });
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
template <typename S2>
fcppt::math::matrix::object<T, R, C, S> &
fcppt::math::matrix::object<T, R, C, S>::operator-=(object<T, R, C, S2> const &_right)
{
  return fcppt::math::detail::member_operator(
      *this, _right, [](T &_left_elem, T const &_right_elem) { _left_elem -= _right_elem; });
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
fcppt::math::matrix::object<T, R, C, S> &
fcppt::math::matrix::object<T, R, C, S>::operator*=(value_type const &_value)
{
  fcppt::math::detail::multiply_scalar(storage_, _value);

  return *this;
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::reference
fcppt::math::matrix::object<T, R, C, S>::get_unsafe(size_type const _j)
{
  return reference(typename reference::storage_type(storage_, _j, this->columns()));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::const_reference
fcppt::math::matrix::object<T, R, C, S>::get_unsafe(size_type const _j) const
{
  return const_reference(typename const_reference::storage_type(storage_, _j, this->columns()));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
constexpr typename fcppt::math::matrix::object<T, R, C, S>::size_type
fcppt::math::matrix::object<T, R, C, S>::rows()
{
  return R;
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
constexpr typename fcppt::math::matrix::object<T, R, C, S>::size_type
fcppt::math::matrix::object<T, R, C, S>::columns()
{
  return C;
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
S &fcppt::math::matrix::object<T, R, C, S>::storage()
{
  return storage_;
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
S const &fcppt::math::matrix::object<T, R, C, S>::storage() const
{
  return storage_;
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::inner_reference
fcppt::math::matrix::object<T, R, C, S>::m00()
{
  return fcppt::math::detail::checked_access<0>(fcppt::math::detail::checked_access<0>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::const_inner_reference
fcppt::math::matrix::object<T, R, C, S>::m00() const
{
  return fcppt::math::detail::checked_access<0>(fcppt::math::detail::checked_access<0>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::inner_reference
fcppt::math::matrix::object<T, R, C, S>::m01()
{
  return fcppt::math::detail::checked_access<1>(fcppt::math::detail::checked_access<0>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::const_inner_reference
fcppt::math::matrix::object<T, R, C, S>::m01() const
{
  return fcppt::math::detail::checked_access<1>(fcppt::math::detail::checked_access<0>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::inner_reference
fcppt::math::matrix::object<T, R, C, S>::m02()
{
  return fcppt::math::detail::checked_access<2>(fcppt::math::detail::checked_access<0>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::const_inner_reference
fcppt::math::matrix::object<T, R, C, S>::m02() const
{
  return fcppt::math::detail::checked_access<2>(fcppt::math::detail::checked_access<0>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::inner_reference
fcppt::math::matrix::object<T, R, C, S>::m03()
{
  return fcppt::math::detail::checked_access<3>(fcppt::math::detail::checked_access<0>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::const_inner_reference
fcppt::math::matrix::object<T, R, C, S>::m03() const
{
  return fcppt::math::detail::checked_access<3>(fcppt::math::detail::checked_access<0>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::inner_reference
fcppt::math::matrix::object<T, R, C, S>::m10()
{
  return fcppt::math::detail::checked_access<0>(fcppt::math::detail::checked_access<1>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::const_inner_reference
fcppt::math::matrix::object<T, R, C, S>::m10() const
{
  return fcppt::math::detail::checked_access<0>(fcppt::math::detail::checked_access<1>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::inner_reference
fcppt::math::matrix::object<T, R, C, S>::m11()
{
  return fcppt::math::detail::checked_access<1>(fcppt::math::detail::checked_access<1>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::const_inner_reference
fcppt::math::matrix::object<T, R, C, S>::m11() const
{
  return fcppt::math::detail::checked_access<1>(fcppt::math::detail::checked_access<1>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::inner_reference
fcppt::math::matrix::object<T, R, C, S>::m12()
{
  return fcppt::math::detail::checked_access<2>(fcppt::math::detail::checked_access<1>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::const_inner_reference
fcppt::math::matrix::object<T, R, C, S>::m12() const
{
  return fcppt::math::detail::checked_access<2>(fcppt::math::detail::checked_access<1>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::inner_reference
fcppt::math::matrix::object<T, R, C, S>::m13()
{
  return fcppt::math::detail::checked_access<3>(fcppt::math::detail::checked_access<1>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::const_inner_reference
fcppt::math::matrix::object<T, R, C, S>::m13() const
{
  return fcppt::math::detail::checked_access<3>(fcppt::math::detail::checked_access<1>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::inner_reference
fcppt::math::matrix::object<T, R, C, S>::m20()
{
  return fcppt::math::detail::checked_access<0>(fcppt::math::detail::checked_access<2>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::const_inner_reference
fcppt::math::matrix::object<T, R, C, S>::m20() const
{
  return fcppt::math::detail::checked_access<0>(fcppt::math::detail::checked_access<2>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::inner_reference
fcppt::math::matrix::object<T, R, C, S>::m21()
{
  return fcppt::math::detail::checked_access<1>(fcppt::math::detail::checked_access<2>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::const_inner_reference
fcppt::math::matrix::object<T, R, C, S>::m21() const
{
  return fcppt::math::detail::checked_access<1>(fcppt::math::detail::checked_access<2>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::inner_reference
fcppt::math::matrix::object<T, R, C, S>::m22()
{
  return fcppt::math::detail::checked_access<2>(fcppt::math::detail::checked_access<2>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::const_inner_reference
fcppt::math::matrix::object<T, R, C, S>::m22() const
{
  return fcppt::math::detail::checked_access<2>(fcppt::math::detail::checked_access<2>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::inner_reference
fcppt::math::matrix::object<T, R, C, S>::m23()
{
  return fcppt::math::detail::checked_access<3>(fcppt::math::detail::checked_access<2>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::const_inner_reference
fcppt::math::matrix::object<T, R, C, S>::m23() const
{
  return fcppt::math::detail::checked_access<3>(fcppt::math::detail::checked_access<2>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::inner_reference
fcppt::math::matrix::object<T, R, C, S>::m30()
{
  return fcppt::math::detail::checked_access<0>(fcppt::math::detail::checked_access<3>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::const_inner_reference
fcppt::math::matrix::object<T, R, C, S>::m30() const
{
  return fcppt::math::detail::checked_access<0>(fcppt::math::detail::checked_access<3>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::inner_reference
fcppt::math::matrix::object<T, R, C, S>::m31()
{
  return fcppt::math::detail::checked_access<1>(fcppt::math::detail::checked_access<3>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::const_inner_reference
fcppt::math::matrix::object<T, R, C, S>::m31() const
{
  return fcppt::math::detail::checked_access<1>(fcppt::math::detail::checked_access<3>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::inner_reference
fcppt::math::matrix::object<T, R, C, S>::m32()
{
  return fcppt::math::detail::checked_access<2>(fcppt::math::detail::checked_access<3>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::const_inner_reference
fcppt::math::matrix::object<T, R, C, S>::m32() const
{
  return fcppt::math::detail::checked_access<2>(fcppt::math::detail::checked_access<3>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::inner_reference
fcppt::math::matrix::object<T, R, C, S>::m33()
{
  return fcppt::math::detail::checked_access<3>(fcppt::math::detail::checked_access<3>(*this));
}

template <typename T, fcppt::math::size_type R, fcppt::math::size_type C, typename S>
typename fcppt::math::matrix::object<T, R, C, S>::const_inner_reference
fcppt::math::matrix::object<T, R, C, S>::m33() const
{
  return fcppt::math::detail::checked_access<3>(fcppt::math::detail::checked_access<3>(*this));
}

#endif
