//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_DETAIL_CYCLIC_ITERATOR_BASE_HPP_INCLUDED
#define FCPPT_DETAIL_CYCLIC_ITERATOR_BASE_HPP_INCLUDED

#include <fcppt/cyclic_iterator_fwd.hpp>
#include <fcppt/iterator/base_fwd.hpp>
#include <fcppt/iterator/types_from.hpp>

namespace fcppt
{
namespace detail
{
template <typename ContainerIterator>
using cyclic_iterator_base = fcppt::iterator::base<
    fcppt::iterator::types_from<fcppt::cyclic_iterator<ContainerIterator>, ContainerIterator>>;

}
}

#endif
