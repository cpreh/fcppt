//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_ARRAY_COMPARISON_HPP_INCLUDED
#define FCPPT_ENUM_ARRAY_COMPARISON_HPP_INCLUDED

#include <fcppt/array/comparison.hpp> // IWYU pragma: keep
#include <fcppt/enum/array_impl.hpp>

namespace fcppt::enum_
{
/**
\brief Compares two enum arrays for equality.

\ingroup fcpptenum

\tparam Value Must be equality-comparable.
*/
template <typename Enum, typename Value>
bool operator==(
    fcppt::enum_::array<Enum, Value> const &_a, fcppt::enum_::array<Enum, Value> const &_b)
{
  return _a.impl() == _b.impl();
}

/**
\brief Compares two enum arrays for inequality.

\ingroup fcpptenum

\tparam Value Must be equality-comparable.
*/
template <typename Enum, typename Value>
inline bool
operator!=(fcppt::enum_::array<Enum, Value> const &_a, fcppt::enum_::array<Enum, Value> const &_b)
{
  return !(_a == _b);
}

}

#endif
