//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_APPLY_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_APPLY_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/container/grid/dim_type.hpp>
#include <fcppt/container/grid/is_object.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/pos_type.hpp>
#include <fcppt/math/dim/comparison.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/lambda/trait.hpp>
#include <metal/list/all_of.hpp>
#include <metal/list/list.hpp>
#include <array>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief Applies a function to multiple grids of the same size

\ingroup fcpptcontainergrid

For grids <code>g_1 = _grid1</code> and <code>g_2, ..., g_n = _grids</code>, if
g_1,...,g_n are all of the same size <code>s</code>, the result <code>r</code>
is a grid of size <code>s</code> such that for every position <code>p <
s</code>, <code>r[p] = _function(g_1[p],...,g_n[p])</code>. If g_1,...g_n are
not of the same size, the result is an empty grid.
*/
template<
	typename Function,
	typename Grid1,
	typename... Grids
>
auto
apply(
	Function const &_function,
	Grid1 &&_grid1,
	Grids &&... _grids
)
->
fcppt::container::grid::object<
	decltype(
		_function(
			fcppt::move_if_rvalue<
				Grid1
			>(
				_grid1.get_unsafe(
					std::declval<
						fcppt::container::grid::pos_type<
							fcppt::type_traits::remove_cv_ref_t<
								Grid1
							>
						>
					>()
				)
			),
			fcppt::move_if_rvalue<
				Grids
			>(
				_grids.get_unsafe(
					std::declval<
						fcppt::container::grid::pos_type<
							fcppt::type_traits::remove_cv_ref_t<
								Grid1
							>
						>
					>()
				)
			)...
		)
	),
	fcppt::type_traits::remove_cv_ref_t<
		Grid1
	>::static_size::value
>
{
	typedef
	fcppt::type_traits::remove_cv_ref_t<
		Grid1
	>
	grid1;

	static_assert(
		fcppt::container::grid::is_object<
			grid1
		>::value,
		"Grid1 must be a grid"
	);

	static_assert(
		::metal::all_of<
			::metal::list<
				fcppt::type_traits::remove_cv_ref_t<
					Grids
				>...
			>,
			::metal::trait<
				fcppt::container::grid::is_object
			>
		>::value,
		"Grids must all be grids"
	);

	typedef
	fcppt::container::grid::pos_type<
		grid1
	>
	pos_type;

	typedef
	fcppt::container::grid::object<
		decltype(
			_function(
				fcppt::move_if_rvalue<
					Grid1
				>(
					_grid1.get_unsafe(
						std::declval<
							pos_type
						>()
					)
				),
				fcppt::move_if_rvalue<
					Grids
				>(
					_grids.get_unsafe(
						std::declval<
							pos_type
						>()
					)
				)...
			)
		),
		grid1::static_size::value
	>
	result_type;

	typedef
	fcppt::container::grid::dim_type<
		grid1
	>
	dim_type;

	return
		fcppt::algorithm::all_of(
			std::array<
				dim_type,
				sizeof...(
					Grids
				)
			>{{
				_grids.size()...
			}},
			[
				&_grid1
			](
				dim_type const _dim
			)
			{
				return
					_dim
					==
					_grid1.size();
			}
		)
		?
			result_type(
				_grid1.size(),
				[
					&_function,
					&_grid1,
					&_grids...
				](
					pos_type const _pos
				)
				{
					return
						_function(
							fcppt::move_if_rvalue<
								Grid1
							>(
								_grid1.get_unsafe(
									_pos
								)
							),
							fcppt::move_if_rvalue<
								Grids
							>(
								_grids.get_unsafe(
									_pos
								)
							)...
						);
				}
			)
		:
			result_type()
		;
}

}
}
}

#endif
