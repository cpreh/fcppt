//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_OUTPUT_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_OUTPUT_HPP_INCLUDED

#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/detail/print_recurse.hpp>
#include <fcppt/math/vector/null.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief Outputs a grid

\ingroup fcpptcontainergrid

Outputs the grid \a _object to \a _stream. Every level of the grid will be
wrapped in parenthesis. So, for example, a two dimensional grid of size
<code>(n,m)</code> will be written as <code>((x_0, y_0), (x_1, y_0), ..., (x_0,
y_1), ..., (x_n, y_m))</code>.

\tparam T Must be a type that has an appropriate <code>operator<< </code>

\param _stream The stream to write to

\param _object The grid to write

\return \a _stream
*/
template<
	typename Ch,
	typename Traits,
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
std::basic_ostream<
	Ch,
	Traits
> &
operator<<(
	std::basic_ostream<
		Ch,
		Traits
	> &_stream,
	fcppt::container::grid::object<
		T,
		N,
		A
	> const &_object
)
{
	typedef
	fcppt::container::grid::object<
		T,
		N,
		A
	>
	object;

	fcppt::container::grid::detail::print_recurse<
		N
	>(
		_stream,
		_object,
		fcppt::math::vector::null<
			typename
			object::pos
		>()
	);

	return
		_stream;
}

}
}
}

#endif
