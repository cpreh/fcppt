//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_DETAIL_ALL_INITIALIZERS_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_ALL_INITIALIZERS_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/all_of.hpp>
#include <fcppt/record/detail/contains_initializer.hpp>

namespace fcppt::record::detail
{
template <typename Elements, typename Args>
using all_initializers = fcppt::mpl::list::all_of<
    Elements,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<fcppt::record::detail::contains_initializer>,
        fcppt::mpl::constant<Args>,
        fcppt::mpl::arg<1>>>;
}

#endif
