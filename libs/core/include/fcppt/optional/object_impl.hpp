//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONAL_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/optional/object_decl.hpp> // IWYU pragma: export
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename T>
fcppt::optional::object<T>::object() : impl_{}
{
}

template <typename T>
fcppt::optional::object<T>::object(T const &_value) : impl_{_value}
{
}

template <typename T>
fcppt::optional::object<T>::object(T &&_other) : impl_{std::move(_other)}
{
}

template <typename T>
T &fcppt::optional::object<T>::get_unsafe()
{
  return *this->impl_; //NOLINT(bugprone-unchecked-optional-access)
}

template <typename T>
T const &fcppt::optional::object<T>::get_unsafe() const
{
  return *this->impl_; //NOLINT(bugprone-unchecked-optional-access)
}

template <typename T>
bool fcppt::optional::object<T>::has_value() const
{
  return this->impl_.has_value();
}

template <typename T>
typename fcppt::optional::object<T>::std_type &fcppt::optional::object<T>::impl()
{
  return this->impl_;
}

template <typename T>
typename fcppt::optional::object<T>::std_type const &fcppt::optional::object<T>::impl() const
{
  return this->impl_;
}

#endif
