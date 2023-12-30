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
#include <fcppt/mpl/size_type_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/at.hpp>
#include <fcppt/mpl/list/interval.hpp>
#include <fcppt/mpl/list/map.hpp>
#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/size.hpp>

namespace fcppt::mpl::list
{
/**
\brief Removes some elements of a list from the beginning.
\ingroup fcpptmpl
If <code>List = list::object<L_1,...,L_n></code> then the result is
\code
list::object<L_{S+1},...,L_n>
\endcode
*/
template <fcppt::mpl::list::object_concept List, fcppt::mpl::size_type_concept S>
using drop = fcppt::mpl::list::map<
    fcppt::mpl::list::interval<S, fcppt::mpl::list::size<List>>,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<fcppt::mpl::list::at>,
        fcppt::mpl::constant<List>,
        fcppt::mpl::arg<1>>>;
}

#endif
