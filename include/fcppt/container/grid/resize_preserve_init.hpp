//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_RESIZE_PRESERVE_INIT_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_RESIZE_PRESERVE_INIT_HPP_INCLUDED

#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/detail/assign_fill_recurse.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief Like \ref resize_preserve but also initializes new elements
For every p where every component of p is greater or equal to \p _new_size
_result[p] will be assigned from \p _value
*/
template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
void
resize_preserve_init(
	grid::object<T, N, A> &_result,
	typename grid::object<T, N, A>::dim const &_new_size,
	typename grid::object<T, N, A>::const_reference _value
)
{
	typedef grid::object<T, N, A> object;

	object const temp(
		_result
	);

	_result.resize(
		_new_size
	);

	detail::assign_fill_recurse<
		N
	>(
		_result,
		temp,
		_value,
		typename object::dim(),
		true
	);
}

}
}
}

#endif
