//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSIGN_IMPL_MAKE_CONTAINER_HPP_INCLUDED
#define FCPPT_ASSIGN_IMPL_MAKE_CONTAINER_HPP_INCLUDED

#include <fcppt/assign/detail/insert.hpp>

template<
	typename Container
>
fcppt::assign::make_container<Container>::make_container(
	typename container_type::const_reference _other
)
:
	container_()
{
	(*this)(
		_other
	);
}

template<
	typename Container
>
fcppt::assign::make_container<Container> &
fcppt::assign::make_container<Container>::operator()(
	typename container_type::const_reference _other
)
{
	detail::insert(
		container_,
		_other
	);

	return *this;
}

template<
	typename Container
>
fcppt::assign::make_container<Container>::operator Container() const
{
	return this->container();
}

template<
	typename Container
>
Container const &
fcppt::assign::make_container<Container>::container() const
{
	return container_;
}

#endif
