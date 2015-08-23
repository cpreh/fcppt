//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_RESIZE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_RESIZE_HPP_INCLUDED

#include <fcppt/math/dim/contents.hpp>
#include <fcppt/container/raw_vector_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
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
	typename A,
	typename Dim
>
inline
void
resize(
	std::vector<
		T,
		A
	> &_impl,
	Dim const &_size
)
{
	_impl.resize(
		fcppt::math::dim::contents(
			_size
		)
	);
}

template<
	typename T,
	typename A,
	typename Dim
>
inline
void
resize(
	fcppt::container::raw_vector<
		T,
		A
	> &_impl,
	Dim const &_size
)
{
	_impl.resize_uninitialized(
		fcppt::math::dim::contents(
			_size
		)
	);
}

}
}
}
}

#endif
