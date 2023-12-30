//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_ANY_OF_HPP_INCLUDED
#define FCPPT_MPL_LIST_ANY_OF_HPP_INCLUDED

#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/lambda_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/fold.hpp>
#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{
/**
\brief Checks if a predicate holds for any type of a list.
\ingroup fcpptmpl
If <code>List=list::object<L_1,...,L_n></code> and
<code>L</code> holds a function <code>F</code> of arity <code>1</code>,
then the result is
\code
std::bool_constant<std::disjunction_v<F<L_1>, ..., F<L_n>>>
\endcode

TODO(concepts)
*/
template <fcppt::mpl::list::object_concept List, fcppt::mpl::lambda_concept L>
using any_of = fcppt::mpl::list::fold<
    List,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<std::disjunction>,
        fcppt::mpl::bind<L, fcppt::mpl::arg<1>>,
        fcppt::mpl::arg<2>>,
    std::false_type>;
}

#endif
