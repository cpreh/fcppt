//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_INTRUSIVE_ITERATOR_IMPL_HPP_INCLUDED
#define FCPPT_INTRUSIVE_ITERATOR_IMPL_HPP_INCLUDED

#include <fcppt/cast/static_downcast.hpp>
#include <fcppt/intrusive/base_impl.hpp>
#include <fcppt/intrusive/iterator_decl.hpp>

template <typename Type>
fcppt::intrusive::iterator<Type>::iterator() : iterator_base{}, cur_{nullptr}
{
}

template <typename Type>
fcppt::intrusive::iterator<Type>::iterator(pointer_type const _cur // NOLINT(misc-misplaced-const)
                                           )
    : iterator_base{}, cur_{_cur}
{
}

template <typename Type>
void fcppt::intrusive::iterator<Type>::increment()
{
  cur_ = cur_->next_;
}

template <typename Type>
void fcppt::intrusive::iterator<Type>::decrement()
{
  cur_ = cur_->prev_;
}

template <typename Type>
typename fcppt::intrusive::iterator<Type>::reference
fcppt::intrusive::iterator<Type>::dereference() const
{
  return fcppt::cast::static_downcast<reference>(*cur_);
}

template <typename Type>
bool fcppt::intrusive::iterator<Type>::equal(iterator const &_other) const
{
  return cur_ == _other.cur_;
}

#endif
