//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_SET_TO_LIST_HPP_INCLUDED
#define FCPPT_MPL_SET_TO_LIST_HPP_INCLUDED

#include <fcppt/mpl/list/object_fwd.hpp>
#include <fcppt/mpl/set/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/set/object_fwd.hpp>

namespace fcppt::mpl::set
{
namespace detail
{
template<typename Set>
struct to_list;

template<typename... Es>
struct to_list<fcppt::mpl::set::object<Es...>>
{
  using type = fcppt::mpl::list::object<Es...>;
};
}

/**
\brief Converts a set to a list.
\ingroup fcpptmpl
Let <code>Set = set::object<E_1,...,E_n></code>. The result is
\code
list::object<E_1,...,E_n>
\endcode
*/
template<fcppt::mpl::set::object_concept Set>
using to_list = fcppt::mpl::set::detail::to_list<Set>::type;
}

#endif
