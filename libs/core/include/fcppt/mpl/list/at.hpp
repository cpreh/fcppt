//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_AT_HPP_INCLUDED
#define FCPPT_MPL_LIST_AT_HPP_INCLUDED

#include <fcppt/mpl/size_type.hpp>
#include <fcppt/mpl/size_type_concept.hpp>
#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/mpl/list/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <tuple>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
template<typename List, typename I>
struct at;

template<typename... E, std::size_t I>
requires (std::less<>{}(I,sizeof...(E)))
struct at<fcppt::mpl::list::object<E...>,fcppt::mpl::size_type<I>>
{
  using type = std::tuple_element_t<I,std::tuple<E...>>;
};
}

template<fcppt::mpl::list::object_concept List, fcppt::mpl::size_type_concept I>
using at = typename fcppt::mpl::list::detail::at<List,I>::type;

}

#endif
