//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_SET_FROM_LIST_RELAXED_HPP_INCLUDED
#define FCPPT_MPL_SET_FROM_LIST_RELAXED_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/fold.hpp>
#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/mpl/set/insert_relaxed.hpp>
#include <fcppt/mpl/set/object.hpp>
#include <fcppt/mpl/set/unique.hpp>

namespace fcppt::mpl::set
{
template <fcppt::mpl::list::object_concept List>
using from_list_relaxed = fcppt::mpl::list::fold<
    List,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<fcppt::mpl::set::insert_relaxed>,
        fcppt::mpl::arg<2>,
        fcppt::mpl::arg<1>>,
    fcppt::mpl::set::object<>>;
}

#endif
