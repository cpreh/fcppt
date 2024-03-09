//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_FOR_EACH_BREAK_HPP_INCLUDED
#define FCPPT_MPL_LIST_FOR_EACH_BREAK_HPP_INCLUDED

#include <fcppt/loop.hpp>
#include <fcppt/tag.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
template <typename Fun>
inline void for_each_break(fcppt::mpl::list::object<>, Fun const &)
{
}

template <typename Type, typename... Types, typename Fun>
void for_each_break(fcppt::mpl::list::object<Type,Types...>, Fun const &_func)
{
  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GCC_WARNING(-Wswitch-default)
  switch (_func(fcppt::tag<Type>{}))
  {
  case fcppt::loop::continue_:
    fcppt::mpl::list::detail::for_each_break(fcppt::mpl::list::object<Types...>{},_func);
    return;
  case fcppt::loop::break_:
    return;
  }
  FCPPT_PP_POP_WARNING
}
}

/**
\brief Calls a runtime function for each element of a listing, possibly breaking out early.
\ingroup fcpptmpl

Let <code>List = list::object<L_1,...,L_n></code>.
Calls <code>r_1 = _function(fcppt::tag<L_1>{})</code>.
If <code>r_1 == fcppt::loop::break_</code>, the algorithm stops.
If <code>r_1 == fcppt::loop::continue_</code>, then <code>r_2 = _function(fcppt::tag<L_2>{})</code> and so on,
up to <code>r_n = _function(fcppt::tag<L_n>{})</code>.

// TODO(concepts)
*/
template <fcppt::mpl::list::object_concept List, typename Function>
inline void for_each_break(Function const &_function)
{
  return fcppt::mpl::list::detail::for_each_break(List{},_function);
}

}

#endif
