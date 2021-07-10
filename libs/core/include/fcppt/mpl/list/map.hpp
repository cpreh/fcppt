//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_MAP_HPP_INCLUDED
#define FCPPT_MPL_LIST_MAP_HPP_INCLUDED

#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/lambda_concept.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/mpl/list/object_concept.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
template<typename List, typename F>
struct map;

template<typename... Types,template<typename...> class F>
struct map<fcppt::mpl::list::object<Types...>,fcppt::mpl::lambda<F>>
{
  using type = fcppt::mpl::list::object<F<Types>...>;
};
}
/**
\brief Applies a lambda to every element of a list.
\ingroup fcpptmpl
If <code>List=list::object<L_1,...,L_n></code> and
<code>L</code> holds a function <code>F</code> of arity <code>1</code>,
then the result is
\code
list::object<F<L_1>,...,F<L_n>>
\endcode
*/
template <fcppt::mpl::list::object_concept List, fcppt::mpl::lambda_concept F>
using map = typename fcppt::mpl::list::detail::map<List,F>::type;
}

#endif
