//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_RESIZE_PRESERVE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_RESIZE_PRESERVE_HPP_INCLUDED

#include <fcppt/no_init.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/detail/assign_recurse.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief Resizes \p _result to \p _newsize and preserves all elements possible

\ingroup fcpptcontainergrid

For every p where every component of p is less than every component of
_new_size, _result[p] will be preserved
*/
template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
void
resize_preserve(
	fcppt::container::grid::object<
		T,
		N,
		A
	> &_result,
	typename fcppt::container::grid::object<
		T,
		N,
		A
	>::dim const &_new_size
)
{
	typedef
	fcppt::container::grid::object<
		T,
		N,
		A
	> object;

	object const temp(
		_result
	);

	_result.resize(
		_new_size,
		fcppt::no_init{}
	);

	fcppt::container::grid::detail::assign_recurse<
		N
	>(
		_result,
		temp,
		object::pos::null()
	);
}

}
}
}

#endif
