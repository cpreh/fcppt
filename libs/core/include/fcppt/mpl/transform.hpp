//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_TRANSFORM_HPP_INCLUDED
#define FCPPT_MPL_TRANSFORM_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/fold.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/lambda_concept.hpp>
#include <fcppt/mpl/list.hpp>
#include <fcppt/mpl/list_concept.hpp>
#include <fcppt/mpl/push_back.hpp>

namespace fcppt::mpl
{
template <fcppt::mpl::list_concept List, fcppt::mpl::lambda_concept F>
using transform = fcppt::mpl::fold<
    List,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<fcppt::mpl::push_back>,
        fcppt::mpl::arg<1>,
        fcppt::mpl::bind<F, fcppt::mpl::arg<0>>>,
    fcppt::mpl::list<>>;
}

#endif
