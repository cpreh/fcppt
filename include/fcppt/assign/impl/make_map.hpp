//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
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
	typename container_type::key_type const &_key,
	typename container_type::mapped_type const &_mapped
)
:
	assign_container_(
		std::make_pair(
			_key,
			_mapped
		)
	)
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
	typename container_type::key_type const &_key,
	typename container_type::mapped_type const &_mapped
)
{
	assign_container_(
		std::make_pair(
			_key,
			_mapped
		)
	);

	return *this;
}

template<
	typename Container
>
fcppt::assign::make_map<
	Container
>::operator Container() const
{
	return
		this->container();
}

template<
	typename Container
>
typename
fcppt::assign::make_map<
	Container
>::container_type const &
fcppt::assign::make_map<
	Container
>::container() const
{
	return
		assign_container_.container();
}

#endif
