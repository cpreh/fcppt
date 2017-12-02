//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CYCLIC_ITERATOR_IMPL_HPP_INCLUDED
#define FCPPT_CYCLIC_ITERATOR_IMPL_HPP_INCLUDED

#include <fcppt/cyclic_iterator_decl.hpp>
#include <fcppt/iterator/base_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


template<
	typename ContainerIterator
>
fcppt::cyclic_iterator<
	ContainerIterator
>::cyclic_iterator()
:
	it_{},
	boundary_{
		container_iterator_type{},
		container_iterator_type{}
	}
{
}

template<
	typename ContainerIterator
>
template<
	typename OtherIterator
>
fcppt::cyclic_iterator<
	ContainerIterator
>::cyclic_iterator(
	cyclic_iterator<
		OtherIterator
	> const &_other
)
:
	it_(
		_other.it_
	),
	boundary_(
		_other.boundary_
	)
{
}

template<
	typename ContainerIterator
>
fcppt::cyclic_iterator<
	ContainerIterator
>::cyclic_iterator(
	container_iterator_type const &_it,
	boundary const &_boundary
)
:
	it_(
		_it
	),
	boundary_(
		_boundary
	)
{
}

template<
	typename ContainerIterator
>
template<
	typename OtherIterator
>
fcppt::cyclic_iterator<
	ContainerIterator
> &
fcppt::cyclic_iterator<
	ContainerIterator
>::operator=(
	cyclic_iterator<
		OtherIterator
	> const &_other
)
{
	it_ =
		_other.it_;

	boundary_ =
		_other._boundary;

	return
		*this;
}

template<
	typename ContainerIterator
>
typename
fcppt::cyclic_iterator<
	ContainerIterator
>::boundary const &
fcppt::cyclic_iterator<
	ContainerIterator
>::get_boundary() const
{
	return
		boundary_;
}

template<
	typename ContainerIterator
>
typename
fcppt::cyclic_iterator<
	ContainerIterator
>::container_iterator_type
fcppt::cyclic_iterator<
	ContainerIterator
>::get() const
{
	return
		it_;
}

template<
	typename ContainerIterator
>
void
fcppt::cyclic_iterator<
	ContainerIterator
>::advance(
	difference_type const _diff
)
{
	difference_type const size{
		std::distance(
			boundary_.first,
			boundary_.second
		)
	};

	difference_type const diff{
		(
			std::distance(
				boundary_.first,
				it_
			)
			+
			_diff
		)
		%
		size
	};

	it_ =
		boundary_.first
		+
		(
			diff
			<
			0
			?
				diff
				+
				size
			:
				diff
		);
}

template<
	typename ContainerIterator
>
void
fcppt::cyclic_iterator<
	ContainerIterator
>::increment()
{
	if(
		++it_
		==
		boundary_.second
	)
		it_ =
			boundary_.first;
}

template<
	typename ContainerIterator
>
void
fcppt::cyclic_iterator<
	ContainerIterator
>::decrement()
{
	if(
		it_
		==
		boundary_.first
	)
		it_ =
			std::prev(
				boundary_.second
			);
	else
		--it_;
}

template<
	typename ContainerIterator
>
bool
fcppt::cyclic_iterator<
	ContainerIterator
>::equal(
	cyclic_iterator const &_other
) const
{
	return
		it_
		==
		_other.it_;
}

template<
	typename ContainerIterator
>
typename
fcppt::cyclic_iterator<
	ContainerIterator
>::reference
fcppt::cyclic_iterator<
	ContainerIterator
>::dereference() const
{
	return
		*it_;
}

template<
	typename ContainerIterator
>
typename
fcppt::cyclic_iterator<
	ContainerIterator
>::difference_type
fcppt::cyclic_iterator<
	ContainerIterator
>::distance_to(
	cyclic_iterator const &_other
) const
{
	return
		std::distance(
			it_,
			_other.it_
		);
}

#endif
