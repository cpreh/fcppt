//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_REMOVE_IF_HPP_INCLUDED
#define FCPPT_MPL_LIST_REMOVE_IF_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/if.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/lambda_concept.hpp>
#include <fcppt/mpl/list/fold.hpp>
#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/mpl/list/object_fwd.hpp>
#include <fcppt/mpl/list/push_back.hpp>

namespace fcppt::mpl::list
{
/**
\brief Removes the elements that satisfy a predicate.
\ingroup fcpptmpl
Removes the elements of \a List for which \a Pred is <code>std::true_type</code>.
The order of the remaining elements stays the same.
*/
template <fcppt::mpl::list::object_concept List, fcppt::mpl::lambda_concept Pred>
using remove_if = fcppt::mpl::list::fold<
    List,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<fcppt::mpl::if_>,
        fcppt::mpl::bind<Pred, fcppt::mpl::arg<1>>,
        fcppt::mpl::arg<2>,
        fcppt::mpl::bind<
            fcppt::mpl::lambda<fcppt::mpl::list::push_back>,
            fcppt::mpl::arg<2>,
            fcppt::mpl::arg<1>>>,
    fcppt::mpl::list::object<>>;
}

#endif
