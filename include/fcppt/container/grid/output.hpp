//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_OUTPUT_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_OUTPUT_HPP_INCLUDED

#include <fcppt/container/grid/detail/print_recurse.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
namespace grid
{

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
	grid::object<
		T,
		N,
		A
	> const &_object
)
{
	typedef grid::object<T, N, A> object;

	detail::print_recurse<
		N
	>(
		_stream,
		_object,
		typename object::dim()
	);

	return _stream;
}

}
}
}

#endif
