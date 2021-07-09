//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_CONTAINS_HPP_INCLUDED
#define FCPPT_MPL_LIST_CONTAINS_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/any_of.hpp>
#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{
/**
\brief Checks if a list contains an element.
\ingroup fcpptmpl
Let <code>List = list::object<L_1,...,L_n></code>. The result is
<code>std::true_type</code> if <code>E = L_i</code> for some <code>1 <= i <= n</code>.
Otherwise, it is <code>std::false_type</code>.
*/
template <fcppt::mpl::list::object_concept List, typename E>
using contains = fcppt::mpl::list::any_of<
    List,
    fcppt::mpl::
        bind<fcppt::mpl::lambda<std::is_same>, fcppt::mpl::arg<1>, fcppt::mpl::constant<E>>>;
}

#endif
