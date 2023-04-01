//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_DYNAMIC_ARRAY_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_DYNAMIC_ARRAY_IMPL_HPP_INCLUDED

#include <fcppt/cast/to_signed.hpp>
#include <fcppt/container/dynamic_array_decl.hpp>
#include <fcppt/preprocessor/ignore_unsafe_buffer_usage.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

template <typename T, typename A>
fcppt::container::dynamic_array<T, A>::dynamic_array(size_type const _size)
    : dynamic_array{_size, A{}}
{
}

template <typename T, typename A>
fcppt::container::dynamic_array<T, A>::dynamic_array(size_type const _size, A const _alloc)
    : alloc_{_alloc}, data_{alloc_.allocate(_size)}, size_{_size}
{
}

namespace fcppt::container
{
template <typename T, typename A>
dynamic_array<T, A>::~dynamic_array() noexcept
{
  alloc_.deallocate(data_, size_);
}
}

template <typename T, typename A>
typename fcppt::container::dynamic_array<T, A>::pointer
fcppt::container::dynamic_array<T, A>::data() noexcept
{
  return data_;
}

template <typename T, typename A>
typename fcppt::container::dynamic_array<T, A>::const_pointer
fcppt::container::dynamic_array<T, A>::data() const noexcept
{
  return data_;
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_IGNORE_UNSAFE_BUFFER_USAGE

template <typename T, typename A>
typename fcppt::container::dynamic_array<T, A>::pointer
fcppt::container::dynamic_array<T, A>::data_end() noexcept
{
  return this->data() + fcppt::cast::to_signed(size_);
}

template <typename T, typename A>
typename fcppt::container::dynamic_array<T, A>::const_pointer
fcppt::container::dynamic_array<T, A>::data_end() const noexcept
{
  return this->data() + fcppt::cast::to_signed(size_);
}

FCPPT_PP_POP_WARNING

template <typename T, typename A>
typename fcppt::container::dynamic_array<T, A>::size_type
fcppt::container::dynamic_array<T, A>::size() const noexcept
{
  return size_;
}

#endif
