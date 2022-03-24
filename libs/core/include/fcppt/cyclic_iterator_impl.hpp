//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CYCLIC_ITERATOR_IMPL_HPP_INCLUDED
#define FCPPT_CYCLIC_ITERATOR_IMPL_HPP_INCLUDED

#include <fcppt/cyclic_iterator_decl.hpp>
#include <fcppt/iterator/base_impl.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename ContainerIterator>
fcppt::cyclic_iterator<ContainerIterator>::cyclic_iterator()
    : it_{}, boundary_{container_iterator_type{}, container_iterator_type{}}
{
}

template <typename ContainerIterator>
template <typename OtherIterator>
fcppt::cyclic_iterator<ContainerIterator>::cyclic_iterator(
    cyclic_iterator<OtherIterator> const &_other)
    : it_(_other.it_), boundary_(_other.boundary_)
{
}

template <typename ContainerIterator>
fcppt::cyclic_iterator<ContainerIterator>::cyclic_iterator(
    container_iterator_type const &_it, boundary _boundary)
    : it_(_it), boundary_(std::move(_boundary))
{
}

template <typename ContainerIterator>
template <typename OtherIterator>
fcppt::cyclic_iterator<ContainerIterator> &
fcppt::cyclic_iterator<ContainerIterator>::operator=(cyclic_iterator<OtherIterator> const &_other)
{
  this->it_ = _other.it_;

  this->boundary_ = _other._boundary;

  return *this;
}

template <typename ContainerIterator>
typename fcppt::cyclic_iterator<ContainerIterator>::boundary const &
fcppt::cyclic_iterator<ContainerIterator>::get_boundary() const
{
  return this->boundary_;
}

template <typename ContainerIterator>
typename fcppt::cyclic_iterator<ContainerIterator>::container_iterator_type
fcppt::cyclic_iterator<ContainerIterator>::get() const
{
  return this->it_;
}

template <typename ContainerIterator>
void fcppt::cyclic_iterator<ContainerIterator>::advance(difference_type const _diff)
{
  difference_type const size{std::distance(this->boundary_first(), this->boundary_second())};

  difference_type const diff{(std::distance(this->boundary_first(), this->it_) + _diff) % size};

  this->it_ = this->boundary_first() + (diff < 0 ? diff + size : diff);
}

template <typename ContainerIterator>
void fcppt::cyclic_iterator<ContainerIterator>::increment()
{
  if (++this->it_ == this->boundary_second())
  {
    this->it_ = this->boundary_first();
  }
}

template <typename ContainerIterator>
void fcppt::cyclic_iterator<ContainerIterator>::decrement()
{
  if (this->it_ == this->boundary_first())
  {
    this->it_ = std::prev(this->boundary_second());
  }
  else
  {
    --this->it_;
  }
}

template <typename ContainerIterator>
bool fcppt::cyclic_iterator<ContainerIterator>::equal(cyclic_iterator const &_other) const
{
  return this->it_ == _other.it_;
}

template <typename ContainerIterator>
typename fcppt::cyclic_iterator<ContainerIterator>::reference
fcppt::cyclic_iterator<ContainerIterator>::dereference() const
{
  return *this->it_;
}

template <typename ContainerIterator>
typename fcppt::cyclic_iterator<ContainerIterator>::difference_type
fcppt::cyclic_iterator<ContainerIterator>::distance_to(cyclic_iterator const &_other) const
{
  return std::distance(this->it_, _other.it_);
}

template <typename ContainerIterator>
typename fcppt::cyclic_iterator<ContainerIterator>::container_iterator_type
fcppt::cyclic_iterator<ContainerIterator>::boundary_first() const
{
  return fcppt::tuple::get<0>(this->get_boundary());
}

template <typename ContainerIterator>
typename fcppt::cyclic_iterator<ContainerIterator>::container_iterator_type
fcppt::cyclic_iterator<ContainerIterator>::boundary_second() const
{
  return fcppt::tuple::get<1>(this->get_boundary());
}

#endif
