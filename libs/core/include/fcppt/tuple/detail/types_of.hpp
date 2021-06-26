//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_DETAIL_TYPES_OF_HPP_INCLUDED
#define FCPPT_TUPLE_DETAIL_TYPES_OF_HPP_INCLUDED

#include <fcppt/mpl/list/object_fwd.hpp>
#include <fcppt/tuple/object_fwd.hpp>

namespace fcppt::tuple::detail
{
template <typename Type>
struct types_of;

template <typename... Types>
struct types_of<fcppt::tuple::object<Types...>>
{
  using type = fcppt::mpl::list::object<Types...>;
};

}

#endif
