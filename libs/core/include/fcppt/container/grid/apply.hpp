//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_APPLY_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_APPLY_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/array/object_impl.hpp>
#include <fcppt/container/grid/dim_type.hpp>
#include <fcppt/container/grid/object_concept.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/pos_type.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container::grid
{
/**
\brief Applies a function to multiple grids of the same size

\ingroup fcpptcontainergrid

For grids <code>g_1 = _grid1</code> and <code>g_2, ..., g_n = _grids</code>, if
g_1,...,g_n are all of the same size <code>s</code>, the result <code>r</code>
is a grid of size <code>s</code> such that for every position <code>p <
s</code>, <code>r[p] = _function(g_1[p],...,g_n[p])</code>. If g_1,...g_n are
not of the same size, the result is an empty grid.
*/
template <typename Function, fcppt::container::grid::object_concept Grid1, fcppt::container::grid::object_concept... Grids>
// NOLINTNEXTLINE(cppcoreguidelines-missing-std-forward)
auto apply(Function const &_function, Grid1 &&_grid1, Grids &&..._grids)
    -> fcppt::container::grid::object<
        decltype(_function(
            fcppt::move_if_rvalue<Grid1>(_grid1.get_unsafe(
                std::declval<fcppt::container::grid::pos_type<std::remove_cvref_t<Grid1>>>())),
            fcppt::move_if_rvalue<Grids>(_grids.get_unsafe(
                std::declval<fcppt::container::grid::pos_type<std::remove_cvref_t<Grid1>>>()))...)),
        std::remove_cvref_t<Grid1>::static_size::value>
{
  using grid1 = std::remove_cvref_t<Grid1>;

  using pos_type = fcppt::container::grid::pos_type<grid1>;

  using result_type = fcppt::container::grid::object<
      decltype(_function(
          fcppt::move_if_rvalue<Grid1>(_grid1.get_unsafe(std::declval<pos_type>())),
          fcppt::move_if_rvalue<Grids>(_grids.get_unsafe(std::declval<pos_type>()))...)),
      grid1::static_size::value>;

  using dim_type = fcppt::container::grid::dim_type<grid1>;

  return fcppt::algorithm::all_of(
             fcppt::array::object<dim_type, sizeof...(Grids)>{_grids.size()...},
             [&_grid1](dim_type const _dim) { return _dim == _grid1.size(); })
             ? result_type(
                   _grid1.size(),
                   [&_function, &_grid1, &_grids...](pos_type const _pos)
                   {
                     return _function(
                         fcppt::move_if_rvalue<Grid1>(_grid1.get_unsafe(_pos)),
                         fcppt::move_if_rvalue<Grids>(_grids.get_unsafe(_pos))...);
                   })
             : result_type();
}
}

#endif
