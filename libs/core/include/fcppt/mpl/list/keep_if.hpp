//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_KEEP_IF_HPP_INCLUDED
#define FCPPT_MPL_LIST_KEEP_IF_HPP_INCLUDED

#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/lambda_concept.hpp>
#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/mpl/list/remove_if.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{
/**
\brief Only keeps elements that satisfy a predicate.
\ingroup fcpptmpl
Keeps the elements of \a List for which \a Pred is <code>std::true_type</code>.
The order of the elements stays the same.
*/
template <fcppt::mpl::list::object_concept List, fcppt::mpl::lambda_concept Pred>
using keep_if =
    fcppt::mpl::list::remove_if<List, fcppt::mpl::bind<fcppt::mpl::lambda<std::negation>, Pred>>;
}

#endif
