//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_INDEX_OF_HPP_INCLUDED
#define FCPPT_MPL_LIST_INDEX_OF_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/index_of_if.hpp>
#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{
template <fcppt::mpl::list::object_concept List, typename E>
using index_of = fcppt::mpl::list::index_of_if<
    List,
    fcppt::mpl::
        bind<fcppt::mpl::lambda<std::is_same>, fcppt::mpl::constant<E>, fcppt::mpl::arg<0>>>;
}

#endif
