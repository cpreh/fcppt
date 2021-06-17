//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_AT_HPP_INCLUDED
#define FCPPT_MPL_AT_HPP_INCLUDED

#include <fcppt/mpl/list_fwd.hpp>
#include <fcppt/mpl/list_concept.hpp>
#include <fcppt/mpl/index.hpp>
#include <fcppt/mpl/index_concept.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl
{
namespace detail
{
template<typename List, typename I>
struct at;

template<typename... E, std::size_t I>
struct at<fcppt::mpl::list<E...>,fcppt::mpl::index<I>>
{
  using type = std::tuple_element_t<I,std::tuple<E...>>;
};
}

template<fcppt::mpl::list_concept List, fcppt::mpl::index_concept I>
using at = typename fcppt::mpl::detail::at<List,I>::type;

}

#endif
