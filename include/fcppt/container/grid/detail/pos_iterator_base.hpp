//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_POS_ITERATOR_BASE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_POS_ITERATOR_BASE_HPP_INCLUDED

#include <fcppt/container/grid/pos_fwd.hpp>
#include <fcppt/container/grid/pos_iterator_fwd.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <cstddef>
#include <iterator>
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
	fcppt::container::grid::size_type Size
>
using pos_iterator_base
=
boost::iterator_facade<
	fcppt::container::grid::pos_iterator<
		Size
	>,
	fcppt::container::grid::pos<
		std::size_t,
		Size
	>,
	std::forward_iterator_tag,
	fcppt::container::grid::pos<
		std::size_t,
		Size
	>,
	std::ptrdiff_t
>;

}
}
}
}

#endif
