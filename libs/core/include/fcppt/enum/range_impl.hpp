//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_RANGE_IMPL_HPP_INCLUDED
#define FCPPT_ENUM_RANGE_IMPL_HPP_INCLUDED

#include <fcppt/enum/iterator_impl.hpp>
#include <fcppt/enum/range_decl.hpp>

template <typename Enum>
constexpr fcppt::enum_::range<Enum>::range(
    size_type const _begin, // NOLINT(bugprone-easily-swappable-parameters)
    size_type const _end) noexcept // NOLINT(bugprone-easily-swappable-parameters)
    : begin_{_begin}, end_{_end}
{
}

template <typename Enum>
constexpr typename fcppt::enum_::range<Enum>::iterator
fcppt::enum_::range<Enum>::begin() const noexcept
{
  return iterator(begin_);
}

template <typename Enum>
constexpr typename fcppt::enum_::range<Enum>::iterator
fcppt::enum_::range<Enum>::end() const noexcept
{
  return iterator(end_);
}

template <typename Enum>
constexpr typename fcppt::enum_::range<Enum>::size_type
fcppt::enum_::range<Enum>::size() const noexcept
{
  return end_ - begin_;
}

#endif
