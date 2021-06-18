//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_TRANSFORM_HPP_INCLUDED
#define FCPPT_MPL_LIST_TRANSFORM_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/lambda_concept.hpp>
#include <fcppt/mpl/list/fold.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/mpl/list/push_back.hpp>

namespace fcppt::mpl::list
{
template <fcppt::mpl::list::object_concept List, fcppt::mpl::lambda_concept F>
using transform = fcppt::mpl::list::fold<
    List,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<fcppt::mpl::list::push_back>,
        fcppt::mpl::arg<1>,
        fcppt::mpl::bind<F, fcppt::mpl::arg<0>>>,
    fcppt::mpl::list::object<>>;
}

#endif
