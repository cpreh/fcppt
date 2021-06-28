//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_REPEAT_HPP_INCLUDED
#define FCPPT_MPL_LIST_REPEAT_HPP_INCLUDED

#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/size_type.hpp>
#include <fcppt/mpl/size_type_concept.hpp>
#include <fcppt/mpl/list/interval.hpp>
#include <fcppt/mpl/list/map.hpp>

namespace fcppt::mpl::list
{
template <typename Type, fcppt::mpl::size_type_concept Size>
using repeat = fcppt::mpl::list::
    map<fcppt::mpl::list::interval<fcppt::mpl::size_type<0U>, Size>, fcppt::mpl::constant<Type>>;
}

#endif
