//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_INTERPOLATE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_INTERPOLATE_HPP_INCLUDED

#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/structure_cast.hpp>
#include <fcppt/math/vector/mod.hpp>
#include <fcppt/math/dim/structure_cast.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/container/array.hpp>
#include <fcppt/math/generate_binary_vectors.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/mpl/identity.hpp>
#include <cstddef>
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
boost::enable_if_c
<
	N == 1,
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
	Grid::dim
	grid_dim;

	return
		interpolator(
			p[0],
			grid[
				fcppt::math::vector::structure_cast<grid_dim>(
					indices[value_index])],
			grid[
				fcppt::math::vector::structure_cast<grid_dim>(
					indices[value_index+1])]);
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
boost::enable_if_c
<
	N != 1,
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

	return
		interpolator(
			p[static_cast<float_vector_size_type>(N-1)],
			interpolate<static_cast<std::size_t>(N-1)>(
				grid,
				indices,
				value_index,
				p,
				interpolator),
			interpolate<static_cast<std::size_t>(N-1)>(
				grid,
				indices,
				static_cast<index_sequence_size_type>(
					value_index + (1u << (N-1u))),
				p,
				interpolator));
}
}

template
<
	typename Grid,
	typename Vector,
	typename Interpolator
>
typename Grid::value_type const
interpolate(
	Grid const &grid,
	Vector const &floating_point_position,
	Interpolator const &interpolator)
{
	typedef
	fcppt::math::vector::basic
	<
		typename Grid::dim::value_type,
		typename Grid::dim::dim_wrapper,
		typename Grid::dim::storage_type
	>
	integer_vector_type;

	typedef
	fcppt::container::array
	<
		integer_vector_type,
		static_cast<std::size_t>(1u << integer_vector_type::dim_wrapper::value)
	>
	binary_vector_array_type;

	typedef typename
	binary_vector_array_type::iterator
	binary_vector_array_type_iterator;

	typedef typename
	binary_vector_array_type::size_type
	binary_vector_array_type_size_type;

	typedef typename
	Vector::value_type
	vector_value_type;

	integer_vector_type const floored =
		fcppt::math::vector::structure_cast<integer_vector_type>(
			floating_point_position);

	binary_vector_array_type binary_vectors(
		fcppt::math::generate_binary_vectors
		<
			typename integer_vector_type::value_type,
			integer_vector_type::dim_wrapper::value
		>());

	for(
		binary_vector_array_type_iterator i =
			binary_vectors.begin();
		i != binary_vectors.end();
		++i)
		*i += floored;

	return
		detail::interpolate<integer_vector_type::dim_wrapper::value>(
			grid,
			binary_vectors,
			static_cast<binary_vector_array_type_size_type>(
				0),
			math::vector::mod(
				floating_point_position,
				static_cast<vector_value_type>(
					1)),
			interpolator);
}
}
}
}

#endif
