//          Copyright Carl Philipp Reh 2009 - 2014.
//          Copyright Philipp Middendorf 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSIGN_IMPL_MAKE_CONTAINER_HPP_INCLUDED
#define FCPPT_ASSIGN_IMPL_MAKE_CONTAINER_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Container
>
fcppt::assign::make_container<
	Container
>::make_container(
	typename container_type::value_type &&_other
)
:
	container_()
{
	(*this)(
		std::move(
			_other
		)
	);
}

template<
	typename Container
>
fcppt::assign::make_container<
	Container
> &
fcppt::assign::make_container<
	Container
>::operator()(
	typename container_type::value_type &&_other
)
{
	container_.insert(
		container_.end(),
		std::move(
			_other
		)
	);

	return
		*this;
}

template<
	typename Container
>
fcppt::assign::make_container<
	Container
>::operator Container &&()
{
	return
		this->move_container();
}

template<
	typename Container
>
Container &&
fcppt::assign::make_container<
	Container
>::move_container()
{
	return
		std::move(
			container_
		);
}

#endif
