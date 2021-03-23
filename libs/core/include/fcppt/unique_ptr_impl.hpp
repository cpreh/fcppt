//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_UNIQUE_PTR_IMPL_HPP_INCLUDED
#define FCPPT_UNIQUE_PTR_IMPL_HPP_INCLUDED

#include <fcppt/default_deleter_fwd.hpp>
#include <fcppt/unique_ptr_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

template <typename Type, typename Deleter>
inline fcppt::unique_ptr<
    Type,
    Deleter>::unique_ptr(pointer const _ptr // NOLINT(misc-misplaced-const)
                         ) noexcept
    : impl_{_ptr}
{
}

template <typename Type, typename Deleter>
inline fcppt::unique_ptr<Type, Deleter>::unique_ptr(unique_ptr &&) noexcept = default;

template <typename Type, typename Deleter>
inline fcppt::unique_ptr<Type, Deleter> &
fcppt::unique_ptr<Type, Deleter>::operator=(unique_ptr &&) noexcept = default;

template <typename Type, typename Deleter>
inline fcppt::unique_ptr<Type, Deleter>::~unique_ptr<Type, Deleter>() = default;

template <typename Type, typename Deleter>
inline std::add_lvalue_reference_t<Type>
fcppt::unique_ptr<Type, Deleter>::operator*() const noexcept
{
  return *this->impl_;
}

template <typename Type, typename Deleter>
inline typename fcppt::unique_ptr<Type, Deleter>::pointer
fcppt::unique_ptr<Type, Deleter>::operator->() const noexcept
{
  return this->get_pointer();
}

template <typename Type, typename Deleter>
inline typename fcppt::unique_ptr<Type, Deleter>::pointer
fcppt::unique_ptr<Type, Deleter>::get_pointer() const noexcept
{
  return this->impl_.get();
}

template <typename Type, typename Deleter>
inline typename fcppt::unique_ptr<Type, Deleter>::pointer
fcppt::unique_ptr<Type, Deleter>::release_ownership() noexcept
{
  return this->impl_.release();
}

template <typename Type, typename Deleter>
inline fcppt::unique_ptr<Type, Deleter>::unique_ptr(std::unique_ptr<Type> &&_impl) noexcept
    : impl_{_impl.release()}
{
  static_assert(std::is_same_v<Deleter, fcppt::default_deleter>);
}

#endif
