//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_COMPARISON_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_COMPARISON_HPP_INCLUDED

#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/dim/comparison.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container::grid
{
/**
\brief Compares two grids for equality

\ingroup fcpptcontainergrid
*/
template <typename T, fcppt::container::grid::size_type N, typename A>
bool operator==(
    fcppt::container::grid::object<T, N, A> const &_a,
    fcppt::container::grid::object<T, N, A> const &_b)
{
  return _a.size() == _b.size() && std::equal(_a.begin(), _a.end(), _b.begin());
}

/**
\brief <code>!(a == b)</code>

\ingroup fcpptcontainergrid
*/
template <typename T, fcppt::container::grid::size_type N, typename A>
inline bool operator!=(
    fcppt::container::grid::object<T, N, A> const &_a,
    fcppt::container::grid::object<T, N, A> const &_b)
{
  return !(_a == _b);
}

}

#endif
