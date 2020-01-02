//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_RESIZE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_RESIZE_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/container/to_value_type.hpp>
#include <fcppt/container/grid/at_optional.hpp>
#include <fcppt/container/grid/dim_type.hpp>
#include <fcppt/container/grid/is_object.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/pos_type.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief Returns a resized grid with potentially new elements

\ingroup fcpptcontainergrid

Returns a grid <code>g</code> of size \a _new_size, such that for every
position <code>p</code> in <code>g</code> we have that:
<ul>
<li><code>g[p] = _grid[p]</code> if <code>p</code> is also a position in \a _grid, or</li>
<li><code>g[p] = _init(p)</code> otherwise.</li>
</ul>

\tparam Grid Must be a grid.

\tparam Function A function callable as <code>Grid::value_type (Grid::pos)</code>.
*/
template<
	typename Grid,
	typename Function
>
fcppt::type_traits::remove_cv_ref_t<
	Grid
>
resize(
	Grid &&_grid,
	fcppt::container::grid::dim_type<
		fcppt::type_traits::remove_cv_ref_t<
			Grid
		>
	> const &_new_size,
	Function const &_init
)
{
	typedef
	fcppt::type_traits::remove_cv_ref_t<
		Grid
	>
	result_type;

	static_assert(
		fcppt::container::grid::is_object<
			result_type
		>::value,
		"Grid must be a grid"
	);

	return
		result_type{
			_new_size,
			[
				&_grid,
				&_init
			](
				fcppt::container::grid::pos_type<
					result_type
				> const _fcppt_pos
			)
			{
				return
					fcppt::optional::maybe(
						fcppt::container::grid::at_optional(
							_grid,
							_fcppt_pos
						),
						[
							&_init,
							_fcppt_pos
						]{
							return
								_init(
									_fcppt_pos
								);
						},
						[](
							fcppt::reference<
								fcppt::container::to_value_type<
									std::remove_reference_t<
										Grid
									>
								>
							> const _ref
						)
						{
							return
								fcppt::move_if_rvalue<
									Grid
								>(
									_ref.get()
								);
						}
					);
			}
		};
}

}
}
}

#endif
