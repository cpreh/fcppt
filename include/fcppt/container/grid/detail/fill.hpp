//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_FILL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_FILL_HPP_INCLUDED

#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
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
	fcppt::container::grid::size_type Current,
	typename T,
	fcppt::container::grid::size_type N,
	typename A,
	typename Fn
>
typename
boost::disable_if_c
<
	Current != N,
	void
>::type
fill(
	fcppt::container::grid::object<T,N,A> &g,
	Fn const &f,
	typename fcppt::container::grid::object<T,N,A>::pos position)
{
	g[position] =
		f(
			position);
}

template
<
	fcppt::container::grid::size_type Current,
	typename T,
	fcppt::container::grid::size_type N,
	typename A,
	typename Fn
>
typename
boost::enable_if_c
<
	Current != N,
	void
>::type
fill(
	fcppt::container::grid::object<T,N,A> &g,
	Fn const &f,
	typename fcppt::container::grid::object<T,N,A>::pos position)
{
	for(
		typename fcppt::container::grid::object<T,N,A>::size_type i = 0;
		i < g.size()[Current];
		++i)
	{
		position[Current] = i;
		fcppt::container::grid::detail::fill<
			Current + 1u
		>(
			g,
			f,
			position);
	}
}
}
}
}
}

#endif
