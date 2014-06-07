//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_RESIZE_OPT_INIT_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_RESIZE_OPT_INIT_HPP_INCLUDED

#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{
namespace detail
{

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename
boost::enable_if<
	std::is_default_constructible<
		T
	>,
	void
>::type
resize_opt_init(
	fcppt::container::grid::object<
		T,
		N,
		A
	> &_result,
	typename
	fcppt::container::grid::object<
		T,
		N,
		A
	>::dim const _new_size,
	T const &
)
{
	_result.resize(
		_new_size
	);
}

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A
>
typename
boost::disable_if<
	std::is_default_constructible<
		T
	>,
	void
>::type
resize_opt_init(
	fcppt::container::grid::object<
		T,
		N,
		A
	> &_result,
	typename
	fcppt::container::grid::object<
		T,
		N,
		A
	>::dim const _new_size,
	T const &_value
)
{
	_result.resize_init(
		_new_size,
		_value
	);
}

}
}
}
}

#endif
