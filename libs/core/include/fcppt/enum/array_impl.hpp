//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_ARRAY_IMPL_HPP_INCLUDED
#define FCPPT_ENUM_ARRAY_IMPL_HPP_INCLUDED

#include <fcppt/cast/enum_to_int.hpp>
#include <fcppt/enum/array_decl.hpp>

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::reference
fcppt::enum_::array<Enum, Value>::operator[](Enum const _index)
{
  return impl_[this->to_index(_index)];
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::const_reference
fcppt::enum_::array<Enum, Value>::operator[](Enum const _index) const
{
  return impl_[this->to_index(_index)];
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::reference fcppt::enum_::array<Enum, Value>::front()
{
  return impl_.front();
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::const_reference
fcppt::enum_::array<Enum, Value>::front() const
{
  return impl_.front();
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::reference fcppt::enum_::array<Enum, Value>::back()
{
  return impl_.back();
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::const_reference
fcppt::enum_::array<Enum, Value>::back() const
{
  return impl_.back();
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::pointer fcppt::enum_::array<Enum, Value>::data()
{
  return impl_.data();
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::const_pointer
fcppt::enum_::array<Enum, Value>::data() const
{
  return impl_.data();
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::iterator fcppt::enum_::array<Enum, Value>::begin()
{
  return impl_.begin();
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::iterator fcppt::enum_::array<Enum, Value>::end()
{
  return impl_.end();
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::const_iterator
fcppt::enum_::array<Enum, Value>::cbegin() const
{
  return impl_.cbegin();
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::const_iterator
fcppt::enum_::array<Enum, Value>::cend() const
{
  return impl_.cend();
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::const_iterator
fcppt::enum_::array<Enum, Value>::begin() const
{
  return impl_.begin();
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::const_iterator
fcppt::enum_::array<Enum, Value>::end() const
{
  return impl_.end();
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::reverse_iterator
fcppt::enum_::array<Enum, Value>::rbegin()
{
  return impl_.rbegin();
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::reverse_iterator fcppt::enum_::array<Enum, Value>::rend()
{
  return impl_.rend();
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::const_reverse_iterator
fcppt::enum_::array<Enum, Value>::crbegin() const
{
  return impl_.crbegin();
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::const_reverse_iterator
fcppt::enum_::array<Enum, Value>::crend() const
{
  return impl_.crend();
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::const_reverse_iterator
fcppt::enum_::array<Enum, Value>::rbegin() const
{
  return impl_.rbegin();
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::const_reverse_iterator
fcppt::enum_::array<Enum, Value>::rend() const
{
  return impl_.rend();
}

template <typename Enum, typename Value>
constexpr typename fcppt::enum_::array<Enum, Value>::size_type
fcppt::enum_::array<Enum, Value>::size() const
{
  return impl_.size();
}

template <typename Enum, typename Value>
void fcppt::enum_::array<Enum, Value>::fill(Value const &_value)
{
  impl_.fill(_value);
}

template <typename Enum, typename Value>
void fcppt::enum_::array<Enum, Value>::swap(array &_other)
{
  impl_.swap(_other.impl_);
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::internal const &
fcppt::enum_::array<Enum, Value>::impl() const
{
  return impl_;
}

template <typename Enum, typename Value>
typename fcppt::enum_::array<Enum, Value>::internal::size_type
fcppt::enum_::array<Enum, Value>::to_index(Enum const _index)
{
  return fcppt::cast::enum_to_int<size_type>(_index);
}

template <typename Enum, typename Value>
void fcppt::enum_::swap(
    fcppt::enum_::array<Enum, Value> &_left, fcppt::enum_::array<Enum, Value> &_right)
{
  _left.swap(_right);
}

#endif
