//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_STATIC_ROW_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_STATIC_ROW_HPP_INCLUDED

#include <fcppt/cast/size.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/static_row_type.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief Creates an \link fcppt::container::grid::static_row_type\endlink.

\ingroup fcpptcontainergrid
*/
template<
	typename Arg1,
	typename... Args
>
fcppt::container::grid::static_row_type<
	fcppt::type_traits::remove_cv_ref_t<
		Arg1
	>,
	fcppt::cast::size<
		fcppt::container::grid::size_type
	>(
		sizeof...(Args) + 1u
	)
>
static_row(
	Arg1 &&_arg1,
	Args && ..._args
)
{
	typedef
	fcppt::type_traits::remove_cv_ref_t<
		Arg1
	>
	element_type;

	static_assert(
		std::conjunction_v<
			std::is_same<
				fcppt::type_traits::remove_cv_ref_t<
					Args
				>,
				element_type
			>...
		>,
		"All row elements must have the same type"
	);

	return
		fcppt::container::grid::static_row_type<
			element_type,
			fcppt::cast::size<
				fcppt::container::grid::size_type
			>(
				sizeof...(Args) + 1u
			)
		>{{
			std::forward<
				Arg1
			>(
				_arg1
			),
			std::forward<
				Args
			>(
				_args
			)...
		}};
}

}
}
}

#endif
