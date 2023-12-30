//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_SET_INTERSECTION_HPP_INCLUDED
#define FCPPT_MPL_SET_INTERSECTION_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/if.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/fold.hpp>
#include <fcppt/mpl/set/contains.hpp>
#include <fcppt/mpl/set/insert_relaxed.hpp>
#include <fcppt/mpl/set/object.hpp>
#include <fcppt/mpl/set/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/set/to_list.hpp>

namespace fcppt::mpl::set
{
/**
\brief The intersection of two sets.
\ingroup fcpptmpl
The result contains every element that is both in \a Set1 and \a Set2.
*/
template <fcppt::mpl::set::object_concept Set1, fcppt::mpl::set::object_concept Set2>
using intersection = fcppt::mpl::list::fold<
    fcppt::mpl::set::to_list<Set1>,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<fcppt::mpl::if_>,
        fcppt::mpl::bind<
            fcppt::mpl::lambda<fcppt::mpl::set::contains>,
            fcppt::mpl::constant<Set2>,
            fcppt::mpl::arg<1>>,
        fcppt::mpl::bind<
            fcppt::mpl::lambda<fcppt::mpl::set::insert_relaxed>,
            fcppt::mpl::arg<2>,
            fcppt::mpl::arg<1>>,
        fcppt::mpl::arg<2>>,
    fcppt::mpl::set::object<>>;
}

#endif
