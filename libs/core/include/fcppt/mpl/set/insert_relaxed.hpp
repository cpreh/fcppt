//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_SET_INSERT_RELAXED_HPP_INCLUDED
#define FCPPT_MPL_SET_INSERT_RELAXED_HPP_INCLUDED

#include <fcppt/mpl/apply.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/if.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/set/contains.hpp>
#include <fcppt/mpl/set/insert.hpp>
#include <fcppt/mpl/set/object_concept.hpp>

namespace fcppt::mpl::set
{
/**
\brief Inserts an element into a set.
\ingroup fcpptmpl
Let <code>Set = set::object<E_1,...,E_n></code>.
If <code>E</code> is not equal to any of the <code>E_1,...,E_n</code>, then the result is
\code
set::object<E_1,...,E_n,E>
\endcode
Otherwise, the result is <code>Set</code>.
*/
template <fcppt::mpl::set::object_concept Set, typename Value>
using insert_relaxed = fcppt::mpl::apply<fcppt::mpl::if_<
    fcppt::mpl::set::contains<Set, Value>,
    fcppt::mpl::constant<Set>,
    fcppt::mpl::bind<
        fcppt::mpl::lambda<fcppt::mpl::set::insert>,
        fcppt::mpl::constant<Set>,
        fcppt::mpl::constant<Value>>>>;
}

#endif
