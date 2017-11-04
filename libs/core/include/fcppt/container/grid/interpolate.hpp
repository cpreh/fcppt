//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_INTERPOLATE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_INTERPOLATE_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/cast/float_to_int_fun.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/detail/interpolate.hpp>
#include <fcppt/math/vector/bit_strings.hpp>
#include <fcppt/math/vector/mod.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/structure_cast.hpp>
#include <fcppt/math/vector/to_unsigned.hpp>
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
\brief Interpolates a value inside the grid cells

\ingroup fcpptcontainergrid

With \link fcppt::container::grid::object grid::object \endlink alone, you can
only access values at discrete points (since the \link
fcppt::container::grid::object::dim object::dim \endlink type used to specify
positions has an integral <code>value_type</code>).

Sometimes, however, you want to take a value in between the grid nodes. Think
about a magnifying filter for textures, or drawing a line from one plot point
to the next (in a one-dimensional grid). This is called <em>interpolation</em>,
and it works in all dimensions.

To interpolate, you specify the \p _grid, the \p _floating_point_position and an
\p _interpolator. The latter will determine what kind of interpolation is used
(linear, trigonometric, ...). You can choose one of the functions in
fcppt::math::interpolation or you can write your own interpolator function.

Here's an example:

\snippet container/grid.cpp grid_interpolate

\tparam F The floating point type used for calculations.

\tparam Interpolator A function callable as <code>T (F, T, T)</code>.

*/
template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A,
	typename F,
	typename Interpolator
>
T
interpolate(
	fcppt::container::grid::object<
		T,
		N,
		A
	> const &_grid,
	fcppt::math::vector::static_<
		F,
		N
	> const &_floating_point_position,
	Interpolator const &_interpolator
)
{
	typedef
	fcppt::container::grid::object<
		T,
		N,
		A
	>
	grid_type;

	typedef
	typename
	grid_type::pos
	integer_vector_type;

	typedef
	std::array<
		integer_vector_type,
		fcppt::math::power_of_2<
			std::size_t
		>(
			N
		)
	>
	binary_vector_array_type;

	typedef
	typename
	binary_vector_array_type::size_type
	binary_vector_array_type_size_type;

	typedef
	F
	vector_value_type;

	integer_vector_type const floored(
		fcppt::math::vector::to_unsigned(
			fcppt::math::vector::structure_cast<
				typename
				grid_type::signed_pos,
				fcppt::cast::float_to_int_fun
			>(
				_floating_point_position
			)
		)
	);

	binary_vector_array_type binary_vectors(
		fcppt::math::vector::bit_strings<
			typename
			integer_vector_type::value_type,
			N
		>()
	);

	for(
		integer_vector_type &i : binary_vectors
	)
		i += floored;

	return
		fcppt::container::grid::detail::interpolate<
			integer_vector_type::dim_wrapper::value
		>(
			_grid,
			binary_vectors,
			fcppt::literal<
				binary_vector_array_type_size_type
			>(
				0
			),
			fcppt::math::vector::mod(
				_floating_point_position,
				fcppt::literal<
					vector_value_type
				>(
					1
				)
			).get_unsafe(),
			_interpolator
		);
}

}
}
}

#endif
