//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_APPLY_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_APPLY_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/container/grid/is_object.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/detail/same_sizes.hpp>
#include <fcppt/mpl/all_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/vector.hpp>
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
				_grid1[
					std::declval<
						typename
						std::decay<
							Grid1
						>::type::pos
					>()
				]
			),
			fcppt::move_if_rvalue<
				Grids
			>(
				_grids[
					std::declval<
						typename
						std::decay<
							Grid1
						>::type::pos
					>()
				]
			)...
		)
	),
	std::decay<
		Grid1
	>::type::static_size::value
>
{
	typedef
	typename
	std::decay<
		Grid1
	>::type
	grid1;

	static_assert(
		fcppt::container::grid::is_object<
			grid1
		>::value,
		"Grid1 must be a grid"
	);

	static_assert(
		fcppt::mpl::all_of<
			boost::mpl::vector<
				typename
				std::decay<
					Grids
				>::type...
			>,
			fcppt::container::grid::is_object<
				boost::mpl::_1
			>
		>::value,
		"Grids must all be grids"
	);

	typedef
	fcppt::container::grid::object<
		decltype(
			_function(
				fcppt::move_if_rvalue<
					Grid1
				>(
					_grid1[
						std::declval<
							typename
							grid1::pos
						>()
					]
				),
				fcppt::move_if_rvalue<
					Grids
				>(
					_grids[
						std::declval<
							typename
							grid1::pos
						>()
					]
				)...
			)
		),
		grid1::static_size::value
	>
	result_type;

	return
		fcppt::container::grid::detail::same_sizes(
			_grid1,
			_grids...
		)
		?
			result_type(
				_grid1.size(),
				[
					&_function,
					&_grid1,
					&_grids...
				](
					typename
					grid1::pos const _pos
				)
				{
					return
						_function(
							fcppt::move_if_rvalue<
								Grid1
							>(
								_grid1[
									_pos
								]
							),
							fcppt::move_if_rvalue<
								Grids
							>(
								_grids[
									_pos
								]
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
