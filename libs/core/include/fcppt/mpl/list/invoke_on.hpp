//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_INVOKE_ON_HPP_INCLUDED
#define FCPPT_MPL_LIST_INVOKE_ON_HPP_INCLUDED

#include <fcppt/runtime_index.hpp>
#include <fcppt/tag.hpp>
#include <fcppt/mpl/size_type.hpp>
#include <fcppt/mpl/list/at.hpp>
#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/mpl/list/size.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4702)

/**
\brief Applies a function to the nth element of an mpl::list with a runtime index.

\ingroup fcpptmpl

Let \a List be the types <code>(t_0,...,t_{n-1})</code> and <code>i =
_index</code>.
If i is less than n,
the result is \a _function called with <code>fcppt::tag<t_i></code>.
Otherwise, the result of \a _fail_function is returned.

\note The compile time and the runtime complexities of this function are linear
in the size of the mpl list.

\snippet mpl/list/invoke_on.cpp mpl_invoke_on

\tparam Function Must be callable as <code>R fcppt::tag<T>()</code> for every T
in \a List , where R is the result type.

\tparam FailFunction Must be a callable as <code>R ()</code>, where R is the result tye.

TODO(concepts)
*/
template <fcppt::mpl::list::object_concept List, typename Function, typename FailFunction>
std::invoke_result_t<FailFunction>
invoke_on(std::size_t const _index, Function const &_function, FailFunction const &_fail_function)
{
  return fcppt::runtime_index<fcppt::mpl::list::size<List>>(
      _index,
      [&_function]<std::size_t Cur>(fcppt::mpl::size_type<Cur>) -> decltype(auto)
      { return _function(fcppt::tag<fcppt::mpl::list::at<List, fcppt::mpl::size_type<Cur>>>{}); },
      _fail_function);
}

FCPPT_PP_POP_WARNING

}

#endif
