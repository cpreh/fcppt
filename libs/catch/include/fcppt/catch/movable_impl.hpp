//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CATCH_MOVABLE_IMPL_HPP_INCLUDED
#define FCPPT_CATCH_MOVABLE_IMPL_HPP_INCLUDED

#include <fcppt/catch/movable_decl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Type>
fcppt::catch_::movable<Type>::movable(Type const &_value) : value_{_value}
{
}

template <typename Type>
fcppt::catch_::movable<Type>::movable(Type &&_value)

    : value_{std::move(_value)}
{
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wnull-dereference)

template <typename Type>
fcppt::catch_::movable<Type>::movable(movable &&_other) noexcept(
    std::is_nothrow_move_constructible_v<Type>)
    : value_{std::move(_other.value())}
{
}

FCPPT_PP_POP_WARNING

template <typename Type>
fcppt::catch_::movable<Type> &fcppt::catch_::movable<Type>::operator=(movable &&_other) noexcept(
    std::is_nothrow_move_assignable_v<Type>)
{
  value_ = std::move(_other.value());

  return *this;
}

template <typename Type>
fcppt::catch_::movable<Type>::~movable<Type>() = default;

template <typename Type>
Type &fcppt::catch_::movable<Type>::value()
{
  return value_;
}

template <typename Type>
Type const &fcppt::catch_::movable<Type>::value() const
{
  return value_;
}

#endif
