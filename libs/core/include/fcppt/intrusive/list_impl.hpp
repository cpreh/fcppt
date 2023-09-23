//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_INTRUSIVE_LIST_IMPL_HPP_INCLUDED
#define FCPPT_INTRUSIVE_LIST_IMPL_HPP_INCLUDED

#include <fcppt/intrusive/base_impl.hpp>
#include <fcppt/intrusive/iterator_impl.hpp>
#include <fcppt/intrusive/list_decl.hpp> // IWYU pragma: export

template <typename Type>
fcppt::intrusive::list<Type>::list() : head_{}
{
}

template <typename Type>
fcppt::intrusive::list<Type>::list(list &&_other) noexcept : head_{}
{
  if (!_other.empty())
  {
    this->head_ = std::move(_other.head_);
  }
}

template <typename Type>
fcppt::intrusive::list<Type> &fcppt::intrusive::list<Type>::operator=(list &&_other) noexcept
{
  if (&_other == this)
  {
    return *this;
  }

  if (_other.empty())
  {
    this->head_.next_ = &this->head_;

    this->head_.prev_ = &this->head_;
  }
  else
  {
    this->head_ = std::move(_other.head_);
  }

  return *this;
}

namespace fcppt::intrusive
{
template <typename Type>
list<Type>::~list() = default;
}

template <typename Type>
typename fcppt::intrusive::list<Type>::iterator fcppt::intrusive::list<Type>::begin()
{
  return iterator{this->head_.next_};
}

template <typename Type>
typename fcppt::intrusive::list<Type>::iterator fcppt::intrusive::list<Type>::end()
{
  return iterator{&this->head_};
}

template <typename Type>
typename fcppt::intrusive::list<Type>::const_iterator fcppt::intrusive::list<Type>::begin() const
{
  return const_iterator{this->head_.next_};
}

template <typename Type>
typename fcppt::intrusive::list<Type>::const_iterator fcppt::intrusive::list<Type>::end() const
{
  return const_iterator{&this->head_};
}

template <typename Type>
bool fcppt::intrusive::list<Type>::empty() const
{
  return this->begin() == this->end();
}

#endif
