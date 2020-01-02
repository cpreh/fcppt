//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_MIN_FWD_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MIN_FWD_HPP_INCLUDED

#include <fcppt/strong_typedef_fwd.hpp>
#include <fcppt/container/grid/min_tag.hpp>
#include <fcppt/container/grid/pos_fwd.hpp>
#include <fcppt/container/grid/size_type.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief The start type of a pos range

\ingroup fcpptcontainergrid
*/
template<
	typename SizeType,
	fcppt::container::grid::size_type Size
>
using
min
=
fcppt::strong_typedef<
	fcppt::container::grid::pos<
		SizeType,
		Size
	>,
	fcppt::container::grid::min_tag
>;

}
}
}

#endif
