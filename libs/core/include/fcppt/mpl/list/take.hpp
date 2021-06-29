//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_TAKE_HPP_INCLUDED
#define FCPPT_MPL_LIST_TAKE_HPP_INCLUDED

#include <fcppt/mpl/size_type.hpp>
#include <fcppt/mpl/size_type_concept.hpp>
#include <fcppt/mpl/list/at.hpp>
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/mpl/list/object_concept.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
template<typename List, typename Indices>
struct take;

template<typename List, std::size_t... Indices>
struct take<List,std::index_sequence<Indices...>>
{
  using type = fcppt::mpl::list::object<fcppt::mpl::list::at<List,fcppt::mpl::size_type<Indices>>...>;
};
}

template<fcppt::mpl::list::object_concept List, fcppt::mpl::size_type_concept Size>
using take = typename fcppt::mpl::list::detail::take<List,std::make_index_sequence<Size::value>>::type;

}

#endif
