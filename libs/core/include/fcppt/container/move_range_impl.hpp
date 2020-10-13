//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_MOVE_RANGE_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_MOVE_RANGE_IMPL_HPP_INCLUDED

#include <fcppt/container/move_range_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Container
>
fcppt::container::move_range<
	Container
>::move_range(
	Container &&_container
)
:
	container_(
		std::move(
			_container
		)
	)
{
}

template<
	typename Container
>
fcppt::container::move_range<
	Container
>::move_range(
	move_range &&
)
noexcept
= default;

template<
	typename Container
>
fcppt::container::move_range<
	Container
> &
fcppt::container::move_range<
	Container
>::operator=(
	move_range &&
)
noexcept
= default;


template<
	typename Container
>
fcppt::container::move_range<
	Container
>::~move_range<
	Container
>()
= default;

template<
	typename Container
>
typename
fcppt::container::move_range<
	Container
>::iterator
fcppt::container::move_range<
	Container
>::begin()
{
	return
		std::make_move_iterator(
			container_.begin()
		);
}

template<
	typename Container
>
typename
fcppt::container::move_range<
	Container
>::iterator
fcppt::container::move_range<
	Container
>::end()
{
	return
		std::make_move_iterator(
			container_.end()
		);
}

template<
	typename Container
>
typename
fcppt::container::move_range<
	Container
>::const_iterator
fcppt::container::move_range<
	Container
>::begin() const
{
	return
		container_.begin();
}

template<
	typename Container
>
typename
fcppt::container::move_range<
	Container
>::const_iterator
fcppt::container::move_range<
	Container
>::end() const
{
	return
		container_.end();
}

#endif
