//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_SET_EQUAL_HPP_INCLUDED
#define FCPPT_MPL_SET_EQUAL_HPP_INCLUDED

#include <fcppt/mpl/set/object_concept.hpp>
#include <fcppt/mpl/set/object_fwd.hpp>
#include <fcppt/mpl/set/symmetric_difference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::set
{
/**
\brief Checks if two sets are equal.

\ingroup fcpptmpl

Two sets are equal if and only if they contain the same elements.
Let <code>Set1=set::object<E_1,...,E_n></code>
and <code>Set2=set::object<E_1',...,E_m'>></code>.
Then the result is <code>std::true_type</code> if
\code
{E_1,...,E_n} = {E_1',...,E_m'}
\endcode
Otherwise, the result is <code>std::false_type</code>.
*/
template <fcppt::mpl::set::object_concept Set1, fcppt::mpl::set::object_concept Set2>
using equal =
    std::is_same<fcppt::mpl::set::symmetric_difference<Set1, Set2>, fcppt::mpl::set::object<>>;
}

#endif
