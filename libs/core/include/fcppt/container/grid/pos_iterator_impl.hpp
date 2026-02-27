//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_POS_ITERATOR_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_ITERATOR_IMPL_HPP_INCLUDED

#include <fcppt/container/grid/next_position.hpp>
#include <fcppt/container/grid/pos_iterator_decl.hpp> // IWYU pragma: export
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/iterator/base_impl.hpp> // IWYU pragma: keep
#include <fcppt/math/vector/comparison.hpp> // IWYU pragma: keep
#include <fcppt/math/vector/null.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename SizeType, fcppt::container::grid::size_type Size>
fcppt::container::grid::pos_iterator<SizeType, Size>::pos_iterator()
    : current_{fcppt::math::vector::null<pos>()},
      min_{min{fcppt::math::vector::null<pos>()}},
      sup_{sup{fcppt::math::vector::null<pos>()}}
{
}

template <typename SizeType, fcppt::container::grid::size_type Size>
fcppt::container::grid::pos_iterator<SizeType, Size>::pos_iterator(pos _current, min _min, sup _sup)
    : current_{std::move(_current)}, min_{std::move(_min)}, sup_{std::move(_sup)}
{
}

template <typename SizeType, fcppt::container::grid::size_type Size>
void fcppt::container::grid::pos_iterator<SizeType, Size>::increment()
{
  current_ = fcppt::container::grid::next_position(current_, min_, sup_);
}

template <typename SizeType, fcppt::container::grid::size_type Size>
fcppt::container::grid::pos_iterator<SizeType, Size>::reference
fcppt::container::grid::pos_iterator<SizeType, Size>::dereference() const
{
  return current_;
}

template <typename SizeType, fcppt::container::grid::size_type Size>
bool fcppt::container::grid::pos_iterator<SizeType, Size>::equal(pos_iterator const &_other) const
{
  return current_ == _other.current_;
}

#endif
