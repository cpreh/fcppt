//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_SET_INSERT_HPP_INCLUDED
#define FCPPT_MPL_SET_INSERT_HPP_INCLUDED

#include <fcppt/mpl/set/contains.hpp>
#include <fcppt/mpl/set/object.hpp>
#include <fcppt/mpl/set/object_concept.hpp> // IWYU pragma: keep

namespace fcppt::mpl::set
{
namespace detail
{
template<typename Set, typename Key>
struct insert;

template<typename... Elements, typename Key>
struct insert<fcppt::mpl::set::object<Elements...>,Key>
{
  using type = fcppt::mpl::set::object<Elements...,Key>;
};
}
/**
\brief Inserts a new element into a set.
\ingroup fcpptmpl
Let <code>Set = set::object<E_1,...,E_n></code>.
Then the result is
\code
set::object<E_1,...,E_n,E>
\endcode
This only works if <code>E</code> is not equal to any of the <code>E_1,...,E_n</code>.
*/
template<fcppt::mpl::set::object_concept Set, typename E>
requires (!fcppt::mpl::set::contains<Set,E>::value)
using insert = typename fcppt::mpl::set::detail::insert<Set,E>::type;
}

#endif
