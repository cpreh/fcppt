//          Copyright Carl Philipp Reh 2009 - 2014.
//          Copyright Philipp Middendorf 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_INTERPOLATE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_INTERPOLATE_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/cast/float_to_int_fun.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/detail/interpolate.hpp>
#include <fcppt/math/generate_binary_vectors.hpp>
#include <fcppt/math/vector/mod.hpp>
#include <fcppt/math/vector/structure_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{
/**
\ingroup fcpptcontainergrid
\brief Interpolates a value inside the grid cells

With \link fcppt::container::grid::object grid::object \endlink alone, you can
only access values at discrete points (since the \link
fcppt::container::grid::object::dim object::dim \endlink type used to specify
positions has an integral <code>value_type</code>).

Sometimes, however, you want to take a value in between the grid nodes. Think
about a magnifying filter for textures, or drawing a line from one plot point
to the next (in a one-dimensional grid). This is called <em>interpolation</em>,
and it works in all dimensions.

To interpolate, you specify the \p grid, the \p floating_point_position and an
\p interpolator. The latter will determine what kind of interpolation is used
(linear, trigonometric, ...). You can choose one of the classes in
fcppt::math::interpolation (the ones ending in <code>_functor</code>) or you
can write your own interpolator class. It just needs an <code>operator()</code>
looking like this:

\code
Grid::value_type
operator()(
	Vector::value_type,
	Grid::value_type,
	Grid::value_type) const
{
	// ...
}
\endcode

The <code>Vector</code> template parameter determines which floating point type
is used for calculations. Here's an example:

\snippet container/grid.cpp grid_interpolate
*/
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
	typename
	Grid::pos
	integer_vector_type;

	typedef
	std::array
	<
		integer_vector_type,
		fcppt::literal<
			std::size_t
		>(
			1u
		)
		<<
		integer_vector_type::dim_wrapper::value
	>
	binary_vector_array_type;

	typedef typename
	binary_vector_array_type::size_type
	binary_vector_array_type_size_type;

	typedef typename
	Vector::value_type
	vector_value_type;

	integer_vector_type const floored(
		fcppt::math::vector::structure_cast<
			integer_vector_type,
			fcppt::cast::float_to_int_fun
		>(
			floating_point_position
		)
	);

	binary_vector_array_type binary_vectors(
		fcppt::math::generate_binary_vectors
		<
			typename integer_vector_type::value_type,
			integer_vector_type::dim_wrapper::value
		>());

	for(
		integer_vector_type &i : binary_vectors
	)
		i += floored;

	return
		fcppt::container::grid::detail::interpolate<
			integer_vector_type::dim_wrapper::value
		>(
			grid,
			binary_vectors,
			fcppt::literal<
				binary_vector_array_type_size_type
			>(
				0
			),
			fcppt::math::vector::mod(
				floating_point_position,
				fcppt::literal<
					vector_value_type
				>(
					1
				)
			),
			interpolator
		);
}

}
}
}

#endif
