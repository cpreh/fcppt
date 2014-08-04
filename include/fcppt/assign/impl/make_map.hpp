//          Copyright Carl Philipp Reh 2009 - 2014.
//          Copyright Philipp Middendorf 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSIGN_IMPL_MAKE_MAP_HPP_INCLUDED
#define FCPPT_ASSIGN_IMPL_MAKE_MAP_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Container
>
fcppt::assign::make_map<
	Container
>::make_map(
	typename container_type::key_type &&_key,
	typename container_type::mapped_type &&_mapped
)
:
	container_()
{
	(*this)(
		std::move(
			_key
		),
		std::move(
			_mapped
		)
	);
}

template<
	typename Container
>
fcppt::assign::make_map<
	Container
>::make_map(
	typename container_type::key_type const &_key,
	typename container_type::mapped_type const &_mapped
)
:
	container_{
		std::make_pair(
			_key,
			_mapped
		)
	}
{
}

template<
	typename Container
>
fcppt::assign::make_map<
	Container
> &
fcppt::assign::make_map<
	Container
>::operator()(
	typename container_type::key_type &&_key,
	typename container_type::mapped_type &&_mapped
)
{
	container_.insert(
		std::make_pair(
			std::move(
				_key
			),
			std::move(
				_mapped
			)
		)
	);

	return
		*this;
}

template<
	typename Container
>
fcppt::assign::make_map<
	Container
> &
fcppt::assign::make_map<
	Container
>::operator()(
	typename container_type::key_type const &_key,
	typename container_type::mapped_type const &_mapped
)
{
	container_.insert(
		std::make_pair(
			_key,
			_mapped
		)
	);

	return
		*this;
}

template<
	typename Container
>
fcppt::assign::make_map<
	Container
>::operator Container &&()
{
	return
		this->move_container();
}

template<
	typename Container
>
typename
fcppt::assign::make_map<
	Container
>::container_type &&
fcppt::assign::make_map<
	Container
>::move_container()
{
	return
		std::move(
			container_
		);
}

#endif
