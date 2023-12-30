//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_INDEX_OF_IF_HPP_INCLUDED
#define FCPPT_MPL_LIST_INDEX_OF_IF_HPP_INCLUDED

#include <fcppt/mpl/apply.hpp>
#include <fcppt/mpl/if.hpp>
#include <fcppt/mpl/lambda_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/size_type.hpp>
#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
template<typename List, typename L, typename O>
struct index_of_if;

template <typename E, typename... Es, fcppt::mpl::lambda_concept L, std::size_t O>
struct index_of_if<fcppt::mpl::list::object<E, Es...>, L, fcppt::mpl::size_type<O>>
    : fcppt::mpl::if_<
          fcppt::mpl::apply<L, E>,
          fcppt::mpl::size_type<O>,
          typename fcppt::mpl::list::detail::
              index_of_if<fcppt::mpl::list::object<Es...>, L, fcppt::mpl::size_type<O + 1U>>>
{
};
}
/**
\brief The first index where an element matches a predicate inside a list.
\ingroup fcpptmpl
Let <code>List = list::object<L_1,...,L_n></code> and let <code>L</code> hold a
function <code>F</code> of arity <code>1</code>.
Returns <code>size_type<Index></code> where <code>Index</code> is the smallest number such that
<code>F<L_{Index}> = std::true_type</code>.
*/
template<fcppt::mpl::list::object_concept List, fcppt::mpl::lambda_concept L>
using index_of_if = typename fcppt::mpl::list::detail::index_of_if<List,L,fcppt::mpl::size_type<0U>>::type;
}

#endif
