//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_POS_REF_ITERATOR_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_REF_ITERATOR_IMPL_HPP_INCLUDED

#include <fcppt/cast/to_signed.hpp>
#include <fcppt/container/grid/dim.hpp> // IWYU pragma: keep
#include <fcppt/container/grid/object_impl.hpp> // IWYU pragma: keep
#include <fcppt/container/grid/offset.hpp>
#include <fcppt/container/grid/pos.hpp> // IWYU pragma: keep
#include <fcppt/container/grid/pos_ref_iterator_decl.hpp> // IWYU pragma: export
#include <fcppt/container/grid/pos_reference_impl.hpp> // IWYU pragma: keep
#include <fcppt/iterator/base_impl.hpp> // IWYU pragma: keep
#include <fcppt/math/dim/null.hpp>
#include <fcppt/math/vector/comparison.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Grid>
fcppt::container::grid::pos_ref_iterator<Grid>::pos_ref_iterator()
    : iterator_{},
      pos_iterator_{},
      size_{fcppt::math::dim::null<dim>()}
{
}

template <typename Grid>
fcppt::container::grid::pos_ref_iterator<Grid>::pos_ref_iterator(
    iterator _iterator, pos_iterator _pos_iterator, dim _size)
    : iterator_{std::move(_iterator)},
      pos_iterator_{std::move(_pos_iterator)},
      size_{std::move(_size)}
{
}

template <typename Grid>
void fcppt::container::grid::pos_ref_iterator<Grid>::increment()
{
  ++pos_iterator_;
}

template <typename Grid>
fcppt::container::grid::pos_ref_iterator<Grid>::reference
fcppt::container::grid::pos_ref_iterator<Grid>::dereference() const
{
  pos const current(*pos_iterator_);

  return reference(
      current,
      *(iterator_ + fcppt::cast::to_signed(fcppt::container::grid::offset(current, size_))));
}

template <typename Grid>
bool fcppt::container::grid::pos_ref_iterator<Grid>::equal(pos_ref_iterator const &_other) const
{
  return pos_iterator_ == _other.pos_iterator_;
}

#endif
