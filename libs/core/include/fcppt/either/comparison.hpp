//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_COMPARISON_HPP_INCLUDED
#define FCPPT_EITHER_COMPARISON_HPP_INCLUDED

#include <fcppt/either/object_impl.hpp>

namespace fcppt::either
{
/**
\brief Compares two eithers for equality.

\ingroup fcppteither

TODO(concepts)
*/
template <typename Failure, typename Success>
[[nodiscard]] bool operator==(
    fcppt::either::object<Failure, Success> const &_a,
    fcppt::either::object<Failure, Success> const &_b)
{
  return _a.impl() == _b.impl();
}

/**
\brief Compares two eithers for inequality.

\ingroup fcppteither

TODO(concepts)
*/
template <typename Failure, typename Success>
[[nodiscard]] bool operator!=(
    fcppt::either::object<Failure, Success> const &_a,
    fcppt::either::object<Failure, Success> const &_b)
{
  return !(_a == _b);
}
}

#endif
