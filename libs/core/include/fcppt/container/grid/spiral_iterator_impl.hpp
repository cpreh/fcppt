//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_SPIRAL_ITERATOR_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_SPIRAL_ITERATOR_IMPL_HPP_INCLUDED

#include <fcppt/container/grid/spiral_iterator_decl.hpp>
#include <fcppt/iterator/base_impl.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Pos>
fcppt::container::grid::spiral_iterator<Pos>::spiral_iterator(
    pos _cur, difference_type const _max_dist)
    : cur_(std::move(_cur)), max_dist_(_max_dist), cur_dist_(0), dir_(-1, -1), step_(0)
{
}

template <typename Pos>
void fcppt::container::grid::spiral_iterator<Pos>::increment()
{
  if (step_ == cur_dist_)
  {
    std::swap(dir_.x(), dir_.y());

    dir_.y() = -dir_.y();

    if (dir_ == pos(-1, 1))
    {
      ++cur_dist_;

      cur_ = pos(cur_.x(), cur_.y() - 1);
    }

    step_ = 0;
  }

  ++step_;

  cur_ += dir_;
}

template <typename Pos>
typename fcppt::container::grid::spiral_iterator<Pos>::reference
fcppt::container::grid::spiral_iterator<Pos>::dereference() const
{
  return cur_;
}

template <typename Pos>
bool fcppt::container::grid::spiral_iterator<Pos>::equal(spiral_iterator const &_other) const
{
  return cur_ == _other.cur_;
}

#endif
