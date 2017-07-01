//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_INTERPOLATE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_INTERPOLATE_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/math/vector/at_c.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{
namespace detail
{

template
<
	std::size_t N,
	typename Grid,
	typename IndexSequence,
	typename FloatVector,
	typename Interpolator
>
typename
std::enable_if
<
	N == 1u,
	typename Grid::value_type
>::type
interpolate(
	Grid const &grid,
	IndexSequence const &indices,
	typename IndexSequence::size_type const value_index,
	FloatVector const &p,
	Interpolator const &interpolator)
{
	return
		interpolator(
			p.x(),
			grid.get_unsafe(
				indices[
					value_index
				]
			),
			grid.get_unsafe(
				indices[
					value_index
					+
					1u
				]
			)
		);
}

template
<
	std::size_t N,
	typename Grid,
	typename IndexSequence,
	typename FloatVector,
	typename Interpolator
>
typename
std::enable_if
<
	N != 1u,
	typename Grid::value_type
>::type
interpolate(
	Grid const &grid,
	IndexSequence const &indices,
	typename IndexSequence::size_type const value_index,
	FloatVector const &p,
	Interpolator const &interpolator)
{
	typedef typename
	FloatVector::size_type
	float_vector_size_type;

	typedef typename
	IndexSequence::size_type
	index_sequence_size_type;

	constexpr std::size_t const next_n(
		N
		-
		fcppt::literal<
			std::size_t
		>(
			1
		)
	);

	return
		interpolator(
			fcppt::math::vector::at_c<
				fcppt::cast::size<
					float_vector_size_type
				>(
					next_n
				)
			>(
				p
			),
			fcppt::container::grid::detail::interpolate<
				next_n
			>(
				grid,
				indices,
				value_index,
				p,
				interpolator),
			fcppt::container::grid::detail::interpolate<
				next_n
			>(
				grid,
				indices,
				fcppt::cast::size<
					index_sequence_size_type
				>(
					value_index
					+
					(
						fcppt::literal<
							std::size_t
						>(
							1
						)
						<<
						next_n
					)
				),
				p,
				interpolator
			)
		);
}

}
}
}
}

#endif
