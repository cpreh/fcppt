//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_INDICES_HPP_INCLUDED
#define FCPPT_MPL_LIST_INDICES_HPP_INCLUDED

#include <fcppt/mpl/list/interval.hpp>
#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/mpl/list/size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{
template<fcppt::mpl::list::object_concept List>
using indices = fcppt::mpl::list::interval<std::size_t,0U,fcppt::mpl::list::size<List>::value>;
}

#endif
