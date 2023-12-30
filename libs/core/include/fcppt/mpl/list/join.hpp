//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_JOIN_HPP_INCLUDED
#define FCPPT_MPL_LIST_JOIN_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/append.hpp>
#include <fcppt/mpl/list/fold.hpp>
#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/object_fwd.hpp>

namespace fcppt::mpl::list
{
/**
\brief Joins a list of lists.
\ingroup fcpptmpl
If <code>List = list::object<L_1,...,L_n></code> and <code>L_1, ..., L_n</code> are lists, then the result is
\code
append<L_1,append<L_2,...,append<L_{n-1},L_n> ...>>
\endcode

\tparam List Must be a list of lists.
//TODO(concepts)
*/
template <fcppt::mpl::list::object_concept List>
using join = fcppt::mpl::list::fold<
    List,
    fcppt::mpl::
        bind<fcppt::mpl::lambda<fcppt::mpl::list::append>, fcppt::mpl::arg<2>, fcppt::mpl::arg<1>>,
    fcppt::mpl::list::object<>>;
}

#endif
