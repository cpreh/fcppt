//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_DETAIL_POS_REF_ITERATOR_BASE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_POS_REF_ITERATOR_BASE_HPP_INCLUDED

#include <fcppt/container/grid/pos_ref_iterator_fwd.hpp>
#include <fcppt/container/grid/pos_reference_fwd.hpp>
#include <fcppt/iterator/base_fwd.hpp>
#include <fcppt/iterator/types_fwd.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container::grid::detail
{
template <typename Grid>
using pos_ref_iterator_base = fcppt::iterator::base<fcppt::iterator::types<
    fcppt::container::grid::pos_ref_iterator<Grid>,
    fcppt::container::grid::pos_reference<Grid>,
    fcppt::container::grid::pos_reference<Grid>,
    typename Grid::difference_type,
    std::input_iterator_tag>>;

}

#endif
