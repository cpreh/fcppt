//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_DROP_HPP_INCLUDED
#define FCPPT_MPL_LIST_DROP_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/size_type_concept.hpp>
#include <fcppt/mpl/list/at.hpp>
#include <fcppt/mpl/list/interval.hpp>
#include <fcppt/mpl/list/map.hpp>
#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/mpl/list/size.hpp>

namespace fcppt::mpl::list
{
template <fcppt::mpl::list::object_concept List, fcppt::mpl::size_type_concept Size>
using drop = fcppt::mpl::list::map<
    fcppt::mpl::list::interval<Size, fcppt::mpl::list::size<List>>,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<fcppt::mpl::list::at>,
        fcppt::mpl::constant<List>,
        fcppt::mpl::arg<1>>>;
}

#endif
