//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENABLE_SHARED_FROM_THIS_IMPL_HPP_INCLUDED
#define FCPPT_ENABLE_SHARED_FROM_THIS_IMPL_HPP_INCLUDED

#include <fcppt/enable_shared_from_this_decl.hpp> // IWYU pragma: export
#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/detail/make_shared_wrapper.hpp>

template <typename Type>
fcppt::enable_shared_from_this<Type>::enable_shared_from_this() : base{}
{
}

template <typename Type>
fcppt::enable_shared_from_this<Type>::enable_shared_from_this(enable_shared_from_this const &) =
    default;

template <typename Type>
fcppt::enable_shared_from_this<Type>::enable_shared_from_this(enable_shared_from_this &&) noexcept =
    default;

template <typename Type>
fcppt::enable_shared_from_this<Type> &
fcppt::enable_shared_from_this<Type>::operator=(enable_shared_from_this const &) = default;

template <typename Type>
fcppt::enable_shared_from_this<Type> &
fcppt::enable_shared_from_this<Type>::operator=(enable_shared_from_this &&) noexcept = default;

namespace fcppt
{
template <typename Type>
enable_shared_from_this<Type>::~enable_shared_from_this() = default;
}

template <typename Type>
fcppt::shared_ptr<Type> fcppt::enable_shared_from_this<Type>::fcppt_shared_from_this()
{
  return fcppt::shared_ptr<Type>{
      fcppt::detail::make_shared_wrapper<Type>{this->shared_from_this()}};
}

template <typename Type>
fcppt::shared_ptr<Type const> fcppt::enable_shared_from_this<Type>::fcppt_shared_from_this() const
{
  return fcppt::shared_ptr<Type const>{
      fcppt::detail::make_shared_wrapper<Type const>{this->shared_from_this()}};
}

#endif
