//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_BOX_COMPARISON_HPP_INCLUDED
#define FCPPT_MATH_BOX_COMPARISON_HPP_INCLUDED

#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::math::box
{
/**
\brief Compare two boxes componentwise using <code>value_type</code>'s <code>operator==</code>

\ingroup fcpptmathbox
*/
template <typename T, fcppt::math::size_type N>
inline bool
operator==(fcppt::math::box::object<T, N> const &_a, fcppt::math::box::object<T, N> const &_b)
{
  return _a.pos() == _b.pos() && _a.size() == _b.size();
}

/**
\brief Compare two boxes componentwise using <code>value_type</code>'s <code>operator!=</code>

\ingroup fcpptmathbox
*/
template <typename T, fcppt::math::size_type N>
inline bool
operator!=(fcppt::math::box::object<T, N> const &_a, fcppt::math::box::object<T, N> const &_b)
{
  return !(_a == _b);
}

/**
\brief Compare two boxes lexicographically

\ingroup fcpptmathbox
*/
template <typename T, fcppt::math::size_type N>
inline bool
operator<(fcppt::math::box::object<T, N> const &_a, fcppt::math::box::object<T, N> const &_b)
{
  return std::make_pair(_a.pos(), _a.size()) < std::make_pair(_b.pos(), _b.size());
}

}

#endif
