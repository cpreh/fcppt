//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_SHRINK_TO_FIT_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_SHRINK_TO_FIT_HPP_INCLUDED

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
	typename A
>
void
shrink_to_fit(
	std::vector<T, A> &_impl
)
{
	std::vector<T, A> new_vec(
		_impl
	);

	_impl.swap(
		new_vec
	);
}

template<
	typename T,
	typename A
>
void
shrink_to_fit(
	fcppt::container::raw_vector<T, A> &_impl
)
{
	_impl.shrink_to_fit();
}

}
}
}
}

#endif
