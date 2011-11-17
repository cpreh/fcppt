//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_OUT_OF_RANGE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_OUT_OF_RANGE_HPP_INCLUDED

#include <fcppt/container/grid/exception.hpp>
#include <fcppt/string.hpp>

namespace fcppt
{
namespace container
{
namespace grid
{

/// Thrown by the grid's \link fcppt::container::grid::object::at at \endlink function.
class out_of_range
:
	public fcppt::container::grid::exception
{
public:
	out_of_range();
};

}
}
}

#include <fcppt/container/grid/impl/out_of_range.hpp>

#endif
