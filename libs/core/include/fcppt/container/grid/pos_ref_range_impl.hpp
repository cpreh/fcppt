//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_POS_REF_RANGE_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_REF_RANGE_IMPL_HPP_INCLUDED

#include <fcppt/container/grid/object_impl.hpp> // IWYU pragma: keep
#include <fcppt/container/grid/pos_ref_iterator_impl.hpp> // IWYU pragma: keep
#include <fcppt/container/grid/pos_ref_range_decl.hpp> // IWYU pragma: export

template <typename Grid>
fcppt::container::grid::pos_ref_range<Grid>::pos_ref_range(
    Grid &_grid, min_type const _min, sup_type const _sup)
    : grid_{_grid}, pos_range_{_min, _sup}
{
}

template <typename Grid>
fcppt::container::grid::pos_ref_range<Grid>::iterator
fcppt::container::grid::pos_ref_range<Grid>::begin() const
{
  return this->make_iterator(pos_range_.begin());
}

template <typename Grid>
fcppt::container::grid::pos_ref_range<Grid>::iterator
fcppt::container::grid::pos_ref_range<Grid>::end() const
{
  return this->make_iterator(pos_range_.end());
}

template <typename Grid>
fcppt::container::grid::pos_ref_range<Grid>::size_type
fcppt::container::grid::pos_ref_range<Grid>::size() const
{
  return pos_range_.size();
}

template <typename Grid>
fcppt::container::grid::pos_ref_range<Grid>::min_type const &
fcppt::container::grid::pos_ref_range<Grid>::min() const
{
  return pos_range_.min();
}

template <typename Grid>
fcppt::container::grid::pos_ref_range<Grid>::sup_type const &
fcppt::container::grid::pos_ref_range<Grid>::sup() const
{
  return pos_range_.sup();
}

template <typename Grid>
fcppt::container::grid::pos_ref_range<Grid>::iterator
fcppt::container::grid::pos_ref_range<Grid>::make_iterator(pos_iterator const _pos_iterator) const
{
  return iterator(grid_.get().begin(), _pos_iterator, grid_.get().size());
}

#endif
