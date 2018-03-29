//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_INTERPOLATE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_INTERPOLATE_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/math/vector/at.hpp>
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

template<
	std::size_t N,
	typename Grid,
	typename IndexSequence,
	typename FloatVector,
	typename Interpolator
>
std::enable_if_t<
	N == 1u,
	fcppt::type_traits::value_type<
		Grid
	>
>
interpolate(
	Grid const &_grid,
	IndexSequence const &_indices,
	typename IndexSequence::size_type const _value_index,
	FloatVector const &_pos,
	Interpolator const &_interpolator
)
{
	return
		_interpolator(
			_pos.x(),
			_grid.get_unsafe(
				_indices[
					_value_index
				]
			),
			_grid.get_unsafe(
				_indices[
					_value_index
					+
					1u
				]
			)
		);
}

template<
	std::size_t N,
	typename Grid,
	typename IndexSequence,
	typename FloatVector,
	typename Interpolator
>
std::enable_if_t<
	N != 1u,
	fcppt::type_traits::value_type<
		Grid
	>
>
interpolate(
	Grid const &_grid,
	IndexSequence const &_indices,
	typename IndexSequence::size_type const _value_index,
	FloatVector const &_pos,
	Interpolator const &_interpolator
)
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
		_interpolator(
			fcppt::math::vector::at<
				fcppt::cast::size<
					float_vector_size_type
				>(
					next_n
				)
			>(
				_pos
			),
			fcppt::container::grid::detail::interpolate<
				next_n
			>(
				_grid,
				_indices,
				_value_index,
				_pos,
				_interpolator
			),
			fcppt::container::grid::detail::interpolate<
				next_n
			>(
				_grid,
				_indices,
				fcppt::cast::size<
					index_sequence_size_type
				>(
					_value_index
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
				_pos,
				_interpolator
			)
		);
}

}
}
}
}

#endif
