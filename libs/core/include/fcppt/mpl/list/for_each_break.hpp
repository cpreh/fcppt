//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_FOR_EACH_BREAK_HPP_INCLUDED
#define FCPPT_MPL_LIST_FOR_EACH_BREAK_HPP_INCLUDED

#include <fcppt/loop.hpp>
#include <fcppt/tag.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/mpl/list/object_concept.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
template <typename Fun>
void for_each_break(fcppt::mpl::list::object<>, Fun const &)
{
}

template <typename Type, typename... Types, typename Fun>
void for_each_break(fcppt::mpl::list::object<Type,Types...>, Fun const &_func)
{
  switch (_func(fcppt::tag<Type>{}))
  {
  case fcppt::loop::continue_:
    fcppt::mpl::list::detail::for_each_break(fcppt::mpl::list::object<Types...>{},_func);
    return;
  case fcppt::loop::break_:
    return;
  }
}
}

// TODO(concepts)
template <fcppt::mpl::list::object_concept List, typename Function>
inline void for_each_break(Function const &_function)
{
  return fcppt::mpl::list::detail::for_each_break(List{},_function);
}

}

#endif
