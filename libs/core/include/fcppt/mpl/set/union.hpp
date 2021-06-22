//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_SET_UNION_HPP_INCLUDED
#define FCPPT_MPL_SET_UNION_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/fold.hpp>
#include <fcppt/mpl/set/insert_relaxed.hpp>
#include <fcppt/mpl/set/object_concept.hpp>
#include <fcppt/mpl/set/to_list.hpp>

namespace fcppt::mpl::set
{
/**
\brief The union of two sets.

\ingroup fcpptmpl

The result contains every element that is in \a Set1 or in \a Set2.
*/
template <fcppt::mpl::set::object_concept Set1, fcppt::mpl::set::object_concept Set2>
using union_ = fcppt::mpl::list::fold<
    fcppt::mpl::set::to_list<Set1>,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<fcppt::mpl::set::insert_relaxed>,
        fcppt::mpl::arg<1>,
        fcppt::mpl::arg<0>>,
    Set2>;
}

#endif
