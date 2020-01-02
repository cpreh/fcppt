//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_POS_ITERATOR_BASE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_POS_ITERATOR_BASE_HPP_INCLUDED

#include <fcppt/container/grid/pos_fwd.hpp>
#include <fcppt/container/grid/pos_iterator_fwd.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/iterator/base_fwd.hpp>
#include <fcppt/iterator/types_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
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
	typename SizeType,
	fcppt::container::grid::size_type Size
>
using pos_iterator_base
=
fcppt::iterator::base<
	fcppt::iterator::types<
		fcppt::container::grid::pos_iterator<
			SizeType,
			Size
		>,
		fcppt::container::grid::pos<
			SizeType,
			Size
		>,
		fcppt::container::grid::pos<
			SizeType,
			Size
		>,
		std::make_signed_t<
			SizeType
		>,
		std::input_iterator_tag
	>
>;

}
}
}
}

#endif
