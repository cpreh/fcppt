//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_OBJECT_FWD_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_OBJECT_FWD_HPP_INCLUDED

#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace container
{
namespace grid
{

template<
	typename T,
	fcppt::container::grid::size_type N,
	typename A = std::allocator<T>
>
class object;

}
}
}

#endif
