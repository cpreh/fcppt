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
#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/remove_if.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{
/**
\brief Removes a specific type from a list.
\ingroup fcpptmpl
Removes every occurrence of \a T from \a List.
The order of the remaining elements stays the same.
*/
template <fcppt::mpl::list::object_concept List, typename T>
using remove = fcppt::mpl::list::remove_if<
    List,
    fcppt::mpl::
        bind<fcppt::mpl::lambda<std::is_same>, fcppt::mpl::constant<T>, fcppt::mpl::arg<1>>>;
}

#endif
