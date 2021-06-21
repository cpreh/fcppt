//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_LIST_SIZE_HPP_INCLUDED
#define FCPPT_MPL_LIST_SIZE_HPP_INCLUDED

#include <fcppt/mpl/size_type.hpp>
#include <fcppt/mpl/list/object_fwd.hpp>
#include <fcppt/mpl/list/object_concept.hpp>

namespace fcppt::mpl::list
{
namespace detail
{
template<typename List>
struct size;

template<typename... E>
struct size<fcppt::mpl::list::object<E...>>
{
  using type = fcppt::mpl::size_type<sizeof...(E)>;
};
}

template<fcppt::mpl::list::object_concept List>
using size = typename fcppt::mpl::list::detail::size<List>::type;

}

#endif
