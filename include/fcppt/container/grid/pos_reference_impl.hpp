#ifndef FCPPT_CONTAINER_GRID_POS_REFERENCE_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_POS_REFERENCE_IMPL_HPP_INCLUDED

#include <fcppt/container/grid/pos_reference_decl.hpp>


template<
	typename Grid
>
fcppt::container::grid::pos_reference<
	Grid
>::pos_reference(
	dim const &_pos,
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
>::dim const &
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
