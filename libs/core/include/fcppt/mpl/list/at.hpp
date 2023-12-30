//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_AT_HPP_INCLUDED
#define FCPPT_MPL_LIST_AT_HPP_INCLUDED

#include <fcppt/mpl/size_type.hpp>
#include <fcppt/mpl/size_type_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/object_concept.hpp> // IWYU pragma: keep
#include <fcppt/mpl/list/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <functional> // IWYU pragma: keep
#include <tuple>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
template<typename List, typename Index>
struct at;

template<typename... Elems, std::size_t Index>
requires (std::less<>{}(Index,sizeof...(Elems)))
struct at<fcppt::mpl::list::object<Elems...>,fcppt::mpl::size_type<Index>>
{
  using type = std::tuple_element_t<Index,std::tuple<Elems...>>;
};
}

/**
\brief The element of a list at a given position.
\ingroup fcpptmpl
If <code>List = list::object<L_1,...,L_n></code>
and <code>Index = fcppt::mpl::size_type<j></code> with <code>0 <= j < n</code> then the result is <code>L_{j-1}</code>.
*/
template<fcppt::mpl::list::object_concept List, fcppt::mpl::size_type_concept Index>
using at = typename fcppt::mpl::list::detail::at<List,Index>::type;

}

#endif
