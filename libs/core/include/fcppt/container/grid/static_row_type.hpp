//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_STATIC_ROW_TYPE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_STATIC_ROW_TYPE_HPP_INCLUDED

#include <fcppt/array/object_impl.hpp>
#include <fcppt/container/grid/size_type.hpp>

namespace fcppt
{
namespace container
{
namespace grid
{
/**
\brief The type of a static row (an array).

\ingroup fcpptcontainergrid
*/
template <typename T, fcppt::container::grid::size_type N>
using static_row_type = fcppt::array::object<T, N>;

}
}
}

#endif
