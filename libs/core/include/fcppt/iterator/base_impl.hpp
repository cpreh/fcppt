//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ITERATOR_BASE_IMPL_HPP_INCLUDED
#define FCPPT_ITERATOR_BASE_IMPL_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/cast/static_downcast.hpp>
#include <fcppt/iterator/base_decl.hpp> // IWYU pragma: export
#include <fcppt/type_traits/implication.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Types>
fcppt::iterator::base<Types>::base()
{
  static_assert(
      fcppt::type_traits::implication<
          my_category_at_least<std::forward_iterator_tag>,
          std::is_default_constructible<derived>>::value,
      "Forward iterators must be default-constructible");
}

template <typename Types>
typename fcppt::iterator::base<Types>::reference fcppt::iterator::base<Types>::operator*() const
{
  return this->get().dereference();
}

template <typename Types>
typename fcppt::iterator::base<Types>::derived &fcppt::iterator::base<Types>::operator++()
{
  this->get().increment();

  return this->get();
}

template <typename Types>
bool fcppt::iterator::base<Types>::operator==(base const &_other) const
{
  return this->get().equal(_other.get());
}

template <typename Types>
bool fcppt::iterator::base<Types>::operator!=(base const &_other) const
{
  return !(*this == _other);
}

template <typename Types>
typename fcppt::iterator::base<Types>::pointer fcppt::iterator::base<Types>::operator->() const
{
  static_assert(
      std::is_reference_v<reference>,
      "reference must be a real reference for operator-> to make sense");

  return &*(*this);
}

template <typename Types>
typename fcppt::iterator::base<Types>::derived fcppt::iterator::base<Types>::operator++(int)
{
  derived temp{this->get()};

  ++(*this);

  return temp;
}

template <typename Types>
void fcppt::iterator::base<Types>::swap(base &_other) noexcept
{
  std::swap(this->get(), _other.get());
}

template <typename Types>
typename fcppt::iterator::base<Types>::derived &fcppt::iterator::base<Types>::operator--()
{
  static_assert(
      my_category_at_least<std::bidirectional_iterator_tag>::value,
      "operator-- is only supported for bidirectional iterators");

  this->get().decrement();

  return this->get();
}

template <typename Types>
typename fcppt::iterator::base<Types>::derived fcppt::iterator::base<Types>::operator--(int)
{
  derived temp{this->get()};

  --*this;

  return temp;
}

template <typename Types>
typename fcppt::iterator::base<Types>::derived &
fcppt::iterator::base<Types>::operator+=(difference_type const _diff)
{
  static_assert(
      my_category_at_least<std::random_access_iterator_tag>::value,
      "operator+= is only supported for random access iterators");

  this->get().advance(_diff);

  return this->get();
}

template <typename Types>
typename fcppt::iterator::base<Types>::derived
fcppt::iterator::base<Types>::operator+(difference_type const _diff) const
{
  derived temp{this->get()};

  return temp += _diff;
}

template <typename Types>
typename fcppt::iterator::base<Types>::derived &
fcppt::iterator::base<Types>::operator-=(difference_type const _diff)
{
  return *this += -_diff;
}

template <typename Types>
typename fcppt::iterator::base<Types>::derived
fcppt::iterator::base<Types>::operator-(difference_type const _diff) const
{
  derived temp{this->get()};

  return temp -= _diff;
}

template <typename Types>
typename fcppt::iterator::base<Types>::reference
fcppt::iterator::base<Types>::operator[](difference_type const _pos) const
{
  return *(*this + _pos);
}

template <typename Types>
typename fcppt::iterator::base<Types>::difference_type
fcppt::iterator::base<Types>::operator-(base const &_other) const
{
  static_assert(
      my_category_at_least<std::random_access_iterator_tag>::value,
      "operator- is only supported for random access iterators");

  return _other.get().distance_to(this->get());
}

template <typename Types>
typename fcppt::iterator::base<Types>::derived &fcppt::iterator::base<Types>::get()
{
  return fcppt::cast::static_downcast<derived &>(*this);
}

template <typename Types>
typename fcppt::iterator::base<Types>::derived const &fcppt::iterator::base<Types>::get() const
{
  return fcppt::cast::static_downcast<derived const &>(*this);
}

template <typename Types>
void fcppt::iterator::swap(
    fcppt::iterator::base<Types> &_left, fcppt::iterator::base<Types> &_right) noexcept
{
  _left.swap(_right);
}

template <typename Types>
typename fcppt::iterator::base<Types>::derived fcppt::iterator::operator+(
    typename fcppt::iterator::base<Types>::difference_type const _diff,
    fcppt::iterator::base<Types> const &_it)
{
  return _it + _diff;
}

template <typename Types>
bool fcppt::iterator::operator<(
    fcppt::iterator::base<Types> const &_left, fcppt::iterator::base<Types> const &_right)
{
  return (_right - _left) >
         fcppt::literal<typename fcppt::iterator::base<Types>::difference_type>(0);
}

template <typename Types>
bool fcppt::iterator::operator>(
    fcppt::iterator::base<Types> const &_left, fcppt::iterator::base<Types> const &_right)
{
  return _right < _left;
}

template <typename Types>
bool fcppt::iterator::operator<=(
    fcppt::iterator::base<Types> const &_left, fcppt::iterator::base<Types> const &_right)
{
  return !(_left > _right);
}

template <typename Types>
bool fcppt::iterator::operator>=(
    fcppt::iterator::base<Types> const &_left, fcppt::iterator::base<Types> const &_right)
{
  return !(_left < _right);
}

#endif
