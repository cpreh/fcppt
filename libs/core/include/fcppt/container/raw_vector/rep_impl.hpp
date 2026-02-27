//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_RAW_VECTOR_REP_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_RAW_VECTOR_REP_IMPL_HPP_INCLUDED

#include <fcppt/strong_typedef_impl.hpp> // IWYU pragma: keep
#include <fcppt/container/raw_vector/rep_decl.hpp> // IWYU pragma: export

template <typename A>
fcppt::container::raw_vector::rep<A>::rep(
    A const &_alloc, first_t const _first, last_t const _last, cap_t const _cap) noexcept
    : alloc_{_alloc}, first_{_first.get()}, last_{_last.get()}, cap_{_cap.get()}
{
}

template <typename A>
A const &fcppt::container::raw_vector::rep<A>::alloc() const noexcept
{
  return this->alloc_;
}

template <typename A>
fcppt::container::raw_vector::rep<A>::pointer
fcppt::container::raw_vector::rep<A>::first() const noexcept
{
  return this->first_;
}

template <typename A>
fcppt::container::raw_vector::rep<A>::pointer
fcppt::container::raw_vector::rep<A>::last() const noexcept
{
  return this->last_;
}

template <typename A>
fcppt::container::raw_vector::rep<A>::pointer
fcppt::container::raw_vector::rep<A>::cap() const noexcept
{
  return this->cap_;
}

#endif
