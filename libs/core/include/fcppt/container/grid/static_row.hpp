//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GRID_STATIC_ROW_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_STATIC_ROW_HPP_INCLUDED

#include <fcppt/cast/size.hpp>
#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/static_row_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container::grid
{
/**
\brief Creates an #fcppt::container::grid::static_row_type.

\ingroup fcpptcontainergrid
*/
template <typename Arg1, typename... Args>
fcppt::container::grid::static_row_type<
    std::remove_cvref_t<Arg1>,
    fcppt::cast::size<fcppt::container::grid::size_type>(sizeof...(Args) + 1U)>
static_row(Arg1 &&_arg1, Args &&..._args)
  requires(
      std::conjunction_v<std::is_same<std::remove_cvref_t<Args>, std::remove_cvref_t<Arg1>>...>)
{
  return fcppt::container::grid::static_row_type<
      std::remove_cvref_t<Arg1>,
      fcppt::cast::size<fcppt::container::grid::size_type>(sizeof...(Args) + 1U)>{
      std::forward<Arg1>(_arg1), std::forward<Args>(_args)...};
}
}

#endif
