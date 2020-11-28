//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_REFERENCE_IMPL_HPP_INCLUDED
#define FCPPT_REFERENCE_IMPL_HPP_INCLUDED

#include <fcppt/reference_decl.hpp>

template <typename Type>
inline fcppt::reference<Type>::reference(type &_ref) noexcept : impl_(&_ref)
{
}

template <typename Type>
inline typename fcppt::reference<Type>::type &fcppt::reference<Type>::get() const noexcept
{
  return *this->impl_;
}

template <typename Type>
inline typename fcppt::reference<Type>::type *fcppt::reference<Type>::operator->() const noexcept
{
  return this->impl_;
}

#endif
