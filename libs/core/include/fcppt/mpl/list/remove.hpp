//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_REMOVE_HPP_INCLUDED
#define FCPPT_MPL_LIST_REMOVE_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/mpl/list/remove_if.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{
template <fcppt::mpl::list::object_concept List, typename Type>
using remove = fcppt::mpl::list::remove_if<
    List,
    fcppt::mpl::
        bind<fcppt::mpl::lambda<std::is_same>, fcppt::mpl::constant<Type>, fcppt::mpl::arg<1>>>;
}

#endif
