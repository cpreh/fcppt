//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MATH_VECTOR_NORMALIZE_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_NORMALIZE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/length.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/optional/object_impl.hpp>

namespace fcppt::math::vector
{
/**
\brief Normalizes a vector.

\ingroup fcpptmathvector

Returns nothing in case the length of \a _vec is zero.

\tparam T Must be a floating-point type.
*/
template <typename T, fcppt::math::size_type N, typename S>
[[nodiscard]] inline fcppt::optional::object<fcppt::math::vector::static_<T, N>>
normalize(fcppt::math::vector::object<T, N, S> const &_vec)
{
  return _vec / fcppt::math::vector::length(_vec);
}

}

#endif
