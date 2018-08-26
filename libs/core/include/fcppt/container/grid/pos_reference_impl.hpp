//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_POS_REFERENCE_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_REFERENCE_IMPL_HPP_INCLUDED

#include <fcppt/container/grid/pos_reference_decl.hpp>


template<
	typename Grid
>
fcppt::container::grid::pos_reference<
	Grid
>::pos_reference(
	pos_type const &_pos,
	reference _value
)
:
	pos_(
		_pos
	),
	value_(
		_value
	)
{
}

template<
	typename Grid
>
typename
fcppt::container::grid::pos_reference<
	Grid
>::pos_type const &
fcppt::container::grid::pos_reference<
	Grid
>::pos() const
{
	return
		pos_;
}

template<
	typename Grid
>
typename
fcppt::container::grid::pos_reference<
	Grid
>::reference
fcppt::container::grid::pos_reference<
	Grid
>::value() const
{
	return
		value_;
}

#endif
