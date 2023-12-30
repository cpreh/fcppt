//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_INT_RANGE_IMPL_HPP_INCLUDED
#define FCPPT_INT_RANGE_IMPL_HPP_INCLUDED

#include <fcppt/int_iterator_impl.hpp> // IWYU pragma: keep
#include <fcppt/int_range_decl.hpp> // IWYU pragma: export
#include <fcppt/type_iso/undecorate.hpp>

template <typename Int>
constexpr fcppt::int_range<Int>::int_range(Int const _begin, Int const _end)
    : begin_{_begin}, end_{_end < _begin ? _begin : _end}
{
}

template <typename Int>
constexpr typename fcppt::int_range<Int>::iterator fcppt::int_range<Int>::begin() const
{
  return iterator(begin_);
}

template <typename Int>
constexpr typename fcppt::int_range<Int>::iterator fcppt::int_range<Int>::end() const
{
  return iterator(end_);
}

template <typename Int>
constexpr typename fcppt::int_range<Int>::size_type fcppt::int_range<Int>::size() const
{
  return static_cast<size_type>(
      fcppt::type_iso::undecorate(end_) - fcppt::type_iso::undecorate(begin_));
}

#endif
