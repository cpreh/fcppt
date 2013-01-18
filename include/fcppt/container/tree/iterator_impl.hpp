//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_ITERATOR_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_ITERATOR_IMPL_HPP_INCLUDED

#include <fcppt/container/tree/iterator_decl.hpp>


template<
	typename It
>
fcppt::container::tree::iterator<
	It
>::iterator()
:
	base(),
	impl_()
{
}

template<
	typename It
>
template<
	typename OtherIt
>
fcppt::container::tree::iterator<
	It
>::iterator(
	fcppt::container::tree::iterator<
		OtherIt
	> const &_other
)
:
	base(),
	impl_(
		_other.impl_
	)
{
}

template<
	typename It
>
fcppt::container::tree::iterator<
	It
>::iterator(
	It const _impl
)
:
	base(),
	impl_(
		_impl
	)
{
}

template<
	typename It
>
It
fcppt::container::tree::iterator<
	It
>::get() const
{
	return
		impl_;
}

template<
	typename It
>
void
fcppt::container::tree::iterator<
	It
>::increment()
{
	++impl_;
}

template<
	typename It
>
void
fcppt::container::tree::iterator<
	It
>::decrement()
{
	--impl_;
}

template<
	typename It
>
bool
fcppt::container::tree::iterator<
	It
>::equal(
	iterator const &_other
) const
{
	return
		_other.impl_
		==
		impl_;
}

template<
	typename It
>
typename
fcppt::container::tree::iterator<
	It
>::reference
fcppt::container::tree::iterator<
	It
>::dereference() const
{
	return
		**impl_;
}

#endif
