//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CYCLIC_ITERATOR_IMPL_HPP_INCLUDED
#define FCPPT_CYCLIC_ITERATOR_IMPL_HPP_INCLUDED

#include <fcppt/cyclic_iterator_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/next_prior.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>

template<
	typename ContainerIterator
>
fcppt::cyclic_iterator<ContainerIterator>::cyclic_iterator()
:
	it_(),
	begin_(),
	end_()
{
}

template<
	typename ContainerIterator
>
template<
	typename OtherIterator
>
fcppt::cyclic_iterator<ContainerIterator>::cyclic_iterator(
	cyclic_iterator<OtherIterator> const &_other
)
:
	it_(_other.it_),
	begin_(_other.begin_),
	end_(_other.end_)
{
}

template<
	typename ContainerIterator
>
fcppt::cyclic_iterator<ContainerIterator>::cyclic_iterator(
	container_iterator_type const &_it,
	container_iterator_type const &_begin,
	container_iterator_type const &_end
)
:
	it_(_it),
	begin_(_begin),
	end_(_end)
{
}

template<
	typename ContainerIterator
>
template<
	typename OtherIterator
>
fcppt::cyclic_iterator<ContainerIterator> &
fcppt::cyclic_iterator<ContainerIterator>::operator=(
	cyclic_iterator<OtherIterator> const &_other
)
{
	it_ = _other.it_;

	begin_ = _other.begin_;

	end_ = _other.end_;

	return *this;
}

template<
	typename ContainerIterator
>
typename fcppt::cyclic_iterator<ContainerIterator>::container_iterator_type
fcppt::cyclic_iterator<ContainerIterator>::begin() const
{
	return begin_;
}

template<
	typename ContainerIterator
>
typename fcppt::cyclic_iterator<ContainerIterator>::container_iterator_type
fcppt::cyclic_iterator<ContainerIterator>::end() const
{
	return end_;
}

template<
	typename ContainerIterator
>
typename fcppt::cyclic_iterator<ContainerIterator>::container_iterator_type
fcppt::cyclic_iterator<ContainerIterator>::get() const
{
	return it_;
}

template<
	typename ContainerIterator
>
void
fcppt::cyclic_iterator<ContainerIterator>::increment()
{
	if(
		begin_ != end_
		&& ++it_ == end_
	)
		it_ = begin_;
}

template<
	typename ContainerIterator
>
void
fcppt::cyclic_iterator<ContainerIterator>::decrement()
{
	if(
		begin_ == end_
	)
		return;

	if(
		it_ == begin_
	)
		it_ =
			boost::prior(
				end_
			);
	else
		--it_;
}

template<
	typename ContainerIterator
>
bool
fcppt::cyclic_iterator<ContainerIterator>::equal(
	cyclic_iterator const &_other
) const
{
	return it_ == _other.it;
}

template<
	typename ContainerIterator
>
typename fcppt::cyclic_iterator<ContainerIterator>::reference
fcppt::cyclic_iterator<ContainerIterator>::dereference() const
{
	return *it_;
}

template<
	typename ContainerIterator
>
typename fcppt::cyclic_iterator<ContainerIterator>::difference_type
fcppt::cyclic_iterator<ContainerIterator>::distance_to(
	cyclic_iterator const &_other
) const
{
	return _other.it_ - it_;
}

#endif
